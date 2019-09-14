#ifndef CONTROLES_H_INCLUDED
#define CONTROLES_H_INCLUDED

void modificar_control();
void listar_control_x_id();
void listar_todos_controles();
void cancelar_control();

controles leer_control(int pos)
{
    FILE *p;
    struct controles reg;
    p=fopen("controles.dat","rb");
    if(p==NULL)
    {
        cout<<"error de archivo en la funcion leer control"<<endl;
        exit(1);
    }
    fseek(p, sizeof(controles)*pos, SEEK_SET);
    fread(&reg, sizeof(controles), 1, p);
    fclose(p);
    return reg;
}




void listar_control(struct controles reg)
{
    if(reg.estado==true)
    {
        cout<<"ID DEL CONTROL: " <<reg.id<<endl;
        cout<<"DNI DEL PACIENTE: "<<reg.dni<<endl;
        cout<<"MATRICULA DEL MEDICO: "<<reg.nro_matricula<<endl;
        cout<<"COSTO DEL CONTROL: "<<reg.costo<<endl;
        cout<<"FECHA: "<<reg.fecha_control.dia<<"/"<<reg.fecha_control.mes<<"/"<<reg.fecha_control.anio<<endl;
        cout<<"DURACION: "<<reg.duracion<<endl;
        cout<<"=================================================================================================="<<endl;
    }///fin del if
}



void mostrarcontrol(controles reg)
{
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

int nuevoID()   ///cuenta la cantidad de controles en el archivo controles . dat y le suma +1 para poder auto generar la nueva id
{
    struct controles reg;
    FILE *p;
    p=fopen("controles.dat","rb");
    if (p==NULL)
    {
        return 1;
    }
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

void guardarControles(struct controles reg) /// recibe por parametro el registro "reg" de tipo controles y lo guarda en el archivo controles . dat
{
    FILE *p;
    p = fopen("controles.dat","ab");
    if (p == NULL)
    {
        cout<<"error en funcion guardar control"<<endl;
        exit(1);
    }

    fwrite(&reg, sizeof reg,1,p);
    fclose(p);

}




void nuevo_control()
{                           ///carga y alta de un registro de tipo controles falta validar la fecha
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
    if(buscardnipaciente(reg.dni)==false)
    {
        cout<<"EL DNI DEL PACIENTE NO EXISTE!"<<endl;
        cout<<"INGRESE UN PACIENTE EXISTENTE: ";
        cin>>reg.dni;
    }
    cout<<"MATRICULA DEL MEDICO: ";
    cin>>reg.nro_matricula;
    int auxMat=reg.nro_matricula;
    if(buscarMatricula(auxMat)==false)
    {
        cout<<"EL MEDICO NO EXISTE ";
        cout<<"INGRESE UNA MATRICULA: ";
        cin>>reg.nro_matricula;
    }
    cout<<"COSTO: ";
    cin>>reg.costo;
    cout<<"FECHA DEL CONTROL "<<endl;
    cout<<"DIA: ";
    cin>>reg.fecha_control.dia;
    cout<<"MES: ";
    cin>>reg.fecha_control.mes;
    cout<<"ANIO: ";
    cin>>reg.fecha_control.anio;
    cout<<"DURACION: ";
    cin>>reg.duracion;
    if(reg.duracion < 0)
    {
        cout<<"la duracion del control debe ser un numero positivo , inserte una duracion valida "<<endl;
        cin>>reg.duracion;
    }
    reg.id=contarregistroscontroles()+1;
    guardarControles(reg);
    cout<<"EL CONTROL SE REGISTRO EXITOSAMENTE! ";
    system("pause");
    cout<<endl;
}

void listarControles()
{
    int cantidad_de_registros;  /// vriable entera para contar la  cantidad de registros en el archivo controles
    struct controles reg;       ///registro controles necesario para mostrar los controles en el archivo
    cantidad_de_registros = contarregistroscontroles(); ///se cuenta la cantidad de registros en el archivo
    for(int i=0; i<cantidad_de_registros; i++) ///se usa como tope la cantidad de registros en el archivo
    {
        reg=leer_control(i);    ///se lee el registro que este en la pocisopn "i"
        mostrarcontrol(reg);    ///se muestra el registro en la pocision "i"
    }
    system("pause");
}


int contarregistroscontroles()  ///cuenta los registros en el archivo y los devuelve , como por ejemplo para usar la variable obtenida
{                               /// como tope de un for en una funcion de lectura.

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

bool buscar_codigo_control(int id_control)  ///busca el id de control ingresado para saber si ya existe o no en el archivo "controles.dat"
{
    struct controles reg;
    int pos =0;
    int r=0;
    FILE *p;
    p=fopen("controles.dat","rb");
    if(p==NULL)
    {
        cout<<"error de archivo en la funcion buscar_control"<<endl;
        exit(1);
    }

    while(fread(&reg,sizeof reg, 1, p))
    {

        if(reg.id == id_control)
        {
            fclose(p);
            return true ;
        }
    }
    fclose(p);
    return false;
}


bool sobreescribir_control (controles reg, int pos){    ///guarda un nuevo registro reg en la posicion que se le indique
  FILE *p;
  p = fopen("controles.dat", "rb+");
  if (p == NULL){
    return false;
  }
  int aux=pos-1;                                ///se le resta 1 a la posicion para evitar el -sizeof
  fseek(p, sizeof(controles)*aux, 0);
    fwrite(&reg, sizeof(controles), 1, p);
  fclose(p);
}


void modificar_control()
{
    int aux;
    struct controles reg;
    cout<<"INGRESE LA ID DEL PROCEDIMIENTO A MODIFCAR"<<endl;
    cin>>aux;
    if(buscar_codigo_control(aux)== false)  ///chequea que el codigo de control ya exista , en todo caso se solicita el ingreso de uno valido
    {
        cout<<"NO SE ENCONTRO LA ID DE PROCEDIMIENTO BUSCADA INGRESE OTRA ID"<<endl;
        cin>>aux;
    }
                reg=leer_control(aux);  ///se lee el control en la posicion "aux" (el orden de los registros es igual a su id)
                cout<<"INGRESE LA NUEVA DURACION DEL CONTROL"<<endl;
                cin>>reg.duracion;  ///se carga el campo que se desea modificar en el registro previamente leido
                sobreescribir_control(reg,aux);     /// se sobreescribe el archivo con la nueva informacion
}



void cancelar_control()
{

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

void listar_control_x_id()
{

    int aux;
    FILE *p;
    struct controles reg;
    cout<<"INGRESE LA ID DEL CONTROL A LISTAR"<<endl;
    cin>>aux;                                           /// se almacena el dato ingresado para verificar que sea valido
    if(buscar_codigo_control(aux)== false)
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
            if(aux==reg.id)                     ///se busca el registro que contenga la misma id que solicito el usuario
            {
                mostrarcontrol(reg);    ///se envia el registro en caso de ser encontrado a la funcion mostrar control para
                 fclose(p);                       ///que el usuario pueda ver la informacion que solicito
                system("pause");
                 return;
            }

        }


    }

          cout<<"NO SE ENCONTRO EL REGISTRO CON LA ID INGRESADA"<<endl;     ///a estas llaves solo se llega en caso de fallar en el
            cout<<"INTENTELO NUEVAMENTE"<<endl;                             ///segundo intento de ingresar  la ID A LISTAR
            system("pause");
}


#endif // CONTROLES_H_INCLUDED
