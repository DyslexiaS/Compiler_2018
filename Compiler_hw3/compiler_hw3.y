/*	Definition section */
%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "common.h"
extern int yylineno;
extern int yylex();
int yyerror(char* msg);
#define get_data(Val)   ( Val.type == I_CONST ? Val.data.idata : Val.data.fdata )
#define operation(left, op, right)  if((left.type == I_CONST) && (right.type == I_CONST)){  \
                                        ret.type = I_CONST;                                 \
                                        ret.data.idata = get_data(left) op get_data(right); \
                                    }                                                       \
                                    else{                                                   \
                                        ret.type = F_CONST;                                 \
                                        ret.data.fdata = get_data(left) op get_data(right); \
                                    }                                                       
#define print_rel($$)   printf("%s\n",get_data($$) ? " true" : " false");
#define print_type(type)    type == I_CONST ? fprintf(fp, "\ti") : fprintf(fp, "\tf")
#define def_type_trans(left, right)     if((left.type == I_CONST)&&(right.type == F_CONST))    fprintf(fp, "\tf2i\n"); \
                                        if((left.type == F_CONST)&&(right.type == I_CONST))    fprintf(fp, "\ti2f\n");


/* Symbol table function - you can add new function if need. */
Variable* lookup_symbol(struct Table*, char* id);
void create_symbol(struct Table** table);
void insert_symbol(struct Table** table, char* id, int type, INT_FLOAT Var);

INT_FLOAT val_assign(int type, void* value, int index);
INT_FLOAT alu(INT_FLOAT left, int op, INT_FLOAT right);
INT_FLOAT get_id(char* id);
void assign_expr(char* id, INT_FLOAT value);
void assign_id(char* id, int op, INT_FLOAT expr);
bool is_redef(struct Table* table, char* id);
void new_scope();
void delete_scope();
void print_var(char* id);
void print_load(char* id);
void print_store(char* id);
void print_for_start();
void print_jump(int op, char* label_name, int IDX[]);
void print_label(char* label_name, int IDX[]);
void alu_type_trans(INT_FLOAT left, INT_FLOAT right);
void op_assign(INT_FLOAT left, INT_FLOAT right);
int bool_handler(INT_FLOAT left, int op, INT_FLOAT right);
struct Table* CUR_TABLE;
int depth;
int var_idx;
FILE* fp;
int ELSE_IDX[100];
int EXIT_IDX[100];
int FOR_IDX[100];
int BOOL_IDX[100];
int ERROR;
int func_num;
void func_insert_symbol(struct Table** table, char* id, int type);
void func_store(struct Table** table);
int get_func_type(const char* name);
FuncName func_info[10];
%}

/* Using union to define nonterminal and token type */
%union {
    int i_val;
    double f_val;
    char* string;
    INT_FLOAT if_val;
}
 
/* Token without return */
%token PRINT PRINTLN 
%token IF ELSE FOR
%token VAR NEWLINE
%token VOID   
%token FUNC 
%token RET 

%token ADD SUB MUL DIV MOD INC DEC
%token GT LT GE LE EQ NE
%token ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token AND OR NOT
%token LB RB LCB RCB

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <string> STRING
%token <string> ID
%token <string> F_NAME
%token <i_val> INT
%token <i_val> FLOAT

/* Nonterminal with return, which need to sepcify type */
%type <if_val> expression_stat
%type <if_val> initializer
%type <if_val> identifier
%type <f_val> incdec_stat
%type <i_val> type
%type <if_val> literal
%type <if_val> operand
%type <i_val> boolean_expr
%type <if_val> print_constent
%type <if_val> function_call


/* Yacc will start at this nonterminal */
%start program

/* Precedence */
%right ASSIGN ADD_ASSIGN
%left OR
%left AND
%left EQ NE GT LT GE LE
%left ADD SUB
%left MUL DIV MOD
%left INC DEC
/* Grammar section */
%%

program
    : program stat
    |
;

