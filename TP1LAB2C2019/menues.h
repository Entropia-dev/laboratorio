#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED


void MenuPacientes();
void MenuMedicos();
void MenuControles();
void MenuReportes();
void MenuConfiguracion();

//Verifica por primera vez la matricula porque el archivo no existiria sin esa funcion y evitar exit 1.
//revisa que no este protegido contra lectura
//int aux=contarregistrosmedicos();
//int aux1=contarregistrospaciente();
//int aux2=contarregistroscontroles();  //para que iniclice el arhivo y despues el autonumerico


void MenuPrincipal()
{

    char aux;
    int opc;

    while(true)
    {

        system("cls");

        gotoxy(50,2);
        cout<<"-------------------------"<<endl;
        gotoxy(50,3);
        cout<<"||CLINICA SAN SIMON    ||"<<endl;
        gotoxy(50,4);
        cout<<"||---------------------||"<<endl;
        gotoxy(50,5);
        cout<<"||MENU PRINCIPAL       ||"<<endl;
        gotoxy(50,6);
        cout<<"||---------------------||"<<endl;
        gotoxy(50,7);
        cout<<"||1) PACIENTES         ||"<<endl;
        gotoxy(50,8);
        cout<<"||2) MEDICOS           ||"<<endl;
        gotoxy(50,9);
        cout<<"||3) CONTROLES         ||"<<endl;
        gotoxy(50,10);
        cout<<"||4) REPORTES          ||"<<endl;
        gotoxy(50,11);
        cout<<"||5) CONFIGURACION     ||"<<endl;
        gotoxy(50,12);
        cout<<"||---------------------||"<<endl;
        gotoxy(50,13);
        cout<<"||0) SALIR DEL PROGRAMA||"<<endl;
        gotoxy(50,14);
        cout<<"||---------------------||"<<endl;
        gotoxy(50,15);
        cout<<"||OPCION INGRESADA:    ||"<<endl;
        gotoxy(70,15);
        cin>>opc;
        gotoxy(50,16);
        cout<<"||---------------------||"<<endl;
        switch(opc)
        {

        case 1:
            MenuPacientes();
            break;

        case 2:
            MenuMedicos();
            break;

        case 3:
            MenuControles();
            break;

        case 4:
            MenuReportes();
            break;

        case 5:
            MenuConfiguracion();
            break;

        case 0:
            gotoxy(52,17);
            cout<<"realmente desea salir?"<<endl;
            gotoxy(50,18);
            cin>>aux;
            if(aux == 's')
            {
                return;
            }
            else
            {
                break;
            }
        default:
            cout<<"Ingrese una opcion correcta"<<endl;
            cin>>opc;
            break;

        }

    }

}

void MenuPacientes()
{
    int opc;

    system("cls");

    while(true)
    {


        gotoxy(50,2);
        cout<<"----------------------------------"<<endl;
        gotoxy(50,3);
        cout<<"||CLINICA SAN SIMON             ||"<<endl;
        gotoxy(50,4);
        cout<<"||------------------------------||"<<endl;
        gotoxy(50,5);
        cout<<"||MENU PACIENTES                ||"<<endl;
        gotoxy(50,6);
        cout<<"||------------------------------||"<<endl;
        gotoxy(50,7);
        cout<<"||1) NUEVO PACIENTE             ||"<<endl;
        gotoxy(50,8);
        cout<<"||2) MODIFICAR PACIENTE         ||"<<endl;
        gotoxy(50,9);
        cout<<"||3) LISTAR PACIENTE POR DNI    ||"<<endl;
        gotoxy(50,10);
        cout<<"||4) LISTAR TODOS LOS PACIENTES ||"<<endl;
        gotoxy(50,11);
        cout<<"||5) ELIMINAR PACIENTE          ||"<<endl;
        gotoxy(50,12);
        cout<<"||------------------------------||"<<endl;
        gotoxy(50,13);
        cout<<"||0) VOLVER AL MENU PRINCIPAL   ||"<<endl;
        gotoxy(50,14);
        cout<<"||------------------------------||"<<endl;
        gotoxy(50,15);
        cout<<"||OPCION INGRESADA:             ||"<<endl;
        gotoxy(70,15);
        cin>>opc;
        switch(opc)
        {
        case 1:
            system("cls");
            altaPaciente();
            return;
            break;

        case 2:
            system("cls");
            modificarobrasocial();
            return;
            break;

        case 3:
            system("cls");
            listarpacientepordni();
            system("pause");
            return;
            break;

        case 4:
            listartodoslospacientes();
            return;
            break;

        case 5:
            eliminarpaciente();
            return;
            break;

        case 0:
            return;
            break;


        default:
            cout<<"Ingrese una opcion correcta"<<endl;
            cin>>opc;
            break;


        }



    }

}

void MenuMedicos()
{
    int opc;
    system("cls");

    while(true)
    {
        cout<<"MENU MEDICOS"<<endl;
        cout<<"--------------"<<endl;
        cout<<"1) NUEVO MEDICO"<<endl;
        cout<<"2) MODIFICAR MEDICO"<<endl;
        cout<<"3) LISTAR TODOS LOS MEDICOS"<<endl;
        cout<<"4) LISTAR MEDICO POR MATRICULA"<<endl;
        cout<<"-------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cin>>opc;

        switch(opc)
        {
        case 1:
            system("cls");
            altamedicos();
            return;
            break;

        case 2:
            system("cls");
            modificarmedicos();
            return;
            break;

        case 3:
            system("cls");
            listartodoslosmedicos();
            return;
            break;

        case 4:
            system("cls");
            listarmedicoxmatricula();
            return;
            break;

        case 0:
            return;

        default:
            cout<<"Ingrese una opcion correcta"<<endl;
            cin>>opc;
            break;


        }


    }
}


void MenuControles()
{
    while(true)
    {
        cout<<"MENU CONTROLES "<<endl;
        cout<<endl;
        cout<<"1) NUEVO CONTROL"<<endl;
        cout<<"2) MODIFICAR CONTROL"<<endl;
        cout<<"3) LISTAR CONTROL POR ID"<<endl;
        cout<<"4) LISTAR TODOS LOS CONTROLES"<<endl;
        cout<<"5) CANCELAR CONTROL"<<endl;
        int opc;
        cin>>opc;
        switch(opc)
        {
        case 1:
            system("cls");
            //nuevo_control();
            return;
            break;
        case 2:
            system("cls");
            //modificar_control();
            return;
            break;
        case 3:
            system("cls");
           // listar_control_x_id();
            return;
            break;
        case 4:
            system("cls");
            //listar_todos_controles();
            return;
            break;
        case 5:
            system("cls");
            //cancelar_control();
            return;
            break;
        case 0:
            return;
        default:
            cout<<"Ingrese una opcion correcta"<<endl;
            cin>>opc;
            break;
        }
    }

    return;
}

void MenuReportes()
{

    return;
}

void MenuConfiguracion()
{

    return;
}


#endif // MENUES_H_INCLUDED
