#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

struct fecha {
int dia;
int mes;
int anio;
};

struct paciente{
int dni;
char apellido[50];
char nombre[50];
char genero;
fecha fecha_nacimiento;
int obra_social;
bool estado;
};

struct medicos{
int numero_matricula;
char apellido[50];
char nombre[50];
int especialidad;
float sueldo;
};



/// FUNCION PARA REPOSICIONAR EL PUNTERO DE LA CONSOLA
 void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

#endif // ESTRUCTURAS_H_INCLUDED
