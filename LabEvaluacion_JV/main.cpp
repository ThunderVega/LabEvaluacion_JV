#include <iostream>
#include <stdlib.h>
#include "Cliente.h"
#include "Fecha.h"
#include "Prestamo.h"
#include "Pago.h"
#define TAM 3
using namespace std;

int Menu()
{
    int op;
    cout<<"\n======================================";
    cout<<"\n\t~MENU DE OPCIONES~";
    cout<<"\n======================================\n";
    cout<<" > [1] Agregar clientes a la lista\n";
    cout<<" > [2] Agregar prestamo a la lista\n";
    cout<<" > [3] Hacer pagos de prestamos\n";
    cout<<" > [4] Mostrar lista de clientes\n";
    cout<<" > [5] Mostrar lista de prestamos\n";
    cout<<" > [6] Mostrar detalles del prestamo\n";
    cout<<" > [7] Salir\n";
    cout<<"======================================\n";

    cout<<" Digite una opcion: ";
    cin>>op;
    cout<<"\n";

    return op;
}

Cliente *agregarClientes()
{
    Cliente *client;
    int codigoC;
    string nom, ape;

    cout<<"Digite un codigo para el cliente: ";
    cin>>codigoC;
    cout<<"\n";

    cout<<"Digite el Nombre del cliente: ";
    cin>>nom;
    cout<<"\n";

    cout<<"Digite el Apellido del cliente: ";
    cin>>ape;
    cout<<"\n";

    client = new Cliente(codigoC, nom, ape);

    return client;
}


Cliente *buscarCliente(Cliente *lstCliente[], int contClie, int codClie)
{
    bool encontrado = false;
    int cont = 0;
    Cliente *cl = NULL;

    while (cont<contClie && !encontrado)
    {
        if (lstCliente[cont]->getIdCliente() == codClie)
        {
            encontrado = true;
            cl = lstCliente[cont];

        }
        else
        {
            cont++;
        }
    }

    return cl;

}

Prestamo *agregarPrestamo(Cliente *clie)
{
    int numPrest;
    int d,m,a;
    Fecha *fech;
    float mont;
    Prestamo *prest;

    cout<<"\nDigite el numero del Prestamo: ";
    cin>>numPrest;

    cout<<"\nDigite la Fecha (dd/mm/aa)"<<endl;
    cin>>d;
    cin>>m;
    cin>>a;

    fech = new Fecha(d,m,a);

    cout<<"\nDigite el monto aprobado: "<<endl;
    cin>>mont;

    prest = new Prestamo(numPrest,clie, fech, mont);

    return prest;
}

Prestamo *buscarPrestamo(Prestamo *lstPrestamo[], int contPrest, int numPrest)
{
    bool encontrado = false;
    int cont = 0;
    Prestamo *prest = NULL;

    while (cont<contPrest && !encontrado)
    {
        if (lstPrestamo[cont]->getNumPrestamo() == numPrest)
        {
            encontrado = true;
            prest = lstPrestamo[cont];

        }
        else
        {
            cont++;
        }
    }

    return prest;

}

void registrarPago(Prestamo *pre)
{
    int d,m,a;
    Fecha *fech;
    float mont;
    Pago *pg;

    cout<<"\nDigite la Fecha (dd/mm/aa)"<<endl;
    cin>>d;
    cin>>m;
    cin>>a;

    fech = new Fecha(d,m,a);

    cout<<"\nDigite el monto a pagar: ";
    cin>>mont;

    pg = new Pago(fech, mont);

    pre->hacerPago(pg);

}

void verDetallesP(Prestamo *prest)
{
    cout<<"\n=============================================";
    cout<<"\nNumero: "<<prest->getNumPrestamo()<<endl;
    cout<<"Cliente: "<< prest->getCliente()->getNombre()<<" "<<prest->getCliente()->getApellido()<<endl;
    cout<<"Fecha de aprobacion: ";
    prest->getFechaAprobacion()->MostrarFecha();
    cout<<endl;
    cout<<"Monto aprobado: "<<prest->getMontoAprobado()<<endl;
    cout<<"Saldo pendiente: "<<prest->getSaldoPendiente()<<endl;
    cout<<"============================================="<<endl;

    if(prest->getContadorPagos()==0)
    {
        cout<<"[No tiene pagos registrados]"<<endl;
    }
    else
    {
        Pago **lstP = prest->getLstPago();
        cout<<"\n=============================================\n";
        cout<<"No\tFecha\t\tMonto\n";
        cout<<"=============================================\n";

        for(int i = 0; i<prest->getContadorPagos(); i++)
        {
            cout<<(i+1)<<"\t";
            lstP[i]->getFechaPago()->MostrarFecha();
            cout<<"\t\t"<<lstP[i]->getMontoPago()<<endl;
        }

        cout<<"\n=============================================\n";

    }
}

