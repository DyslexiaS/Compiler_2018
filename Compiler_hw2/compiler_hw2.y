/*	Definition section */
%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
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
#define print_rel($$)  printf("%s\n",get_data($$) ? " true" : " false");
/* Strcuct */
typedef union _DATA{
    int     idata;
    double  fdata;
    char    sdata[101];
}DATA;

typedef struct _INT_FLOAT{
    int     type;
    DATA    data;
}INT_FLOAT;

typedef struct _Variable{
    char    id[100];
    INT_FLOAT  Val;
}Variable;

struct Table{
    int index;
    int depth;
    Variable Var[1001];
    struct Table* prev;
    struct Table* next;
};

/* Symbol table function - you can add new function if need. */
Variable* lookup_symbol(struct Table*, char* id);
void create_symbol(struct Table** table);
void insert_symbol(struct Table** table, char* id, int type, INT_FLOAT Var);
void dump_symbol(struct Table* table);

INT_FLOAT val_assign(int type, void* value);
INT_FLOAT alu(INT_FLOAT left, int op, INT_FLOAT right);
INT_FLOAT get_id(char* id);
void assign_expr(char* id, INT_FLOAT value);
void assign_id(char* id, int op, INT_FLOAT expr);
bool is_redef(struct Table* table, char* id);
void new_scope();
void delete_scope();
struct Table* CUR_TABLE;
int depth;
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
    | NEWLINE           {}
;

declaration
    : VAR ID type ASSIGN initializer { insert_symbol(&CUR_TABLE, $2, $3, $5);   }
    | VAR ID type {  INT_FLOAT n;   insert_symbol(&CUR_TABLE, $2, $3, n);    }
;

type
    : INT   { $$ = I_CONST;}
    | FLOAT { $$ = F_CONST;}
    | VOID  { $$ = VOID;}
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
        assign_id($1, ADD, one);
    }
    | ID DEC {
        INT_FLOAT one;
        one.type = I_CONST;
        one.data.idata = 1;
        assign_id($1, SUB, one);
    }
;

assign_stat
    : ID ASSIGN expression_stat { 
        printf(" ASSIGN\n");
        assign_expr($1, $3);
    }
    | ID ADD_ASSIGN expression_stat {
        printf(" ADD_ASSIGN\n");
        assign_id($1, ADD, $3);
    }
    | ID SUB_ASSIGN expression_stat {
        printf(" SUB_ASSIGN\n");
        assign_id($1, SUB, $3);
    }
    | ID MUL_ASSIGN expression_stat {
        printf(" MUL_ASSIGN\n");
        assign_id($1, MUL, $3);
    }
    | ID DIV_ASSIGN expression_stat {
        printf(" DIV_ASSIGN\n");
        assign_id($1, DIV, $3);
    }
    | ID MOD_ASSIGN expression_stat {
        printf(" MOD_ASSIGN\n");
        assign_id($1, MOD, $3);
    }
;
for_stat
    : FOR expression_stat block     {}
;
if_stat
    : IF expression_stat block              {} 
    | IF expression_stat block ELSE block   {}
    | IF expression_stat block ELSE if_stat {}
;

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
    : PRINT LB expression_stat RB   {
        switch($3.type){
            case I_CONST:
                printf(" Print : %d\t\tbelongs to block of depth %d\n", $3.data.idata, depth);
                break;
            case F_CONST:
                printf(" Print : %lf\tbelongs to block of depth %d\n", $3.data.fdata, depth);
                break;
            case STRING:
                printf(" Print : %s\t\tbelongs to block of depth %d\n", $3.data.sdata, depth);
                break;
       }    
    }
    | PRINTLN LB expression_stat RB {
       switch($3.type){
            case I_CONST:
                printf(" Println : %d\t\tbelongs to block of depth %d\n\n", $3.data.idata, depth);                break;
            case F_CONST:
                printf(" Println : %lf\tbelongs to block of depth %d\n\n", $3.data.fdata, depth);
                break;
            case STRING:
                printf(" Println : %s\t\tbelongs to block of depth %d\n\n", $3.data.sdata, depth);
                break;
       }    
    }
;
expression_stat
    : operand
    | expression_stat AND expression_stat { $$ = alu($1,AND,$3); print_rel($$); }
    | expression_stat OR expression_stat { $$ = alu($1,OR,$3); print_rel($$); }
    | expression_stat EQ expression_stat { $$ = alu($1,EQ,$3); print_rel($$); }
    | expression_stat NE expression_stat { $$ = alu($1,NE,$3); print_rel($$); }
    | expression_stat LT expression_stat { $$ = alu($1,LT,$3); print_rel($$); }
    | expression_stat LE expression_stat { $$ = alu($1,LE,$3); print_rel($$); }
    | expression_stat GT expression_stat { $$ = alu($1,GT,$3); print_rel($$); }
    | expression_stat GE expression_stat { $$ = alu($1,GE,$3); print_rel($$); }
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
    : I_CONST { $$ = val_assign(I_CONST, &$1);}
    | F_CONST { $$ = val_assign(F_CONST, &$1);}
    | STRING  { $$ = val_assign(STRING, $1);}
