#ifndef FECHA_VAL_H_INCLUDED
#define FECHA_VAL_H_INCLUDED

fecha cargar_fecha() {
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
    if(reg.dia>0 && reg.dia<32 && reg.mes>0 && reg.mes<13 && reg.anio>0){
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
                if(auxiliar == 3) {return reg;}
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

#endif // FECHA_VAL_H_INCLUDED
