#include "Fecha.h"

Fecha::Fecha()
{
    //ctor
}
Fecha :: Fecha (int d, int m, int a)
{
    this->dia = d;
    this->mes = m;
    this->anio = a;
}
Fecha::~Fecha()
{
    //dtor
}

void Fecha :: MostrarFecha()
{
    cout<<this->dia<<"/"<<this->mes<<"/"<<this->anio;
}
