#ifndef PAGO_H
#define PAGO_H
#include "Fecha.h"
#include <iostream>
using namespace std;


class Pago
{
    public:
        Pago();
        Pago(Fecha *f, float p);
        virtual ~Pago();
        Fecha *getFechaPago();
        float getMontoPago();

    protected:

    private:
        Fecha *fechaPago;
        float montoPago;
};

#endif // PAGO_H
