#include "Prestamo.h"

Prestamo::Prestamo()
{
    this->numPrestamo = 0;
    this->montoAprobado = 0;
    this->saldoPendiente = 0;
    this->contadorPagos = 0;
}

Prestamo::Prestamo(int np, Cliente *c, Fecha *f, float ma)
{
    this->numPrestamo = np;
    this->cliente = c;
    this->fechaAprobacion = f;
    this->montoAprobado = ma;
    this->saldoPendiente = ma;
    this->contadorPagos = 0;
}

Prestamo::~Prestamo()
{
    //dtor
}

int Prestamo::getNumPrestamo()
{
    return this->numPrestamo;
}

void Prestamo::setNumPrestamo(int np)
{
    this->numPrestamo = np;
}

Cliente *Prestamo::getCliente()
{
    return this->cliente;
}

void Prestamo::setCliente(Cliente *c)
{
    this->cliente = c;
}

void Prestamo::setFechaAprobacion(Fecha *f)
{
    this->fechaAprobacion = f;
}

Fecha *Prestamo::getFechaAprobacion()
{
    return this->fechaAprobacion;
}

void Prestamo::setMontoAprobado(float ma)
{
    this->montoAprobado = ma;
}

float Prestamo::getMontoAprobado()
{
    return this->montoAprobado;
}

bool Prestamo::hacerPago(Pago *pa)
{
    bool ret = false;
    if(this->contadorPagos<DIM)
    {
        this->lstpago[this->contadorPagos] = pa;
        this->contadorPagos++;
        this->saldoPendiente -= pa->getMontoPago();
        ret = true;
    }
    return ret;
}

Pago **Prestamo::getLstPago()
{
    return this->lstpago;
}

float Prestamo::getSaldoPendiente()
{
    return this->saldoPendiente;
}

int Prestamo::getContadorPagos()
{
    return this->contadorPagos;
}


