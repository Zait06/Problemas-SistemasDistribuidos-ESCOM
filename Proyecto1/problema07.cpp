#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,j,*k;
    vector<bool> numeros;
    vector<bool>::iterator i;

    cout<<"Ingrese un numero cualquiera: ";
    cin>>n;

    numeros.reserve(n);
    for(j=0;j<n;j++){
        numeros[j]=true;
    }

    for(i=numeros.begin()+2;i!=numeros.end();i++){
    }
}