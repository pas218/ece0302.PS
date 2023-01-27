#ifndef BITSET_HPP
#define BITSET_HPP
#include <stdint.h>
#include <stdlib.h>
#include <string>


/** Bitset interface implementation
 * @author Pavel Serhiayenka
 * @file bitset.hpp
*/

class Bitset{
public:

  /**
  * @param default constructor
  * @post set bit length to 8 with all zeros; it will be valid
  */
  Bitset();

  /**
  * @param  constructor
  * @pre must input an integer N >0
  * @post set bit length to N with all zeros; it will be valid
  */
  Bitset(intmax_t size);

  /**
  * @param  constructor
  * @pre must input a string S, all values in string must be either 0 or 1
  * @post set bit string to the string that is inputted; validity will be
  * @post granted if all values in string are either 1 or 0
  */
  Bitset(const std::string & value);

  /**
  * @param  deconstructor
  * @post delete pointer for bit string
  */
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  /**
  * @param size accesor
  * @return size of bitstring
  */
  intmax_t size() const;

  /**
  * @param validity checker
  * @return return bool; 1 = valid, 0 = invalid
  */
  bool good() const;

  /**
  * @param method to set the Nth bit to 1
  * @pre must input an integer N >0, but must be <= bitSize -1
  * @post set bit N to 1
  */
  void set(intmax_t index);

  /**
  * @param method to set the Nth bit to 0
  * @pre must input an integer N >0, but must be <= bitSize -1
  * @post set bit N to 0
  */
  void reset(intmax_t index);

  /**
  * @param method to toggle the Nth bit
  * @pre must input an integer N >0, but must be <= bitSize -1
  * @post if Nth bit was 1, it will be 0; if Nth bit was 0, it will be 1; 
  * @post if Nth bit was neither, the string will be invalid
  */
  void toggle(intmax_t index);

  /**
  * @param method to see if the Nth bit is 1
  * @pre must input an integer N >0, but must be <= bitSize -1
  * @return bool; 1 = Nth bit is 1; 0 = Nth bit is not 1
  */
  bool test(intmax_t index);

  /**
  * @param method to return the bitString as a string
  * @return the bitString as a string
  */
  std::string asString() const;

private:

  int* bitString;
  std::intmax_t stringSize;
  bool isValid;

};

#endif
