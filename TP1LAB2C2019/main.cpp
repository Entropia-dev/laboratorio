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
#include "configuracion.h"
#include "libreria_angel.h"
#include "pacientes.h"
#include "medicos.h"
#include "controles.h"
#include "menues.h"

/**

 Notas/Tareas :
    Version final, todos los aspectos del sistema son funcionales.
        Repositorio:
            https://github.com/Entropia-dev/laboratorio
                integrantes:Parrotta Federico , Galeano Jeremias , Ortega Banegas , santiago.
                    en caso de querer eliminar todos los archivos ".dat" y querer volver a correr el programa sin cargar previamente
                        algun backuo , se necesita eliminar tambien el archivo "inicio.dat".
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
