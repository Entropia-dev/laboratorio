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
///IMPORTANTE : TERMINAR LOS LISTADOS DE LA PARTE 2

/// EJEMPLO DE FSEEK : fseek(p, -sizeof reg , 1 ,p).


/// cargar uno mostrar / uno mostrar todos / modificar un articulo / buscar articulo / verificar si existe
/// hacer que buscar articulo devuelva un entero / devuelve un registro de articulo leer un registro (pasarle la posicion de registro)/
/// para buscar el un registro
/// si existe
///leer registro a registro
/// comparo el cpodigo con el codigo leido
/// cierro el archivo y devolver la pocision del registro que encontre
/// si no existe
/// devolver -1

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
