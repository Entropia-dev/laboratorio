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
/// opcines del menu paciente que faltan
/// eliminar paciente (segun el archivo pdf del tp pide un "codigo de paciente" supongo que se usara el dni)
/// modificar paciente (se pide modificar obra social ingresando dni)
/// fseek(p, -sizeof reg , 1 ,p)


int main()
{
    MenuPrincipal();
    return 0;
}
