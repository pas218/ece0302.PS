#ifndef _ABSTRACT_BAG_HPP_
#define _ABSTRACT_BAG_HPP_

#include <cstdlib>

/** abstract base class for bags
 * @author Pavel Serhiayenka
 * @file abstract_bag.hpp
*/

template<typename T> class AbstractBag
{
public:

  /** 
   * @param accesses the number of elements in the bag
   * @pre : function takes no input
   * @post : method returns the current number of elements in the bag
   * @return number of elements in bag
  */
  virtual std::size_t getCurrentSize() const = 0;

  /** 
   * @param tell user if the bag is empty
   * @pre : function takes no input
   * @post : method returns to the user a bool value
   * @return meaning of return value: 1 = empty, 0 = not empty
  */
  virtual bool isEmpty() const = 0;


  /** 
   * @param adds item to the bag
   * @pre : the input value must be of type T, which is defined at class declaration
   * @pre : the current size cannot be equal to the Max Size
   * @post : method adds the item to the bag, and increases the size by one
   * @post : if the size is equal to the maxsize, then the item will not be added 
   * @return returns a bool; meaning of return value: 1 = successfully added, 0 = bag is full, cannot add
  */
  virtual bool add(const T& entry) = 0;

  /** 
   * @param removes item from the bag
   * @pre : the input value must be of type T, which is defined at class declaration
   * @pre : the current size cannot be equal to zero and the item must exist in the bag
   * @post : method removes the first instance of this item in the bag and reduces size by one
   * @post : if the size is 0, or the item does not exist, the function will return a bool 0
   * @return returns a bool; meaning of return value: 1 = successfully removed, 0 = bag is empty/ item doesnt exist
  */
  virtual bool remove(const T& entry) = 0;

  /** 
   * @param clears contents from bag
   * @pre : method takes no parameters
   * @post :size of bag will be zero
  */
  virtual void clear() = 0;

  /** 
   * @param finds the frequrncy of input item in the bag
   * @pre : the input value must be of type T, which is defined at class declaration
   * @return returns int: number of occurances of input item in bag
  */
  virtual std::size_t getFrequencyOf(const T& entry) const = 0;

  /** 
   * @param finds if the bag contains atleast one instance of an item
   * @pre : the input value must be of type T, which is defined at class declaration
   * @return returns bool: 1 = bag contains atleast on instance, 0 = bag does not contain at all
  */
  virtual bool contains(const T& entry) const = 0;
  
};


#endif