#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include  <windows.h>

using namespace std;

#include "estructuras.h"
#include "pacientes.h"
#include "medicos.h"
#include "menues.h"


/// Notas/Tareas :
/// IMPORTANTES:
/// 1)Se necesita validar el genero del paciente
/// 2)Se necesita mejorar la validacion de fecha. (Preguntar el viernes)
/// 3)Falta comprobar que esten todas las validaciones de pacientes (ya funcionan todas las opciones del menu correctametne).

/// Esteticos :
/// 1)Darle forma al menu principal (a mitad de camino )  ¿como mostrar los listados y las cargas?
/// 2) agregar indicadores de "fin de listado medicos" , "presione una tecla para continuar" , "registro cargado con exito"
/// 3)Aniadir funcion que lea un solo registro ?.

/// EJEMPLO DE FSEEK : fseek(p, -sizeof reg , 1 ,p).


int main()
{

    system("COLOR 5f");
    MenuPrincipal();
    return 0;
}
