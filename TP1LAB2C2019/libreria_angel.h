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

fecha cargar_fecha(){


    struct fecha reg;
    bool bisiesto = false;
    int aux=0;

    gotoxy(21,10);
    cout << "Dia de Nacimiento:           ";
    gotoxy(39,10);
    cin >> reg.dia;
    gotoxy(21,11);
    cout << "Mes de Nacimiento:           ";
    gotoxy(39,11);
    cin >> reg.mes;
    gotoxy(21,12);
    cout << "Anio de Nacimiento:          ";
    gotoxy(40,12);
    cin >> reg.anio;

    //Pasos:

    //1)Comprobamos el año,como sigue:SI EL AÑO ES BISIESTO significa que el año tiene 365.A priori ,eso NO ESTÁ MAL.
    //El dia adicional se le suma a  Febrero.

    //2)Verificar por mes y toda la logica que se muestra en los ifs.



    while ( aux == 0 ){    // REPITO ABSOLUTAMENTE TODO MIENTRAS QUE "AUX" SEA == 0. CUANDO ES ALGUNA FECHA VALIDA,AUX=1;

//Comprobamos si el año es bisiesto
    if((reg.anio%4==0 && reg.anio%100!=100) || reg.anio%400==0){
        bisiesto = true;}else{bisiesto=false;}


    if ( reg.mes == 1 || reg.mes == 3 ||
         reg.mes == 5 || reg.mes == 7 ||
         reg.mes == 8 || reg.mes == 10 || reg.mes == 12){

            if ( reg.dia > 0 && reg.dia < 32  ){
                aux++;}else{
        //while (reg.dia < 1 && reg.dia > 31){  // HAGO WHILE CON EL RANGO CONTRARIO HASTA QUE SEA UNA FECHA VALIDA.EN OTRAS PALBRAS MIENTRAS ESTE MAL ,REPITO WHILE.

                                gotoxy(21,11);
                                cout<<"                                                                ";
                                gotoxy(21,12);
                                cout<<"                                                                ";
                                gotoxy(21,10);
                                cout << "Dia Incorrecto,Vuelva a Empezar - Dia de Nacimiento:           ";
                                 gotoxy(73,10);
                                cin >> reg.dia;
                                gotoxy(21,11);
                                cout << "Mes de Nacimiento:           ";
                                gotoxy(39,11);
                                cin >> reg.mes;
                                gotoxy(21,12);
                                cout << "Anio de Nacimiento:          ";
                                gotoxy(40,12);
                                cin >> reg.anio;
                            //}  // while del else del rango de dias.

                      } // else del if de rango dias.

             }else if( reg.mes == 4 || reg.mes == 6 ||
                       reg.mes == 9 || reg.mes == 11 ){

            if (reg.dia >0 && reg.dia < 31 ){
                aux++;}else{
    //while (reg.dia < 1 && reg.dia > 30){  // HAGO WHILE CON EL RANGO CONTRARIO HASTA QUE SEA UNA FECHA VALIDA.EN OTRAS PALBRAS MIENTRAS ESTE MAL ,REPITO WHILE.

                                gotoxy(21,11);
                                cout<<"                                                                ";
                                gotoxy(21,12);
                                cout<<"                                                                ";
                                gotoxy(21,10);
                                cout << "Dia Incorrecto,Vuelva a Empezar - Dia de Nacimiento:           ";
                                gotoxy(73,10);
                                cin >> reg.dia;
                                gotoxy(21,11);
                                cout << "Mes de Nacimiento:           ";
                                gotoxy(39,11);
                                cin >> reg.mes;
                                gotoxy(21,12);
                                cout << "Anio de Nacimiento:          ";
                                gotoxy(40,12);
                                cin >> reg.anio;
                            } // while del else del rango de dias.

                     // } // else del if de rango dias.

                }else if ( reg.mes == 2){

                      if (bisiesto == true){

                         if ( reg.dia >0 && reg.dia <30 ){
                            aux++;}else{
   // while (reg.dia < 1 && reg.dia > 30){  // HAGO WHILE CON EL RANGO CONTRARIO HASTA QUE SEA UNA FECHA VALIDA.EN OTRAS PALBRAS MIENTRAS ESTE MAL ,REPITO WHILE.

                                gotoxy(21,11);
                                cout<<"                                                                ";
                                gotoxy(21,12);
                                cout<<"                                                                ";
                                gotoxy(21,10);
                                cout << "Dia Bisiesto Incorrecto,Vuelva a Empezar - Dia de Nacimiento:           ";
                                 gotoxy(82,10);
                                cin >> reg.dia;
                                gotoxy(21,11);
                                cout << "Mes de Nacimiento:           ";
                                gotoxy(39,11);
                                cin >> reg.mes;
                                gotoxy(21,12);
                                cout << "Anio de Nacimiento:          ";
                                gotoxy(40,12);
                                cin >> reg.anio;
                              //  }  // while del else del rango de dias.

                           }  // else del if de rango dias.
                      } // bisiesto == true VERDADERO

                       else{ // bisiesto == true FALSO

                    if ( reg.dia >0 && reg.dia < 29){
                            aux++;}else{
       // while (reg.dia < 1 && reg.dia > 30){  // HAGO WHILE CON EL RANGO CONTRARIO HASTA QUE SEA UNA FECHA VALIDA.EN OTRAS PALBRAS MIENTRAS ESTE MAL ,REPITO WHILE.

                                gotoxy(21,11);
                                cout<<"                                                                ";
                                gotoxy(21,12);
                                cout<<"                                                                ";
                                gotoxy(21,10);
                                cout << "Dia Incorrecto,Vuelva a Empezar - Dia de Nacimiento:           ";
                                 gotoxy(73,10);
                                cin >> reg.dia;
                                gotoxy(21,11);
                                cout << "Mes de Nacimiento:           ";
                                gotoxy(39,11);
                                cin >> reg.mes;
                                gotoxy(21,12);
                                cout << "Anio de Nacimiento:          ";
                                gotoxy(40,12);
                                cin >> reg.anio;
                               // } // while del else del rango de dias.

                           }  // else del rango de reg.dias

                    } // bisiesto == true FALSO



                 }else{ // else if de reg.mes== 2


                    //SI NO ES NADA DE LO ANTERIOR,ES PORQUE ES UN MES INVALIDO.

   // while (reg.mes < 1 && reg.mes > 12){  // HAGO WHILE CON EL RANGO CONTRARIO HASTA QUE SEA UNA FECHA VALIDA.EN OTRAS PALBRAS MIENTRAS ESTE MAL ,REPITO WHILE.

                            gotoxy(21,11);
                            cout<<"                                                                ";
                            gotoxy(21,12);
                            cout<<"                                                                ";
                            gotoxy(21,10);
                            cout << "Mes Incorrecto,Vuelva a Empezar - Dia de Nacimiento:           ";
                            gotoxy(73,10);
                            cin >> reg.dia;
                            gotoxy(21,11);
                            cout << "Mes de Nacimiento:           ";
                            gotoxy(39,11);
                            cin >> reg.mes;
                            gotoxy(21,12);
                            cout << "Anio de Nacimiento:          ";
                            gotoxy(40,12);
                            cin >> reg.anio;
                           // }// while del else del rango de dias.

                 }


    } //  ************************  WHILE DE AUX *******************************



        return reg;

} // CARGAR FECHA