stat
    : declaration       {}
    | compound_stat     {}
    | expression_stat   {}
    | print_func        {}
    | function_stat     {}
    | return_stat       {}
    | NEWLINE           {}
;
return_stat
    : RET expression_stat   {}
;
function_stat
    : function_call     {}
    | function_declare  {}
;
function_declare
    : FUNC F_NAME{
                    new_scope();
                    fprintf(fp, "FUNC_%s:\n", $2); 
                    if(!strcmp($2, "main")){
                        var_idx = 0;
                    }
                    else{
                        strcpy((char*)func_info[func_num].name, $2);
                        fprintf(fp, "\tastore %d\n", (++func_num)*STACK_SIZE ); 
                        var_idx = func_num*STACK_SIZE+1;
                    }
                }
    LB argument_get RB type{ func_info[func_num-1].type = $7; }
    LCB { func_store(&CUR_TABLE); }  program RCB
    {   
        delete_scope();
        if (strcmp($2, "main"))
            fprintf(fp, "\tret %d\n", func_num*STACK_SIZE);
    }
;

argument_get
    : argument_get ',' ID type { func_insert_symbol(&CUR_TABLE, $3, $4 ); }
    | ID type   {  func_insert_symbol(&CUR_TABLE, $1, $2 );  }
    |
;
function_call
    :   F_NAME LB argument_send RB { $$.type = get_func_type($1); fprintf(fp, "\tjsr FUNC_%s\n", $1); }
;
argument_send
    :   argument_send ',' expression_stat
    |   expression_stat
    |
;

declaration
    : VAR ID type ASSIGN initializer NEWLINE { insert_symbol(&CUR_TABLE, $2, $3, $5);   }
    | VAR ID type NEWLINE {  INT_FLOAT n; fprintf(fp, "\tldc 0\n"); insert_symbol(&CUR_TABLE, $2, $3, n); }
;

type
    : INT   { $$ = I_CONST;}
    | FLOAT { $$ = F_CONST;}
    | VOID  { $$ = VOID;}
    |       {}
;

initializer
    : expression_stat
;

compound_stat
    : incdec_stat
    | assign_stat
    | for_stat
    | if_stat
    | block
;
incdec_stat
    : ID INC {
        INT_FLOAT one;
        one.type = I_CONST;
        one.data.idata = 1;
        fprintf(fp, "\tldc 1\n");
        assign_id($1, ADD, one);
    }
    | ID DEC {
        INT_FLOAT one;
        one.type = I_CONST;
        one.data.idata = 1;
        fprintf(fp, "\tldc 1\n");
        assign_id($1, SUB, one);
    }
;

assign_stat
    : ID ASSIGN expression_stat { 
        assign_expr($1, $3);
        print_store($1);
    }
    | ID ADD_ASSIGN expression_stat {
        assign_id($1, ADD, $3);
    }
    | ID SUB_ASSIGN expression_stat {
        assign_id($1, SUB, $3);
    }
    | ID MUL_ASSIGN expression_stat {
        assign_id($1, MUL, $3);
    }
    | ID DIV_ASSIGN expression_stat {
        assign_id($1, DIV, $3);
    }
    | ID MOD_ASSIGN expression_stat {
        assign_id($1, MOD, $3);
    }
    | ID ASSIGN function_call{
        assign_expr($1, $3);
        print_store($1);
    }
;
for_expr
    : assign_stat
    | incdec_stat
;
for_stat
    : for_ boolean_expr { print_jump($2, "FOR_EXIT", FOR_IDX );} block { print_jump(-1,"FOR_START", FOR_IDX); print_label("FOR_EXIT", FOR_IDX);}
    | for_ assign_stat ';' { print_for_start();}
      boolean_expr { print_jump($5, "FOR_EXIT", FOR_IDX ); print_jump(-1,"FOR_CONTENT", FOR_IDX);}
      ';' {fprintf(fp, "\tFOR_EXPR_%d_%d:\n", CUR_TABLE->depth, FOR_IDX[CUR_TABLE->depth]);} 
      for_expr { print_jump(-1,"FOR_START", FOR_IDX); fprintf(fp, "\tFOR_CONTENT_%d_%d:\n", CUR_TABLE->depth, FOR_IDX[CUR_TABLE->depth]); }
      block { print_jump(-1,"FOR_EXPR", FOR_IDX); print_label("FOR_EXIT", FOR_IDX);}
