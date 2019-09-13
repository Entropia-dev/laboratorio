#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED

//Si quieren modificar el orden del codigo y les da error,solo deben agregar el prototipo de las funciones
//que no reconoce el compilador.Lo ideal es agregar  todas pero mientras que no de error no hace falta
//poner todos los prototipos.(ya puse todas)

bool buscardnipaciente(int);
paciente CargarPaciente();
void GuardarPaciente(struct paciente);
void altaPaciente();
int buscarposiciondni(int);
int contarregistroscontroles();
void eliminarpaciente();
void listarpaciente(struct paciente);
void listarpacientepordni();
void listartodoslospacientes();
void modificarobrasocial();



//====================================================================================================================
//
// **********************  SECCION REFERENTE AL LISTADO DE PACIENTES  *************************
//
//====================================================================================================================

//====================================================================================================================
// FUNCION    :
// ACCION     :
// PARAMETROS :
//
//DEVUELVE    :
//====================================================================================================================



void listarpaciente(struct paciente reg,int modo){

    if ( modo ==1 ){

    gotoxy(28,12);
    cout<<"Apellido del paciente: "<<reg.apellido<<endl;
    gotoxy(28,13);
    cout<<"Nombre del paciente: "<<reg.nombre<<endl;
    gotoxy(28,14);
    cout<<"Fecha de nacimiento: "<<reg.fecha_nacimiento.dia<<"/"<<reg.fecha_nacimiento.mes<<"/"<<reg.fecha_nacimiento.anio<<endl;
    gotoxy(28,15);
    cout<<"Dni del paciente: "<<reg.dni<<endl;
    gotoxy(28,16);
    cout<<"Obra social del paciente: "<<reg.obra_social<<endl;
    gotoxy(28,17);
    cout<<"Genero del paciente: "<<reg.genero<<endl;
    gotoxy(28,18);
    cout<<"====================="<<endl;
    gotoxy(28,19);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(28,20);
    cout<<" ******  FIN LISTADO DE PACIENTE POR DNI  ****** "<<endl;
    gotoxy(28,21);
    cout<<"-------------------------------------------------"<<endl;

     }else{




    //gotoxy(2,3);
    cout<<"Apellido del paciente: "<<reg.apellido<<endl;
    //gotoxy(2,4);
    cout<<"Nombre del paciente: "<<reg.nombre<<endl;
    //gotoxy(2,5);
    cout<<"Fecha de nacimiento: "<<reg.fecha_nacimiento.dia<<"/"<<reg.fecha_nacimiento.mes<<"/"<<reg.fecha_nacimiento.anio<<endl;
    //gotoxy(2,6);
    cout<<"Dni del paciente: "<<reg.dni<<endl;
    //gotoxy(2,7);
    cout<<"Obra social del paciente: "<<reg.obra_social<<endl;
    //gotoxy(2,8);
    cout<<"Genero del paciente: "<<reg.genero<<endl;
    //gotoxy(2,9);
    cout<<"====================="<<endl;
    //gotoxy(2,10);

     }


    return;
}

//====================================================================================================================
// FUNCION    :
// ACCION     :
// PARAMETROS :
//
//DEVUELVE    :
//====================================================================================================================




void listartodoslospacientes(){

    //ESTA VARIABLE ME SIRVE PORQUE SE LA VOY A PASAR A LA FUNCION LISTARPACIENTE INDICANDOLE CUAL MENU LA LLAMO.
    int modo=2;
    struct paciente reg;
    FILE *p;
    p=fopen("pacientes.dat","rb");
    if(p==NULL){
        cout<<"error de funcion listar todos los pacientes"<<endl;
        exit(1);
    }
    while(fread(&reg,sizeof reg,1,p)==1){

        if(reg.estado==true){
            listarpaciente(reg,modo);
        }
    }
    fclose(p);
   // gotoxy(20,76);
    system("pause");
}

//====================================================================================================================
// FUNCION    :
// ACCION     :
// PARAMETROS :
//
//DEVUELVE    :
//====================================================================================================================


