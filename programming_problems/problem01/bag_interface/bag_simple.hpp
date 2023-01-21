#ifndef STUDENT_BAG_HPP
#define STUDENT_BAG_HPP

#include "abstract_bag.hpp"

template<typename T> class Bag : public AbstractBag<T>
{
public:

  Bag();
  
  virtual ~Bag();

  virtual std::size_t getCurrentSize() const;

  virtual bool isEmpty() const;

  virtual bool add(const T& entry);

  virtual bool remove(const T& entry);

  virtual void clear();

  virtual std::size_t getFrequencyOf(const T& entry) const;

  virtual bool contains(const T& entry) const;

  static const std::size_t MAXSIZE = 100;
  
private:
  // implementation using fixed automatic storage
  std::size_t size;
  
  T data[MAXSIZE];
};

#include "bag_simple.tpp"

#endif
