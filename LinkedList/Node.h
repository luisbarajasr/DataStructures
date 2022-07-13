#ifdef _NODE_H_
#define _NODE_H_

template <class T>
class Node{

  public: 
    T data; 
    Node<T> *next; //Apuntador 

    Node(); 
    Node(T value); 
}; 

template<class T> 
Node<T>::Node() : data{}, next{nullptr}{}

template<class T> 
Node<T>::Node(T value){
  data = value; //En la casilla guardara value 
  next = nullptr ; //Va apuntar al vacio 
}


#endif //_NODE_H_