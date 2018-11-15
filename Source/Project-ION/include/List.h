#ifndef LIST_H
#define LIST_H
#include <cstddef> //library for NULL
#include <iostream>
using std::cout;
using std::endl;

template<class TYPE>
class List
{
public:
    List();
    virtual ~List();
    void include(TYPE newe);
    void go();
    int size();
    void clear();

    class Element{
        private:
            Element* next;
            TYPE data;
        public:
            Element();
            void setNext(Element* n);
            Element* getNext() {return next;}
            void setData(TYPE d);
            TYPE getData();
            ~Element();
    };

    TYPE at(int i){
        Element* aux = first;
        for(int j = 0; j < i; j++){
            aux = aux->getNext();
        }
        return aux->getData();
    }

private:
    Element* first;
    Element* current;
    int sizee;
};

template<class TYPE>
List<TYPE>::Element::Element(){
    next = NULL;
}

template<class TYPE>
List<TYPE>::Element::~Element(){}

template<class TYPE>
void List<TYPE>::Element::setNext(Element* n){
    next = n;
}

template<class TYPE>
void List<TYPE>::Element::setData(TYPE d){
    data = d;
}

template<class TYPE>
TYPE List<TYPE>::Element::getData(){
    return data;
}

template<class TYPE>
List<TYPE>::List(){
    first = NULL;
    current = NULL;
    sizee = 0;
}

template<class TYPE>
List<TYPE>::~List(){}

template<class TYPE>
void List<TYPE>::include(TYPE newe){
    List<TYPE>::Element* aux = new List<TYPE>::Element;
    aux->setData(newe);
    if(first == NULL){
        first = aux;
        current = first;
    }
    else{
        current->setNext(aux);
        current = aux;
    }
    sizee++;
}

template<class TYPE>
int List<TYPE>::size(){
    return sizee;
}

template<class TYPE>
void List<TYPE>::clear(){
    List<TYPE>::Element* aux = first;
    List<TYPE>::Element* aux2;
    while(aux != NULL){
        aux2 = aux->getNext();
        delete aux;
        aux = NULL;
        sizee--;
        aux = aux2;
    }
}

#endif // LIST_H
