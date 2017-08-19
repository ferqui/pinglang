#include <iostream>
#include <stack>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

#include "nodo.hpp"
#include "lexico.h"

YYSTYPE yylval;
int ta;

int yylex(void);
extern char* yytext;

int error(string msg);
void cuadra(int t);

Nodo* entrada(void);
Nodo* op(void);
Nodo* noot(void);
Nodo* neet(void);

Nodo* entrada(void)
{
    Nodo* codigo;
    Nodo* sig;
    if (ta == NIT) {
        cuadra(NIT);
        cuadra(NIT);
        codigo = entrada();
        cuadra(NUTE);
        cuadra(NIT);
        sig = entrada();
        return new NodoBucle(codigo, sig);
    }else if ((ta == NOOT)||(ta==NEET)) {
        codigo = op();
        sig = entrada();
        return new NodoEntrada(codigo, sig);
    }else{
        return nullptr;
    }
}

Nodo* op(void)
{
    if (ta == NOOT){
        cuadra(NOOT);
        return noot();
    }else if(ta == NEET){
        cuadra(NEET);
        return neet();
    }else{
        error("En op");
    }
    return nullptr;
}

Nodo* noot(void)
{
    if (ta == NEET) {
        cuadra(NEET);
        return new NodoIncrementaPuntero();
    }else if (ta == NUTE) {
        cuadra(NUTE);
        return new NodoDecrementaPuntero();
    }else if (ta == NIT) {
        cuadra(NIT);
        return new NodoIncrementaByte();
    }else{
        error("En noot");
    }
    return nullptr;
}

Nodo* neet(void)
{
    if (ta == NEET) {
        cuadra(NEET);
        return new NodoDecrementaByte();
    }else if (ta == NUTE) {
        cuadra(NUTE);
        return new NodoPrint();
    }else if (ta == NIT) {
        cuadra(NIT);
        return new NodoScanf();
    }else{
        error("En neet");
    }
    return nullptr;
}

// ************************************************************

int main(int argc, char **argv)
{
    if (argc != 2){
        return -1;
    }
    //
    std::istringstream input(argv[1]);
    std::vector<std::string> v;

    // note: the following loop terminates when std::ios_base::operator bool()
    // on the stream returned from getline() returns false
    for (std::string a; std::getline(input, a, '.'); ) {
        v.push_back(a);
    }

    int n = v.size();
    string extension;
    string name;
    if (n >= 2){
        extension = v[n-1];
        if (extension != "ping") return -1;
        name = v[0];
    }else{
        return -1;
    }
    //
    yyin = fopen(argv[1], "r");
    cout << "PingLang" << endl;
    ta = yylex();
    Nodo* ast = entrada();
    ast->ejecutar();
    std::ofstream fs (name + ".cpp");
    fs << Nodo::print() << endl;
    fs.close();
    system(string("g++ -std=c++11 -o " + name + " " + name + ".cpp").c_str());
    std::remove(string(name + ".cpp").c_str());
}

int error(string msg) {
    cerr << msg << endl;
    cerr << "token actual = " << ta << " (" << yytext << ")\n";
    exit(EXIT_FAILURE);
}

void cuadra(int t) {
    if (ta == t) {
        ta = yylex();
    }
    else {
        cerr << "Error al cuadrar: esperaba ta = " << ta << " pero hay t = " << t << " (" << yytext << ")\n";
        error("en cuadra");
    }
}
