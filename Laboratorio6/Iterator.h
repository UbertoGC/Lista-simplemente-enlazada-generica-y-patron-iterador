#ifndef ITERATOR_H
#define ITERATOR_H
#include "Nodo.h"
template <typename Tipo>
class Iterator;
template <typename Tipo>
ostream& operator << (ostream &o, const Iterator<Tipo> &a);
template<typename Tipo>
class Iterator{
    private:
    Nodo<Tipo> *g;
    public:
    Iterator(Nodo<Tipo> *b);
    friend ostream& operator << <>(ostream &o, const Iterator<Tipo> &a);
    Iterator<Tipo>& operator ++();
    bool operator!=(Nodo<Tipo>*p);
    ~Iterator();
};
//Constructores
template<typename Tipo>
Iterator<Tipo>::Iterator(Nodo<Tipo> *b){
    g=b;
}
template<typename Tipo>
//Operadores
ostream& operator << (ostream &o, const Iterator<Tipo> &a){
    o<<a.g->Devol2();
    return o;
}
template<typename Tipo>
Iterator<Tipo>& Iterator<Tipo>::operator ++(){
    if(this->g->Devolver()==nullptr){
        this->g=nullptr;
    }
    else{
        this->g=this->g->Devolver();
    }
    return *this;
}
template<typename Tipo>
bool Iterator<Tipo>::operator!=(Nodo<Tipo>*p){
    return this->g!=p->Devolver();
}
//Destructor
template<typename Tipo>
Iterator<Tipo>::~Iterator(){
    delete g;
}
#endif