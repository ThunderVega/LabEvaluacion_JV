#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Cliente.h"
#include "Fecha.h"
#include "Pago.h"
#include <iostream>
#define DIM 3

using namespace std;

class Prestamo
{
    public:
        Prestamo();
        Prestamo(int np, Cliente *c, Fecha *f, float ma);
        virtual ~Prestamo();
        int getNumPrestamo();
        void setNumPrestamo(int np);
        Cliente *getCliente();
        void setCliente(Cliente *c);
        void setFechaAprobacion(Fecha *f);
        Fecha *getFechaAprobacion();
        void setMontoAprobado(float ma);
        float getMontoAprobado();
        bool hacerPago(Pago *pa);
        Pago **getLstPago();
        float getSaldoPendiente();
        int getContadorPagos();

    protected:

    private:
        int numPrestamo;
        Cliente *cliente;
        Fecha *fechaAprobacion;
        float montoAprobado;
        Pago *lstpago[DIM];
        float saldoPendiente;
        int contadorPagos;
};

#endif // PRESTAMO_H
