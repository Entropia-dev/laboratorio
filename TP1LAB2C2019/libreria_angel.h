#ifndef LIBRERIA_ANGEL_H_INCLUDED
#define LIBRERIA_ANGEL_H_INCLUDED

enum Color
{
    cNEGRO=0,
    cAZUL=1,
    cVERDE=2,
    cCIAN=3,
    cROJO=4,
    cMAGENTA=5,
    cMARRON=6,
    cGRIS_CLARO=7,
    cGRIS=8,
    cAZUL_CLARO=9,
    cVERDE_CLARO=10,
    cCIAN_CLARO=11,
    cROJO_CLARO=12,
    cMAGENTA_CLARO=13,
    cAMARILLO=14,
    cBLANCO=15
};

void clrscr(void)
{
    system("cls");
}

void pause(void)
{
    system("pause >nul");
}

void gotoxy(short x, short y)
{
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

void textcolor(short colorTexto=15, short colorFondo=0)
{
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}

void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cMAGENTA){

    //  FECHA/HORA ACTUAL BASADO EN EL SISTEMA ACTUAL.
 time_t now =  time(0);

 //  OBJETO DE UNA ESTRUCTURA tm  CON FECHA/HORA ACTUAL.
 tm *time = localtime(&now);

    vector<string> dia_semana;
    dia_semana.push_back("Domingo");
    dia_semana.push_back("Lunes");
    dia_semana.push_back("Martes");
    dia_semana.push_back("Miercoles");
    dia_semana.push_back("Jueves");
    dia_semana.push_back("Viernes");
    dia_semana.push_back("Sabado");

    vector<string> mes;
    mes.push_back("Enero");
    mes.push_back("Febrero");
    mes.push_back("Marzo");
    mes.push_back("Abril");
    mes.push_back("Mayo");
    mes.push_back("Junio");
    mes.push_back("Julio");
    mes.push_back("Agosto");
    mes.push_back("Septiembre");
    mes.push_back("Octubre");
    mes.push_back("Noviembre");
    mes.push_back("Diciembre");

    int anio = 1900 + time->tm_year;
    int i, j,lineaCabecera,lineaPie;
    // Son solo ejemplos despues probar.
    lineaCabecera = (iniY + 3);
    lineaPie = ((iniY+alto)-3); // Tiene que ser 3 si o si abajo por el modelo que le quiero dar.(igual es un ejemplo)


	//for eje de la X o I HORIZONTAL:POR ULTIMO HAGO EL ANCHO DEL  RECUADRO
    for(i=iniX; i<=iniX+ancho; i++){

		//for eje de la Y o J VERTICAL: PRIMERO HAGO EL ALTO DEL RECUADRO
        for(j=iniY; j<=iniY+alto; j++){

			//ME POSICIONO EN EL EJE CORRESPONDIENTE.
            gotoxy(i, j);

            textcolor(colorLinea, colorFondo);

			// PRINCIPIO 4 ESQUINAS

            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
               cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
              cout << (char) 188;
            }

			// FIN 4 ESQUINAS


            //Lineas VERTICALES  arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 205;
            }

			//SE TIENEN QUE DAR ESTAS 3 CONDICIONES OBLIGADAS:
			// 1° Condicion: Me indica la linea que me interesa colocar el caracter.
			// 2°Condicion: EVITO EL LATERAL IZQUIERDO.
			// 3°Condicion: EVITO EL LATERAL DERECHO.
			else if (   j == lineaCabecera &&   (i !=  iniX ) &&   (i != (iniX+ancho) ) ){
				cout << (char) 205;

			}

			//SE TIENEN QUE DAR ESTAS 3 CONDICIONES OBLIGADAS:
			// 1° Condicion: Me indica la linea que me interesa colocar el caracter.
			// 2°Condicion: EVITO EL LATERAL IZQUIERDO.
			// 3°Condicion: EVITO EL LATERAL DERECHO.
			else if (  j == lineaPie &&   (i !=  iniX ) &&   (i != (iniX+ancho) )    ){
				cout << (char) 205;
			}

            //Lineas HORIZONTALES  LATERALES izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 186;
            }


            //Dentro del recuadro ESTO SOLO OCURRE EN EL MEDIO .
            else{
                cout << " ";
            }
        }

     }


     gotoxy(21,2);
     //Formato final=Martes, 10/09/2019
    cout << dia_semana[time->tm_wday] << ", ";
    //mes[time->tm_mon] si queres poner el nombre del mes.
    cout << time->tm_mday << "/" << time->tm_mon+1 << "/" << anio;
    gotoxy(21,3);
    cout <<"Hora: "<<time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec;



     //HAGO EL PIE DE PAGINA YA QUE ES EL MISMO EN TODOS LOS MENUS.
     //X= Siempre es uno mas que el que le pasas
     //Y=  ((iniY+alto)-2) Asi que eso te da 2 espacios menos,
     //Por ejemplo 8-2= 6 entonces sumale uno siempre y te queda= 7.
	 gotoxy( 21,24 );
     cout <<"Alumnos: Parrotta, Federico | Galeano, Jeremias | Ortega Banegas, Santiago";
     gotoxy( 21,25 );
     cout <<"Materia: Laboratorio 2 - 2C - 2019";



  }

////////////////////////////////Funciones varias///////////////////////////////////

fecha cargar_fecha()
{
    struct fecha reg;
    bool bisiesto = false;
    int auxiliar=0;

    cout << "Introduce el dia: ";
    cin >> reg.dia;
    cout << "Introduce el mes: ";
    cin >> reg.mes;
    cout << "Introduce el anio: ";
    cin >> reg.anio;

//comprobamos si el año es bisiesto
    if(reg.anio%4==0 && reg.anio%100!=100 || reg.anio%400==0)
        bisiesto = true;

    //comprobamos que los datos ingresados esten en un rango valido
    if(reg.dia>0 && reg.dia<32 && reg.mes>0 && reg.mes<13 && reg.anio>0)
    {
        if(reg.mes==1 || reg.mes==3 || reg.mes==5 || reg.mes==7 || reg.mes==8 || reg.mes==10 || reg.mes==12)
        {
            return reg;
        }
        else
        {
            if(reg.mes==2 && reg.dia<30 && bisiesto)    ///verifica que el dia en un bisiesto sea correcto
                auxiliar++; ///
            else if(reg.mes==2 && reg.dia<29 && !bisiesto)  /// verifica el mes
                auxiliar++;
            else if(reg.mes!=2 && reg.dia<31)   ///verifica el año
                auxiliar ++;
            if(auxiliar == 3)
            {
                return reg;
            }
            else
                cout << "\ Ingrese un dia valido"<<endl;
            cin>>reg.dia;
            cout<<"ingrese un mes valido"<<endl;
            cin>>reg.mes;
            cout<<"ingrese un anio valido"<<endl;
            cin>>reg.anio;
            return reg;
        }
    }
    else
        cout << "\ Ingrese un dia valido"<<endl;
    cin>>reg.dia;
    cout<<"ingrese un mes valido"<<endl;
    cin>>reg.mes;
    cout<<"ingrese un anio valido"<<endl;
    cin>>reg.anio;
    return reg;
}

#endif // LIBRERIA_ANGEL_H_INCLUDED