//====================================================================================================================
// FUNCION    :
// ACCION     :
// PARAMETROS :
//
//DEVUELVE    :
//====================================================================================================================




fecha cargar_fecha_control(){


    struct fecha reg;
    bool bisiesto = false;
    int aux=0;


    //  FECHA/HORA ACTUAL BASADO EN EL SISTEMA ACTUAL.
 time_t now =  time(0);

 //  OBJETO DE UNA ESTRUCTURA tm  CON FECHA/HORA ACTUAL.
 tm *time = localtime(&now);




    gotoxy(21,10);
    cout << "Ingrese el Dia del Control:               ";
    gotoxy(48,10);
    cin >> reg.dia;
    gotoxy(21,11);
    cout << "Ingrese el Mes del Control:            ";
    gotoxy(48,11);
    cin >> reg.mes;
    gotoxy(21,12);
    cout << "Ingrese el Anio del Control:             ";
    gotoxy(49,12);
    cin >> reg.anio;

    //Pasos:

    //1)Comprobamos el año,como sigue:SI EL AÑO ES BISIESTO significa que el año tiene 365.A priori ,eso NO ESTÁ MAL.
    //El dia adicional se le suma a  Febrero.

    //2)Verificar por mes y toda la logica que se muestra en los ifs.



    while ( aux == 0 ){    // REPITO ABSOLUTAMENTE TODO MIENTRAS QUE "AUX" SEA == 0. CUANDO ES ALGUNA FECHA VALIDA,AUX=1;

//Comprobamos si el año es bisiesto
    if((reg.anio%4==0 && reg.anio%100!=100) || reg.anio%400==0){
        bisiesto = true;}else{bisiesto=false;}


    if ( reg.mes == 1 || reg.mes == 3 ||
         reg.mes == 5 || reg.mes == 7 ||
         reg.mes == 8 || reg.mes == 10 || reg.mes == 12){

            if ( reg.dia > 0 && reg.dia < 32  ){
                aux++;}else{
        //while (reg.dia < 1 && reg.dia > 31){  // HAGO WHILE CON EL RANGO CONTRARIO HASTA QUE SEA UNA FECHA VALIDA.EN OTRAS PALBRAS MIENTRAS ESTE MAL ,REPITO WHILE.

                                //  ESTAS 4 LINEAS DE ABAJO ESTAN BIEN,SIRVEN PARA BORRAR EL TEXTO ANTERIOR INGRESADO.
                                gotoxy(21,11);
                                cout<<"                                                                ";
                                gotoxy(21,12);
                                cout<<"                                                                ";

                                gotoxy(21,10);
                                cout << "Dia Incorrecto,Vuelva a Empezar - Dia del Control:           ";
                                gotoxy(71,10);
                                cin >> reg.dia;
                                gotoxy(21,11);
                                cout << "Mes del Control:           ";
                                gotoxy(37,11);
                                cin >> reg.mes;
                                gotoxy(21,12);
                                cout << "Anio del Control:          ";
                                gotoxy(38,12);
                                cin >> reg.anio;
                            //}  // while del else del rango de dias.

                      } // else del if de rango dias.

             }else if( reg.mes == 4 || reg.mes == 6 ||
                       reg.mes == 9 || reg.mes == 11 ){

            if (reg.dia >0 && reg.dia < 31 ){
                aux++;}else{
    //while (reg.dia < 1 && reg.dia > 30){  // HAGO WHILE CON EL RANGO CONTRARIO HASTA QUE SEA UNA FECHA VALIDA.EN OTRAS PALBRAS MIENTRAS ESTE MAL ,REPITO WHILE.

                                //  ESTAS 4 LINEAS DE ABAJO ESTAN BIEN,SIRVEN PARA BORRAR EL TEXTO ANTERIOR INGRESADO.

                                gotoxy(21,11);
                                cout<<"                                                                ";
                                gotoxy(21,12);
                                cout<<"                                                                ";


                                gotoxy(21,10);
                                cout << "Dia Incorrecto,Vuelva a Empezar - Dia del Control:           ";
                                gotoxy(71,10);
                                cin >> reg.dia;
                                gotoxy(21,11);
                                cout << "Mes del Control:           ";
                                gotoxy(37,11);
                                cin >> reg.mes;
                                gotoxy(21,12);
                                cout << "Anio del Control:          ";
                                gotoxy(38,12);
                                cin >> reg.anio;
                            } // while del else del rango de dias.

                     // } // else del if de rango dias.

                }else if ( reg.mes == 2){

                      if (bisiesto == true){

                         if ( reg.dia >0 && reg.dia <30 ){
                            aux++;}else{
   // while (reg.dia < 1 && reg.dia > 30){  // HAGO WHILE CON EL RANGO CONTRARIO HASTA QUE SEA UNA FECHA VALIDA.EN OTRAS PALBRAS MIENTRAS ESTE MAL ,REPITO WHILE.

                                //  ESTAS 4 LINEAS DE ABAJO ESTAN BIEN,SIRVEN PARA BORRAR EL TEXTO ANTERIOR INGRESADO.
                                gotoxy(21,11);
                                cout<<"                                                                ";
                                gotoxy(21,12);
                                cout<<"                                                                ";



                                gotoxy(21,10);
                                cout << "Dia Bisiesto Incorrecto,Vuelva a Empezar - Dia del Control:           ";
                                gotoxy(80,10);
                                cin >> reg.dia;
                                gotoxy(21,11);
                                cout << "Mes del Control:           ";
                                gotoxy(37,11);
                                cin >> reg.mes;
                                gotoxy(21,12);
                                cout << "Anio del Control:          ";
                                gotoxy(38,12);
                                cin >> reg.anio;
                              //  }  // while del else del rango de dias.

                           }  // else del if de rango dias.
                      } // bisiesto == true VERDADERO

                       else{ // bisiesto == true FALSO

                    if ( reg.dia >0 && reg.dia < 29){
                            aux++;}else{
       // while (reg.dia < 1 && reg.dia > 30){  // HAGO WHILE CON EL RANGO CONTRARIO HASTA QUE SEA UNA FECHA VALIDA.EN OTRAS PALBRAS MIENTRAS ESTE MAL ,REPITO WHILE.

                                //  ESTAS 4 LINEAS DE ABAJO ESTAN BIEN,SIRVEN PARA BORRAR EL TEXTO ANTERIOR INGRESADO.
                                gotoxy(21,11);
                                cout<<"                                                                ";
                                gotoxy(21,12);
                                cout<<"                                                                ";

                                gotoxy(21,10);
                                cout << "Dia Incorrecto,Vuelva a Empezar - Dia del Control:           ";
                                gotoxy(71,10);
                                cin >> reg.dia;
                                gotoxy(21,11);
                                cout << "Mes del Control:           ";
                                gotoxy(37,11);
                                cin >> reg.mes;
                                gotoxy(21,12);
                                cout << "Anio del Control:          ";
                                gotoxy(38,12);
                                cin >> reg.anio;
                               // } // while del else del rango de dias.

                           }  // else del rango de reg.dias

                    } // bisiesto == true FALSO



                 }else{ // else if de reg.mes== 2


                    //SI NO ES NADA DE LO ANTERIOR,ES PORQUE ES UN MES INVALIDO.

   // while (reg.mes < 1 && reg.mes > 12){  // HAGO WHILE CON EL RANGO CONTRARIO HASTA QUE SEA UNA FECHA VALIDA.EN OTRAS PALBRAS MIENTRAS ESTE MAL ,REPITO WHILE.

                            //  ESTAS 4 LINEAS DE ABAJO ESTAN BIEN,SIRVEN PARA BORRAR EL TEXTO ANTERIOR INGRESADO.
                            gotoxy(21,11);
                            cout<<"                                                                ";
                            gotoxy(21,12);
                            cout<<"                                                                ";


                            gotoxy(21,10);
                            cout << "Mes Incorrecto,Vuelva a Empezar - Dia del Control:           ";
                            gotoxy(71,10);
                            cin >> reg.dia;
                            gotoxy(21,11);
                            cout << "Mes del Control:           ";
                            gotoxy(37,11);
                            cin >> reg.mes;
                            gotoxy(21,12);
                            cout << "Anio del Control:          ";
                            gotoxy(38,12);
                                cin >> reg.anio;
                           // }// while del else del rango de dias.

                 }




    if ( (aux == 1) &&  (reg.dia >= time->tm_mday) &&  (reg.mes >= time->tm_mon+1 ) && (reg.anio  >= time->tm_year+1900) ){
         aux++;
         }
         else{
             aux=0;
                 //  ESTAS 4 LINEAS DE ABAJO ESTAN BIEN,SIRVEN PARA BORRAR EL TEXTO ANTERIOR INGRESADO.
                            gotoxy(21,11);
                            cout<<"                                                                ";
                            gotoxy(21,12);
                            cout<<"                                                                ";


                            gotoxy(21,10);
                            cout << "FECHA INVALIDA PARA CONTROL,Vuelva a Empezar - Dia del Control:           ";
                            gotoxy(84,10);
                            cin >> reg.dia;
                            gotoxy(21,11);
                            cout << "Mes del Control:           ";
                            gotoxy(37,11);
                            cin >> reg.mes;
                            gotoxy(21,12);
                            cout << "Anio del Control:          ";
                            gotoxy(38,12);
                            cin >> reg.anio;


             }






    } //  ************************  WHILE DE AUX *******************************



        return reg;

} // CARGAR FECHA








#endif // LIBRERIA_ANGEL_H_INCLUDED
