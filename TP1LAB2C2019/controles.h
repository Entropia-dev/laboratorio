#ifndef CONTROLES_H_INCLUDED
#define CONTROLES_H_INCLUDED

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
reg.id=nuevoID();
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
    cout<<"ID: " <<reg.id<<endl;
    cout<<"DNI: "<<reg.dni<<endl;
    cout<<"MATRICULA: "<<reg.nro_matricula<<endl;
    cout<<"COSTO: "<<reg.costo<<endl;
    cout<<"FECHA: "<<reg.fecha_control.dia<<reg.fecha_control.mes<<reg.fecha_control.anio<<endl;
    cout<<"DURACION: "<<reg.duracion<<endl;
    cout<<"=================================================================================================="<<endl;
}
system("pause");
}
int contarregistroscontroles()
{

    long int tam_archivo;
    struct controles reg;

    FILE *p;
    p=fopen("controles.dat","ab");  // porque solo lo necesitamos en caso de que no existe ademas.
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


void modificar_control();
void listar_control_x_id();
void listar_todos_controles();
void cancelar_control();




#endif // CONTROLES_H_INCLUDED
