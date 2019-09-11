#ifndef CONTROLES_H_INCLUDED
#define CONTROLES_H_INCLUDED

void modificar_control();
void listar_control_x_id();
void listar_todos_controles();
void cancelar_control();

void mostrarcontrol(controles reg){
cout<<"ID DEL CONTROL :"<<reg.id<<endl;
cout<<"FECHA DEL CONTROL :"<<reg.fecha_control.dia<<"/"<<reg.fecha_control.mes<<"/"<<reg.fecha_control.anio<<endl;
cout<<"DURACION DEL CONTROL :"<<reg.duracion<<endl;
cout<<"DNI DEL PACIENTE: "<<reg.dni<<endl;
cout<<"NUMERO DE MATRICULA DEL MEDICO: "<<reg.nro_matricula<<endl;
cout<<"CONSTO DEL CONTROL: "<<reg.costo<<endl;
cout<<"------------------------------------------------------------------------------"<<endl;
}

//====================================================================================================================
// FUNCION    : int ObtenerId(FILE *archivo,int tamStru).
// ACCION     : Obtiene la posicion actual del archivo.
// PARAMETROS : FILE *archivo: Puntero fil del arvhivo.
//              int tamStru: tamaño de la estructura en bytes.
//DEVUELVE    : Numero de registros donde esta ubicado.Devuelve -1 si algo sale mal
//-------------------------------------------------------------------------------------------------------------------
/*int obtenerId(int tamStru){
FILE *p=fopen("controles.dat","rb");
int result=0;
int cantBytes=0;
if(p!=NULL)
    {
    cantBytes = ftell(p);
    fclose(p);
     result= cantBytes / tamStru;
    }
    else {
        fclose(p);
        result=-1;
    }
    return result;
}*/
/////////////////////////////////////////////
int nuevoID(){
struct controles reg;
FILE *p;
p=fopen("controles.dat","rb");
if (p==NULL){
    return 1;}
    fseek(p,-sizeof reg,2);
    fread(&reg,sizeof reg,1,p);
    fclose(p);
    return reg.id+1;

}
//====================================================================================================================
// FUNCION    : int ObtenerId(FILE *archivo,int tamStru).
// ACCION     : Obtiene la posicion actual del archivo.
// PARAMETROS : FILE *archivo: Puntero fil del arvhivo.
//              int tamStru: tamaño de la estructura en bytes.
//DEVUELVE    : Numero de registros donde esta ubicado.Devuelve -1 si algo sale mal
//-------------------------------------------------------------------------------------------------------------------

 void guardarControles(struct controles reg)
{
    FILE *p;
    p = fopen("controles.dat","ab");
    if (p == NULL)
    {
        cout<<"error en funcion guardar paciente"<<endl;
        exit(1);
    }

     fwrite(&reg, sizeof reg,1,p);
   fclose(p);

}




void nuevo_control(){
    struct controles reg;
        /// prueba de obtencion de datos de sistema
    time_t now = time(0);
            tm * time = localtime(&now);

   /// cout<<"dia del mes"<<time->tm_mday;      obtiene el dia del mes de sistema
 ///  cout<<"numero de mes"<<time->tm_mon+1;    obtiene el numero de mes (de 0 a 11)
  ///  cout<<"anio del sistema"<<time ->tm_year + 1900;  obtiene cuantos años pasaron desde 1900 hasta el año de sistema



cout<<"DNI DEL PACIENTE: ";
cin>>reg.dni;
//int auxDni=reg.dni;
if(buscardnipaciente(reg.dni)==false){
    cout<<"EL DNI DEL PACIENTE NO EXISTE!"<<endl;
    cout<<"INGRESE UN PACIENTE EXISTENTE: ";cin>>reg.dni;
}
cout<<"MATRICULA DEL MEDICO: ";cin>>reg.nro_matricula;
int auxMat=reg.nro_matricula;
if(buscarMatricula(auxMat)==false){
cout<<"EL MEDICO NO EXISTE "; cout<<"INGRESE UNA MATRICULA: ";
cin>>reg.nro_matricula;
}
cout<<"COSTO: ";cin>>reg.costo;
cout<<"FECHA DEL CONTROL "<<endl;
cout<<"DIA: ";cin>>reg.fecha_control.dia; cout<<"MES: ";cin>>reg.fecha_control.mes;cout<<"ANIO: ";cin>>reg.fecha_control.anio;
cout<<"DURACION: ";cin>>reg.duracion;
if(reg.duracion < 0){cout<<"la duracion del control debe ser un numero positivo , inserte una duracion valida "<<endl;
                     cin>>reg.duracion;}
reg.id=contarregistroscontroles()+1;
guardarControles(reg);
cout<<"EL CONTROL SE REGISTRO EXITOSAMENTE! ";
system("pause");
cout<<endl;
}

