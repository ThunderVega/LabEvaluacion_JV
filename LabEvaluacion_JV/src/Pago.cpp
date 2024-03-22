#include "Pago.h"

Pago::Pago()
{
    //ctor
}

Pago :: Pago(Fecha *f, float p)
{
    this->fechaPago = f;
    this->montoPago = p;
}

Pago :: ~Pago()
{
    //dtor
}

Fecha *Pago::getFechaPago()
{
    return this->fechaPago;
}

float Pago::getMontoPago()
{
    return this->montoPago;
}
