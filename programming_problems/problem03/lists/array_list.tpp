#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList(){

  //default values
  length = 0;
  list = new T[65536];
}

template <typename T>
ArrayList<T>::~ArrayList(){
  delete [] list;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList& rhs)
{
  
  length = rhs.getLength();
  list = new T(65536);

  //populate this list with argumanet
  for(unsigned i = 0; i < length; i++){
    setEntry(i, rhs.getEntry(i));
  }
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList rhs){

  //make sure the argument inst this list
  if (this != &rhs){  
    
    length = rhs.getLength();
    list = new T(65536);
    
    //populate this list with argumanet
    for(unsigned i = 0; i < length; i++){
      setEntry(i, rhs.getEntry(i));
    }
  }   

  return *this;
}

template <typename T>
void ArrayList<T>::swap(ArrayList& rhs){

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
bool ArrayList<T>::isEmpty() const noexcept {
  return length == 0;
}

template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept {
  return length;
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  

  //check validity of position
  if((position >= 0) && (position <= length)){


    //make space for new item    
    for(unsigned int i = length; i > position; i--){
      list[i] = list[i - 1];
    }

    //add item
    list[position] = item;
    length++;
    return 1;
  }
  else{
    return 0;
  }
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  
  //check position validity
  if((position >= 0) && (position < length)){

    //shift all items from input position back
    for(unsigned int i = position; i < length - 1; i++){
      list[i] = list[i+1];
    }

    length--;
    return 1;
  }
  else{
    return 0;
  }
}

template <typename T>
void ArrayList<T>::clear(){
  length = 0;

}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
  
  //check position validity
  if((position >= 0) && (position < length)){

    return list[position];
  }
  else{
    return 0;
  }
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue){

  //check position validity
  if((position >= 0) && (position < length)){
    list[position] = newValue;

  }
}