void listarControles(){
struct controles reg;
FILE*p=fopen("controles.dat","rb");
if (p==NULL){cout<<"NO HAY CONTROLES REGISTRADOS!";exit(1);}
while(fread(&reg,sizeof reg, 1, p)==1){
        if(reg.estado==true){
    cout<<"ID DEL CONTROL: " <<reg.id<<endl;
    cout<<"DNI DEL PACIENTE: "<<reg.dni<<endl;
    cout<<"MATRICULA DEL MEDICO: "<<reg.nro_matricula<<endl;
    cout<<"COSTO DEL CONTROL: "<<reg.costo<<endl;
    cout<<"FECHA: "<<reg.fecha_control.dia<<"/"<<reg.fecha_control.mes<<"/"<<reg.fecha_control.anio<<endl;
    cout<<"DURACION: "<<reg.duracion<<endl;
    cout<<"=================================================================================================="<<endl;
}
    }
system("pause");
}


int contarregistroscontroles()
{

    long int tam_archivo;
    struct controles reg;

    FILE *p;
    p=fopen("controles.dat","rb");
    if(p==NULL)
    {
        cout<<"error de archivo ";
        exit(1);
    }
    fseek(p, 0, SEEK_END);
    tam_archivo=ftell(p);
    fclose(p);
    int cantidad_registros =  tam_archivo / sizeof (reg);
    return cantidad_registros;
}


//====================================================================================================================
// FUNCION    : controles leer_registro_controles.
// ACCION     : lee un registro controles de disco y lo devuelve en una variable reg.
// PARAMETROS :
//DEVUELVE    : un struct de tipo controles
//-------------------------------------------------------------------------------------------------------------------

/*
controles leer_registro_controles(){
struct controles reg;
FILE *p;
p=fopen("controles.dat","rb");
if(p==NULL){cout<<"error de archivo en funcion leer_registro_controles"<<endl;
                                exit(1);}
fread(&reg,sizeof reg, 1 , p);
fclose(p);
return reg;
}
**/

// modificarControl(int comparador){
// FILE*p=fopen("controles.dat")
// }



//====================================================================================================================
// FUNCION    :   void buscarId()
// ACCION     :   abrir el archivo controles y buscar
// PARAMETROS :   La opción Modificar Control deberá solicitar
//              el ID del Control y deberá permitir modificar la duración de un control.
//
//DEVUELVE    :
//====================================================================================================================


 /*void buscarId(){
 struct controles reg;
 int id;
 int pos=0;
 cout<<"INGRESE EL ID DEL CONTROL A MODIFICAR: ";cin>>comparador;
 FILE*p=fopen("controles.dat","rb");
 if(p==NULL)cout<<" ARCHIVO INEXISTENTE!"<<exit(1);
 while(fread(&reg,sizeof reg,1,p)==1){

    if (id==reg.id){
    pos=modificarControl(reg.id);
    fclose(p);
    return pos;
    }pos++;
 }fclose(p);
 return -1;
 }

**/

 bool buscar_codigo_control(int id_control){
struct controles reg;
int pos =0;
int r=0;
FILE *p;
p=fopen("controles.dat","rb");
if(p==NULL){cout<<"error de archivo en la funcion buscar_control"<<endl;
				exit(1);}

while(fread(&reg,sizeof reg, 1 , p)){

    if(reg.id == id_control){
            fclose(p);
        return true ;
    }
                }
fclose(p);
return false;
}

