#include "list.hpp"

template <typename T>
List<T>::List()
{
  //default values
  headPtr = nullptr;
  length = 0;
}

template <typename T>
List<T>::~List()
{
  clear();
}

template <typename T>
List<T>::List(const List<T> &x)
{

  length = 0;
  headPtr = nullptr;

  //populate this linked list with argument values
  for(int i = 0; i < x.getLength(); i++){
    insert(i, x.getEntry(i));
  }
}

template <typename T>
List<T> &List<T>::operator=(List<T> x)
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
void List<T>::swap(List<T> &x)
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
bool List<T>::isEmpty() const noexcept
{
  return (length == 0);
}

template <typename T>
std::size_t List<T>::getLength() const noexcept
{
  return length;
}

template <typename T>
void List<T>::insert(std::size_t position, const T &item)
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
  }
  else{
    throw(std::range_error("out of range"));
  }
  
}


template <typename T>
void List<T>::remove(std::size_t position)
{
  
   
    //make sure position is valid
    if((position >=0) && (position < length)){
    

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
  }
  else{
    throw(std::range_error("out of range"));
  }
  
  
}

template <typename T>
void List<T>::clear()
{
  while(!isEmpty()){
    remove(0);
  }
}

template <typename T>
T List<T>::getEntry(std::size_t position) const
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
void List<T>::setEntry(std::size_t position, const T &newValue)
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

template<class ItemType>
Node<ItemType>::Node() : next(nullptr)
{
} // end default constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr)
{
} // end constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) :
                item(anItem), next(nextNodePtr)
{
} // end constructor

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
   item = anItem;
} // end setItem

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
   next = nextNodePtr;
} // end setNext

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
   return item;
} // end getItem

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
   return next;
} // end getNext
