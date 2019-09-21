#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED


void restaurar_controles()
{
    controles reg;

    FILE  *pback,*p;
    pback=fopen("bck/backupControles.dat","rb");
    if(pback==NULL)
    {
        cout<<"No existe archivo para poder realizar la restauracion de controles"<<endl;
        return ;
    }
    p=fopen("controles.dat","wb");
    if(p==NULL)
    {
        return ;
    }
    fclose(p);
    p=fopen("controles.dat","ab");
    if(p==NULL)
    {
        return ;
    }
    while(fread(&reg,sizeof(controles),1,pback)==1)
    {

        fwrite(&reg,sizeof(controles),1,p);
    }
    cout<<"Se restauro el archivo controles.dat con exito!"<<endl;
    fclose(p);
    fclose(pback);
    return;
}


void restaurar_medicos()
{
    medicos reg;

    FILE  *pback,*p;
    pback=fopen("bck/backupMedicos.dat","rb");
    if(pback==NULL)
    {
        cout<<"No existe archivo para poder realizar la restauracion de medicos"<<endl;
        return ;
    }
    p=fopen("medicos.dat","wb");
    if(p==NULL)
    {
        return ;
    }
    fclose(p);
    p=fopen("medicos.dat","ab");
    if(p==NULL)
    {
        return ;
    }
    while(fread(&reg,sizeof(medicos),1,pback)==1)
    {

        fwrite(&reg,sizeof(medicos),1,p);
    }
    cout<<"Se restauro el archivo medicos.dat con exito!"<<endl;
    fclose(p);
    fclose(pback);
    return;
}


void restaurar_pacientes()
{
    paciente reg;

    FILE  *pback,*p;
    pback=fopen("bck/backupPacientes.dat","rb");
    if(pback==NULL)
    {
        cout<<"No existe archivo para poder realizar la restauracion de Pacientes"<<endl;
        return ;
    }
    p=fopen("pacientes.dat","wb");
    if(p==NULL)
    {
        return ;
    }
    fclose(p);
    p=fopen("pacientes.dat","ab");
    if(p==NULL)
    {
        return ;
    }
    while(fread(&reg,sizeof(paciente),1,pback)==1)
    {

        fwrite(&reg,sizeof(paciente),1,p);
    }
    cout<<"Se restauro el archivo pacientes.dat con exito!"<<endl;
    fclose(p);
    fclose(pback);
    return;
}



void bckControles()
{
    controles reg;
    FILE  *pback,*p;
    p=fopen("controles.dat","rb");
    if(p==NULL)
    {
        cout<<"El archivo controles.dat no existe"<<endl;
        return ;
    }
    pback=fopen("bck/backupControles.dat","wb");
    if(pback==NULL)
    {
        return ;
    }
    fclose(pback);
    pback=fopen("bck/backupControles.dat","ab");
    if(pback==NULL)
    {
        return ;
    }
    while(fread(&reg,sizeof(controles),1,p)==1)
    {

        fwrite(&reg,sizeof(controles),1,pback);
    }
    cout<<"Se realizo backup del archivo controles.dat con exito!"<<endl;
    fclose(p);
    fclose(pback);
    return;
}



void bckMedicos()
{
    medicos reg;
    FILE  *pback,*p;
    p=fopen("medicos.dat","rb");
    if(p==NULL)
    {
        cout<<"El archivo medicos.dat no existe"<<endl;
        return ;
    }
    pback=fopen("bck/backupMedicos.dat","wb");
    if(pback==NULL)
    {
        return ;
    }
    fclose(pback);
    pback=fopen("bck/backupMedicos.dat","ab");
    if(pback==NULL)
    {
        return ;
    }
    while(fread(&reg,sizeof(medicos),1,p)==1)
    {

        fwrite(&reg,sizeof(medicos),1,pback);
    }
    cout<<"Se realizo backup del archivo medicos.dat con exito!"<<endl;
    fclose(p);
    fclose(pback);
    return;
}

void bckPacientes()
{
    paciente reg;
    FILE  *pback,*p;
    p=fopen("pacientes.dat","rb");
    if(p==NULL)
    {
        cout<<"El archivo controles.dat no existe"<<endl;
        return ;
    }
    pback=fopen("bck/backupPacientes.dat","wb");
    if(pback==NULL)
    {
        return ;
    }
    fclose(pback);
    pback=fopen("bck/backupPacientes.dat","ab");
    if(pback==NULL)
    {
        return ;
    }
    while(fread(&reg,sizeof(paciente),1,p)==1)
    {

        fwrite(&reg,sizeof(paciente),1,pback);
    }
    cout<<"Se realizo backup del archivo Pacientes.dat con exito!"<<endl;
    fclose(p);
    fclose(pback);
    return;
}

#endif // CONFIGURACION_H_INCLUDED
