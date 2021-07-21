#include <iostream>
#include "Listaenlazada.h"
using namespace std;
int main(){
	//con strings
    Listaenlazada<string> a;
    a.Anadir("hola");
    a.Anadir("como");
    a.Anadir("estas");
    a.Anadir("amigo");
    a.Anadir("compa");
    a.Anadir("causa");
    Iterator<string> i(a.begin());
    for (;i!=a.end();++i){
        cout<<i<<" ";
    }
    cout<<endl;
    //con enteros
    Listaenlazada<int> b;
    b.Anadir(6);
    b.Anadir(5);
    b.Anadir(8);
    b.Anadir(1);
    Iterator<int> j(b.begin());
    for (;j!=b.end();++j){
        cout<<j<<" ";
    }
    return 0;
}
