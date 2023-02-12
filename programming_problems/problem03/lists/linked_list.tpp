#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  headPtr = nullptr;
  length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  clear();
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &x)
{

  length = 0;
  headPtr = nullptr;

  for(int i = 0; i < x.getLength(); i++){
    insert(i, x.getEntry(i));
  }
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> x)
{
  
  if(this != &x){

    length = 0;
    headPtr = nullptr;

    for(int i = 0; i < x.getLength(); i++){
      insert(i, x.getEntry(i));
    }
  }

  return *this;
}

template <typename T>
void LinkedList<T>::swap(LinkedList &x)
{
  

  T helper[length];

  for(int i = 0; i < length; i++){
    helper[i] = x.getEntry(i);
  }

  for(int i = 0; i < length; i++){
    x.setEntry(i, getEntry(i));
  }

  for(int i = 0; i < length; i++){
    setEntry(i, helper[i]);
  }

}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  return (length == 0);
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  return length;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T &item)
{
 
  if((position >=0) && (position <= length)){
    
    Node<T>* newPtr = new Node<T>(item);

    if(position == 0){
      
      newPtr->setNext(headPtr);
      headPtr = newPtr;

      length++;
      
    }
    else{

      Node<T>* prevPtr = headPtr;

      for(unsigned i = position; i > length; i++){
        prevPtr = prevPtr->getNext();
      }

      newPtr->setNext(prevPtr->getNext());
      prevPtr->setNext(newPtr);
    }

    length++;
  }
  else{
    return 0;
  }
}


template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  
   
    return 0;
  
}

template <typename T>
void LinkedList<T>::clear()
{
  while(!isEmpty()){
    remove(0);
  }
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  if((position >=0) && (position < length)){
    
    Node<T>* helper = headPtr;

    for(int i = position; i < length; i++){
      helper = helper->getNext();
    }

    return helper->getItem();
    
  }
  else{
    return 0;
  }
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T &newValue)
{
  if((position >=0) && (position < length)){
    
    Node<T>* helper = headPtr;

    for(int i = position; i < length; i++){
      helper = helper->getNext();
    }

  helper->setItem(newValue);
  }
  
}
