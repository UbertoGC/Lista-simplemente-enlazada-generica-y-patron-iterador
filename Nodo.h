#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;
template<typename Tipo>
class Nodo{
    private:
    Tipo head;
    Nodo<Tipo> *sig;
    public:
    Nodo(Tipo a);
    Nodo(Nodo<Tipo> &a);
    void Siguiente(Tipo a);
    Nodo<Tipo> *Devolver();
    Tipo Devol2();
    
};
//Constructores
template<typename Tipo>
Nodo<Tipo>::Nodo(Tipo a){
    sig=nullptr;
    head=a;
}
template<typename Tipo>
Nodo<Tipo>::Nodo(Nodo<Tipo> &a){
    this->head=a.head;
    if(a.sig==nullptr){
        this->sig=nullptr;
    }
    else{
        this->sig=new Nodo<Tipo>(a.sig->head);
        Nodo<Tipo> *tmp;
        tmp=a.sig;
        Nodo<Tipo> *tmp2;
        tmp2=this->sig;
        while(tmp->sig!=nullptr){
            tmp2->sig=new Nodo<Tipo>(tmp->sig->head);
            tmp=tmp->sig;
            tmp2=tmp2->sig;
        }
        tmp->sig=nullptr;
    }
}
//Métodos
template<typename Tipo>
void Nodo<Tipo>::Siguiente(Tipo a){
    sig=new Nodo<Tipo>(a);
}
template<typename Tipo>
Nodo<Tipo> *Nodo<Tipo>::Devolver(){
    return sig;
}
template<typename Tipo>
Tipo Nodo<Tipo>::Devol2(){
    return head;
}
#endif