void listarpacientepordni(){

    struct paciente reg;
    int aux;
    //ESTA VARIABLE ME SIRVE PORQUE SE LA VOY A PASAR A LA FUNCION LISTARPACIENTE INDICANDOLE CUAL MENU LA LLAMO.
    int modo=1;
    FILE *p;

    system("cls");
    recuadro(20,1,75,25);
    gotoxy(45,2);
    cout<<" **** CLINICA SAN SIMON ****"<<endl;
    gotoxy(45,3);
    cout<<" LISTADO DE PACIENTE POR DNI"<<endl;
    gotoxy(28,6);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(28,7);
    cout<<" Listar un paciente mediante un determinado DNI  "<<endl;
    gotoxy(28,8);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(28,9);
    cout<<"Ingrese El Dni del Paciente a Listar:"<<endl;
    gotoxy(65,9);
    cin>>aux;


    while(buscardnipaciente(aux)==false){
        gotoxy(28,10);
        cout<<"ERROR: Dni No Encontrado - Ingrese Un Dni Valido:        "<<endl;
        gotoxy(77,10);
        cin>>aux;
    }




    p=fopen("pacientes.dat","rb");
    if(p==NULL){
        gotoxy(45,8);
        cout<<"error en la funcion listar paciente x dni "<<endl;
        exit(1);
    }


    while(fread(&reg,sizeof reg,1,p)){

        if(aux==reg.dni){

            listarpaciente(reg,modo);
            fclose(p);
            return;
        }
    }
    fclose(p);
    return;
}



//====================================================================================================================
//
// **********   SECCION DE ALTA/BAJA/MODIFICACION Y BUSQUEDA DE PACIENTES  *********************
//
//====================================================================================================================



void altaPaciente(){

    paciente reg;
    reg=CargarPaciente();
    GuardarPaciente(reg);
    return;
}

//====================================================================================================================
// FUNCION    :
// ACCION     :
// PARAMETROS :
//
//DEVUELVE    :
//====================================================================================================================




