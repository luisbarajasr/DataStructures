#ifndef _DoubleLinkedList_H_
#define _DoubleLinkedList_H_

#include "DLLNode.h"
#include <iostream>

template <class T> 
class DoubleLinkedList {
  private:
    DLLNode<T> *head;
    DLLNode<T> *tail;
    int numElements;
  
  public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    int getNumElements();
    void printList();
    void addFirst(T value);
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
DoubleLinkedList<T>::DoubleLinkedList() {
  std::cout << "-------CREANDO UNA LISTA VACIA----------" << std::endl;
  head = nullptr;
  tail = nullptr;
  numElements = 0;
}

template <class T> 
DoubleLinkedList<T>::~DoubleLinkedList() {
  std::cout << "---------LIBERANDO MEMORIA DE LA LISTA-------------"<< std::endl;

  // Elimina todos los nodos uno por uno
  DLLNode<T> *prev, *q;
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
int DoubleLinkedList<T>::getNumElements() { 
  return numElements; 
}

template <class T> 
void DoubleLinkedList<T>::printList() {
  DLLNode<T> *ptr = head;

  while (ptr != nullptr) {
    std::cout << ptr->data << " ";
    ptr = ptr->next;
  }
  std::cout << std::endl;
}

template <class T> 
void DoubleLinkedList<T>::addFirst(T value) {
  // Creando un nuevo nodo de la lista

  DLLNode<T> *newDLLNode = new DLLNode<T>(value); 
  // Se llama al constructor DLLNode<T> --------ptr esta apuntando a este Nodo

  // Si la lista esta vacia if(head == nullptr)
  if (numElements == 0) {
    head = tail = newDLLNode;
  } 
  else {
    newDLLNode->next = head;
    head->prev = newDLLNode; 
    head = newDLLNode;
  }

  numElements++;
}

template <class T> 
void DoubleLinkedList<T>::addLast(T value) {
  // Creando un nuevo nodo de la lista

  DLLNode<T> *ptr = new DLLNode<T>(value);

  // Si la lista esta vacia if(head == nullptr)
  if (numElements == 0) {
    addFirst(value);
  } 
  else {
    DLLNode<T> *newDLLNode = new DLLNode<T>(value); // Se crea un nuevo nodo
    tail->next = newDLLNode; // El apuntador tail apunta al nuevo nodo del final
    newDLLNode->prev = tail; 
    tail = newDLLNode; // El apuntador tail sera igual al ultimo nodo (el nuevo creado)
    numElements++;
  }
}

template <class T> 
bool DoubleLinkedList<T>::deleteData(T value) {
  bool estado = false; 

  //Si la lista esta vacia 
  if(numElements == 0){
    return estado; 
  }
  else{
    DLLNode<T> *p = head;
    DLLNode<T> *previo = nullptr;

    //Buscar el valor en la lista: mientras el apuntador apunte diferente a "nullptr" y tenga un dato diferente al buscado 
    while(p != nullptr && p->data != value){
      previo = p; 
      p = p->next; 
    }

    //Si no esta value en la lista 
    if(p == nullptr)
      return estado; 

    //Si debe borrarse el primer elemento en la lista 
    if(p == head){
      head = p->next;

      if(head != nullptr){
        head->prev = nullptr; 
      }  
    }
    else if(p->next == nullptr){ //borrar ultimo en la lista 
      previo->next = nullptr; 
      tail = previo; 
    }
    else{
      previo-> next = p->next; 
      p->next->prev = p->prev; 
      
    }

    delete p; 
    numElements--; 
    estado = true; 
    return estado; 
    
  }
}

template <class T>
bool DoubleLinkedList<T>::deleteAt(int position){
  bool estado = false; 

  if(position < 0 || position >= numElements){
    throw std::out_of_range("Indice fuera de rango"); 
  }
  else if(position == 0){ //Si debe borrarse el primer elemento
    
    DLLNode<T> *p = head; 

    //Si la lista contiene un solo nodo 
    if(head != nullptr && head->next == nullptr){
      head = nullptr; 
      tail = nullptr;
    }
    else{
      head = p->next;
      head->prev = nullptr; 
    }

    delete p; 
    numElements--; 
    estado = true; 
    return estado; 
  }
  else{ //Si posicion > 0 
    DLLNode<T> *p = head; 
    DLLNode<T> *q = nullptr; 
    int index = 0; 

    //Buscar el indice en la lista 
    while(index != position){
      q = p; 
      p = p->next; 
      index++;
    }

    //Si debo de borrar el ultimo elemento 
    if(p->next == nullptr){
      q->next = nullptr; 
      tail = q;   
    }
    else{
      q->next = p->next; 
      p->next->prev = q; 
    }

    delete p; 
    numElements--; 
    estado = true; 
    return estado; 
  }
}

template <class T> 
T DoubleLinkedList<T>::getData(int posicion){
  
  if(posicion < 0 || posicion >= numElements){
    throw std::out_of_range("Indice fuera de rango"); 
  }
  else{
    if(posicion == 0){
      return head->data; 
    }

    DLLNode<T> *p = head; 
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
void DoubleLinkedList<T>::updateData(T value, T newValue){
  DLLNode<T> *p = head; 

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

#endif //_DoubleLinkedList_H_