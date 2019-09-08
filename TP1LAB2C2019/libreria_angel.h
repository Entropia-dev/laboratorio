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

void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cMAGENTA)
{
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++)
    {
        for(j=iniY; j<=iniY+alto; j++)
        {
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY)
            {
                cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY)
            {
                cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto)
            {
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto)
            {
                cout << (char) 188;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto)
            {
                cout << (char) 205;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho)
            {
                cout << (char) 186;
            }
            //Dentro del recuadro
            else
            {
                cout << " ";
            }
        }
    }
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
