#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  //default values
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

  //populate this linked list with argument values
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

    //populate this linked list with argument values
    for(int i = 0; i < x.getLength(); i++){
      insert(i, x.getEntry(i));
    }
  }

  return *this;
}

template <typename T>
void LinkedList<T>::swap(LinkedList &x)
{
  

  //helper array
  T helper[length];

  //populate helper with argument list
  for(int i = 0; i < length; i++){
    helper[i] = x.getEntry(i);
  }

  //populate argument with this list
  for(int i = 0; i < length; i++){
    x.setEntry(i, getEntry(i));
  }

  //populate this list with argument via helper array
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
 

  //if statement to make sure position is valid
  if((position >=0) && (position <= length)){
    
    //make new node
    Node<T>* newPtr = new Node<T>(item);

    //case that position is 0
    if(position == 0){
      
      newPtr->setNext(headPtr);
      headPtr = newPtr;
      
    }

    //case position isnt zero
    else{

      //find previous pointer
      Node<T>* prevPtr = headPtr;
      for(unsigned i = 0; i < position - 1; i++){
        prevPtr = prevPtr->getNext();
      }

      //insert new node
      newPtr->setNext(prevPtr->getNext());
      prevPtr->setNext(newPtr);
    }

    length++;
    return 1;
  }
  else{
    return 0;
  }
}


template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  
   
    //make sure position is valid
    if((position >=0) && (position <= length)){
    

      //case position is zero
      if(position == 0){
        
        headPtr = headPtr->getNext();
        
      }

      //case position isnt zero
      else{

        //helper pointers
        Node<T>* prevPtr = headPtr;
        Node<T>* deletePtr = headPtr;

        //locate helpers
        for(unsigned i = 0; i < position - 1; i++){
          prevPtr = prevPtr->getNext();
        }

        for(unsigned i = 0; i < position; i++){
          deletePtr = deletePtr->getNext();
        }

        //delete desired pointer
        prevPtr->setNext(deletePtr->getNext());
      }

    length--;
    return 1;
  }
  else{
    return 0;
  }
  
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

  //check validity of position
  if((position >=0) && (position < length)){
    
    Node<T>* helper = headPtr;

    //find pointer loaction
    for(unsigned i = 0; i < position; i++){
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

  //check valaidity of position
  if((position >=0) && (position < length)){
    
    Node<T>* helper = headPtr;

    //get pointer location
    for(unsigned i = 0; i < position; i++){
      helper = helper->getNext();
    }

  helper->setItem(newValue);
  }
  
}