;
for_
    : FOR { print_for_start();}
;
if_stat
    : if_stat_only { print_label("ELSE", ELSE_IDX);} 
    | if_else_stat block   { print_label("EXIT", EXIT_IDX);}
    | if_else_stat if_stat { print_label("EXIT", EXIT_IDX);}
;
if_stat_only
    : IF boolean_expr { print_jump($2, "ELSE", ELSE_IDX); } block
;
if_else_stat
    : if_stat_only { print_jump(-1, "EXIT", EXIT_IDX); } ELSE { print_label("ELSE", ELSE_IDX);}
;
boolean_expr
    : LB boolean_expr RB { $$ = $2; }
    | expression_stat AND expression_stat { $$ = bool_handler($1, AND, $3); }
    | expression_stat OR expression_stat { $$ = bool_handler($1, OR, $3); }
    | expression_stat EQ expression_stat { $$ = bool_handler($1, EQ, $3); }
    | expression_stat NE expression_stat { $$ = bool_handler($1, NE, $3); }
    | expression_stat LT expression_stat { $$ = bool_handler($1, LT, $3); }
    | expression_stat LE expression_stat { $$ = bool_handler($1, LE, $3); }
    | expression_stat GT expression_stat { $$ = bool_handler($1, GT, $3); }
    | expression_stat GE expression_stat { $$ = bool_handler($1, GE, $3); }

block
    : lcb program rcb   { }
;
lcb
    : LCB   {
        if(CUR_TABLE == NULL)  create_symbol(&CUR_TABLE);
        else    new_scope();
    }
;

rcb 
    : RCB   {
        delete_scope();
    }
;