/*
bool sobreescribir_control (controles reg, int pos){
  FILE *p;
  p = fopen("controles.dat", "rb+");
  if (p == NULL){
    return false;
  }
  fseek(p, sizeof(controles)*pos, 0);
  bool i=fwrite(&reg, sizeof(controles), 1, p);
  fclose(p);
  return i;
}
**/

void modificar_control(){

    int aux;
    FILE *p;
    struct controles reg;
    cout<<"INGRESE LA ID DEL PROCEDIMIENTO A MODIFCAR"<<endl;
    cin>>aux;
    if(buscar_codigo_control(aux)== -1)
    {
        cout<<"NO SE ENCONTRO LA ID DE PROCEDIMIENTO BUSCADA INGRESE OTRA ID"<<endl;
        cin>>aux;
    }

    if(buscar_codigo_control(aux) == true )
    {
        p=fopen("controles.dat","rb+");
        if(p==NULL)
        {
            cout<<"error en la funcion modificar_control"<<endl;
            exit(1);
        }
        while(fread(&reg,sizeof reg,1,p))
        {
            if(aux==reg.id)
            {
                fseek(p, -sizeof reg, 1 );      ///retrocede el puntero por que la lectura al final del registro
                cout<<"INGRESE LA NUEVA DURACION DEL CONTROL"<<endl;
                cin>>reg.duracion;                                       ///se ingresa el dato a cargar
                if(reg.duracion < 0)
                {
                    cout<<"la duracion no puede ser un numero negativo"<<endl;
                    cin>>reg.duracion;
                }
                fwrite(&reg, sizeof(reg),1,p);      ///se sobre escribe en el mismo lugar
                fclose(p);
            }
        }


    }
    fclose(p);
}



void cancelar_control(){

    int aux;
    FILE *p;
    struct controles reg;
    cout<<"INGRESE LA ID DEL PROCEDIMIENTO A CANCELAR"<<endl;
    cin>>aux;
    if(buscar_codigo_control(aux)== -1)
    {
        cout<<"NO SE ENCONTRO EL ID DE PROCEDIMIENTO A MODIFICAR INGRESE UN NUEVO DNI"<<endl;
        cin>>aux;
    }

    if(buscar_codigo_control(aux) == true )
    {
        p=fopen("controles.dat","rb+");
        if(p==NULL)
        {
            cout<<"error en la funcion modificar_control"<<endl;
            exit(1);
        }
        while(fread(&reg,sizeof reg,1,p))
        {
            if(aux==reg.id)
            {
                fseek(p, -sizeof reg, 1 );      ///retrocede el puntero por que la lectura al final del registro
                reg.estado=false;
                fwrite(&reg, sizeof(reg),1,p);      ///se sobre escribe en el mismo lugar
                fclose(p);
                cout<<"PROCEDIMIENTO CANCELADO CON EXITO"<<endl;
                system("pause");
            }
        }


    }
    fclose(p);
}

void listar_control_x_id(){

    int aux;
    FILE *p;
    struct controles reg;
    cout<<"INGRESE LA ID DEL CONTROL A LISTAR"<<endl;
    cin>>aux;
    if(buscar_codigo_control(aux)== -1)
    {
        cout<<"NO SE ENCONTRO LA ID A LISTAR INGRESE OTRA ID"<<endl;
        cin>>aux;
    }

    if(buscar_codigo_control(aux) == true )
    {
        p=fopen("controles.dat","rb+");
        if(p==NULL)
        {
            cout<<"error en la funcion listar control x id "<<endl;
            exit(1);
        }
        while(fread(&reg,sizeof reg,1,p))
        {
            if(aux==reg.id)
            {
            mostrarcontrol(reg);
            system("pause");
            }
        }


    }
    fclose(p);
}

#endif // CONTROLES_H_INCLUDED
