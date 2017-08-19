#pragma once

enum yytokentype {
    NOOT = 300,
    NEET,
    NUTE,
    NIT
};


typedef union YYSTYPE {
    string *nombre;
} YYSTYPE;

extern YYSTYPE yylval;
extern FILE* yyin;
