#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"
#include "sort.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;


// write your test cases here
TEST_CASE("ints", "sorting ints"){

  LinkedList<int> lst;

  lst.insert(0, 100);
  lst.insert(1, 4);
  lst.insert(2, 10);
  lst.insert(3, 25);
  lst.insert(4, 11);

  LinkedList<int> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == 4);
  REQUIRE(sorted.getEntry(1) == 10);
  REQUIRE(sorted.getEntry(2) == 11);
  REQUIRE(sorted.getEntry(3) == 25);
  REQUIRE(sorted.getEntry(4) == 100);
  
}

TEST_CASE("longer ints", "sorting ints"){

  LinkedList<int> lst;

  lst.insert(0, 100);
  lst.insert(1, 4);
  lst.insert(2, 10);
  lst.insert(3, 25);
  lst.insert(4, 11);
  lst.insert(0, 2544);
  lst.insert(1, 5);
  lst.insert(2, 245);
  lst.insert(3, 245555);
  lst.insert(4, 1);

  LinkedList<int> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == 1);
  REQUIRE(sorted.getEntry(1) == 4);
  REQUIRE(sorted.getEntry(2) == 5);
  REQUIRE(sorted.getEntry(3) == 10);
  REQUIRE(sorted.getEntry(4) == 11);
  REQUIRE(sorted.getEntry(5) == 25);
  REQUIRE(sorted.getEntry(6) == 100);
  REQUIRE(sorted.getEntry(7) == 245);
  REQUIRE(sorted.getEntry(8) == 2544);
  REQUIRE(sorted.getEntry(9) == 245555);
  
}

TEST_CASE("chars", "sorting ints"){

  LinkedList<char> lst;

  lst.insert(0, 'a');
  lst.insert(1, 'p');
  lst.insert(2, 'h');
  lst.insert(3, 'z');
  lst.insert(4, 'b');

  LinkedList<char> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == 'a');
  REQUIRE(sorted.getEntry(1) == 'b');
  REQUIRE(sorted.getEntry(2) == 'h');
  REQUIRE(sorted.getEntry(3) == 'p');
  REQUIRE(sorted.getEntry(4) == 'z');

}


