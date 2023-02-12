#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE("Prove of existence", "[LinkedList]")
{

  LinkedList<int> list;

  REQUIRE(list.getLength() == 0);
  REQUIRE(list.isEmpty());
}

TEST_CASE("Test", "[LinkedList]")
{

  LinkedList<int> list;

  REQUIRE(list.getLength() == 0);
  REQUIRE(list.isEmpty());

  list.insert(0,1);
  list.insert(1,2);
  list.insert(2,3);

  REQUIRE(list.getLength() == 3);
  REQUIRE(list.isEmpty() == 0);
  REQUIRE(list.getEntry(0) == 1);

}


TEST_CASE("Test insert", "[LinkedList]")
{

  LinkedList<int> list;

  list.insert(0, 1);
  list.insert(1, 2);
  list.insert(2, 3);

  REQUIRE(list.getLength() == 3);
  REQUIRE(list.getEntry(2) == 3);
}

TEST_CASE("Test remove", "[LinkedList]")
{

  LinkedList<int> list;

  list.insert(0, 1);
  list.insert(1, 2);
  list.insert(2, 3);
  list.insert(3, 4);
  list.insert(4, 5);

  REQUIRE(list.getLength() == 5);
  REQUIRE(list.getEntry(2) == 3);

  list.remove(2);

  REQUIRE(list.getLength() == 4);
  REQUIRE(list.getEntry(2) == 4);
}

TEST_CASE("Test clear", "[LinkedList]")
{

  LinkedList<int> list;

  list.insert(0, 1);
  list.insert(1, 2);
  list.insert(2, 3);
  list.insert(3, 4);
  list.insert(4, 5);

  REQUIRE(list.getLength() == 5);
  REQUIRE(list.getEntry(2) == 3);

  list.clear();

  REQUIRE(list.getLength() == 0);
  REQUIRE(list.isEmpty());
}

TEST_CASE("Test setEntry", "[LinkedList]")
{

  LinkedList<int> list;

  list.insert(0, 1);
  list.insert(1, 2);
  list.insert(2, 3);
  list.insert(3, 4);
  list.insert(4, 5);

  REQUIRE(list.getLength() == 5);
  REQUIRE(list.getEntry(2) == 3);

  list.setEntry(3, 98);

  REQUIRE(list.getLength() == 5);
  REQUIRE(list.getEntry(3) == 98);
}



TEST_CASE("Test copy constructor", "[LinkedList]")
{

  LinkedList<int> list;

  list.insert(0, 1);
  list.insert(1, 2);
  list.insert(2, 3);
  list.insert(3, 4);
  list.insert(4, 5);

  REQUIRE(list.getLength() == 5);
  REQUIRE(list.getEntry(2) == 3);

  LinkedList<int> list2(list);

  REQUIRE(list2.getLength() == 5);
  REQUIRE(list2.getEntry(3) == 4);
}


TEST_CASE("Test assignement operator", "[LinkedList]")
{

  LinkedList<int> list;

  list.insert(0, 1);
  list.insert(1, 2);
  list.insert(2, 3);
  list.insert(3, 4);
  list.insert(4, 5);

  REQUIRE(list.getLength() == 5);
  REQUIRE(list.getEntry(2) == 3);

  LinkedList<int> list2;

  list2 = list;

  REQUIRE(list2.getLength() == 5);
  REQUIRE(list2.getEntry(3) == 4);
}



TEST_CASE("Test swap", "[LinkedList]")
{

  LinkedList<int> list;
  LinkedList<int> list2;

  list.insert(0, 1);
  list.insert(1, 2);
  list.insert(2, 3);
  list.insert(3, 4);
  list.insert(4, 5);

  list2.insert(0, 6);
  list2.insert(1, 5);
  list2.insert(2, 4);
  list2.insert(3, 3);
  list2.insert(4, 2);

  REQUIRE(list.getLength() == 5);
  REQUIRE(list.getEntry(2) == 3);

  REQUIRE(list2.getLength() == 5);
  REQUIRE(list2.getEntry(3) == 3);

  list.swap(list2);

  REQUIRE(list2.getLength() == 5);
  REQUIRE(list2.getEntry(3) == 4);

  REQUIRE(list.getLength() == 5);
  REQUIRE(list.getEntry(3) == 3);
}


TEST_CASE("Test char", "[LinkedList]")
{

  LinkedList<char> list;

  list.insert(0, 'a');
  list.insert(1, 'b');
  list.insert(2, 'c');
  list.insert(3, 'd');
  list.insert(4, 'e');

  REQUIRE(list.getLength() == 5);
  REQUIRE(list.getEntry(2) == 'c');

  list.clear();

  REQUIRE(list.getLength() == 0);
  REQUIRE(list.isEmpty());
}