print_func
    : PRINT LB print_constent RB   {
        fprintf(fp, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n");
        switch($3.type){
            case I_CONST:
                fprintf(fp, "\tinvokevirtual java/io/PrintStream/print(I)V\n");
                break;
            case F_CONST:
                fprintf(fp, "\tinvokevirtual java/io/PrintStream/print(F)V\n");
                break;
            case STRING:
                fprintf(fp, "\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                break;
       }    
    }
    | PRINTLN LB print_constent RB {
        fprintf(fp, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n");
        switch($3.type){
            case I_CONST:
                fprintf(fp, "\tinvokevirtual java/io/PrintStream/println(I)V\n");
                break;
            case F_CONST:
                fprintf(fp, "\tinvokevirtual java/io/PrintStream/println(F)V\n");
                break;
            case STRING:
                fprintf(fp, "\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
                break;
       }    
    }
;
print_constent
    : expression_stat { $$ = $1; }
    | boolean_expr {
        if(CUR_TABLE==NULL)
            create_symbol(&CUR_TABLE);
        $$.type = STRING;
        print_jump($1, "BOOL_F", BOOL_IDX);
        fprintf(fp,"\tldc \"True\"\n");
        print_jump(-1, "BOOL_T", BOOL_IDX);
        fprintf(fp, "BOOL_F_%d_%d:\n", CUR_TABLE->depth, BOOL_IDX[CUR_TABLE->depth]);
        fprintf(fp,"\tldc \"False\"\n");
        fprintf(fp, "BOOL_T_%d_%d:\n", CUR_TABLE->depth, BOOL_IDX[CUR_TABLE->depth]);
        ++ BOOL_IDX[CUR_TABLE->depth];
        }
;
expression_stat
    : operand
    | expression_stat ADD expression_stat { $$ = alu($1,ADD,$3); }
    | expression_stat SUB expression_stat { $$ = alu($1,SUB,$3); }
    | expression_stat MUL expression_stat { $$ = alu($1,MUL,$3); }
    | expression_stat DIV expression_stat { $$ = alu($1,DIV,$3); }
    | expression_stat MOD expression_stat { $$ = alu($1,MOD,$3); }
;

operand
    : literal
    | identifier
    | LB expression_stat RB { $$ = $2;}
;

literal
    : I_CONST { $$ = val_assign(I_CONST, &$1, CONST); fprintf(fp, "\tldc %d\n", $1); }
    | F_CONST { $$ = val_assign(F_CONST, &$1, CONST); fprintf(fp, "\tldc %f\n", $1); }
    | STRING  { $$ = val_assign(STRING, $1, CONST); fprintf(fp, "\tldc \"%s\"\n", $1); }
;

identifier
    : ID { 
            $$ = get_id($1);
            print_load($1);
    }
;

%%

/* C code section */

int main(int argc, char** argv)
{
    fp = fopen("Computer.j","w");
    fprintf(fp, ".class public main\n.super java/lang/Object\n.method public static main([Ljava/lang/String;)V\n.limit stack 100\n.limit locals 100\n");
    fprintf(fp, "\tgoto FUNC_main\n");
    fprintf(fp, "FUNC_main:\n");
    yylineno = 0;
    yyparse();
    printf("\n Total lines: %d\n\n", yylineno);
    fprintf(fp, "\treturn\n.end method\n");
    fclose(fp);
    if(ERROR)
        remove("Computer.j");
    return 0;
}
int yyerror(char* msg){
    fclose(fp);
    remove("Computer.j");
    fprintf(stderr, " Error: %s at line %d\n", msg, yylineno);
}
void create_symbol(struct Table** table) {
    *table = (struct Table*)malloc(sizeof(struct Table));
    assert(*table != NULL);
    memset(*table, 0, sizeof(struct Table));
    printf(" Create symbol table\n");
}
void insert_symbol(struct Table** table, char* id, int type, INT_FLOAT n){
    if(*table == NULL)  create_symbol(table);
    assert(*table != NULL);
    if(is_redef(CUR_TABLE, id)){
        printf(" <ERROR> Re-declaration for variable %s (line %d)\n", id, yylineno);
        ERROR = 1;
        return;
    }
    printf(" Insert symbol: %s\tdeclare in block of depth %d\n", id, (*table)->depth);
    int idx = ++((*table)->index);
    strcpy((*table)->Var[idx].id, id);
    (*table)->Var[idx].Val = n;
    (*table)->Var[idx].Val.type = type;
    (*table)->Var[idx].index = (*table)->Var[idx].Val.index = var_idx++;
    def_type_trans((*table)->Var[idx].Val, n);
    type == I_CONST ? fprintf(fp, "\tistore %d\n", (*table)->Var[idx].index) : fprintf(fp, "\tfstore %d\n", (*table)->Var[idx].index);
}
Variable* lookup_symbol(struct Table* table, char* id) {
    if(table == NULL)   return NULL;
    assert(table != NULL);
    for(int i=1 ;i<=table->index; ++i){
        if(!strcmp(id, table->Var[i].id)){
            depth = table->depth;
            return &(table->Var[i]);
        }
    }
    if(table->prev != NULL)
        return lookup_symbol(table->prev, id);
    return NULL;
}
INT_FLOAT val_assign(int type, void* value, int index){
    INT_FLOAT Val;
    Val.type = type;
    Val.index = index;
    switch(type){                                           
        case I_CONST:
            Val.data.idata = *(int*) value;
            break;
        case F_CONST:
            Val.data.fdata = *(double*) value; 
            break;
        case STRING: 
            strcpy(Val.data.sdata, (char*) value);     
            break;
    }
    return Val;
}
INT_FLOAT alu(INT_FLOAT left, int op, INT_FLOAT right){
    INT_FLOAT ret;
    alu_type_trans(left, right);
    switch(op){    
        case ADD:
            fprintf(fp, "add\n");
            operation(left, +, right);
            break;
        case SUB:
            fprintf(fp, "sub\n");
            operation(left, -, right);
            break;
        case MUL:
            fprintf(fp, "mul\n");
            operation(left, *, right);
            break;
        case DIV:
            //if(((right.type == I_CONST) && (right.data.idata == 0)) || ((right.type == F_CONST) && (right.data.fdata == 0))){
            if((right.index == -1)&&(((right.type == I_CONST) && (right.data.idata == 0)) || ((right.type == F_CONST) && (right.data.fdata == 0)))){
                printf(" <ERROR> The divisor can’t be 0 (line %d)\n", yylineno+1);
                ERROR = 1;
                ret.type = -1;
            }
            else {
                fprintf(fp, "div\n");
                operation(left, /, right);
            }
            break;
        case MOD:
            if((left.type == I_CONST) && (right.type == I_CONST)){
                fprintf(fp, "rem\n");
                ret.type = I_CONST;
                ret.data.idata = left.data.idata % right.data.idata;
            }
            else{
                printf(" <ERROR> MOD type error! (Line %d)\n", yylineno+1);
                ERROR = 1;
                ret.type = -1;
            }
            break;
    }
    return ret;
}
void assign_expr(char* id, INT_FLOAT Val){
     Variable* v = lookup_symbol(CUR_TABLE, id);
     if(v == NULL){
        printf(" <ERROR> Undefine variable %s (Line %d)\n", id, yylineno);
        ERROR = 1;
    }
     else{
        def_type_trans(v->Val, Val);                                    // TODO f2i
        v->Val = val_assign(v->Val.type, &Val.data, v->Val.index);
    }
}
INT_FLOAT get_id(char* id){
    Variable* v = lookup_symbol(CUR_TABLE, id);
    if(v == NULL){
        printf(" <ERROR> Undefine ID: %s (Line %d)\n", id, yylineno);
        ERROR = 1;
        INT_FLOAT n = {0};
        return n;
    }
    else
        return v->Val;
}
void assign_id(char* id, int op, INT_FLOAT expr){
    INT_FLOAT left = get_id(id);
    op_assign(left, expr);
    INT_FLOAT Val = alu(left, op, expr);
    assign_expr(id, Val);
    print_var(id);
}
bool is_redef(struct Table* table, char* id){
    for(int i=1; i<=table->index; ++i){
        if(!strcmp(id, table->Var[i].id))
            return true;
    }
    return false;
}
void new_scope(){
    if(CUR_TABLE == NULL)   create_symbol(&CUR_TABLE);
    assert(CUR_TABLE != NULL);
    struct Table* next;
    create_symbol(&next);
    CUR_TABLE->next = next;
    next->prev = CUR_TABLE;
    next->depth = CUR_TABLE->depth + 1;
    CUR_TABLE = next;
}
void delete_scope(){
    assert(CUR_TABLE != NULL);
    CUR_TABLE = CUR_TABLE->prev;
    free(CUR_TABLE->next);
    printf("\n Delete this scope symbol table\n");
}
void print_var(char* id){
    Variable* v = lookup_symbol(CUR_TABLE, id);
    assert(v != NULL);
    v->Val.type == I_CONST ? fprintf(fp, "\tistore %d\n", v->index) : fprintf(fp, "\tfstore %d\n", v->index);
}
void print_load(char* id){
    Variable* v = lookup_symbol(CUR_TABLE, id);
    if(v == NULL)   return;
    assert(v != NULL);
    print_type(v->Val.type);
    fprintf(fp, "load %d\n", v->index);
}
void print_store(char* id){
    Variable* v = lookup_symbol(CUR_TABLE, id);
    if(v == NULL)   return;
    assert(v != NULL);
    print_type(v->Val.type);
    fprintf(fp, "store %d\n", v->index);
}
void alu_type_trans(INT_FLOAT left, INT_FLOAT right){
    if((left.type == F_CONST)&&(right.type == I_CONST))
        fprintf(fp, "\ti2f\n\tf");
    else if((left.type == I_CONST)&&(right.type == F_CONST))
        fprintf(fp, "\tfstore %d\n\ti2f\n\tfload %d\n\tf", var_idx, var_idx);
    else if((left.type == I_CONST)&&(right.type == I_CONST))
        fprintf(fp, "\ti");
    else
        fprintf(fp, "\tf");
}
void op_assign(INT_FLOAT left, INT_FLOAT right){
    print_type(right.type); 
    fprintf(fp, "store %d\n", var_idx);
    print_type(left.type); 
    fprintf(fp, "load %d\n", left.index);
    print_type(right.type); 
    fprintf(fp, "load %d\n", var_idx);
}
int bool_handler(INT_FLOAT left, int op, INT_FLOAT right){
    INT_FLOAT ret;
    if((left.type == F_CONST) || (right.type == F_CONST)){
        alu_type_trans(left, right);
        fprintf(fp, "cmpl\n");
    }
    else{
        alu_type_trans(left, right);
        fprintf(fp, "sub\n");
    }
    return op;
}
void print_for_start(){
    fprintf(fp, "FOR_START_%d_%d:\n", CUR_TABLE->depth, FOR_IDX[CUR_TABLE->depth]);
}
void print_label(char* label_name, int IDX[] ){
    fprintf(fp, "%s_%d_%d:\n", label_name, CUR_TABLE->depth, IDX[CUR_TABLE->depth]);
    ++ IDX[CUR_TABLE->depth];
}
void print_jump(int op, char* label_name, int IDX[]){
    switch(op){
        case AND:
            printf(" AND\n");
            break;
        case OR:
            printf(" OR\n");
            break;
        case EQ:
            fprintf(fp, "\tifne %s_%d_%d\n", label_name, CUR_TABLE->depth, IDX[CUR_TABLE->depth]);
            break;
        case NE:
            fprintf(fp, "\tifqe %s_%d_%d\n", label_name, CUR_TABLE->depth, IDX[CUR_TABLE->depth]);
            break;
        case LT:
            fprintf(fp, "\tifge %s_%d_%d\n", label_name, CUR_TABLE->depth, IDX[CUR_TABLE->depth]);
            break;
        case LE:
            fprintf(fp, "\tifgt %s_%d_%d\n", label_name, CUR_TABLE->depth, IDX[CUR_TABLE->depth]);
            break;
        case GT:
            fprintf(fp, "\tifle %s_%d_%d\n", label_name, CUR_TABLE->depth, IDX[CUR_TABLE->depth]);
            break;
        case GE:
            fprintf(fp, "\tiflt %s_%d_%d\n", label_name, CUR_TABLE->depth, IDX[CUR_TABLE->depth]);
            break;
        default:
            fprintf(fp, "\tgoto %s_%d_%d\n", label_name, CUR_TABLE->depth, IDX[CUR_TABLE->depth]);
            break;
    }
}
void func_insert_symbol(struct Table** table, char* id, int type){
    if(*table == NULL)  create_symbol(table);
    assert(*table != NULL);
    if(is_redef(CUR_TABLE, id)){
        printf(" <ERROR> Re-declaration for variable %s (line %d)\n", id, yylineno);
        ERROR = 1;
        return;
    }
    printf(" Insert symbol: %s\tdeclare in block of depth %d\n", id, (*table)->depth);
    int idx = ++((*table)->index);
    strcpy((*table)->Var[idx].id, id);
    (*table)->Var[idx].Val.type = type;
    (*table)->Var[idx].index = (*table)->Var[idx].Val.index = var_idx++;
}
void func_store(struct Table** table){
    for(int i = var_idx-1 ; i > func_num*STACK_SIZE ; --i ){
        INT_FLOAT T = get_id((*table)->Var[i-func_num*STACK_SIZE].id);
        T.type == I_CONST ? fprintf(fp, "\tistore %d\n", i) : fprintf(fp, "\tfstore %d\n", i);
    }    
}
int get_func_type(const char* name){
    for(int i = 0; i<func_num ; ++i){
        if( !strcmp((char*)func_info[i].name, name))
            return func_info[i].type;
    }
}

