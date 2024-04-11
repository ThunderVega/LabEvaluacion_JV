#include <iostream>
#include "OSWindows.h"
#include "OSLinux.h"
#include "OSOSx.h"
#include <stdlib.h>

using namespace std;

int menu()
{
    int opc;
    cout<<"Digite la opcion del motor grafico a mostrar\n";
    cout<<"[1]. Windows\n";
    cout<<"[2]. Linux\n";
    cout<<"[3]. OSx\n";
    cout<<"\nDigite [4] si desea cerrar el progama\n";
    cin>>opc;

    return opc;

}

int main()
{
    int op;
    OSWindows _win;
    OSLinux _lin;
    OSOSx _osx;
    do
    {
        system("cls");
        op=menu();

        switch(op)
        {
            case 1:
                system("cls");
                _win.Pintar();

            break;

            case 2:
                system("cls");
                _lin.Pintar();

            break;

            case 3:
                system("cls");
                _osx.Pintar();

            break;

            case 4:
                cout<<"\nFinalizando programa...\n"<<endl;
            break;

            default:
                cout<<"La opcion digitada no es valida!\n"<<endl;
            break;
        }

        cout<<"\n";
        system("pause");

    }while(op!=4);


    return 0;
}
