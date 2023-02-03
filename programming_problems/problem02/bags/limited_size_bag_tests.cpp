#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "limited_size_bag.hpp"

// force template expansion for ints
template class LimitedSizeBag<int>;

TEST_CASE("Calling all public members", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);

}

TEST_CASE("Test add", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  REQUIRE(b.getCurrentSize() == 0);
  b.add(0);
  b.add(1);
  REQUIRE(b.getCurrentSize() == 2);

}

TEST_CASE("Test add past limit", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  REQUIRE(b.getCurrentSize() == 0);
  
  for (unsigned int i = 0; i < 99; i++){
    b.add(0);
  }

  REQUIRE(b.add(0));
  REQUIRE_FALSE(b.add(0));

}

TEST_CASE("Test remove", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  REQUIRE(b.getCurrentSize() == 0);
  b.add(0);
  b.add(1);
  REQUIRE(b.getCurrentSize() == 2);
  b.remove(1);
  REQUIRE(b.getCurrentSize() == 1);
  REQUIRE_FALSE(b.remove(1));

}

TEST_CASE("Test clear", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  REQUIRE(b.getCurrentSize() == 0);
  
  for (unsigned int i = 0; i < 99; i++){
    b.add(0);
  }

  REQUIRE(b.getCurrentSize() == 99);
  b.clear();
  REQUIRE(b.getCurrentSize() == 0);
  

}

TEST_CASE("Test is empty", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  REQUIRE(b.getCurrentSize() == 0);
  
  for (unsigned int i = 0; i < 99; i++){
    b.add(0);
  }

  REQUIRE(b.getCurrentSize() == 99);
  b.clear();
  REQUIRE(b.isEmpty());
  

}

TEST_CASE("Test conatins", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  REQUIRE(b.getCurrentSize() == 0);
  
  for (unsigned int i = 0; i < 99; i++){
    b.add(0);
  }

  REQUIRE(b.contains(0));
  REQUIRE_FALSE(b.contains(1));
  

}

TEST_CASE("Test getFrequency of", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  REQUIRE(b.getCurrentSize() == 0);
  
  for (unsigned int i = 0; i < 95; i++){
    b.add(0);
  }

  b.add(100);
  b.add(100);
  b.add(100);
  b.add(100);
  b.add(100);
  REQUIRE(b.getFrequencyOf(0) == 95);
  REQUIRE(b.getFrequencyOf(100) == 5);
  

}


