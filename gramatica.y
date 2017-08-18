%{
#include <iostream>

using namespace std;

extern int line;
int yyerror(const char* msj);
int yylex(void);
%}

%error-verbose

%token NOOT NEET NUTE NIT

%start entrada1

%%

entrada1 :    entrada2

entrada2 :    instr entrada2
         |
         ;

instr   :   NOOT noot
        |   NEET neet
        |   NUTE nute
        |   NIT nit
        ;

noot    :   NOOT
        |   NEET
        ;

neet    :   NEET
        |   NUTE
        ;

nute    :   NUTE
        |   NIT
        ;

nit     :   NIT
        |   NOOT
        ;

%%

int main()
{
    yyparse();
    //ast-escribe();
    //delete ast;

    return EXIT_SUCCESS;
}

int yyerror(const char* msj) {
  cerr << msj << "-" << line << endl;
  return 1;
}
