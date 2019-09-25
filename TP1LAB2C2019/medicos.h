#ifndef MEDICOS_H_INCLUDED
#define MEDICOS_H_INCLUDED

//Si quieren modificar el orden del codigo y les da error,solo deben agregar el prototipo de las funciones
//que no reconoce el compilador.Lo ideal es agregar  todas pero mientras que no de error no hace falta
//poner todos los prototipos.(ya puse todas)


void listarMedico(struct medicos,int);
bool buscarMatricula(int);
medicos CargarMedico();
void GuardarMedico(struct medicos);
void modificarmedicos();
void altamedicos();
int BuscarPosMatricula(int);
void listarmedicoxmatricula();
void listartodoslosmedicos();
medicos leer_medico();
int contarregistrosmedicos();
void sobreescribir_medico(struct medicos , int tam);

//-------------------------------------------------------------------------------------------------------------------
//
// **********************  SECCION REFERENTE AL LISTADO DE MEDICOS  *************************
//
//-------------------------------------------------------------------------------------------------------------------


//====================================================================================================================
// FUNCION    :listartodoslosmedicos.
// ACCION     :muestra por pantalla la informacion de todos los medicos cargados en el sistema.
// PARAMETROS :no necesita el envio de ningun parametro.
//
//DEVUELVE    :void.
//====================================================================================================================

void listartodoslosmedicos(){

    medicos reg;
    int modo=2;


        FILE *p;
        p=fopen("medicos.dat","rb");

        if(p==NULL){
            cout<<"error de funcion listar todos los medicos"<<endl;
            exit(1);
        }

            while(fread(&reg,sizeof reg,1,p)){
                listarMedico(reg,modo);
            }



    fclose(p);
    system("pause");

}


//====================================================================================================================
// FUNCION    :listarmedicoxmatricula.
// ACCION     :mostrar los datos de un medico con una matricula en especifico.
// PARAMETROS :no ecesita ningun el envio parametro.
//
//DEVUELVE    :void.
//====================================================================================================================

void listarmedicoxmatricula(){

        struct medicos reg;
        FILE *p;
        int aux;
        int modo=1;


        system("cls");
        recuadro(20,1,75,25);
        gotoxy(45,2);
        cout<<" **** CLINICA SAN SIMON ****";
        gotoxy(45,3);
        cout<<" LISTAR MEDICO POR MATRICULA";
        gotoxy(28,6);
        cout<<"----------------------------------------------------";
        gotoxy(28,7);
        cout<<"  Listar Medico Mediante una Determinada Matricula  ";
        gotoxy(28,8);
        cout<<"----------------------------------------------------";




        gotoxy(28,9);
        cout<<"Ingrese la Matricula a Listar:                         ";
        gotoxy(58,9);
        cin>>aux;


            while(buscarMatricula(aux)==false){
                gotoxy(28,9);
                cout<<"ERROR:No Existe Matricula, Ingrese Matricula Existente:          ";
                gotoxy(83,9);
                cin>>aux;
            }



        p=fopen("medicos.dat","rb");

            while(fread(&reg,sizeof reg,1,p)){

                if(reg.numero_matricula==aux){
                    listarMedico(reg,modo);
                    fclose(p);
                    return;
                }

             }




        fclose(p);
        return;

}


//====================================================================================================================
// FUNCION    :listarMedico.
// ACCION     :listar un la informacion por mantalla de un registro de tipo medico ,
//              con o sin recuadro en caso de ser necesario.
// PARAMETROS :un registro de tipo medico que se desee listar y un entero indicando la forma
//              en la que se desea listar dicha informacion.
//DEVUELVE    :void.
//====================================================================================================================
void listarMedico(struct medicos reg,int modo){


        if (modo == 1){

            gotoxy(28,10);
            cout<<"Apellido del medico: "<<reg.apellido;
            gotoxy(28,11);
            cout<<"Nombre del medico: "<<reg.nombre;
            gotoxy(28,12);
            cout<<"Especialidad: "<<reg.especialidad;
            gotoxy(28,13);
            cout<<"Sueldo: "<<reg.sueldo;
            gotoxy(28,14);
            cout<<"Matricula: "<<reg.numero_matricula;
            gotoxy(28,19);
            cout<<"-------------------------------------------------";
            gotoxy(28,20);
            cout<<" **** FIN LISTADO DE MEDICO POR MATRICULA  ****  ";
            gotoxy(28,21);
            cout<<"-------------------------------------------------";





        }else{  //LISTAMOS TODO EN PANTALLA VACIA SIN RECUADRO

            //gotoxy(28,10);
            cout<<"Apellido del medico: "<<reg.apellido<<endl;
            //gotoxy(28,11);
            cout<<"Nombre del medico: "<<reg.nombre<<endl;
            //gotoxy(28,12);
            cout<<"Especialidad: "<<reg.especialidad<<endl;
            //gotoxy(28,13);
            cout<<"Sueldo: "<<reg.sueldo<<endl;
            //gotoxy(28,14);
            cout<<"Matricula: "<<reg.numero_matricula<<endl;
            cout<<"====================="<<endl;

          }



    return;

}



