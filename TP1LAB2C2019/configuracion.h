#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED


void restaurar_controles();
void restaurar_medicos();
void restaurar_pacientes();
void bckControles();
void bckMedicos();
void bckPacientes();



void restaurar_controles()
{


    recuadro(20,1,75,25);

    gotoxy(45,2);
    cout<<" **** CLINICA SAN SIMON ****";
    gotoxy(45,3);
    cout<<"      RESTAURAR BACKUP     ";



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

    gotoxy(21,5);
    cout<<"Se Restauro El Archivo Controles.dat Con Exito!"<<endl;

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

    gotoxy(21,6);
    cout<<"Se Restauro El Archivo Medicos.dat Con Exito!"<<endl;
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

    gotoxy(21,7);
    cout<<"Se Restauro El Archivo Pacientes.dat Con Exito!"<<endl;
    fclose(p);
    fclose(pback);
    return;
}



void bckControles()
{

    recuadro(20,1,75,25);

    gotoxy(45,2);
    cout<<" **** CLINICA SAN SIMON ****";
    gotoxy(45,3);
    cout<<"       MENU DE BACKUP     ";

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


    gotoxy(21,5);
    cout<<"Se Realizo Backup del Archivo Controles.dat Con Exito!"<<endl;
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
    gotoxy(21,6);
    cout<<"Se Realizo Backup del Archivo Medicos.dat Con Exito!"<<endl;

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

    gotoxy(21,7);
    cout<<"Se Realizo Backup del Archivo Pacientes.dat Con Exito!"<<endl;
    fclose(p);
    fclose(pback);
    return;
}

#endif // CONFIGURACION_H_INCLUDED
