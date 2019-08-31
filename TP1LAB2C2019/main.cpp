#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

#include "estructuras.h"
#include "pacientes.h"
#include "medicos.h"
#include "menues.h"

/// prueba Santy Visual Studio Code
/// Santy prueba pull para Visual studio code
/// notas:
/// se necesita mejorar la validacion de fecha
/// aveces falla el seleccionar genero en la carga de pacientes
/// fseek(p, -sizeof reg , 1 ,p)
/// falta comprobar que esten todas las validaciones de pacientes (ya funcionan todas las opciones del menu correctametne)
/// averiguar la forma mas limpia de recorrer el archivo en modo lectura
/// añadir funcion que lea un solo registro ?
/// darle forma al menu principal ¿cambiar colores?

int main()
{
    MenuPrincipal();
    return 0;
}
