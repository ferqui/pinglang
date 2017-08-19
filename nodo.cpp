#include "nodo.hpp"
#include <sstream>
#include <iomanip>

string code=
"#include<iostream>\n"
"#include<list>\n"
"using namespace std;\n"
"list<unsigned char> cinta = {0};\n"
"list<unsigned char>::iterator puntero = cinta.begin();\n"
"\n"
"int main() {\n";

std::ostringstream Nodo::ss(code, std::ios_base::ate);

static int inicio{0};
static int fin{0};
static int actual{0};

static int level{0};

string Nodo::print()
{
    return ss.str() + "return 0;\n}";
}

void NodoEntrada::ejecutar()
{
    codigo->ejecutar();
    if (sig != nullptr) sig->ejecutar();
}

void NodoIncrementaPuntero::ejecutar()
{
    if (actual == fin) {
        ss << std::setw(level*4) << "cinta.push_back(0);\n";
        ++fin;
    }
    ++actual;
    ss << std::setw(level*4) << "++puntero;\n";
}

NodoIncrementaPuntero::NodoIncrementaPuntero() {
    //cout << "Incrementa puntero" << endl;
}

void NodoDecrementaPuntero::ejecutar()
{
    if (actual == inicio) {
        ss << std::setw(level*4) << "cinta.push_front(0);\n";
        --inicio;
    }
    --actual;
    ss << std::setw(level*4) << "--puntero;\n";
}

NodoDecrementaPuntero::NodoDecrementaPuntero() {
    //cout << "Decrementa puntero" << endl;
}

void NodoIncrementaByte::ejecutar()
{
    ss << std::setw(level*4) << "*puntero = *puntero + 1;\n";
}

NodoIncrementaByte::NodoIncrementaByte() {
    //cout << "Incrementa byte" << endl;
}

void NodoDecrementaByte::ejecutar()
{
    ss << std::setw(level*4) << "*puntero = *puntero - 1;\n";
}

NodoDecrementaByte::NodoDecrementaByte(){
    //cout << "Decrementa byte" << endl;
}

void NodoPrint::ejecutar()
{
    ss << std::setw(level*4) << "std::cout << *puntero;\n";
}

NodoPrint::NodoPrint() {
    //cout << "Imprime" << endl;
}

void NodoScanf::ejecutar()
{
    ss << std::setw(level*4) << "std::cin >> *puntero;\n";
}

NodoScanf::NodoScanf() {
    //cout << "Lee" << endl;
}

void NodoBucle::ejecutar()
{
    ss << std::setw(level*4) << "while(*puntero != 0) {\n";
    ++level;
    if (codigo != nullptr) codigo->ejecutar();
    --level;
    ss << std::setw(level*4) << "}";
    if (sig != nullptr) sig->ejecutar();
}

NodoBucle::NodoBucle(Nodo* codigo, Nodo* sig): codigo{codigo}, sig{sig} {
    //cout << "NodoBucle" << endl;
}
