%{
#include <iostream>

using namespace std;

#include "gramatica.tab.h"
int line=0;
int yyerror(const char* msj);
%}

%option noyywrap

TOK_NOOT "NOOT"
TOK_NEET "NEET"
TOK_NUTE "NUTE"
TOK_NIT  "NIT"

%%

{TOK_NOOT}      {return NOOT;}
{TOK_NEET}      {return NEET;}
{TOK_NUTE}      {return NUTE;}
{TOK_NIT}       {return NIT;}
[\n]            {line++;}
[ \t\r]         {}
.               {cout << yytext << endl;yyerror("Error léxico");}

%%
