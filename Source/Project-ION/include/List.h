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

        //template<class TYPE>
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
        };

    private:
        Element* first;
        Element* current;
};

template<class TYPE>
List<TYPE>::Element::Element(){
    next = NULL;
}

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

//template<class TYPE>
//List<TYPE>::Element *List<TYPE>::Element::getNext(){
//    return next;
//}

template<class TYPE>
List<TYPE>::List(){
    first = NULL;
    current = NULL;
}

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
}

template<class TYPE>
void List<TYPE>::go(){
    List<TYPE>::Element* aux = first;
    while(aux != NULL){
        cout << aux->getData() << endl;
        aux = aux->getNext();
    }
}

#endif // LIST_H
