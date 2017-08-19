%{
#include <iostream>

using namespace std;

#include "nodo.hpp"
#include "lexico.h"

int line=0;
%}

%option noyywrap

%%

[ \t\r]+  ;

"NOOT"      {return NOOT;}
"NEET"      {return NEET;}
"NUTE"      {return NUTE;}
"NIT"       {return NIT;}
[\n]        {line++;}
.           {cout << "Error lexico, carácter (" << yytext << ") desconocido\n";}

%%
