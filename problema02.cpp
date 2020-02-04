#include <iostream>
using namespace std;

int main(){
    const double GRAVEDAD=9.81;
    double tiempo;
    
    cout<<"Ingrese el tiempo que tardo la pelota de tenis al llegar al piso en segundos: ";
    cin>>tiempo;

    cout<<"La altura del edificio es de: "<<tiempo*tiempo*GRAVEDAD/2.0<<" m^2"<<endl;

    return 0;
}