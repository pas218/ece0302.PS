#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "adjacency_list_graph.hpp"

TEST_CASE("Test Construction", "[construction]") {
  AdjacencyListGraph<int>  listGraph;
  REQUIRE(listGraph.getNumVertices() == 0);
}

TEST_CASE("Test add", "[construction]") {
  AdjacencyListGraph<int>  listGraph;
  listGraph.add(1,2);
  REQUIRE(listGraph.getNumVertices() == 2);
  REQUIRE(listGraph.getNumEdges() == 1);
  REQUIRE_FALSE(listGraph.add(1,2));
  listGraph.add(2,3);
  REQUIRE(listGraph.getNumVertices() == 3);
  REQUIRE(listGraph.getNumEdges() == 2);
}

TEST_CASE("Test remove", "[construction]") {
  AdjacencyListGraph<int>  listGraph;
  listGraph.add(1,2);
  REQUIRE(listGraph.getNumVertices() == 2);
  REQUIRE(listGraph.getNumEdges() == 1);
  REQUIRE_FALSE(listGraph.add(1,2));
  listGraph.add(2,3);
  REQUIRE(listGraph.getNumVertices() == 3);
  REQUIRE(listGraph.getNumEdges() == 2);
  REQUIRE(listGraph.remove(2,3));
  REQUIRE(listGraph.getNumVertices() == 2);
  REQUIRE(listGraph.getNumEdges() == 1);
}

