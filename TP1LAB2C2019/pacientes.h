#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED



bool buscardnipaciente(int a)
{
    FILE *p;
    p=fopen("pacientes.dat","rb");
    if (p==NULL)
    {
        cout<<"error de archivo en la funcion buscardnipaciente"<<endl;
        exit(1);
    }
    struct paciente reg;
    while(fread(&reg,sizeof(paciente),1,p)==1)
    {
        if(reg.dni==a)
        {
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}

void listarpaciente(paciente reg)
{
    cout<<"====================="<<endl;
    cout<<"Apellido del paciente: "<<reg.apellido<<endl;
    cout<<"Nombre del paciente: "<<reg.nombre<<endl;
    cout<<"Fecha de nacimiento: "<<reg.fecha_nacimiento.dia<<"/"<<reg.fecha_nacimiento.mes<<"/"<<reg.fecha_nacimiento.anio<<endl;
    cout<<"Dni del paciente: "<<reg.dni<<endl;
    cout<<"Obra social del paciende: "<<reg.obra_social<<endl;
    cout<<"Genero del paciende: "<<reg.genero<<endl;
    return;
}

void GuardarPaciente(struct paciente reg)
{
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

paciente CargarPaciente()
{

    struct paciente reg;
    int aux;

    cout<<"INGRESE EL DNI DEL PACIENTE"<<endl;
    cin>>reg.dni;
    aux=reg.dni;
    if(reg.dni<1) {}
    if(buscardnipaciente(aux)==true)
    {
        cout<<"el dni del paciente no puede estar duplicado , ingrese un numero valido"<<endl;
        cin>>reg.dni;
    }

    cout<<"INGRESE EL APELLIDO DEL PACIENTE"<<endl;
    cin.ignore();
    cin.getline(reg.apellido, 50);
    cout<<"INGRESE EL NOMBRE DEL PACIENTE"<<endl;

    ///si esta entre dos getline no lleva ignore

    cin.getline(reg.nombre, 50);
    cout<<"INGRESE EL GENERO DEL PACIENTE"<<endl;
    cin>>reg.genero;
    if(reg.genero != 'M' )
    {
        cout<<"INGRESE UN GENERO VALIDO"<<endl;
        cin>>reg.genero;
    }
    if(reg.genero != 'F' )
    {
        cout<<"INGRESE UN GENERO VALIDO"<<endl;
        cin>>reg.genero;
    }
    if(reg.genero != 'O' )
    {
        cout<<"INGRESE UN GENERO VALIDO"<<endl;
        cin>>reg.genero;
    }
    if(reg.genero != 'm' )
    {
        cout<<"INGRESE UN GENERO VALIDO"<<endl;
        cin>>reg.genero;
    }
    if(reg.genero != 'f' )
    {
        cout<<"INGRESE UN GENERO VALIDO"<<endl;
        cin>>reg.genero;
    }
    if(reg.genero != 'o' )
    {
        cout<<"INGRESE UN GENERO VALIDO"<<endl;
        cin>>reg.genero;
    }

    cout<<"INGRESE EL DIA DE NACIMIENTO DEL PACIENTE"<<endl;
    cin>>reg.fecha_nacimiento.dia;
    if(reg.fecha_nacimiento.dia>31 || reg.fecha_nacimiento.dia<1)
    {
        cout<<"INGRESE UN NUMERO DE NACIMIENTO VALIDO"<<endl;
        cin>>reg.fecha_nacimiento.dia;
    }
    cout<<"INGRESE EL MES DE NACIMIENTO DEL PACIENTE"<<endl;
    cin>>reg.fecha_nacimiento.mes;
    if(reg.fecha_nacimiento.mes > 12 || reg.fecha_nacimiento.mes < 1)
    {
        cout<< "INGRESE UN MES DE NACIMIENTO VALIDO"<<endl;
        cin>>reg.fecha_nacimiento.mes;
    }
    cout<<"INGRESE EL ANIO DE NACIMIENTO DEL PACIENTE"<<endl;
    cin>>reg.fecha_nacimiento.anio;
    if(reg.fecha_nacimiento.anio < 1900 || reg.fecha_nacimiento.anio > 2019 )
    {
        cout<<"INGRESE UN ANIO DE NACIMIENTO VALIDO"<<endl;
        cin>>reg.fecha_nacimiento.anio;
    }
    cout<<"INGRESE LA OBRA SOCIAL DEL PACIENTE"<<endl;
    cin>>reg.obra_social;
    if(reg.obra_social  >   1 || reg.obra_social > 50)
    {
        cout<<"LA OBRA SOCIAL DEBE SER UN NUMERO ENTRE 1 Y 50, INGRESE UN NUMERO VALIDO"<<endl;
        cin>>reg.obra_social;
    }

    reg.estado=true;

    return reg;
}


void altaPaciente()
{
    paciente reg;
    reg=CargarPaciente();
    GuardarPaciente(reg);
    return;
}

void listartodoslospacientes()
{
    paciente reg;
    FILE *p;
    p=fopen("pacientes.dat","rb");
    if(p==NULL)
    {
        cout<<"error de funcion listar todos los pacientes"<<endl;
        exit(1);
    }
    while(fread(&reg,sizeof reg,1,p))
    {

        if(reg.estado==true)
        {
            listarpaciente(reg);
        }
    }
    fclose(p);
    system("pause");
}

///para modificar una variable tengo que buscarla
///cargar el dato que quiero modificar
///llevar el puntero de lectura a un struct anterior ?
///sobre escribir el campo viejo

void modificarobrasocial()
{
    int aux;
    FILE *p;
    struct paciente reg;
    cout<<"INGRESE EL DNI DEL PACIENTE A MODIFICAR OBRA SOCIAL"<<endl;
    cin>>aux;
    if(buscardnipaciente(aux)==false)
    {
        cout<<"NO SE ENCONTRO EL DNI DEL PACIENTE A MODIFICAR INGRESE UN NUEVO DNI"<<endl;
        cin>>aux;
    }

    if(buscardnipaciente(aux)==true)
    {
        p=fopen("pacientes.dat","rb+");
        if(p==NULL)
        {
            cout<<"error en la funcion modificar obra social"<<endl;
            exit(1);
        }
        while(fread(&reg,sizeof reg,1,p))
        {
            if(aux==reg.dni)
            {
                fseek(p, -sizeof reg, 1 );      ///retrocede el puntero por que la lectura al final del registro
                cout<<"INGRESE LA NUEVA OBRA SOCIAL DEL PACIENTE"<<endl;
                cin>>reg.obra_social;                                       ///se ingresa el dato a cargar
                if(reg.obra_social < 1 || reg.obra_social > 50 )
                {
                    cout<<"ingrese una obra social valida"<<endl;
                    cin>>reg.obra_social;
                }
                fwrite(&reg, sizeof(reg),1,p);      ///se sobre escribe en el mismo lugar
                fclose(p);
            }
        }


    }
    fclose(p);
}




int buscarposiciondni(int aux)
{
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


void listarpacientepordni()
{
    struct paciente reg;
    int aux;
    FILE *p;

    cout<<"INGRESE EL DNI DEL PACIENTE A LISTAR"<<endl;
    cin>>aux;
    if(buscardnipaciente(aux)==false)
    {
        cout<<"DNI NO ENCONTRADO INGRESE UN DNI VALIDO"<<endl;
        cin>>aux;
    }

    p=fopen("pacientes.dat","rb");
    if(p==NULL)
    {
        cout<<"error en la funcion listar paciente x dni "<<endl;
        exit(1);
    }
    while(fread(&reg,sizeof reg,1,p))
    {
        if(aux==reg.dni)
        {
            listarpaciente(reg);
            fclose(p);
            return;
        }
    }
    fclose(p);
    return;
}


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

    if(buscardnipaciente(aux)==true)
    {
        p=fopen("pacientes.dat","rb+");
        if(p==NULL)
        {
            cout<<"ERROR EN FUNCION ELIMINAR PACIENTE"<<endl;
            exit(1);
        }
        while(fread(&reg,sizeof reg,1,p))
        {
            if(aux==reg.dni)
            {
                fseek(p, -sizeof reg, 1 );      ///retrocede el puntero por que la lectura al final del registro
                reg.estado=false;
                fwrite(&reg, sizeof(reg),1,p);      ///se sobre escribe en el mismo lugar
                fclose(p);
            }
        }
    }
}
#endif // PACIENTES_H_INCLUDED
