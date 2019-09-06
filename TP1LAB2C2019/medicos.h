#ifndef MEDICOS_H_INCLUDED
#define MEDICOS_H_INCLUDED




int contarregistrosmedicos(){
FILE *p;
long int peso_archivo;
int cantidad_registros;
struct medicos reg;
    p=fopen("medicos.dat","ab");
    if(p==NULL){cout<<"error al inicializar el archivo medicos "; exit(1);}
     fseek(p, 0 , SEEK_END);
    peso_archivo=ftell(p);
    fclose(p);
   cantidad_registros = peso_archivo / sizeof reg;
    return cantidad_registros;

}



///buscar la posicion de la matricula
int BuscarPosMatricula(int aux)
{
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

///busca el numero de matricula del medico

bool buscarMatricula(int a)
{
    FILE *p;
    p=fopen("medicos.dat","rb");

    struct medicos reg;
    while(fread(&reg,sizeof reg,1,p)==1)
    {
        if(reg.numero_matricula==a)
        {
            fclose(p);
            return true;    ///retorna verdadero si la matricula ya existe en el archivo
        }
    }
    fclose(p);
    return false;   ///retorna falso en caso de no encontrar la matricula buscada
}


void listarMedico(struct medicos reg)
{
    cout<<"====================="<<endl;
    cout<<"Apellido del medico: "<<reg.apellido<<endl;
    cout<<"Nombre del medico: "<<reg.nombre<<endl;
    cout<<"Especialidad: "<<reg.especialidad<<endl;
    cout<<"Sueldo: "<<reg.sueldo<<endl;
    cout<<"Matricula: "<<reg.numero_matricula<<endl;
    cout<<"                   "<<endl;
    return;
}


void GuardarMedico(struct medicos reg)
{
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



medicos CargarMedico()
{

 recuadro(50, 1, 40, 16, cBLANCO, cMAGENTA);
    struct medicos reg;
    int aux;
         gotoxy(51,3);
    cout<<"INGRESE LA MATRICULA DEL MEDICO"<<endl;
            gotoxy(51,4);
    cin>>reg.numero_matricula;
    aux=reg.numero_matricula;

    if(buscarMatricula(aux)==true)
    {
        cout<<"la matricula del medico no puede estar duplicado , ingrese un numero valido"<<endl;
        cin>>reg.numero_matricula;
    }
    gotoxy(51,5);
    cout<<"INGRESE EL APELLIDO DEL MEDICO: "<<endl;
    gotoxy(51,6);
    cin.ignore();
    cin.getline(reg.apellido, 50);
            gotoxy(51,7);
    cout<<"INGRESE EL NOMBRE DEL MEDICO: "<<endl;
        gotoxy(51,8);
    ///si esta entre dos getline no lleva ignore

    cin.getline(reg.nombre, 50);
     gotoxy(51,9);
    cout<<"INGRESE LA ESPECIALIDAD DEL MEDICO: "<<endl;
      gotoxy(51,10);
    cin>>reg.especialidad;
    if(reg.especialidad < 0 || reg.especialidad > 20 )
    {
        cout<<"INGRESE UN CARACTER VALIDO ENTRE 1 Y 20"<<endl;
        cin>>reg.especialidad;
    }
    gotoxy(51,11);
    cout<<"INGRESE El SUELDO: "<<endl;
    gotoxy(51,12);
    cin>>reg.sueldo;
    if(reg.sueldo<0)
    {
        cout<<"INGRESE UN MONTO VALIDO"<<endl;
        cin>>reg.sueldo;
    }
        gotoxy(51,13);
        cout<<"MEDICO CARGADO CON EXITO"<<endl;
    system("pause");
    return reg;
}

void altamedicos()
{
    medicos reg;
    reg=CargarMedico();
    GuardarMedico(reg);
    return;
}

void modificarmedicos(){
int aux;
FILE *p;
struct medicos reg;
cout<<"INGRESE UN NUMERO DE MATRICULA"<<endl;
cin>>aux;
if(buscarMatricula(aux)==false){cout<<"EL NUMERO DE MATRICULA NO EXISTE , INGRESE UN NUMERO VALIDO"<<endl;
                                cin>>aux;}
    p=fopen("medicos.dat","rb+");
    while(fread(&reg,sizeof reg,1,p)){
        if(reg.numero_matricula==aux){
            cout<<"INGRESE EL NUEVO SUELDO DEL MEDICO"<<endl;
            cin>>reg.sueldo;
            fseek(p,-sizeof reg,1);
             fwrite(&reg, sizeof(reg),1,p);
             fclose(p);
             return;
            }

        }
            fclose(p);  return; ///por si en el segundo cin se vuelven a confundir
}

void listartodoslosmedicos(){
    medicos reg;
    FILE *p;
    p=fopen("medicos.dat","rb");
    if(p==NULL)
    {
        cout<<"error de funcion listar todos los medicos"<<endl;
        exit(1);
    }
    while(fread(&reg,sizeof reg,1,p))
    {
            listarMedico(reg);
    }
    fclose(p);
    system("pause");
}


void listarmedicoxmatricula(){
struct medicos reg;
FILE *p;
int aux;
cout<<"INGRESE LA MATRICULA A LISTAR"<<endl;
cin>>aux;
if(buscarMatricula(aux)==false){cout<<"NO SE ENCONTRO LA MATRICULA BUSCADA, INGRESE UNA NUEVA MATRICULA"<<endl;
                                    cin>>aux;}

    p=fopen("medicos.dat","rb");
    while(fread(&reg,sizeof reg,1,p)){
        if(reg.numero_matricula==aux){
            listarMedico(reg);
            fclose(p);
            system("pause");
            }
        }
                fclose(p);
}


#endif // MEDICOS_H_INCLUDED
