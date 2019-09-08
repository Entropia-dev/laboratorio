#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED



bool buscardnipaciente(int a)
{
    FILE *p;
    p=fopen("pacientes.dat","rb");
    struct paciente reg;
    if (p==NULL)
    {
        exit(1);
    }                     ///If(p==NULL){if(contarregistros == 0){p=fopen(“archivo.dat”,”ab”);}
    ///else {Cout<<“error de escritura”; exit(1);}}
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
    bool auxGen=true;
    struct paciente reg;
    int aux;

    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"||                        CLINICA SAN SIMON                               ||"<<endl;
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"||INGRESE EL DNI DEL PACIENTE:                                            ||"<<endl;
    cin>>reg.dni;
    aux=reg.dni;
    if(reg.dni<1)
    {
        ;
        cout<<"||INGRESE UN NUMERO DE DNI VALIDO:                                            ||"<<endl;
        cin>>reg.dni;
    }
    if(buscardnipaciente(aux)==true)
    {
        cout<<"||El dni del paciente no puede estar duplicado"<<endl;
        cout<<"||Ingrese un numero valido: "<<endl;
        cin>>reg.dni;
    }
    cout<<"||INGRESE EL APELLIDO DEL PACIENTE:                                       ||"<<endl;
    cin.ignore();
    cin.getline(reg.apellido, 50);
    while(reg.apellido[0]== '\0' )
    {
        cout<<endl;
        cout<<"INGRESE UN APELLIDO CORRECTO"<<endl;
        cin.getline(reg.apellido,50);
    }
    cout<<"||INGRESE EL NOMBRE DEL PACIENTE:                                         ||"<<endl;
    ///si esta entre dos getline no lleva ignore

    cin.getline(reg.nombre, 50);
    while(reg.nombre[0]== '\0' )
    {
        cout<<endl;
        cout<<"INGRESE UN NOMBRE CORRECTO"<<endl;
        cin.getline(reg.nombre,50);
    }
    cout<<"||INGRESE EL GENERO DEL PACIENTE      Femenino * Masculino * Otro         ||"<<endl;

    cout<<"||                                      F            M            O:      ||";
    cin>>reg.genero;
    if (reg.genero  == 'F'   || reg.genero  =='f' || reg.genero  == 'M' || reg.genero  == 'm' ||reg.genero  == 'O' || reg.genero  == 'o' )
    {
    }
    else
    {
        while( auxGen == true )
        {
            cout<<"INGRESE UN GENERO VALIDO";
            cin>>reg.genero;
            if (reg.genero  == 'F'   || reg.genero  =='f' || reg.genero  == 'M' || reg.genero  == 'm' ||reg.genero  == 'O' || reg.genero  == 'o' )
            {
                auxGen = false;
            }  // IF
        }	 // WHILE
    }  // ELSE

    reg.fecha_nacimiento=cargar_fecha();
    cout<<"||INGRESE LA OBRA SOCIAL DEL PACIENTE:                                    ||"<<endl;
    cin>>reg.obra_social;
    if(reg.obra_social  <   1 || reg.obra_social > 50)
    {
        cout<<"||LA OBRA SOCIAL DEBE SER UN NUMERO ENTRE 1 Y 50, INGRESE UN NUMERO VALIDO"<<endl;
        cin>>reg.obra_social;
    }

    reg.estado=true;


    cout<<"||------------------------------------------------------------------------||"<<endl;
    cout<<"||PACIENTE AGREGADO CON EXITO                                             ||"<<endl;
    cout<<"||------------------------------------------------------------------------||"<<endl;
    system("pause");
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
