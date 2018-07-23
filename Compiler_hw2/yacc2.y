/*	Definition section */
%{
extern int yylineno;
extern int yylex();

/* Symbol table function - you can add new function if need. */
int lookup_symbol();
void create_symbol();
void insert_symbol();
void dump_symbol();

/* Strcuct */
struct node{
    char id[100];
    char type[10];
    struct node* next;
};

/* Variable */

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
%token VAR ID NEWLINE
%token INT FLOAT VOID   

/* Token with return */
%token ADD SUB MUL DIV MOD INC DEC
%token GT LT GE LE EQ NE
%token ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token AND OR NOT
%token LB RB LCB RCB

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <string> STRING

/* Nonterminal with return, which need to sepcify type */
%type <f_val> stat
%type <if_val> declaration 
%type <if_val> compound_stat
%type <if_val> expression_stat
%type <if_val> print_func

/* Yacc will start at this nonterminal */
%start program

/* Precedence */
%left OR
%left AND
%left EQ GT LT GE LE
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
    : declaration
    | compound_stat
    | expression_stat
    | print_func
;

declaration
    : VAR ID type '=' initializer NEWLINE
    | VAR ID type NEWLINE
;

type
    : INT { $$ = $1; }
    | FLOAT { $$ = $1; }
    | VOID { $$ = $1; }
;

initializer
    : expression_stat
;

/* compound_stat */
compound_stat
    : incdec_stat
    | assign_stat
    | for_stat
    | if_stat
    | print_func
    | block
;
incdec_stat
    : expression_stat INC { $$ = $1 + 1; }
    | expression_stat DEC { $$ = $1 - 1; }
;
assign_stat
    : expression_stat ASSIGN expression_stat { $1 = $3; }
    | expression_stat ADD_ASSIGN expression_stat { $1 += $3 ; }
    | expression_stat SUB_ASSIGN expression_stat { $1 -= $3 ; }
    | expression_stat MUL_ASSIGN expression_stat { $1 *= $3 ; }
    | expression_stat DIV_ASSIGN expression_stat { $1 /= $3 ; }
    | expression_stat MOD_ASSIGN expression_stat { $1 %= $3 ; }
;

for_stat
    : FOR expression_stat block
;
if_stat
    : IF expression_stat block 
    | IF expression_stat ELSE block
    | IF expression_stat ELSE if_stat
;
print_func
    : PRINT LB operand RB                       /* look tb*/
    | PRINTLN LB operand RB
;
block
    : LCB program RCB
;
/* expression_stat */
expression_stat
    : operand
    | expression_stat AND expression_stat { $$ = $1 && $3; }
    | expression_stat OR expression_stat { $$ = $1 || $3; }
    | expression_stat EQ expression_stat { $$ = $1 == $3; }
    | expression_stat NE expression_stat { $$ = $1 != $3; }
    | expression_stat LT expression_stat { $$ = $1 < $3; }
    | expression_stat LE expression_stat { $$ = $1 <= $3; }
    | expression_stat GT expression_stat { $$ = $1 > $3; }
    | expression_stat GE expression_stat { $$ = $1 >= $3; }
    | expression_stat ADD expression_stat { $$ = $1 + $3; }
    | expression_stat SUB expression_stat { $$ = $1 - $3; }
    | expression_stat MUL expression_stat { $$ = $1 * $3; }
    | expression_stat DIV expression_stat { $$ = $1 / $3; }
    | expression_stat MOD expression_stat { $$ = $1 % $3; }
;

/* operand */
operand
    : literal
    | identifier
    | LB expression_stat RB
;

literal
    : I_CONST
    | F_CONST
    | STRING
;

identifier
    : ID
;

%%

/* C code section */

typedef union _int_float{
    int idata;
    float   fdata;
}INT_FLOAT;
int main(int argc, char** argv)
{
    yylineno = 0;

    yyparse();

    return 0;
}

void create_symbol() {}
void insert_symbol() {}
int lookup_symbol() {}
void dump_symbol() {}
