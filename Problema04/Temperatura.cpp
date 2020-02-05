#include "Temperatura.h"
#include <iostream>
using namespace std;

Temperatura::Temperatura(double tk){
    tempKelvin=tk;
}

void Temperatura::setTempKelvin(double tk){
    tempKelvin=tk;
}

void Temperatura::setTempFahrenheit(double tf){
    tempKelvin=((tf-32)*5.0/9.0)+ctk;
}

void Temperatura::setTempCelsius(double tc){
    tempKelvin=tc+ctk;
}

void Temperatura::getTempKelvin(){
    cout<<"Temperatura en grados Kelvin: "<<tempKelvin<<" K"<<endl;
}

void Temperatura::getTempFahrenheit(){
    cout<<"Temperatura en grados Fahrenheit: "<<((tempKelvin-ctk)*9.0/5.0)+32<<" °F"<<endl;
}

void Temperatura::getTempCelsius(){
    cout<<"Temperatura en grados Celsius: "<<tempKelvin-ctk<<" °C"<<endl;
}