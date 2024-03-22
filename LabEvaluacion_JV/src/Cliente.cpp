#include "Cliente.h"

Cliente::Cliente()
{
    //ctor
}

Cliente::Cliente(int i, string n, string a)
{
    this->idCliente = i;
    this->nombre = n;
    this->apellido = a;
}

Cliente::~Cliente()
{
    //dtor
}

int Cliente::getIdCliente()
{
    return this->idCliente;
}

string Cliente::getNombre()
{
    return this->nombre;
}

string Cliente::getApellido()
{
    return this->apellido;
}
