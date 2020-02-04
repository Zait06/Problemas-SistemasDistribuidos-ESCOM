#include "Fraccion.h"
#include <iostream>
using namespace std;

int main(){
    int a,b;
    Fraccion ff;
    
    cout<<"Ingrese una fraccion [numerador] [denominador]: ";
    cin>>a>>b;
    ff.inicializaFraccion(a,b);
    ff.muestraFraccion();
    cout<<"La division da como resultado: "<<ff.division()<<endl;
    ff.fraccionMinima();

    return 0;
}