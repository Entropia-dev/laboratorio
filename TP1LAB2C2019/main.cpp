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
/// 4)Esconder el contador de registros cargados en la carga de pacientes

/// TODAS ESTAS SE SOLUCIONAN CON UNA FUNCION QUE CUENTE REGISTROS EN ARCHIVO Y REVISE
/// SI ESTA DEVUELVE CERO REGISTROS SE PUEDE EVITAR EL NULL PERO SI EL NUMERO ES DISTINTO DE
/// CERO O UN NUMERO MAYOR QUE CERO SE TIENE QUE DEVOLVER EXIT
/// 1)Si a buscar dni paciente se le agrega un p==NULL la primera carga falla
/// 2)Las funciones relacionadas a pacientes cuando no hay ninguno cargado tiran exit  ¿otro tipo de salida?
/// 3)La carga medicos tiene el mismo error que el comentario 9

/// EJEMPLO DE FSEEK : fseek(p, -sizeof reg , 1 ,p).


int main()
{

    system("COLOR 5f");
    MenuPrincipal();
    return 0;
}