//-------------------------------------------------------------------------------------------------------------------
//
// **********************   SECCION DE ALTA/BAJA/MODIFICACION Y BUSQUEDA DE MEDICOS  *********************
//
//-------------------------------------------------------------------------------------------------------------------

void altamedicos(){

    medicos reg;
    reg=CargarMedico();
    GuardarMedico(reg);
    return;
}



//====================================================================================================================
// FUNCION    :Cargarmedico.
// ACCION     :solicitarle informacion al usuario para cargar un registro de tipo "medicos".
// PARAMETROS :no necesita ningun parametro.
//
//DEVUELVE    :void.
//====================================================================================================================

medicos CargarMedico(){

    struct medicos reg;
    int aux;
    system("cls");
    recuadro(20,1,75,25);


    gotoxy(45,2);
    cout<<" **** CLINICA SAN SIMON ****";
    gotoxy(45,3);
    cout<<"      ALTA DE MEDICOS     ";


    // ************************************** VALIDACION NUMERO 1 *******************************************************

    gotoxy(21,5);
    cout<<"Ingrese La Matricula Del Medico:                        ";
    gotoxy(53,5);
    cin>>reg.numero_matricula;
    aux=reg.numero_matricula;


    while(reg.numero_matricula < 1 || buscarMatricula(aux)==true  ){

            gotoxy(21,5);
            cout<<"Ingrese Un Numero De Matricula Valida:                  ";
            gotoxy(59,5);
            cin>>reg.numero_matricula;
            aux=reg.numero_matricula;


                while(buscarMatricula(aux)==true  ){

                    gotoxy(21,5);
                    cout<<"Matricula Duplicada - Por Favor,Ingrese Matricula Unica:                ";
                    gotoxy(77,5);
                    cin>>reg.numero_matricula;
                    aux=reg.numero_matricula;

                  }

          }




    // ************************************** VALIDACION NUMERO 2 *******************************************************



        gotoxy(21,6);
        cout<<"Ingrese El Apellido Del Medico:                             ";
        cin.ignore();
        gotoxy(52,6);
        cin.getline(reg.apellido, 50);


            while(reg.apellido[0]== '\0' ){
                    gotoxy(21,6);
                    cout<<"Ingrese un Apellido Correcto:                            ";
                    gotoxy(50,6);
                    cin.getline(reg.apellido,50);
               }


        // ************************************** VALIDACION NUMERO 3 *******************************************************


        gotoxy(21,7);
        cout<<"Ingrese el Nombre del Medico:                          ";
        gotoxy(50,7);
        cin.getline(reg.nombre, 50);


                        while(reg.nombre[0]== '\0' ){
                            gotoxy(21,7);
                            cout<<"Ingrese un Nombre Correcto:                     ";
                            gotoxy(48,7);
                            cin.getline(reg.nombre,50);
                        }



        // ************************************** VALIDACION NUMERO 4 *******************************************************



        ///si esta entre dos getline no lleva ignore

        gotoxy(21,8);
        cout<<"Ingrese la Especialidad del Medico(1 al 20):                          ";
        gotoxy(65,8);
        cin>>reg.especialidad;


            while(reg.especialidad < 1 || reg.especialidad > 20  ){

                        gotoxy(21,8);
                        cout<<"La Especialidad Debe ser Numero entre(1 y 20):                     ";
                        gotoxy(67,8);
                        cin>>reg.especialidad;
                    }



        // ************************************** VALIDACION NUMERO 5 *******************************************************


        gotoxy(21,9);
        cout<<"Ingrese el Sueldo del Medico:               ";
        gotoxy(50,9);
        cin>>reg.sueldo;

                while(reg.sueldo < 1  ){

                    gotoxy(21,9);
                    cout<<"Ingrese un Monto Valido:               ";
                    gotoxy(45,9);
                    cin>>reg.sueldo;
                }





            gotoxy(21,20);
            cout<<"------------------------------------------------------------------------";
            gotoxy(21,21);
            cout<<"                     MEDICO AGREGADO CON EXITO                          ";
            gotoxy(21,22);
            cout<<"-----------------------------------------------------------------------";
            gotoxy(20,27);
            system("pause");



        return reg;

}


