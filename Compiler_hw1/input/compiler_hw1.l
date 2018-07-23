/* Definition section */
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>	

	/* Symbol table function */
	void create_symbol();
	void insert_symbol();
	int lookup_symbol();
	void dump_symbol();

        /* handle function */
        void print_label(char*);
        void id_handler();
        void type_handler();
        void new_line_handler();
        void comment_input();
        void var_def_check();
        void init_def_check();

        /* Structure */
        struct Table{
            char id[100];
            char type[100];	
	};
    
	/* Variable */
	int num_lines = 0, num_comment = 0, id_index=0;
	bool comment_end = 0;
        struct Table table[1000]; 
	
%}
%x COMMENT
%x VARIABLE
/* Define regular expression label */

letter [a-zA-Z]
digit [0-9]
id {letter}+({letter}|{digit})*
number {digit}+
type (int|float32)

/* Rules section */
%%

"for"		    { printf("%s \t FOR function \n", yytext); }
"if"		    { printf("%s \t IF  \n", yytext); }
"else"		    { printf("%s \t ELSE \n", yytext); }
"print" 	    { printf("%s \t PRINT function \n", yytext); }
["].*["]            { printf("%s\n", yytext);}
"println"           { printf("%s \t PRINTLN function \n", yytext); }
"var"               { BEGIN VARIABLE; }
<VARIABLE>{type}    { type_handler(); BEGIN INITIAL; }
<VARIABLE>{id}      { var_def_check(); }
<VARIABLE>" "       {;}
{id}	    	    { init_def_check(); }
{number}	    { printf("%s \t Number \n", yytext); }

 /* Comment */
"//".*		{ 
                	++num_comment;
                	printf("%s \t C++ Comment\n", yytext);
                }
"/*"            { comment_input(); BEGIN COMMENT; }
<COMMENT>.      { comment_input(); }
<COMMENT>\n     { comment_input(); ++num_comment; ++num_lines; }
<COMMENT>"*/"   { 
                    comment_input();
                    printf("\t C Comment\n");
                    comment_end = 1;
                    BEGIN INITIAL;
                }

 /* Delimiters */
"("		{ printf("%s \t LB \n", yytext); }
")"		{ printf("%s \t RB \n", yytext); }
"{"		{ printf("%s \t LCB \n", yytext); }
"}"		{ printf("%s \t RCB \n", yytext); }
["]		{ printf("%s \t  \n", yytext); }
\n		{ new_line_handler();}
[ \t]           {;}

 /* Arithmetic */
"+" 		{ print_label("Add"); }
"-"		{ print_label("Sub"); }
"*"		{ print_label("Mul"); }
"/"		{ print_label("Div"); }
"%"		{ print_label("Mod"); }
"++" 		{ print_label("Increment"); }
"--" 		{ print_label("Decrement"); }

 /* Relational */
"<"		{ print_label("Less than"); }
">"		{ print_label("Greater than"); }
"<="		{ print_label("Less or equal than"); }
">="		{ print_label("Greater or equal than"); }
"=="		{ print_label("Equal"); }
"!="		{ print_label("Not equal"); }

 /* Assignment */
"="		{ printf("%s \t Assign\n", yytext); }
"+="		{ printf("%s \t Add Assign\n", yytext); }
"-="		{ printf("%s \t Sub Assign\n", yytext); }
"*="		{ printf("%s \t Mul Assign\n", yytext); }
"/="		{ printf("%s \t Div Assign\n", yytext); }
"%="		{ printf("%s \t Mod Assign\n", yytext); }

 /* Logical */
"&&"		{ printf("%s \t And \n", yytext); }
"||"		{ printf("%s \t Or \n", yytext); }
"!"		{ printf("%s \t Not \n", yytext); }

%%

/* C Code section */
int yywrap(void)
{
    printf("\nParse over, the line number is %d.\n\n",num_lines);
    printf("comment: %d lines\n\n", num_comment);
    dump_symbol();
    return 1;
}

void create_symbol() {
    printf("Create a symbol table\n");
}
void insert_symbol() {
    printf("Insert a symbol: %s \n", table[id_index].id);
    ++id_index;
}
int lookup_symbol() {
    for(int i =0; i<id_index; ++i){
        if(!strcmp(table[i].id, yytext))
            return true;
    }
    return false;
}
void dump_symbol() {
    printf("The symbol table dump:\n");
    for(int i=0; i<id_index; ++i){
        printf("%d\t%s\t%s\n", i, table[i].id, table[i].type);
    }
}
void print_label(char* label){
    printf("%s \t %s \n", yytext, label);
}

void id_handler(){
    strcpy(table[id_index].id, yytext);
}

void type_handler(){
    strcpy(table[id_index].type, yytext);
    printf("%s \t %s TYPE VAR\n", table[id_index].id, table[id_index].type);
    if(!id_index){
        create_symbol();
    }
    insert_symbol();
}

void new_line_handler(){
    if(comment_end){ 
        ++num_comment;
        comment_end = 0;     
    }
    ++num_lines;
}

void comment_input(){
    printf("%s", yytext);
}

void var_def_check(){
    if(lookup_symbol()){
        printf("Redefined variables: %s\n", yytext); 
        yywrap();
        exit(1);
    }   
    else
        id_handler();
}
void init_def_check(){
    if(!lookup_symbol()){
        fprintf( stderr, "Undeclared variables: %s\n", yytext);
        yywrap();
        exit(1);
    }
    else
        fprintf( stderr, "%s \t ID \n", yytext); 
}
int main(int argc,char *argv[])
{
    yyin = fopen(argv[1],"r");
    yylex();

    return 0;
}
