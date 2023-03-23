#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>()
{
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(LinkedList<T> unsorted_list) 
{
  
  //loop through variables in input list
  for (unsigned i = 0; i < unsorted_list.getLength(); i++){

    //add item to sort list
    insert(unsorted_list.getEntry(i));
  }
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{
}

template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(SortedLinkedList<T> x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedLinkedList<T>::isEmpty() const noexcept
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength() const noexcept
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{

  //helper item for comparison
  T compareHelper;

  //if length is zero, just insert at beginning
  if (isEmpty()){
    LinkedList<T>::insert(0, item);
  }

  //else, need to find its place in the order
  else{

    //see if item is larger than anything else in list, if so, add it to end of list
    compareHelper = getEntry(LinkedList<T>::getLength() - 1);
    if (item > compareHelper){
      LinkedList<T>::insert(getLength(), item);
    }

    //if item isnt largest, see where it fits and place it there
    else{


      for (unsigned i = 0; i < LinkedList<T>::getLength(); i++){
        
        //get item
        compareHelper = getEntry(i);

        //if item is less than then the comparer item, insert it at that position
        if(item <= compareHelper){
          LinkedList<T>::insert(i, item);
          break;
        }
        
    }
  }

    
  
  }
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  //helper var
  int positionVar;

  //get item position
  positionVar = getPosition(item);

  //remove at that position
  removeAt(positionVar);

}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  //remove item
  LinkedList<T>::remove(position);
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position) const
{
  return LinkedList<T>::getEntry(position);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& item)
{
  
  
  //start searching loop
  for (unsigned i = 0; i < LinkedList<T>::getLength(); i++){

    //check if item at point is the specified item
    if (item == getEntry(i)){
      return i;
    }

  }

  //if not in list, return -1
  return -1;
}
