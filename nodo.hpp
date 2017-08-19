#pragma once
#include <iostream>

using namespace std;

class Nodo
{
public:
    virtual void ejecutar(){}
    static string print();
    virtual ~Nodo(){}
protected:
    static std::ostringstream ss;
};

class NodoEntrada: public Nodo
{
public:
    NodoEntrada(Nodo* codigo, Nodo* sig): codigo{codigo}, sig{sig} {}
    void ejecutar();
    ~NodoEntrada(){delete codigo; delete sig;}
private:
    Nodo* codigo;
    Nodo* sig;
};

class NodoIncrementaPuntero: public Nodo
{
public:
    NodoIncrementaPuntero();
    void ejecutar();
    ~NodoIncrementaPuntero(){}
};

class NodoDecrementaPuntero: public Nodo
{
public:
    NodoDecrementaPuntero();
    void ejecutar();
    ~NodoDecrementaPuntero(){}
};

class NodoIncrementaByte: public Nodo
{
public:
    NodoIncrementaByte();
    void ejecutar();
    ~NodoIncrementaByte(){}
};

class NodoDecrementaByte: public Nodo
{
public:
    NodoDecrementaByte();
    void ejecutar();
    ~NodoDecrementaByte(){}
};

class NodoPrint: public Nodo
{
public:
    NodoPrint();
    void ejecutar();
    ~NodoPrint(){}
};

class NodoScanf: public Nodo
{
public:
    NodoScanf();
    void ejecutar();
    ~NodoScanf(){}
};

class NodoBucle: public Nodo
{
public:
    NodoBucle(Nodo* codigo, Nodo* sig);
    void ejecutar();
    ~NodoBucle(){delete codigo;delete sig;}
private:
    Nodo* codigo;
    Nodo* sig;
};
