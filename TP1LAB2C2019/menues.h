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


void MenuPrincipal(){

    char aux;
    int opc;

    while(true){

        system("cls");

         ///  Los 2 primeros argumentos son los ejes X e Y respectivamente.
         ///  Los otros 2 son ancho y alto del recuadro respectivamente.
         ///  5 y 7 para debug rapido ó 5,5.
         ///  Tamanio aceptable del recuadro: 75 ,25
        recuadro(20,1,75,25);

        gotoxy(45,3);
        cout<<"**** CLINICA SAN SIMON ****"<<endl;
        gotoxy(45,6);
        cout<<"||---------------------||"<<endl;
        gotoxy(45,7);
        cout<<"||    MENU PRINCIPAL   ||"<<endl;
        gotoxy(45,8);
        cout<<"||---------------------||"<<endl;
        gotoxy(45,9);
        cout<<"||1) PACIENTES         ||"<<endl;
        gotoxy(45,10);
        cout<<"||2) MEDICOS           ||"<<endl;
        gotoxy(45,11);
        cout<<"||3) CONTROLES         ||"<<endl;
        gotoxy(45,12);
        cout<<"||4) REPORTES          ||"<<endl;
        gotoxy(45,13);
        cout<<"||5) CONFIGURACION     ||"<<endl;
        gotoxy(45,14);
        cout<<"||---------------------||"<<endl;
        gotoxy(45,15);
        cout<<"||0) SALIR DEL PROGRAMA||"<<endl;
        gotoxy(45,16);
        cout<<"||---------------------||"<<endl;
        gotoxy(45,17);
        cout<<"||OPCION INGRESADA:    ||"<<endl;
        gotoxy(45,18);
        cout<<"||---------------------||"<<endl;
        gotoxy(64,17);
        cin>>opc;


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
            gotoxy(45,19);
            cout<<"Realmente desea salir?(S/N):"<<endl;
            gotoxy(73,19);
            cin>>aux;
            if(aux == 's' || aux == 'S'){
                return;
            }
            else{
                break;
            }
        default:
            gotoxy(45,19);
            cout<<"Ingrese una opcion correcta:"<<endl;
            gotoxy(73,19);
            cin>>opc;
            break;

        }

    }

}

void MenuPacientes(){

    int opc;
    system("cls");

    while(true){

        recuadro(20,1,75,25);

        gotoxy(45,3);
        cout<<"**** CLINICA SAN SIMON ****"<<endl;
        gotoxy(45,6);
        cout<<"||------------------------------||"<<endl;
        gotoxy(45,7);
        cout<<"||      MENU PACIENTES          ||"<<endl;
        gotoxy(45,8);
        cout<<"||------------------------------||"<<endl;
        gotoxy(45,9);
        cout<<"||1) NUEVO PACIENTE             ||"<<endl;
        gotoxy(45,10);
        cout<<"||2) MODIFICAR PACIENTE         ||"<<endl;
        gotoxy(45,11);
        cout<<"||3) LISTAR PACIENTE POR DNI    ||"<<endl;
        gotoxy(45,12);
        cout<<"||4) LISTAR TODOS LOS PACIENTES ||"<<endl;
        gotoxy(45,13);
        cout<<"||5) ELIMINAR PACIENTE          ||"<<endl;
        gotoxy(45,14);
        cout<<"||------------------------------||"<<endl;
        gotoxy(45,15);
        cout<<"||0) VOLVER AL MENU PRINCIPAL   ||"<<endl;
        gotoxy(45,16);
        cout<<"||------------------------------||"<<endl;
        gotoxy(45,17);
        cout<<"||OPCION INGRESADA:             ||"<<endl;
        gotoxy(45,18);
        cout<<"||------------------------------||"<<endl;

        gotoxy(64,17);
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
            gotoxy(45,19);
            cout<<"Ingrese una opcion correcta:"<<endl;
            gotoxy(73,19);
            cin>>opc;
            break;

        }

    }

}

void MenuMedicos(){

    int opc;
    system("cls");

    while(true){

        recuadro(20,1,75,25);

        gotoxy(45,3);
        cout<<"**** CLINICA SAN SIMON ****"<<endl;
        gotoxy(45,6);
        cout<<"||------------------------------||"<<endl;
        gotoxy(45,7);
        cout<<"||       MENU MEDICOS           ||"<<endl;
        gotoxy(45,8);
        cout<<"||------------------------------||"<<endl;
        gotoxy(45,9);
        cout<<"||1) NUEVO MEDICO               ||"<<endl;
        gotoxy(45,10);
        cout<<"||2) MODIFICAR MEDICO           ||"<<endl;
        gotoxy(45,11);
        cout<<"||3) LISTAR TODOS LOS MEDICOS   ||"<<endl;
        gotoxy(45,12);
        cout<<"||4) LISTAR MEDICO POR MATRICULA||"<<endl;
        gotoxy(45,13);
        cout<<"||------------------------------||"<<endl;
        gotoxy(45,14);
        cout<<"||0) VOLVER AL MENU PRINCIPAL   ||"<<endl;
        gotoxy(45,15);
        cout<<"||------------------------------||"<<endl;
        gotoxy(45,16);
        cout<<"||OPCION INGRESADA:             ||"<<endl;
        gotoxy(45,17);
        cout<<"||------------------------------||"<<endl;

        gotoxy(64,16);
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
            gotoxy(45,18);
            cout<<"Ingrese una opcion correcta:"<<endl;
            gotoxy(73,18);
            cin>>opc;
            break;

        }

    }
}


void MenuControles(){

    int opc;
    system("cls");

    while(true){

        recuadro(20,1,75,25);

        gotoxy(45,3);
        cout<<"**** CLINICA SAN SIMON ****"<<endl;
        gotoxy(45,6);
        cout<<"||-----------------------------||"<<endl;
        gotoxy(45,7);
        cout<<"||      MENU CONTROLES         ||"<<endl;
        gotoxy(45,8);
        cout<<"||-----------------------------||"<<endl;
        gotoxy(45,9);
        cout<<"||1) NUEVO CONTROL             ||"<<endl;
        gotoxy(45,10);
        cout<<"||2) MODIFICAR CONTROL         ||"<<endl;
        gotoxy(45,11);
        cout<<"||3) LISTAR CONTROL POR ID     ||"<<endl;
        gotoxy(45,12);
        cout<<"||4) LISTAR TODOS LOS CONTROLES||"<<endl;
        gotoxy(45,13);
        cout<<"||5) CANCELAR CONTROL          ||"<<endl;
        gotoxy(45,14);
        cout<<"||-----------------------------||"<<endl;
        gotoxy(45,15);
        cout<<"||0) VOLVER AL MENU ANTERIOR   ||"<<endl;
        gotoxy(45,16);
        cout<<"||-----------------------------||"<<endl;
        gotoxy(45,17);
        cout<<"||OPCION INGRESADA:            ||"<<endl;
        gotoxy(45,18);
        cout<<"||-----------------------------||"<<endl;

        gotoxy(64,17);
        cin>>opc;


        switch(opc)
        {
        case 1:
            system("cls");
            nuevo_control();
            return;
            break;
        case 2:
            system("cls");
            modificar_control();
            return;
            break;
        case 3:
            system("cls");
             listar_control_x_id();
            return;
            break;
        case 4:
            system("cls");
            listarControles();
            return;
            break;
        case 5:
            system("cls");
            cancelar_control();
            return;
            break;
        case 0:
            return;
        default:
            gotoxy(45,19);
            cout<<"Ingrese una opcion correcta:"<<endl;
            gotoxy(73,19);
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
