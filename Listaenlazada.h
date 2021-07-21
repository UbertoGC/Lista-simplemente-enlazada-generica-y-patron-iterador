#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include <iostream>
#include "Iterator.h"
using namespace std;
template<typename Tipo>
class Listaenlazada{
    private:
    Nodo<Tipo> *head;
    int tama;
    public:
    Listaenlazada();
    Listaenlazada(Tipo a);
    int Size();
    void Anadir(Tipo a);
    void Eliminar(Tipo a);
    Nodo<Tipo>* begin();
    Nodo<Tipo>* end();
    ~Listaenlazada();
};
//Constructores
template<typename Tipo>
Listaenlazada<Tipo>::Listaenlazada(){
	head=nullptr;
    tama=0;
}
template<typename Tipo>
Listaenlazada<Tipo>::Listaenlazada(Tipo a){
    head=new Nodo<Tipo>(a);
    tama=1;
}
//Métodos
template<typename Tipo>
int Listaenlazada<Tipo>::Size(){
    return tama;
}
template<typename Tipo>
void Listaenlazada<Tipo>::Anadir(Tipo a){
    if (head==nullptr){
        head = new Nodo<Tipo>(a);
    }
    else{
        Nodo<Tipo> *tmp;
        tmp=head;
        while(tmp->Devolver()!=nullptr){
            tmp=tmp->Devolver();
        }
        tmp->Siguiente(a);
    }
    tama++;
}
template<typename Tipo>
void Listaenlazada<Tipo>::Eliminar(Tipo a){
    if (tama>0){
        if(head->Devol2()==a){
            if(tama>1){
                Nodo<Tipo> *tmp;
                tmp=new Nodo<Tipo>(*(head->Devolver()));
                delete head;
                head=tmp;
            }
            else{
                delete head;
                head=nullptr;
            }
        }
        else{
            Nodo<Tipo> *tmp;
            tmp=head;
            while(tmp->Devolver()->Devol2()!=a){
                tmp=tmp->Devolver();
            }
            if(tmp->Devolver()->Devolver()!=nullptr){
                Nodo<Tipo> *tmp2;
                tmp2=new Nodo<Tipo>(*(tmp->Devolver()->Devolver()));
                delete tmp->Devolver();
                *(tmp->Devolver())=*tmp2;
            }
            else{
                delete tmp->Devolver();
            }
        }
        tama--;
    }
}
//Métodos relacionados con Iterator
template<typename Tipo>
Nodo<Tipo> *Listaenlazada<Tipo>::begin(){
    return head;
}
template<typename Tipo>
Nodo<Tipo> *Listaenlazada<Tipo>::end(){
    Nodo<Tipo> *tmp;
    tmp=head;
    for (int i=0; i<tama-1; i++){
        tmp=tmp->Devolver();
    }
    return tmp;
}
//Destructor
template<typename Tipo>
Listaenlazada<Tipo>::~Listaenlazada(){
    delete head;
}
#endif