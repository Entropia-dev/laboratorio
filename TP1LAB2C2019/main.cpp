#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
//Libreria para gotoxy.
#include  <windows.h>
//Librerias para :manejar el tiempo,fecha y vectores dinamicos.
#include<ctime>
#include<vector>

using namespace std;

#include "estructuras.h"
#include "libreria_angel.h"
#include "pacientes.h"
#include "medicos.h"
#include "controles.h"
#include "menues.h"

/**

/// Notas/Tareas :
/// IMPORTANTES:
/// PREGUNTAR SI EL FTELL(); NECESITA EL ARCHIVO ABIERTO PREVIAMENTE
/// FUNCIONES CASI DUPLICADAS LISTAR CONTROL Y MOSTRAR CONTROL PREGUNTAR SI ES PREFERIBLE ELIMINAR ALGUNA

/// EJEMPLO DE FSEEK : fseek(p, -sizeof reg , 1 ,p).


FUNCIONES DE EJEMPLO PARA REALIZAR LOS BACKUPS

[17:57, 19/9/2019] F: void restaurarInmuebles()
{
    Inmueble reg;

    FILE  *pback,*p;
    pback=fopen("bck/backupInmuebles.dat","rb");
    if(pback==NULL)
    {
        cout<<"No existe archivo para poder realizar la restauracion de inmuebles"<<endl;
        return ;
    }
    p=fopen("inmuebles.dat","wb");
    if(p==NULL)
    {
        return ;
    }
    fclose(p);
    p=fopen("inmuebles.dat","ab");
    if(p==NULL)
    {
        return ;
    }
    while(fread(&reg,sizeof(Inmueble),1,pback)==1)
    {

        fwrite(&reg,sizeof(Inmueble),1,p);
    }
    cout<<"Se restauro el archivo inmuebles.dat con exito!"<<endl;
    fclose(p);
    fclose(pback);
    return;
}
[17:57, 19/9/2019] F: void bckInmueble()
{
    Inmueble reg;
    FILE  *pback,*p;
    p=fopen("inmuebles.dat","rb");
    if(p==NULL)
    {
        cout<<"El archivo inmuebles.dat no existe"<<endl;
        return ;
    }
    pback=fopen("bck/backupInmuebles.dat","wb");
    if(pback==NULL)
    {
        return ;
    }
    fclose(pback);
    pback=fopen("bck/backupInmuebles.dat","ab");
    if(pback==NULL)
    {
        return ;
    }
    while(fread(&reg,sizeof(Inmueble),1,p)==1)
    {

        fwrite(&reg,sizeof(Inmueble),1,pback);
    }
    cout<<"Se realizo backup del archivo inmuebles.dat con exito!"<<endl;
    fclose(p);
    fclose(pback);
    return;
}



carga de matriz dinamica ?

Float (*matriz)[12];
Matriz=(float (*) [12]) malloc(cant*12*sizeof (float))
free(matriz);


PREGUNTAR DENUEVO EL FSEEK DE SOBREESCRIBIR PACIENTE

consultar mejora del sistema de inicializar archivos

  "         si las funciones de lectura es conveniente que tengan un entero indicando la posicion que se desea leer o
            dejar que el puntero se maneje por si solo

**/



void inicializar_archivos()
{
    FILE *p;
    p=fopen("inicio.dat","rb");

    if(p==NULL)
    {
        FILE *a=fopen("pacientes.dat","ab");
        fclose(a);
        FILE *b=fopen("medicos.dat","ab");
        fclose(b);
        FILE *c=fopen("controles.dat","ab");
        fclose(c);
        FILE *p=fopen("inicio.dat","ab");
        fclose(p);
        return;
    }
    else
    {
        return;
    }

}


int main(){

    system("COLOR 5f");
    inicializar_archivos ();
    MenuPrincipal();
    return 0;
}
