#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include  <windows.h>

using namespace std;

#include "estructuras.h"
#include "libreria_angel.h"
#include "pacientes.h"
#include "medicos.h"
#include "controles.h"
#include "menues.h"



/// Notas/Tareas :
/// IMPORTANTES:
/// Esteticos :
/// 3) agregar indicadores de "fin de listado medicos" , "presione una tecla para continuar" , "registro cargado con exito"
/// 4)Aniadir funcion que lea un solo registro ?. CONSULTAR

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

/// articulo leer articulo


/** ideas para los puntos de la segunda parte

el campo auto numerico se puede hacer con una funcion como la de inicializar los archivos
como en "contar registros paciente"

el dni como en buscardnipacientes

para el nro de matricula se va a necesitar buscar matricula
buscar funcion "CTIME"

despues usar las bases de las funciones pacientes/medicos

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


int main()
{

    system("COLOR 5f");
    inicializar_archivos ();
    MenuPrincipal();
    return 0;
}
