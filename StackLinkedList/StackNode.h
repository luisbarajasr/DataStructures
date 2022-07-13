#ifndef _StackNode_H_
#define _StackNode_H_

template <class T>
class StackNode{

  public: 
    T data; 
    StackNode<T> *next; //Apuntador 

    StackNode(); 
    StackNode(T value); 
}; 

template<class T> 
StackNode<T>::StackNode() : data{}, next{nullptr}{}

template<class T> 
StackNode<T>::StackNode(T value){
  data = value; //En la casilla guardara value 
  next = nullptr ; //Va apuntar al vacio 
}


#endif //_StackNode_H_