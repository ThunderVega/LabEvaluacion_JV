#include "OSLinux.h"

OSLinux::OSLinux()
{
    strcpy(_lin_titulo,"Red Hat Enterprise Linux (RHEL)");
    strcpy(_lin_area_trabajo,"No hay nada en el area de trabajo");
    strcpy(_lin_estado,"Linux no ha sido activado todavia");
}

OSLinux::~OSLinux()
{
    //dtor
}

void OSLinux::Pintar()
{
    DibujarSimbolo('=',80,true);
    DibujarSimbolo('|',1);
    CentrarTexto(_lin_titulo);
    DibujarSimbolo('|',1,true);
    DibujarSimbolo('=',80,true);

    for(int e=0;e<10;e++)
    {
        DibujarSimbolo('|',1);
        DibujarSimbolo(' ',78);
        DibujarSimbolo('|',1,true);
        if(e == 5)
        {
            DibujarSimbolo('|',1);
            CentrarTexto(_lin_area_trabajo);
            DibujarSimbolo('|',1,true);
        }
    }

    DibujarSimbolo('=',80,true);
    DibujarSimbolo('|',1);
    CentrarTexto(_lin_estado);
    DibujarSimbolo('|',1,true);
    DibujarSimbolo('=',80,true);
}

void OSLinux::DibujarSimbolo(char _simbolo,int _limite,bool _saltarlinea)
{
    for(int e=0;e<_limite;e++)
    {
        cout << _simbolo;
    }
    if(_saltarlinea)
    {
        cout << endl;
    }
}

void OSLinux::CentrarTexto(char *_ptexto)
{
    int k,n,r;
    n = strlen(_ptexto);
    k = (78-n)/2;
    r = (78-n)%2;
    for(int i=0;i<k;i++)
    {
        cout << ' ';
    }
    cout << _ptexto;

    for(int i=0;i<k+r;i++)
    {
        cout << ' ';
    }
}
