#ifndef CONTROLES_H_INCLUDED
#define CONTROLES_H_INCLUDED

// ******************************  PROTOTIPOS ****************************************

void modificar_control();
void listar_control_x_id();
void listar_todos_controles();
void cancelar_control();
void mostrarcontrol(struct controles,int);



///lee el control en la ubicasion indicada

controles leer_control(int pos){

    FILE *p;
    struct controles reg;

    p=fopen("controles.dat","rb");

        if(p==NULL){

            cout<<"error de archivo en la funcion leer control"<<endl;

            exit(1);
        }

    fseek(p, sizeof(controles)*pos, 0);  ///lleva el puntero a la posicion indicada por "pos"

    fread(&reg, sizeof(controles), 1, p);   ///lee el registro elegido

    fclose(p);

    return reg;
}

//====================================================================================================================
// FUNCION    :
// ACCION     :
// PARAMETROS :
//
//DEVUELVE    :
//====================================================================================================================

///lista un control enviado por parametro en caso de que el estado de este sea "activo"
void listar_control(struct controles reg) {


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

///muestra un control enviado como parametro ( es preferible eliminarla ?)

void mostrarcontrol(controles reg , int modo){

    if ( modo == 1 ){

    gotoxy(28,12);
    cout<<"ID del Control :"<<reg.id<<endl;
    gotoxy(28,13);
    cout<<"Fecha del Control :"<<reg.fecha_control.dia<<"/"<<reg.fecha_control.mes<<"/"<<reg.fecha_control.anio<<endl;
    gotoxy(28,14);
    cout<<"Duracion del Control :"<<reg.duracion<<endl;
    gotoxy(28,15);
    cout<<"DNI del Paciente: "<<reg.dni<<endl;
    gotoxy(28,16);
    cout<<"Numero de Matricula del Medico: "<<reg.nro_matricula<<endl;
    gotoxy(28,17);
    cout<<"Costo del Control: "<<reg.costo<<endl;
    gotoxy(28,18);
    cout<<"====================="<<endl;
    gotoxy(28,19);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(28,20);
    cout<<" ******  FIN LISTADO DE CONTROL POR ID  ******   "<<endl;
    gotoxy(28,21);
    cout<<"-------------------------------------------------"<<endl;



    }else{  //LISTAMOS TODO EN PANTALLA VACIA SIN RECUADRO


        cout<<"ID DEL CONTROL :"<<reg.id<<endl;
        cout<<"FECHA DEL CONTROL :"<<reg.fecha_control.dia<<"/"<<reg.fecha_control.mes<<"/"<<reg.fecha_control.anio<<endl;
        cout<<"DURACION DEL CONTROL :"<<reg.duracion<<endl;
        cout<<"DNI DEL PACIENTE: "<<reg.dni<<endl;
        cout<<"NUMERO DE MATRICULA DEL MEDICO: "<<reg.nro_matricula<<endl;
        cout<<"COSTO DEL CONTROL: "<<reg.costo<<endl;
        cout<<"====================="<<endl;


    }

    return;


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

//====================================================================================================================
// FUNCION    :
// ACCION     :
// PARAMETROS :
//
//DEVUELVE    :
//====================================================================================================================


///cuenta la cantidad de controles en el archivo controles . dat y le suma +1 para poder auto generar la nueva id

int nuevoID() {


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

//====================================================================================================================
// FUNCION    :
// ACCION     :
// PARAMETROS :
//
//DEVUELVE    :
//====================================================================================================================

///carga y alta de un registro de tipo controles falta validar la fecha


controles nuevo_control(){

    struct controles reg;


    /// prueba de obtencion de datos de sistema
    time_t now = time(0);
    tm * time = localtime(&now);

    /// cout<<"dia del mes"<<time->tm_mday;      obtiene el dia del mes de sistema
    ///  cout<<"numero de mes"<<time->tm_mon+1;    obtiene el numero de mes (de 0 a 11)
    ///  cout<<"anio del sistema"<<time ->tm_year + 1900;  obtiene cuantos años pasaron desde 1900 hasta el año de sistema



    system("cls");
    recuadro(20,1,75,25);
    gotoxy(45,2);
    cout<<" CLINICA SAN SIMON PROTECTOR"<<endl;
    gotoxy(45,3);
    cout<<"        NUEVO CONTROL       "<<endl;

    gotoxy(28,5);
    cout<<"Menu Altas de Control de la Clinica San Simon Protector"<<endl;



    // ************************************** VALIDACION NUMERO 1 *******************************************************


            //HACER UN NUMERO AUTO INCREMENTAL Y SE LE MUESTRE AL USUARIO AUTOMATICAMENTE.
            gotoxy(21,6);
    cout<<"NUMERO INCREMENTAL EN UN ARCHIVO:                  ";

/*
    gotoxy(21,6);
    cout<<"Ingrese ID del Control:                  ";
    gotoxy(44,6);
    cin>>reg.id;


        while( reg.id < 1 ){
                gotoxy(21,5);
                cout<<"ID Invalido - Ingrese uno Valido:                  ";
                gotoxy(54,5);
                cin>>reg.id;

            }

*/


    // ************************************** VALIDACION NUMERO 2 *******************************************************

    gotoxy(21,7);
    cout<<"Ingrese Dni del Paciente:                           ";
    gotoxy(46,7);
    cin>>reg.dni;
    int auxDni=reg.dni;

    while(  buscardnipaciente(auxDni) == false  ){

                gotoxy(21,7);
                cout<<"ERROR:DNI Inexistente - Ingrese Dni Existente:                      ";
                gotoxy(67,7);
                cin>>reg.dni;
                auxDni=reg.dni;


      }



    // ************************************** VALIDACION NUMERO 3 *******************************************************


    gotoxy(21,8);
    cout<<"Matricula del Medico:                    ";
    gotoxy(42,8);
    cin>>reg.nro_matricula;
    int auxMat=reg.nro_matricula;


            while(buscarMatricula(auxMat)==false){

                gotoxy(21,8);
                cout<<"ERROR:Matricula Inexistente - Ingrese Matricula Existente:             ";
                gotoxy(79,8);
                cin>>reg.nro_matricula;
                auxMat=reg.nro_matricula;

            }





  // ************************************** VALIDACION NUMERO 4 *******************************************************

    gotoxy(21,9);
    cout<<"Ingrese el Costo del Control:           ";
    gotoxy(50,9);
    cin>>reg.costo;

            while(reg.costo < 1){

                gotoxy(21,9);
                cout<<"Ingrese un Monto de Control Valido:             ";
                gotoxy(56,9);
                cin>>reg.costo;

            }




// ************************ VALIDACION NUMERO 5: FECHAS SUPERIOR AL SISTEMA ACTUAL(AL DIA DE HOY) *************************************************

/*
    gotoxy(21,8);
    cout<<"Ingrese el Dia del Control:               ";
    gotoxy(21,8);
    cin>>reg.fecha_control.dia;


    gotoxy(21,9);
    cout<<"Ingrese el Mes del Control:            ";
    gotoxy(48,9);
    cin>>reg.fecha_control.mes;


    gotoxy(21,10);
    cout<<"Ingrese el Anio del Control:             ";
    gotoxy(49,10);
    cin>>reg.fecha_control.anio;

*/


 reg.fecha_control=cargar_fecha_control();







 // ************************************** VALIDACION NUMERO 6 *******************************************************

    gotoxy(21,13);
    cout<<"Ingrese la Duracion del Control:             ";
    gotoxy(53,13);
    cin>>reg.duracion;



            while(reg.duracion < 1){

                gotoxy(21,13);
                cout<<"ERROR: Duracion Invalida - Ingrese una Duracion Valida:          "<<endl;
                gotoxy(76,13);
                cin>>reg.duracion;
            }



    reg.id=contarregistroscontroles()+1;
    guardarControles(reg);





    gotoxy(21,15);
    cout<<"------------------------------------------------------------------------";
    gotoxy(21,16);
    cout<<"                   EL CONTROL SE REGISTRO EXITOSAMENTE                 ";
    gotoxy(21,17);
    cout<<"-----------------------------------------------------------------------";
    gotoxy(20,27);
    system("pause");


    return reg;


}




//====================================================================================================================
// FUNCION    :
// ACCION     :
// PARAMETROS :
//
//DEVUELVE    :
//====================================================================================================================




void listarControles(){

    int modo=2;
    int cantidad_de_registros;  /// vriable entera para contar la  cantidad de registros en el archivo controles
    struct controles reg;       ///registro controles necesario para mostrar los controles en el archivo
    cantidad_de_registros = contarregistroscontroles(); ///se cuenta la cantidad de registros en el archivo
    for(int i=0; i<cantidad_de_registros; i++) ///se usa como tope la cantidad de registros en el archivo
    {
        reg=leer_control(i);    ///se lee el registro que este en la pocisopn "i"
                if(reg.estado==true){
        mostrarcontrol(reg,modo);    ///se muestra el registro en la pocision "i"
                }
    }
    system("pause");
}


//====================================================================================================================
// FUNCION    :
// ACCION     :
// PARAMETROS :
//
//DEVUELVE    :
//====================================================================================================================



///cuenta los registros en el archivo y los devuelve , como por ejemplo para usar la variable obtenida
/// como tope de un for en una funcion de lectura.



int contarregistroscontroles() {



    long int tam_archivo;
    struct controles reg;

    FILE *p;
    p=fopen("controles.dat","rb");  ///se abre el archivo controles para poder ver su contenido y verificar que este exista
    if(p==NULL)
    {
        cout<<"error de archivo ";
        exit(1);
    }
    fseek(p, 0, SEEK_END);      ///se dirije el puntero de lectura hasta el final del archivo
    tam_archivo=ftell(p);       ///se obtiene en bytes el peso del archivo
    fclose(p);                  /// se cierra el archivo ya que no es necesario para continuar con la funcion
    int cantidad_registros =  tam_archivo / sizeof (controles);   ///se obtiene la cantidad de registros en el archivo dividiendo el peso total
    return cantidad_registros;                              ///por lo que pesa cada registro del tipo que contiene el archivo
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

//====================================================================================================================
// FUNCION    :
// ACCION     :
// PARAMETROS :
//
//DEVUELVE    :
//====================================================================================================================


///busca el id de control ingresado para saber si ya existe o no en el archivo "controles.dat"

bool buscar_codigo_control(int id_control){

    struct controles reg;
    int pos =0;
    int r=0;

    FILE *p;
    p=fopen("controles.dat","rb");


    if(p==NULL){
        cout<<"error de archivo en la funcion buscar_control"<<endl;
        exit(1);
    }


            while(fread(&reg,sizeof reg, 1, p)){


                if(reg.id == id_control){

                    fclose(p);
                    return true ;
                }
            }



    fclose(p);
    return false;
}




//====================================================================================================================
// FUNCION    :
// ACCION     :
// PARAMETROS :
//
//DEVUELVE    :
//====================================================================================================================


///guarda un nuevo registro reg en la posicion que se le indique

void sobreescribir_control (controles reg, int pos){
  FILE *p;
  p = fopen("controles.dat", "rb+");
  if (p == NULL){
    return exit(1);
     cout<<"error en funicon sobreescribir archivo"<<endl;
    }
  fseek(p, sizeof(controles)*pos, 0);
  bool i=fwrite(&reg, sizeof(controles), 1, p);
  fclose(p);
    cout<<"CONTROL MODIFICADO CON EXITO"<<endl;

}




//====================================================================================================================
// FUNCION    :
// ACCION     :
// PARAMETROS :
//
//DEVUELVE    :
//====================================================================================================================




void modificar_control(){


    int aux;
    struct controles reg;

    system("cls");
    recuadro(20,1,75,25);
    gotoxy(45,2);
    cout<<" **** CLINICA SAN SIMON ****"<<endl;
    gotoxy(45,3);
    cout<<"      MODIFICAR DURACION     "<<endl;
    gotoxy(28,6);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(28,7);
    cout<<"  Modificacion Duracion de Control Mediante ID     "<<endl;
    gotoxy(28,8);
    cout<<"-------------------------------------------------"<<endl;




    gotoxy(28,9);
    cout<<"Ingrese el ID del Control a Modifcar:                "<<endl;
    gotoxy(65,9);
    cin>>aux;
    reg=leer_control(aux);
    ///chequea que el codigo de control ya exista , en todo caso se solicita el ingreso de uno valido
    while(buscar_codigo_control(aux)== false || reg.estado == false){
        gotoxy(28,9);
        cout<<"ERROR: ID Inexistente, Ingrese un ID Existente:             "<<endl;
        gotoxy(75,9);
        cin>>aux;
    }
        reg=leer_control(aux);  ///se lee el control en la posicion "aux" (el orden de los registros es igual a su id)
        gotoxy(28,10);
        cout<<"Ingrese la Nueva Duracion del Control:             "<<endl;
        gotoxy(66,10);
        cin>>reg.duracion;  ///se carga el campo que se desea modificar en el registro previamente leido

        sobreescribir_control(reg,aux);     /// se sobreescribe el archivo con la nueva informacion

            gotoxy(28,12);
            cout<<"-------------------------------------------------"<<endl;
            gotoxy(28,13);
            cout<<"*****  MODIFICACION DE LA DURACION EXITOSA  *****"<<endl;
            gotoxy(28,14);
            cout<<"-------------------------------------------------"<<endl;

            gotoxy(20,27);
            system("pause");


      return;

}




//====================================================================================================================
// FUNCION    :
// ACCION     :
// PARAMETROS :
//
//DEVUELVE    :
//====================================================================================================================






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



//====================================================================================================================
// FUNCION    :
// ACCION     :
// PARAMETROS :
//
//DEVUELVE    :
//====================================================================================================================





void listar_control_x_id(){

    //VARIABLE Q ME SIRVE PARA SABER QUE FUNCION LLAMA A "MOSTRARCONTROL"
    int modo=1;
    int aux;
    FILE *p;
    struct controles reg;



    system("cls");
    recuadro(20,1,75,25);

    gotoxy(45,2);
    cout<<" **** CLINICA SAN SIMON ****"<<endl;
    gotoxy(45,3);
    cout<<" LISTADO DE CONTROL POR ID"<<endl;

    gotoxy(28,6);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(28,7);
    cout<<" Listar un Control mediante un determinado ID    "<<endl;
    gotoxy(28,8);
    cout<<"-------------------------------------------------"<<endl;


    gotoxy(28,9);
    cout<<"Ingrese El ID del Control a Listar:                "<<endl;
    gotoxy(63,9);
    cin>>aux;


    /// se almacena el dato ingresado para verificar que sea valido



    while(buscar_codigo_control(aux)== false){

        gotoxy(28,9);
        cout<<"ERROR: ID Inexistente - Ingrese un ID Existente:          "<<endl;
        gotoxy(76,9);
        cin>>aux;
    }



    if(buscar_codigo_control(aux) == true ){

        p=fopen("controles.dat","rb+");

            if(p==NULL){
                cout<<"error en la funcion listar control x id "<<endl;
                exit(1);
            }


                ///se busca el registro que contenga la misma id que solicito el usuario
                while(fread(&reg,sizeof reg,1,p)){
                    if(aux==reg.id){
                        mostrarcontrol(reg,modo);    ///se envia el registro en caso de ser encontrado a la funcion mostrar control para
                        fclose(p);                       ///que el usuario pueda ver la informacion que solicito
                        gotoxy(20,27);
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
