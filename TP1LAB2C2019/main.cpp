#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

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
/// 7)Darle forma al menu principal �cambiar colores?.
/// 8)Si se borra pacientes.dat la se rompe la carga


int main()
{
    system("COLOR 5f");
    MenuPrincipal();
    return 0;
}