;

identifier
    : ID { $$ = get_id($1); } 
;

%%

/* C code section */

int main(int argc, char** argv)
{
    yylineno = 0;

    yyparse();
    printf("\n Total lines: %d\n\n", yylineno);
    dump_symbol(CUR_TABLE);
    return 0;
}
int yyerror(char* msg){
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
        return;
    }
    printf(" Insert symbol: %s\tdeclare in block of depth %d\n", id, (*table)->depth);
    int idx = ++((*table)->index);
    strcpy((*table)->Var[idx].id, id);
    (*table)->Var[idx].Val = n;
    (*table)->Var[idx].Val.type = type;
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
void dump_symbol(struct Table* table) {
    assert(table != NULL);
    printf(" The symbol table:\n\n");
    printf(" --------------------------------\n");
    printf(" | ID\t| Type\t| Data\t\t|\n");
    for(int i=1; i<=table->index; ++i){
        printf(" --------------------------------\n");
        switch(table->Var[i].Val.type){
            case I_CONST:   printf(" | %s\t| %s\t| %d\t\t|\n", table->Var[i].id, "int", table->Var[i].Val.data.idata);  break; 
            case F_CONST:   printf(" | %s\t| %s\t| %lf\t|\n", table->Var[i].id, "float", table->Var[i].Val.data.fdata); break;
            case STRING:    printf(" | %s\t| %s\t| %s\t|\n", table->Var[i].id, "string", table->Var[i].Val.data.sdata); break;
        }
    }
    printf(" --------------------------------\n");
}
INT_FLOAT val_assign(int type, void* value){
    INT_FLOAT Val;
    Val.type = type;                                        
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
    switch(op){    
        case AND:
            printf(" AND\n");
            operation(left, &&, right);
            break;
        case OR:
            printf(" OR\n");
            operation(left, ||, right);
            break;
        case EQ:
            printf(" EQ\n");
            operation(left, ==, right);
            break;
        case NE:
            printf(" NE\n");
            operation(left, !=, right);
            break;
        case LT:
            printf(" LT\n");
            operation(left, <, right);
            break;
        case LE:
            printf(" LE\n");
            operation(left, <=, right);
            break;
        case GT:
            printf(" GT\n");
            operation(left, >, right);
            break;
        case GE:
            printf(" GE\n");
            operation(left, >=, right);
            break;
        case ADD:
            printf(" ADD\n");
            operation(left, +, right);
            break;
        case SUB:
            printf(" SUB\n");
            operation(left, -, right);
            break;
        case MUL:
            printf(" MUL\n");
            operation(left, *, right);
            break;
        case DIV:
            if(((right.type == I_CONST) && (right.data.idata == 0)) || ((right.type == F_CONST) && (right.data.fdata == 0))){
                printf(" <ERROR> The divisor can’t be 0 (line %d)\n", yylineno+1);
                ret.type = -1;
            }
            else {
                printf(" DIV\n");
                operation(left, /, right);
            }
            break;
        case MOD:
            if((left.type == I_CONST) && (right.type == I_CONST)){
                printf(" MOD\n");
                ret.type = I_CONST;
                ret.data.idata = left.data.idata % right.data.idata;
            }
            else{
                printf(" <ERROR> MOD type error! (Line %d)\n", yylineno+1);
                ret.type = -1;
            }
            break;
    }
   /* printf("type = %d int %d, float %lf \n",ret.type,ret.data.idata,ret.data.fdata);*/
    return ret;
}
void assign_expr(char* id, INT_FLOAT Val){
     Variable* v = lookup_symbol(CUR_TABLE, id);
     if(v == NULL)
        printf(" <ERROR> Undefine variable %s (Line %d)\n", id, yylineno);
     else
        v->Val = val_assign(v->Val.type, &Val.data);
}
INT_FLOAT get_id(char* id){
    Variable* v = lookup_symbol(CUR_TABLE, id);
    if(v == NULL){
        printf(" <ERROR> Undefine ID: %s (Line %d)\n", id, yylineno);
        INT_FLOAT n = {0};
        return n;
    }
    else
        return v->Val;
}
void assign_id(char* id, int op, INT_FLOAT expr){
    INT_FLOAT left = get_id(id);
    INT_FLOAT Val = alu(left, op, expr);
    assign_expr(id, Val);
}
bool is_redef(struct Table* table, char* id){
    for(int i=1; i<=table->index; ++i){
        if(!strcmp(id, table->Var[i].id))
            return true;
    }
    return false;
}
void new_scope(){
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
