#include "sorted_list.hpp"

template <typename T, typename L>
SortedList<T, L>::SortedList()
{
  // nothing to do, plist gets created on the stack
}

template <typename T, typename L>
SortedList<T, L>::SortedList(const SortedList<T, L> & x)
{
  plist = x.plist; // use copy assignment to implement copy construction
}

template <typename T, typename L>
SortedList<T, L>& SortedList<T, L>::operator=(SortedList<T, L> x)
{
  plist = x.plist;
  return *this;
}

template <typename T, typename L>
SortedList<T, L>::~SortedList()
{
  // plist destructor gets called automatically
}

template <typename T, typename L>
bool SortedList<T, L>::isEmpty() const noexcept
{
  return plist.isEmpty();
}

template <typename T, typename L>
std::size_t SortedList<T, L>::getLength() const noexcept
{
  return plist.getLength();
}

template <typename T, typename L>
void SortedList<T, L>::insert(const T& item)
{
  //helper item for comparison
  T compareHelper;

  //if length is zero, just insert at beginning
  if (isEmpty()){
    plist.insert(0, item);
  }

  //else, need to find its place in the order
  else{

    //see if item is larger than anything else in list, if so, add it to end of list
    compareHelper = getEntry(plist.getLength() - 1);
    if (item > compareHelper){
      plist.insert(getLength(), item);
    }

    //if item isnt largest, see where it fits and place it there
    else{


      for (unsigned i = 0; i < plist.getLength(); i++){
        
        //get item
        compareHelper = getEntry(i);

        //if item is less than then the comparer item, insert it at that position
        if(item <= compareHelper){
          plist.insert(i, item);
          break;
        }
        
      }
    }
  }
}

template <typename T, typename L>
void SortedList<T, L>::remove(const T& item)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  //helper var
  int positionVar;

  //get item position
  positionVar = getPosition(item);

  //remove at that position
  removeAt(positionVar);
}

template <typename T, typename L>
void SortedList<T, L>::removeAt(std::size_t position)
{
  plist.remove(position);
}

template <typename T, typename L>
void SortedList<T, L>::clear()
{
  plist.clear();
}

template <typename T, typename L>
T SortedList<T, L>::getEntry(std::size_t position) const
{
  return plist.getEntry(position);
}

template <typename T, typename L>
long int SortedList<T, L>::getPosition(const T& newValue)
{
  //start searching loop
  for (unsigned i = 0; i < plist.getLength(); i++){

    //check if item at point is the specified item
    if (newValue == getEntry(i)){
      return i;
    }
  }

  //if not in list, return -1
  return -1;
}
