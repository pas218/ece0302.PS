#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_bag.hpp"

// force template expansion for ints
template class DynamicBag<int>;

TEST_CASE("Calling all public members", "[DynamicBag]"){
  DynamicBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);
}

TEST_CASE("Default Contrsuctor and Basic methods", "[DynamicBag]"){
  DynamicBag<int> b;

  b.add(0);
  REQUIRE(b.getCurrentSize() == 1);
  REQUIRE(b.contains(0) == 1);
  b.add(0);
  b.add(1);
  REQUIRE(b.getFrequencyOf(0) == 2);
  REQUIRE(b.getFrequencyOf(1) == 1);
  REQUIRE(b.getCurrentSize() == 3);
  REQUIRE_FALSE(b.isEmpty());
}



TEST_CASE("Testing Swap", "[DynamicBag]"){

  DynamicBag<int> b;
  DynamicBag<int> c;

  b.add(0);
  b.add(1);
  b.add(1);
  b.add(2);
  b.add(3);
  b.add(5);

  REQUIRE(b.getFrequencyOf(1) == 2);
  REQUIRE(b.getCurrentSize() == 6);
  REQUIRE(c.getCurrentSize() == 0);


  c.add(6);
  c.add(7);

  c.swap(b);
  

  REQUIRE(b.getFrequencyOf(6) == 1);
  REQUIRE(b.getCurrentSize() == 2);
  REQUIRE(c.getCurrentSize() == 6);
}


TEST_CASE("Test using chars", "[DynamicBag]"){
  DynamicBag<char> b;

  b.add('a');
  REQUIRE(b.getCurrentSize() == 1);
  REQUIRE(b.contains('a') == 1);
  b.add('a');
  b.add('b');
  REQUIRE(b.getFrequencyOf('a') == 2);
  REQUIRE(b.getFrequencyOf('b') == 1);
  REQUIRE(b.getCurrentSize() == 3);
  REQUIRE_FALSE(b.isEmpty());
}

TEST_CASE("Test using floats", "[DynamicBag]"){
  DynamicBag<float> b;

  b.add(1.1);
  REQUIRE(b.getCurrentSize() == 1);
  REQUIRE(b.contains(1.1) == 1);
  b.add(1.1);
  b.add(1.2);
  REQUIRE(b.getFrequencyOf(1.1) == 2);
  REQUIRE(b.getFrequencyOf(1.2) == 1);
  REQUIRE(b.getCurrentSize() == 3);
  REQUIRE_FALSE(b.isEmpty());
}

TEST_CASE("Copy Constructor", "[DynamicBag]"){
  DynamicBag<int> b;

  b.add(0);
  b.add(1);
  b.add(1);
  b.add(2);
  b.add(3);
  b.add(5);

  DynamicBag<int> c(b); 

  REQUIRE(c.getFrequencyOf(1) == 2);
  REQUIRE(c.getCurrentSize() == b.getCurrentSize());
 
}

TEST_CASE("assignment operator", "[DynamicBag]"){
  DynamicBag<int> b;

  b.add(0);
  b.add(1);
  b.add(1);
  b.add(2);
  b.add(3);
  b.add(5);

  DynamicBag<int> c; 

  c = b;

  REQUIRE(c.getFrequencyOf(1) == 2);
  REQUIRE(c.getCurrentSize() == b.getCurrentSize());
 
}

TEST_CASE("adding and removing", "[DynamicBag]"){

  DynamicBag<int> b;

  b.add(1);
  b.add(2);
  b.add(3);
  b.add(4);

  REQUIRE_FALSE(b.remove(5));
  REQUIRE(b.getCurrentSize() == 4);

  b.remove(2);

  REQUIRE(b.getCurrentSize() == 3);
  REQUIRE(b.remove(2) == 0);
  

  
}

TEST_CASE("test clear", "[DynamicBag]"){

  DynamicBag<int> b;

  b.add(1);
  b.add(2);
  b.add(3);
  b.add(4);

  REQUIRE(b.getCurrentSize() == 4);

  b.clear();

  REQUIRE(b.getCurrentSize() == 0);
  

  
}

