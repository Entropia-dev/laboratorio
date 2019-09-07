#ifndef CONTROLES_H_INCLUDED
#define CONTROLES_H_INCLUDED

void nuevo_control();


int contarregistroscontroles(){

 long int tam_archivo;
 struct controles reg;

    FILE *p;
    p=fopen("controles.dat","ab");  // porque solo lo necesitamos en caso de que no existe ademas.
   if(p==NULL){cout<<"error de archivo "; exit(1);}
   fseek(p, 0 , SEEK_END);
   tam_archivo=ftell(p);
   fclose(p);
   int cantidad_registros =  tam_archivo / sizeof (reg);
   return cantidad_registros;
}


void modificar_control();
void listar_control_x_id();
void listar_todos_controles();
void cancelar_control();




#endif // CONTROLES_H_INCLUDED