//====================================================================================================================
// FUNCION    :GuardarMedico.
// ACCION     :guarda un registro de tipo medico en el archivo "medicos.dat"
// PARAMETROS :necesita que se le envie como parametro el registro de tipo medico que se
//              desea guardar.
//DEVUELVE    :void.
//====================================================================================================================

void GuardarMedico(struct medicos reg){

    FILE *p;
    p = fopen("medicos.dat", "ab");
    if (p == NULL)
    {
        cout<<"error en funcion guardarMedico"<<endl;
        exit(1);
    }


    fwrite(&reg, sizeof(reg),1,p);
    fclose(p);
    return ;

}



//====================================================================================================================
// FUNCION    :modificarmedicos.
// ACCION     :cambiar el sueldo de un medico.
// PARAMETROS :no necesita el envio de ningun parametro.
//
//DEVUELVE    :void.
//====================================================================================================================

void modificarmedicos(){

    int aux;
    FILE *p;
    struct medicos reg;


    system("cls");
    recuadro(20,1,75,25);
    gotoxy(45,2);
    cout<<" **** CLINICA SAN SIMON ****"<<endl;
    gotoxy(45,3);
    cout<<"       MODIFICAR SUELDO    "<<endl;
    gotoxy(28,6);
    cout<<"-----------------------------------------------------"<<endl;
    gotoxy(28,7);
    cout<<"Modificacion de Sueldo del Medico Mediante Matricula"<<endl;
    gotoxy(28,8);
    cout<<"-----------------------------------------------------"<<endl;




    gotoxy(28,9);
    cout<<"Ingrese un Numero de Matricula:           ";
    gotoxy(59,9);
    cin>>aux;




    while(buscarMatricula(aux)==false   ){

                gotoxy(28,9);
                cout<<"ERROR:No Existe Matricula, Ingrese Matricula Existente:       "<<endl;
                gotoxy(83,9);
                cin>>aux;
            }


            p=fopen("medicos.dat","rb+");

            if(p==NULL){
                exit(1);
            }

                    while(fread(&reg,sizeof reg,1,p)){

                        if(reg.numero_matricula==aux){

                            gotoxy(28,10);
                            cout<<"Ingrese el Nuevo Sueldo del Medico:             "<<endl;
                            gotoxy(63,10);
                            cin>>reg.sueldo;

                        while ( reg.sueldo < 0 ){

                            gotoxy(28,10);
                            cout<<"Ingrese un Sueldo Valido:                                  "<<endl;
                            gotoxy(53,10);
                            cin>>reg.sueldo;

                        }



                            fseek(p,-sizeof reg,1);
                            fwrite(&reg, sizeof(reg),1,p);
                            fclose(p);

                            gotoxy(28,12);
                            cout<<"-------------------------------------------------"<<endl;
                            gotoxy(28,13);
                            cout<<"*****     MODIFICACION DE SUELDO EXITOSA  *****  " <<endl;
                            gotoxy(28,14);
                            cout<<"-------------------------------------------------"<<endl;

                            return;
                         }

                   }



        fclose(p);
        return; ///por si en el segundo cin se vuelven a confundir
}



