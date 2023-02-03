#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() {

  size = 0;
  items = new T(0);
}
  

template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag& x){

  size = x.getCurrentSize();

  items = new T(size);

  for(unsigned int i = 0; i < size; i++){
    items[i] = x.items[i];
  }
}
    
template<typename T>
DynamicBag<T>::~DynamicBag(){
  delete [] items;
}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T> x)
{  
  if (this != &x){
    
    size = x.getCurrentSize();
    items = new T(size);

    for(unsigned int i = 0; i < size; i++){
      items[i] = x.items[i];
    }

  }
  return *this;
}

template<typename T>
void DynamicBag<T>::swap(DynamicBag<T>& x){

  std::size_t swappingSize = x.getCurrentSize();

  T* holderPtr = new T[swappingSize];

    for(unsigned int i = 0; i < swappingSize; i++){
      holderPtr[i] = x.items[i];
    }

    x.clear();
    for(unsigned int i = 0; i < size; i++){
      x.add(items[i]);
    }

    clear();
    for(unsigned int i = 0; i < swappingSize; i++){
      add(holderPtr[i]);
    }

  delete [] holderPtr;
}


template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  items[size] = item;
  size = size + 1;
  return true;
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  for (unsigned int i = 0; i < size; i++){
    if(items[i] == item){
      for(unsigned int j = i; j < size - 1; j++){
        items[j] = items[j+1];
      }
      size--;
      return 1;
    }
  }
  return 0;
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  if (size == 0){
    return true;
  }
  else{
    return false;
  }
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return size;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  return getFrequencyOf(item) > 0;
}

template<typename T>
void DynamicBag<T>::clear(){
  size = 0;
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{

  std::size_t freqOfItem = 0;
  for(unsigned int i = 0; i < size; i++){
    if (items[i] == item){
      freqOfItem ++;
    }
  }

  return freqOfItem;
};



