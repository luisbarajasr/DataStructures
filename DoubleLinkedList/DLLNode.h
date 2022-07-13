#ifndef _DLLNode_H_
#define _DLLNode_H_

template <class T>
class DLLNode{

  public: 
    T data; 
    DLLNode<T> *next; //Apuntador al nodo sig
    DLLNode<T> *prev; //Apuntador al nodo pasado 

    DLLNode(); 
    DLLNode(T value); 
}; 

template<class T> 
DLLNode<T>::DLLNode() : data{}, next{nullptr}{}

template<class T> 
DLLNode<T>::DLLNode(T value){
  data = value; //En la casilla guardara value 
  next = nullptr ; //Va apuntar al vacio 
}


#endif //_DLLNode_H_