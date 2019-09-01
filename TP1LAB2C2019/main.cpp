#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

#include "estructuras.h"
#include "pacientes.h"
#include "medicos.h"
#include "menues.h"


/// Notas/Tareas :
/// 1)Se necesita mejorar la validacion de fecha.
/// 2)a veces falla el seleccionar genero en la carga de pacientes.
/// 3)fseek(p, -sizeof reg , 1 ,p).
/// 4)Falta comprobar que esten todas las validaciones de pacientes (ya funcionan todas las opciones del menu correctametne).
/// 5)Averiguar la forma mas limpia de recorrer el archivo en modo lectura.
/// 6)Aniadir funcion que lea un solo registro ?.
/// 7)Darle forma al menu principal
/// 8)Si a buscar dni paciente se le agrega un p==NULL la primera carga falla
/// 9)Las funciones relacionadas a pacientes cuando no hay ninguno cargado tiran exit  ¿otro tipo de salida?
/// 10)Falta por cargar el menu medicos en el .h menues


int main()
{

    system("COLOR 5f");
    MenuPrincipal();
    return 0;
}
