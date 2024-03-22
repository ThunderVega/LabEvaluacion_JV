#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;

class Fecha
{
    public:
        Fecha();
        Fecha (int d, int m, int a);
        virtual ~Fecha();
        void MostrarFecha();

    protected:

    private:
        int dia;
        int mes;
        int anio;
};

#endif // FECHA_H