//====================================================================================================================
// FUNCION    :contarregistrosmedicos.
// ACCION     :contar la cantidad de registros que contiene el archivo "medicos,dat"
// PARAMETROS :no necesita ningun parametro.
//
//DEVUELVE    :una variable de tipo int que representa la cantidad de registros en el archivo
//              "medicos.dat"
//====================================================================================================================

int contarregistrosmedicos(){

    FILE *p;
    long int peso_archivo;
    int cantidad_registros;
    struct medicos reg;
    p=fopen("medicos.dat","ab");
    if(p==NULL)
    {
        cout<<"error al inicializar el archivo medicos ";
        exit(1);
    }
    fseek(p, 0, SEEK_END);
    peso_archivo=ftell(p);
    fclose(p);
    cantidad_registros = peso_archivo / sizeof reg;
    return cantidad_registros;

}


//====================================================================================================================
// FUNCION    :BuscarPosMatricula.
// ACCION     :busca la en el archivo "medicos.dat" que numero de registro ocupa la matricula
//              enviada como parametro.
// PARAMETROS :una variable de tipo entero que contiene la variable que se desea validar
//              su existencia
//
//DEVUELVE    : una variable de tipo entero que representa el numero de registro en el cual
//              se encontro la matricula que se deseaba buscar.
//====================================================================================================================

int BuscarPosMatricula(int aux){

    int pos=0;
    medicos reg;
    FILE *p;
    p=fopen("medicos.dat","rb");
    if( p == NULL)
    {
        cout<<"ERROR EN FUNCION BUSCAR POS X MATRICULA" <<endl;
        exit(1);
    }
    while(fread(&reg,sizeof reg,1,p))
    {
        if(reg.numero_matricula == aux)
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
// FUNCION    :buscarmatricula.
// ACCION     :busca si existe una matricula en el archivo "medicos.dat".
// PARAMETROS :un entero que contenga el numero de matricula.
//DEVUELVE    :booleano , verdadero en caso de haber encontrado la matricula en el archivo
//              , false en caso contrario
//====================================================================================================================

bool buscarMatricula(int a){

    struct medicos reg;

        FILE *p;

        p=fopen("medicos.dat","rb");

        if(p==NULL){
            exit(1);
        }

            while(fread(&reg,sizeof reg,1,p)==1){
                if(reg.numero_matricula==a){
                    fclose(p);
                    return true;    ///retorna verdadero si la matricula ya existe en el archivo
                }
            }


    fclose(p);

    return false;   ///retorna falso en caso de no encontrar la matricula buscada
}

//====================================================================================================================
// FUNCION    :leer_medico.
// ACCION     :lee un registro de tipo medico del archivo "medicos.dat".
// PARAMETROS :no necesita el envio de ningun parametro.
//DEVUELVE    :un registro de tipo medico con informacion obtenida del disco.
//====================================================================================================================

medicos leer_medico(int pos){
FILE *p;
    struct medicos reg;

    p=fopen("pacientes.dat","rb");

    if(p==NULL)
    {

        cout<<"error de archivo en la funcion leer medico"<<endl;

        exit(1);
    }

    fseek(p, sizeof(medicos)*pos, 0);  ///lleva el puntero a la posicion indicada por "pos"
    fread(&reg, sizeof(medicos), 1, p);   ///lee el registro elegido
    fclose(p);

    return reg; ///devuelve en una variable de tipo reg lo leido del disco
}

//====================================================================================================================
// FUNCION    :sobreescribir_medico.
// ACCION     :guarda un registro de tipo medico en el archivo "medicos.dat" un una pocision deseada.
// PARAMETROS :un registro de tipo medico que se desee guardar
//              y una variable de tipo entero que indique la pocision sobre la cual guardar.
//DEVUELVE    :un registro de tipo medico con informacion obtenida del disco.
//====================================================================================================================

void sobreescribir_medico(medicos reg,int pos){
  FILE *p;
  p = fopen("medicos.dat", "rb+");
  if (p == NULL){
     cout<<"error en funicon sobreescribir medico"<<endl;
             exit(1);
    }

  fseek(p, sizeof(medicos)*pos, 0);
  fwrite(&reg, sizeof(medicos), 1, p);
  fclose(p);
    cout<<"MEDICO MODIFICADO CON EXITO"<<endl;
}



#endif // MEDICOS_H_INCLUDED