paciente CargarPaciente(){
    char aux_genero_2;
    bool auxGen=true;
    struct paciente reg;
    int aux;

    system("cls");
    recuadro(20,1,75,25);
    gotoxy(45,2);
    cout<<" **** CLINICA SAN SIMON ****"<<endl;
    gotoxy(45,3);
    cout<<"      ALTA DE PACIENTES     "<<endl;

    // ************************************** INGRESO NUMERO 1 *******************************************************
    gotoxy(21,5);
    cout<<"Ingrese El Dni Del Paciente:                                   ";
    gotoxy(49,5);
    cin>>reg.dni;
    aux=reg.dni;


    // ************************************** VALIDACION  1 *******************************************************
    while(reg.dni<1){
        gotoxy(21,5);
        cout<<"Ingrese Un Numero De Dni Valido:                            ";
        gotoxy(53,5);
        cin>>reg.dni;
        aux=reg.dni;
    }



    while(buscardnipaciente(aux)==true){

        gotoxy(21,5);
        cout<<"DNI Duplicado - Por favor ingrese uno valido:                      ";
        gotoxy(66,5);
        cin>>reg.dni;
        aux=reg.dni;

    }

    // ************************************** INGRESO NUMERO 2 *******************************************************

            gotoxy(21,6);
            cout<<"Ingrese El Apellido Del Paciente:                      ";
            cin.ignore();
            gotoxy(54,6);
            cin.getline(reg.apellido, 50);

            while(reg.apellido[0]== '\0' ){

                gotoxy(21,6);
                cout<<"Ingrese Un Apellido Correcto:                      ";
                gotoxy(50,6);
                cin.getline(reg.apellido,50);
         }

    // ************************************** INGRESO NUMERO 3 *******************************************************


                gotoxy(21,7);
                cout<<"Ingrese El Nombre Del Paciente:                                ";
                ///si esta entre dos getline no lleva ignore
                gotoxy(52,7);
                cin.getline(reg.nombre, 50);

                while(reg.nombre[0]== '\0' ){
                gotoxy(21,7);
                cout<<"Ingrese Un Nombre Correcto:                                     ";
                gotoxy(48,7);
                cin.getline(reg.nombre,50);
                }


    // ************************************** INGRESO NUMERO 4 *******************************************************

        gotoxy(21,8);
        cout<<"Ingrese Genero Del Paciente      |Femenino|  |Masculino|  |Otros|    ";
        gotoxy(21,9);
        cout<<"                                 |   F    |  |    M    |  |  O   |:   ";
        gotoxy(88,9);
        cin>>reg.genero;
         if (reg.genero  == 'F'   || reg.genero  =='f' || reg.genero  == 'M' || reg.genero  == 'm' ||reg.genero  == 'O' || reg.genero  == 'o' )
    {
    }
    else
    {
        while( auxGen == true )
        {
            gotoxy(21,10);
            cout<<"INGRESE UN GENERO VALIDO:     ";
            gotoxy(46,10);
            cin>>reg.genero;
            if (reg.genero  == 'F'   || reg.genero  =='f' || reg.genero  == 'M' || reg.genero  == 'm' ||reg.genero  == 'O' || reg.genero  == 'o' )
            {
                auxGen = false;
            }  // IF
        }	 // WHILE
    }  // ELSE



    // ************************************** INGRESO NUMERO 6 FECHA ****************************************************






    reg.fecha_nacimiento=cargar_fecha();


    // ************************************** INGRESO NUMERO 6 *******************************************************


    gotoxy(21,13);
    cout<<"Ingrese La Obra Social Del Paciente:                                   ";
    gotoxy(57,13);
    cin>>reg.obra_social;

    while(reg.obra_social  <   1 || reg.obra_social > 50){
    gotoxy(21,13);
    cout<<"La Obra Social debe ser (1 al 50) - Ingrese Un Numero Valido:        ";
    gotoxy(82,13);
    cin>>reg.obra_social;
    }

    reg.estado=true;


    gotoxy(21,20);
    cout<<"------------------------------------------------------------------------";
    gotoxy(21,21);
    cout<<"                     PACIENTE AGREGADO CON EXITO                        ";
    gotoxy(21,22);
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


void GuardarPaciente(struct paciente reg){

    FILE *p;
    p = fopen("pacientes.dat", "ab");
    if (p == NULL)
    {
        cout<<"error en funcion guardar paciente"<<endl;
        exit(1);
    }
        fwrite(&reg, sizeof(reg),1,p);
    fclose(p);
    return ;
}

//====================================================================================================================
// FUNCION    :
// ACCION     :
// PARAMETROS :
//
//DEVUELVE    :
//====================================================================================================================



void modificarobrasocial(){

    int aux;
    FILE *p;
    struct paciente reg;

    system("cls");
    recuadro(20,1,75,25);
    gotoxy(45,2);
    cout<<" **** CLINICA SAN SIMON ****"<<endl;
    gotoxy(45,3);
    cout<<"    MODIFICAR OBRA SOCIAL    "<<endl;
    gotoxy(28,6);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(28,7);
    cout<<"Modificacion Obra Social de Paciente Mediante DNI"<<endl;
    gotoxy(28,8);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(28,9);
    cout<<"Ingrese El Dni Del Paciente a Modificar:         "<<endl;
    gotoxy(68,9);
    cin>>aux;



    while(buscardnipaciente(aux)==false){

        gotoxy(28,10);
        cout<<"No Existe Dni de Paciente - Ingrese Un Nuevo Dni:          "<<endl;
        gotoxy(77,10);
        cin>>aux;
    }



    if(buscardnipaciente(aux)==true){

        p=fopen("pacientes.dat","rb+");
        if(p==NULL){
            gotoxy(28,11);
            cout<<"Error en la funcion modificar obra social          ||"<<endl;
            exit(1);
        }

        while(fread(&reg,sizeof reg,1,p)){

            if(aux==reg.dni){

                fseek(p, -sizeof reg, 1 );      ///retrocede el puntero por que la lectura al final del registro

                gotoxy(28,11);
                cout<<"Ingrese La Nueva Obra Social del Paciente(1 al 50):          "<<endl;
                gotoxy(79,11);
                cin>>reg.obra_social;                                       ///se ingresa el dato a cargar

                while(reg.obra_social < 1 || reg.obra_social > 50 ){
                gotoxy(28,11);
                cout<<"Ingrese La Nueva Obra Social del Paciente(1 al 50):          "<<endl;
                gotoxy(79,11);
                cin>>reg.obra_social;
                }

                gotoxy(28,12);
                cout<<"-------------------------------------------------"<<endl;
                gotoxy(28,13);
                cout<<"*****  MODIFICACION DE OBRA SOCIAL EXITOSA  *****"<<endl;
                gotoxy(28,14);
                cout<<"-------------------------------------------------"<<endl;

                fwrite(&reg, sizeof(reg),1,p);      ///se sobre escribe en el mismo lugar
                fclose(p);
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





bool buscardnipaciente(int a){

    FILE *p;
    p=fopen("pacientes.dat","rb");
    struct paciente reg;
    if (p==NULL){
        exit(1);
    }                     ///If(p==NULL){if(contarregistros == 0){p=fopen(�archivo.dat�,�ab�);}
                          ///else {Cout<<�error de escritura�; exit(1);}}

    while(fread(&reg,sizeof(paciente),1,p)==1){
        if(reg.dni==a){
            fclose(p);
            return true;
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



///para modificar una variable tengo que buscarla
///cargar el dato que quiero modificar
///llevar el puntero de lectura a un struct anterior ?
///sobre escribir el campo viejo



int buscarposiciondni(int aux){

    int pos=0;
    paciente reg;
    FILE *p;
    p=fopen("pacientes.dat","rb");
    if( p == NULL)
    {
        cout<<"ERROR EN FUNCION BUSCAR POS X DNI" <<endl;
        exit(1);
    }
    while(fread(&reg,sizeof reg,1,p))
    {
        if(reg.dni == aux)
        {
            fclose(p);
            return pos;
        }

        pos++;
    }


    fclose(p);
    return pos;
}


//====================================================================================================================
// FUNCION    :
// ACCION     :
// PARAMETROS :
//
//DEVUELVE    :
//====================================================================================================================




void eliminarpaciente()
{
    FILE *p;
    int aux;
    struct paciente reg;
    cout<<"INGRESE DNI DEL PACIENTE A ELIMINAR"<<endl;
    cin>>aux;
    if(buscarposiciondni(aux) == false )
    {
        cout<<"DNI NO ENCONTRADO INGRESE UN DNI VALIDO"<<endl;
        cin>>aux;
    }

    if(buscardnipaciente(aux)==true){

        p=fopen("pacientes.dat","rb+");
        if(p==NULL){
            cout<<"ERROR EN FUNCION ELIMINAR PACIENTE"<<endl;
            exit(1);}

        while(fread(&reg,sizeof reg,1,p)){

            if(aux==reg.dni){

                fseek(p, -sizeof reg, 1 );      ///retrocede el puntero por que la lectura al final del registro
                reg.estado=false;
                fwrite(&reg, sizeof(reg),1,p);      ///se sobre escribe en el mismo lugar
                fclose(p);
            }
        }
     } // BUSCARDNIPACIENTE == TRUE
}


//====================================================================================================================
// FUNCION    :
// ACCION     :
// PARAMETROS :
//
//DEVUELVE    :
//====================================================================================================================


int contarregistrospaciente()
{
    FILE *p;
    long int peso_archivo;
    int cantidad_registros;
    struct paciente reg;
    p=fopen("pacientes.dat","rb");
    if(p==NULL)
    {
        cout<<"error al inicializar el archivo pacientes"<<endl;
        exit(1);
    }
    fseek(p, 0, SEEK_END);
    peso_archivo=ftell(p);
    cantidad_registros = peso_archivo / sizeof reg;
    return cantidad_registros;

}






#endif // PACIENTES_H_INCLUDED
