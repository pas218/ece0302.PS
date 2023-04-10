#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "list.hpp"
#include "sorted_list.hpp"
#include "priority_queue.hpp"

TEST_CASE("Testing is empty", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;

  REQUIRE(pq.isEmpty());

}

TEST_CASE("Testing add, remove, and peek", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;

  REQUIRE(pq.isEmpty());

  pq.add(13);
  pq.add(66);
  pq.add(55);
  pq.add(3);

  REQUIRE(pq.peek() == 66);
  pq.remove();
  REQUIRE(pq.peek() == 55);


}

TEST_CASE("Testing string", "[priority queue]") {
  typedef SortedList<std::string, List<std::string>> SortedListType;
  typedef PriorityQueue<std::string, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;

  REQUIRE(pq.isEmpty());

  pq.add("zzzz");
  pq.add("zzza");
  pq.add("aaaa");
  pq.add("bbbb");

  REQUIRE(pq.peek() == "zzzz");
  pq.remove();
  REQUIRE(pq.peek() == "zzza");


}

