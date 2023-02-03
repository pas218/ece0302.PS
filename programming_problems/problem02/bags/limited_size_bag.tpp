#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() 
{
  size = 0;
}
  
template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  if ((size >= 0) && (size < maxsize))
  {
    items[size] = item;
    size = size + 1;
    return true;
  }
  else{
    return false;
  }
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
  for (unsigned int i = 0; i < size; i++){
    if(items[i] == item){
      for(unsigned int j = i; j < size - 1; j++){
        items[j] = items[j+1];
      }
      size--;
      return true;
    }
  }
  return false;
}

template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  if (size == 0){
    return true;
  }
  else{
    return false;
  }
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return size;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  
  return getFrequencyOf(item) > 0;
}

template<typename T>
void LimitedSizeBag<T>::clear()
{
  size = 0;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{

  std::size_t freqOfItem = 0;
  for(unsigned int i = 0; i < size; i++){
    if (items[i] == item){
      freqOfItem ++;
    }
  }

  return freqOfItem;
};
