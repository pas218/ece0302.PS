#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList(){
  length = 0;
  list = new T[length];
}

template <typename T>
ArrayList<T>::~ArrayList(){
  delete [] list;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList& rhs)
{
  length == rhs.getLength();
  for(unsigned i = 0; i < length; i++){
    list[i] = rhs.list[i];
  }
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList rhs){

  ArrayList* helper;

  helper->length == rhs.getLength();
  for(unsigned i = 0; i < length; i++){
    helper->list[i] = rhs.list[i];
  }

  return *helper;
}

template <typename T>
void ArrayList<T>::swap(ArrayList& rhs){
  
  ArrayList* helper;

  helper->clear();
  unsigned int swapLength = rhs.getLength();

  for(unsigned i = 0;i < swapLength; i++){
    helper->list[i] = rhs.list[i];
  }
  
  rhs.clear();
  for(unsigned int i = 0; i < length; i++){
    rhs.list[i] = list[i];
  }

  clear();
  for(unsigned i = 0;i < swapLength; i++){
    list[i] = helper->list[i];
  }

  delete helper;

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
  
  if((position >= 0) && (position <= length)){

    length++;
    for(unsigned int i = position; i < length; i++){
      list[i+1] = list[i];
    }

    list[position] = item;
    return 1;
  }
  else{
    return 0;
  }
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  
  if((position >=0) && (position < length)){

    length--;
    for(unsigned int i = position; i < length; i++){
      list[i] = list[i+1];
    }

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
  
  if((position >=0) && (position < length)){

    return list[position];
  }
  else{
    return -1;
  }
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue){

  if((position >=0) && (position < length)){

    list[position] = newValue;

  }
}
