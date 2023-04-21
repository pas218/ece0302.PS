#include "list.hpp"

template <typename T>
List<T>::List(){

  //default values
  length = 0;
  list = new T[65536];
}

template <typename T>
List<T>::~List(){
  delete [] list;
}

template <typename T>
List<T>::List(const List& rhs)
{
  
  length = rhs.getLength();
  list = new T[10000];

  //populate this list with argumanet
  for(unsigned i = 0; i < length; i++){
    setEntry(i, rhs.getEntry(i));
  }
}

template <typename T>
List<T>& List<T>::operator=(List rhs){

  //make sure the argument inst this list
  if (this != &rhs){  
    
    length = rhs.getLength();
    list = new T[10000];
    
    //populate this list with argumanet
    for(unsigned i = 0; i < length; i++){
      setEntry(i, rhs.getEntry(i));
    }
  }   

  return *this;
}

template <typename T>
void List<T>::swap(List& rhs){

  //helepr array
  T holder[length];

  //populate array with argumant
  for (unsigned i = 0; i < length; i++){
    holder[i] = rhs.getEntry(i);
  }

  //populate arguemtn with this array
  rhs.clear();
  for (unsigned i = 0; i < length; i++){
    rhs.insert(i, getEntry(i));
  }

  //populate this array with argument via helper array
  for (unsigned i = 0; i < length; i++){
    setEntry(i, holder[i]);
  }


}

template <typename T>
bool List<T>::isEmpty() const noexcept {
  return length == 0;
}

template <typename T>
std::size_t List<T>::getLength() const noexcept {
  return length;
}

template <typename T>
void List<T>::insert(std::size_t position, const T& item){
  

  //check validity of position
  if((position >= 0) && (position <= length)){


    //make space for new item    
    for(unsigned int i = length; i > position; i--){
      list[i] = list[i - 1];
    }

    //add item
    list[position] = item;
    length++;
  }
 
}

template <typename T>
void List<T>::remove(std::size_t position){
  
  //check position validity
  if((position >= 0) && (position < length)){

    //shift all items from input position back
    for(unsigned int i = position; i < length - 1; i++){
      list[i] = list[i+1];
    }

    length--;
  }
  
}

template <typename T>
void List<T>::clear(){
  length = 0;

}

template <typename T>
T List<T>::getEntry(std::size_t position) const {
  
  //check position validity
  if((position >= 0) && (position < length)){

    return list[position];
  }
  else{
    T dummy;
    return dummy;
  }
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T& newValue){

  //check position validity
  if((position >= 0) && (position < length)){
    list[position] = newValue;

  }
}
