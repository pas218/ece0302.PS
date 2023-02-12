#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

// force class expansion
template class ArrayList<int>;

TEST_CASE("Prove of existence", "[ArrayList]")
{

  ArrayList<int> list;

  REQUIRE(list.getLength() == 0);
  REQUIRE(list.isEmpty());
}

TEST_CASE("Test insert", "[ArrayList]")
{

  ArrayList<int> list;

  list.insert(0, 1);
  list.insert(1, 2);
  list.insert(2, 3);

  REQUIRE(list.getLength() == 3);
  REQUIRE(list.getEntry(2) == 3);

  list.insert(1,20);

  REQUIRE(list.getLength() == 4);
  REQUIRE(list.getEntry(2) == 2);
  REQUIRE(list.getEntry(1) == 20);

}

TEST_CASE("Test remove", "[ArrayList]")
{

  ArrayList<int> list;

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

TEST_CASE("Test clear", "[ArrayList]")
{

  ArrayList<int> list;

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

TEST_CASE("Test setEntry", "[ArrayList]")
{

  ArrayList<int> list;

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

TEST_CASE("Test copy constructor", "[ArrayList]")
{

  ArrayList<int> list;

  list.insert(0, 1);
  list.insert(1, 2);
  list.insert(2, 3);
  list.insert(3, 4);
  list.insert(4, 5);

  REQUIRE(list.getLength() == 5);
  REQUIRE(list.getEntry(2) == 3);

  ArrayList<int> list2(list);

  REQUIRE(list2.getLength() == 5);
  REQUIRE(list2.getEntry(3) == 4);
}

TEST_CASE("Test assignement operator", "[ArrayList]")
{

  ArrayList<int> list;

  list.insert(0, 1);
  list.insert(1, 2);
  list.insert(2, 3);
  list.insert(3, 4);
  list.insert(4, 5);

  REQUIRE(list.getLength() == 5);
  REQUIRE(list.getEntry(2) == 3);

  ArrayList<int> list2;

  list2 = list;

  REQUIRE(list2.getLength() == 5);
  REQUIRE(list2.getEntry(3) == 4);
}

TEST_CASE("Test swap", "[ArrayList]")
{

  ArrayList<int> list;
  ArrayList<int> list2;

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


TEST_CASE("Test char", "[ArrayList]")
{

  ArrayList<char> list;

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
