#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

void MenuPacientes();
void MenuMedicos();
void MenuControles();
void MenuReportes();
void MenuConfiguracion();


void MenuPrincipal(){

    char aux;
    int opc;

        while(true){

    system("cls");

            cout<<"MENU PRINCIPAL "<<endl;
            cout<<"---------------"<<endl;
            cout<<"1) PACIENTES"<<endl;
            cout<<"2) MEDICOS"<<endl;
            cout<<"3) CONTROLES"<<endl;
            cout<<"4) REPORTES"<<endl;
            cout<<"5) CONFIGURACION"<<endl;
            cout<<"---------------"<<endl;
            cout<<"0) SALIR DEL PROGRAMA"<<endl;

            cin>>opc;

                switch(opc){

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
                    cout<<"realmente desea salir?"<<endl;
                    cin>>aux;
                    if(aux == 's'){
                    return;
                    }
                    else{break;}
                default:
                    cout<<"Ingrese una opcion correcta"<<endl;
                    cin>>opc;
                break;

                                    }

    }

}

void MenuPacientes(){
int opc;

    system("cls");

    while(true){
        cout<<"MENU PACIENTES"<<endl;
        cout<<"--------------"<<endl;
        cout<<"1) NUEVO PACIENTE"<<endl;
        cout<<"2) MODIFICAR PACIENTE"<<endl;
        cout<<"3) LISTAR PACIENTE POR DNI"<<endl;
        cout<<"4) LISTAR TODOS LOS PACIENTES"<<endl;
        cout<<"5) ELIMINAR PACIENTE"<<endl;
        cout<<"-------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cin>>opc;
        switch(opc){
        case 1:
            system("cls");
            altaPaciente();
            return;
        break;

        case 2:
        break;

        case 3:
        break;

        case 4:
        listartodoslospacientes();
        return;
        break;

        case 5:
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

void MenuMedicos(){
int opc;

    system("cls");

    while(true){
        cout<<"MENU MEDICOS"<<endl;
        cout<<"--------------"<<endl;
        cout<<"1) NUEVO MEDICO"<<endl;
        cout<<"2) MODIFICAR MEDICO"<<endl;
        cout<<"3) LISTAR TODOS LOS MEDICOS"<<endl;
        cout<<"4) LISTAR MEDICO POR MATRICULA"<<endl;
        cout<<"-------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cin>>opc;

        switch(opc){
        case 1:
        break;

        case 2:
        break;

        case 3:
        break;

        case 4:
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


void MenuControles(){

return;
}

void MenuReportes(){

return;
}

void MenuConfiguracion(){

return;
}


#endif // MENUES_H_INCLUDED
