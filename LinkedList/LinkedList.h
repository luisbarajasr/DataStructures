#ifdef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "Node.h"
#include <iostream>

template <class T> 
class LinkedList {
  private:
    Node<T> *head;
    Node<T> *tail;
    int numElements;
  
  public:
    LinkedList();
    ~LinkedList();
    int getNumElements();
    void printList();
    void addFirs(T value);
    void addLast(T value);
    bool deleteData(T value);
    bool deleteAt(int position); 
    T getData(int posicion); 
    void updateData(T value, T newValue); 

  //HACER: 
  //getData()
  //updateData()
  //updateAt()

};

template <class T> 
LinkedList<T>::LinkedList() {
  std::cout << "-------CREANDO UNA LISTA VACIA----------" << std::endl;
  head = nullptr;
  tail = nullptr;
  numElements = 0;
}

template <class T> 
LinkedList<T>::~LinkedList() {
  std::cout << "---------LIBERANDO MEMORIA DE LA LISTA-------------"<< std::endl;

  // Elimina todos los nodos uno por uno
  Node<T> *prev, *q;
  prev = head;
  
  while (prev != nullptr) {
    q = prev->next;
    delete prev;
    prev = q;
  }
  head = nullptr;
  tail = nullptr;
  numElements = 0;
}


template <class T> 
int LinkedList<T>::getNumElements() { 
  return numElements; 
}

template <class T> 
void LinkedList<T>::printList() {
  Node<T> *ptr = head;

  while (ptr != nullptr) {
    std::cout << ptr->data << " ";
    ptr = ptr->next;
  }
  std::cout << std::endl;
}

template <class T> 
void LinkedList<T>::addFirst(T value) {
  // Creando un nuevo nodo de la lista

  Node<T> *newNode = new Node<T>(value); 
  // Se llama al constructor Node<T> --------ptr esta apuntando a este Nodo

  // Si la lista esta vacia if(head == nullptr)
  if (numElements == 0) {
    head = tail = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }

  numElements++;
}

template <class T> 
void LinkedList<T>::addLast(T value) {
  // Creando un nuevo nodo de la lista

  Node<T> *ptr = new Node<T>(value);

  // Si la lista esta vacia if(head == nullptr)
  if (numElements == 0) {
    addFirst(value);
  } 
  else {
    Node<T> *newNode = new Node<T>(value); // Se crea un nuevo nodo
    tail->next = newNode; // El apuntador tail apunta al nuevo nodo del final
    tail = newNode; // El apuntador tail sera igual al ultimo nodo (el nuevo creado)
    numElements++;
  }
}

template <class T> 
bool LinkedList<T>::deleteData(T value) {
  bool estado = false; 

  //Si la lista esta vacia 
  if(numElements == 0){
    return estado; 
  }
  else{
    Node<T> *p = head;
    Node<T> *prev = nullptr;

    //Buscar el valor en la lista: mientras el apuntador apunte diferente a "nullptr" y tenga un dato diferente al buscado 
    while(p != nullptr && p->data != value){
      prev = p; 
      p = p->next; 
    }

    //Si no esta value en la lista 
    if(p == nullptr)
      return estado; 

    //Si debe borrarse el primer elemento en la lista 
    if(p == head){
      head = p->next; 
    }
    else if(p->next == nullptr){ //borrar ultimo en la lista 
      prev->next = nullptr; 
      tail = prev; 
    }
    else{
      prev-> next = p->next; 
    }

    delete p; 
    numElements--; 
    estado = true; 
    return estado; 
    
  }
}

template <class T>
bool LinkedList<T>::deleteAt(){
  bool estado = false; 

  if(position < 0 || position >= numElements){
    throw std::out_of_range("Indice fuera de rango"); 
  }
  else if(position == 0){
    Node<T> *p = head; 

    //Si la lista contiene un solo nodo 
    if(head != nullptr && head->next == nullptr){
      head = nullptr; 
      tail = nullptr;
    }
    else{
      head = p->next; 
    }

    delete p; 
    numElements--; 
    estado = true; 
    return estado; 
  }
  else{
    Node<T> *p = head; 
    Node<T> *prev = nullptr; 
    int index = 0; 

    //Buscar el indice en la lista 
    while(index != position){
      prev = p; 
      p = p->next; 
      index++;
    }

    //Si debo de borrar el ultimo elemento 
    if(p->next == nullptr){
      prev->next = nullptr; 
      tail = prev;   
    }
    else{
      prev->next = p->next; 
    }

    delete p; 
    numElements--; 
    estado = true; 
    return estado; 
  }
}

template <class T> 
T LinkedList<T>::getData(int posicion){
  
  if(position < 0 || position >= numElements){
    throw std::out_of_range("Indice fuera de rango"); 
  }
  else{
    if(posicion == 0){
      return head->data; 
    }

    Node<T> *p = head; 
    int index = 0; 

    while(p != nullptr){

      if(index == posicion)
        return p->data; 

      index++; 
      p = p->next; 
    }
    return -1; 
    
  }
}


template<class T> 
void LinkedList<T>::updateData(T value, T newValue){
  Node<T> *p = head; 

  while(p->next != nullptr){
    if(p->data == value){
      p->data = newValue; 
      break; 
    }
    p = p->next; 
  }

  if(p == nullptr)
    throw std::out_of_range("Valor no encontrado en la lista");
  
}

/*
else if(posicion == numElements-1){
      return tail->data; 
    }

*/
#endif //_LINKEDLIST_H_