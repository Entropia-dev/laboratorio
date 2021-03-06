#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

struct fecha
{
    int dia;
    int mes;
    int anio;
};

struct paciente
{
    int dni;
    char apellido[50];
    char nombre[50];
    char genero;
    fecha fecha_nacimiento;
    int obra_social;
    bool estado;
};

struct medicos
{
    int numero_matricula;
    char apellido[50];
    char nombre[50];
    int especialidad;
    float sueldo;
};

struct controles
{
    int id;
    int dni;
    int nro_matricula;
    float costo;
    fecha fecha_control;
    int duracion;
    bool estado;
};


#endif // ESTRUCTURAS_H_INCLUDED