int main()
{
    int opc, idClie, idPrest;
    int contClie=0, conPrest = 0;
    Cliente *lstCliente[TAM];
    Prestamo *lstPrest[TAM];
    Cliente *clie = NULL;
    Prestamo *prest = NULL;

    do
    {
        system("cls");
        opc = Menu();
        switch(opc)
        {
            case 1:
                if(contClie<TAM)
                {
                    cout<<"\n";
                    lstCliente[contClie]= agregarClientes();
                    contClie=contClie +1;
                    cout<<"\n[El Cliente se ha registrado con exito!]\n\n";

                }
                else
                {
                    cout<<"\n[La lista de Clientes esta llena!]\n\n";

                }

            break;

            case 2:

                if(conPrest<TAM)
                {
                    cout<<"\nDigite el Id del cliente: ";
                    cin>>idClie;

                    clie = buscarCliente(lstCliente, contClie, idClie);
                    if(clie)
                    {
                        lstPrest[conPrest] = agregarPrestamo(clie);
                        conPrest++;
                        cout<<"\n\n[El Prestamo se ha registrado con exito!]\n\n";
                    }
                    else
                    {
                        cout<<"\n\n[El Cliente no existe!]\n\n";
                    }
                }
                else
                {
                    cout<<"\nLa lista de prestamos esta llena!\n\n";
                }



            break;


            case 3:

                cout<<"\nDigite el Numero del prestamo: ";
                cin>>idPrest;
                prest = buscarPrestamo(lstPrest, conPrest, idPrest);
                if(prest)
                {
                    registrarPago(prest);
                    cout<<"\n\n[El Pago se ha registrado con exito!]\n\n";

                }
                else
                {
                    cout<<"\n[El Prestamo no existe!]\n\n";
                }

            break;


            case 4:
                {
                    if(contClie==0)
                    {
                        cout<<"\n[La La lista de Clientes esta vacia!]\n"<<endl;
                    }
                    else
                    {
                        cout<<"\n=============================\n";
                        cout<<"Id\tNombre\tApellido";
                        cout<<"\n=============================\n";
                        for(int i = 0; i<contClie; i++)
                        {
                            cout<<lstCliente[i]->getIdCliente()<<"\t";
                            cout<<lstCliente[i]->getNombre()<<"\t";
                            cout<<lstCliente[i]->getApellido()<<"\n";
                        }
                        cout<<"=============================\n";
                    }
                }


            break;

            case 5:

                {
                    if(conPrest==0)
                    {
                        cout<<"\nLa La lista de prestamos esta vacia!\n"<<endl;
                    }
                    else
                    {
                        cout<<"\n========================================================================\n";
                        cout<<"No\tCliente\t\tFecha\t\tMonto pagado\tSaldo pendiente";
                        cout<<"\n========================================================================\n";

                        for(int i = 0; i<conPrest; i++)
                        {
                            cout<<lstPrest[i]->getNumPrestamo()<<"\t";
                            cout<<lstPrest[i]->getCliente()->getNombre()<<" "<<lstPrest[i]->getCliente()->getApellido()<<"\t";
                            lstPrest[i]->getFechaAprobacion()->MostrarFecha();
                            cout<<"\t";
                            cout<<lstPrest[i]->getMontoAprobado()<<"\t\t";
                            cout<<lstPrest[i]->getSaldoPendiente()<<endl;

                        }
                        cout<<"========================================================================\n";
                    }
                }


            break;

            case 6:
                cout<<"\nDigite el Numero del prestamo: ";
                cin>>idPrest;
                prest = buscarPrestamo(lstPrest, conPrest, idPrest);

                if(prest)
                {
                    verDetallesP(prest);

                }
                else
                {
                    cout<<"\nEl Prestamo no existe!\n";
                }

                cout<<"\n";


            break;

            case 7:
                cout<<"\n[Saliendo del programa...]\n";
                cout<<"\n";
            break;


            default:
                cout<<"\n[Opcion no valida...]\n\n";
                break;

        }

        cout<<"\n";
        system("pause");

    }while(opc != 7);

    return 0;
}
