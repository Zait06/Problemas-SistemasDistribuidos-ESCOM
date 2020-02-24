#include "Temperatura.h"
#include <iostream>
using namespace std;

char menu();

int main(){
    double tempUsu;
    char op='a';
    Temperatura temp;

    while(op!='s'){
        op=menu();
        cout<<endl;
        switch (op)
        {
            case 'a':
                cout<<"De el valor de la temperatura Kelvin: ";
                cin>>tempUsu;
                temp.setTempKelvin(tempUsu);
                break;
            case 'b':
                cout<<"De el valor de la temperatura Fahrenheit: ";
                cin>>tempUsu;
                temp.setTempFahrenheit(tempUsu);
                break;
            case 'c':
                cout<<"De el valor de la temperatura Celsius: ";
                cin>>tempUsu;
                temp.setTempCelsius(tempUsu);
                break;
            case 'd':
                temp.getTempKelvin();
                break;
            case 'e':
                temp.getTempFahrenheit();
                break;
            case 'f':
                temp.getTempCelsius();
                break;
            case 's':
                cout<<"\t¡¡¡Adios!!!"<<endl;
                break;
            default:
                cout<<"Opcion no existente, intente de nuevo"<<endl;
                break;
        }
        cout<<endl;
    }
    
    return 0;
}

char menu(){
    char op;
    
    cout<<"Eliga una opción:"<<endl;
    cout<<"\ta. Ingresar temperatura en Kelvin"<<endl;
    cout<<"\tb. Ingresar temperatura en Fahrenheit"<<endl;
    cout<<"\tc. Ingresar temperatura en Celsius"<<endl;
    cout<<"\td. Imprimir temperatura en Kelvin"<<endl;
    cout<<"\te. Imprimir temperatura en Fahrenheit"<<endl;
    cout<<"\tf. Imprimir temperatura en Celsius"<<endl;
    cout<<"\ts. Salir"<<endl;
    cout<<"\tOpcion: ";
    cin>>op;

    return op;
}