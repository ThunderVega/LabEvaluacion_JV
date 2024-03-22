#ifndef CLIENTE_H
#define CLIENTE_H
#include <string.h>
#include <iostream>
using namespace std;

class Cliente
{
    public:
        Cliente();
        Cliente (int i, string n, string a);
        virtual ~Cliente();
        int getIdCliente();
        string getNombre();
        string getApellido();

    protected:

    private:
        int idCliente;
        string nombre;
        string apellido;
};

#endif // CLIENTE_H
