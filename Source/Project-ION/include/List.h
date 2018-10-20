#ifndef LIST_H
#define LIST_H
#include <cstddef> //library for NULL
#include <vector>

template<class TYPE>
class List
{
public:
    List();
    void include(TYPE newe);
    void deleteAll();
    int empty();
    TYPE operator[](int index);
    virtual ~List();
private:
    std::vector<TYPE> vec;
};

template<class TYPE>
List<TYPE>::List()
{}

template<class TYPE>
void List<TYPE>::include(TYPE newe){
    if(newe != NULL)
        vec.push_back(newe);
}

template<class TYPE>
void List<TYPE>::deleteAll(){
    typename std::vector<TYPE>::iterator itr = vec.begin();
    for(; itr != vec.end(); itr++)
        delete *itr;
    vec.clear();
}

template<class TYPE>
TYPE List<TYPE>::operator[](int index){
    return vec.at(index);
}

template<class TYPE>
int List<TYPE>::empty(){
    return vec.empty();
}


template<class TYPE>
List<TYPE>::~List()
{}

#endif // LIST_H
