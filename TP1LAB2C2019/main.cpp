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



/// Notas/Tareas :
/// IMPORTANTES:
/// PREGUNTAR SI EL FTELL(); NECESITA EL ARCHIVO ABIERTO PREVIAMENTE
/// FUNCIONES CASI DUPLICADAS LISTAR CONTROL Y MOSTRAR CONTROL PREGUNTAR SI ES PREFERIBLE ELIMINAR ALGUNA
/// REVISAR LOS WARNINGS

/// EJEMPLO DE FSEEK : fseek(p, -sizeof reg , 1 ,p).

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
