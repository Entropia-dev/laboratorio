#ifndef MEDICOS_H_INCLUDED
#define MEDICOS_H_INCLUDED







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
            return true;
        }
    }
    fclose(p);
    return false;///por que retorna falso??
}


void listarMedico(struct medicos reg)
{
    cout<<"====================="<<endl;
    cout<<"Apellido del medico: "<<reg.apellido<<endl;
    cout<<"Nombre del medico: "<<reg.nombre<<endl;
    cout<<"Especialidad: "<<reg.especialidad<<endl;
    cout<<"Sueldo: "<<reg.sueldo<<endl;
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

    struct medicos reg;
    int aux;

    cout<<"INGRESE LA MATRICULA DEL MEDICO"<<endl;
    cin>>reg.numero_matricula;
    aux=reg.numero_matricula;

    if(buscarMatricula(aux)==true)
    {
        cout<<"la matricula del medico no puede estar duplicado , ingrese un numero valido"<<endl;
        cin>>reg.numero_matricula;
    }

    cout<<"INGRESE EL APELLIDO DEL MEDICO: "<<endl;
    cin.ignore();
    cin.getline(reg.apellido, 50);
    cout<<"INGRESE EL NOMBRE DEL MEDICO: "<<endl;

    ///si esta entre dos getline no lleva ignore

    cin.getline(reg.nombre, 50);
    cout<<"INGRESE LA ESPECIALIDAD DEL MEDICO: "<<endl;
    if(reg.especialidad < 0 || reg.especialidad > 20 )
    {
        cout<<"INGRESE UN CARACTER VALIDO ENTRE 1 Y 20"<<endl;
        cin>>reg.especialidad;
    }
    cin>>reg.especialidad;

    cout<<"INGRESE El SUELDO: "<<endl;
    cin>>reg.sueldo;
    if(reg.sueldo<0)
    {
        cout<<"INGRESE UN MONTO VALIDO"<<endl;
        cin>>reg.sueldo;
    }


    return reg;
}

void altamedicos()
{
    medicos reg;
    reg=CargarMedico();
    GuardarMedico(reg);
    return;
}

#endif // MEDICOS_H_INCLUDED
