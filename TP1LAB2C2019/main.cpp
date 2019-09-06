#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include  <windows.h>

using namespace std;

#include "libreria_angel.h"
#include "estructuras.h"
#include "pacientes.h"
#include "medicos.h"
#include "menues.h"

/// prueba de actualizacion de notas

/// Notas/Tareas :
/// IMPORTANTES:
/// 1)Se necesita mejorar la validacion de fecha. (Preguntar el viernes)
/// 2)Falta comprobar que esten todas las validaciones de pacientes (ya funcionan todas las opciones del menu correctametne).

/// Esteticos :
/// IMPORTANTE : Leer "Libreria angel"
/// 2)Darle forma al menu principal (a mitad de camino )  ¿como mostrar los listados y las cargas?
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
/// devolver -1.4

/// articulo leer articulo
///



/** ideas para los puntos de la segunda parte

struct controles


Campo
Tipo
ID
entero
DNI
entero
NroMatricula
entero
Costo
float
Fecha
struct Fecha
Duración
entero
Estado
bool

el campo auto numerico se puede hacer con una funcion como la de inicializar los archivos
como en "contar registros paciente"

el dni como en buscardnipacientes

para el nro de matricula se va a necesitar buscar matricula
buscar funcion "CTIME"

despues usar las bases de las funciones pacientes/medicos

**/


int main()
{

    system("COLOR 5f");
    MenuPrincipal();
    return 0;
}
