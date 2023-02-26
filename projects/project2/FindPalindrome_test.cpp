#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE( "Test adding words", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(b.add("kayak"));
	REQUIRE(!b.add("kayak"));
	REQUIRE(!b.add("kayak1"));
}

TEST_CASE("test adding vectors", "[FindPalindrome]"){
	FindPalindrome b;

	
	std::vector<std::string> stringVect;
	stringVect.push_back("on");
	stringVect.push_back("sit");
	stringVect.push_back("a");
	stringVect.push_back("otis");
	stringVect.push_back("pan");
	stringVect.push_back("potato");

	REQUIRE(b.add(stringVect));

	REQUIRE(!b.add(stringVect));

	stringVect.clear();

	stringVect.push_back("123");
	stringVect.push_back("hi");

	REQUIRE(!b.add(stringVect));
}

TEST_CASE("test number method", "[FindPalindrome]"){
	FindPalindrome b;

	
	std::vector<std::string> stringVect;
	stringVect.push_back("on");
	stringVect.push_back("sit");
	stringVect.push_back("a");
	stringVect.push_back("otis");
	stringVect.push_back("pan");
	stringVect.push_back("potato");
	REQUIRE(b.add(stringVect));
	REQUIRE(b.number() == 1);

	
}

TEST_CASE( "Test clear", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(b.add("kayak"));
	REQUIRE(b.number() == 1);
	b.clear();
	REQUIRE(b.number() == 0);
}

TEST_CASE("test recursion", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	REQUIRE(b.number() == 6);
}

TEST_CASE("test more complex recursion", "[FindPalindrome]"){
	FindPalindrome b;

	
	std::vector<std::string> stringVect;
	stringVect.push_back("Was");
	stringVect.push_back("it");
	stringVect.push_back("a");
	stringVect.push_back("car");
	stringVect.push_back("or");
	stringVect.push_back("acat");
	stringVect.push_back("I");
	stringVect.push_back("saw");
	REQUIRE(b.add(stringVect));
	REQUIRE(b.number() == 2);
}

TEST_CASE("test cut test 1", "[FindPalindrome]"){

	FindPalindrome b;

	std::vector<std::string> stringVect;
	stringVect.push_back("Was");
	stringVect.push_back("it");
	stringVect.push_back("a");
	stringVect.push_back("car");
	stringVect.push_back("or");
	stringVect.push_back("acat");
	stringVect.push_back("I");
	stringVect.push_back("saw");
	REQUIRE(b.cutTest1(stringVect));
	stringVect.push_back("qp");
	REQUIRE(!b.cutTest1(stringVect));

}

TEST_CASE("test cut test2", "[FindPalindrome]"){

	FindPalindrome b;

	std::vector<std::string> stringVect;
	stringVect.push_back("Was");
	stringVect.push_back("it");
	stringVect.push_back("a");
	stringVect.push_back("car");
	stringVect.push_back("or");
	stringVect.push_back("acat");
	stringVect.push_back("I");
	stringVect.push_back("saw");
	std::vector<std::string> stringVect1;
	REQUIRE(b.cutTest2(stringVect, stringVect1));
	stringVect1.push_back("qp");
	REQUIRE(!b.cutTest2(stringVect, stringVect1));
}

TEST_CASE("test toVector", "[FindPalindrome]"){

	FindPalindrome b;

	std::vector<std::string> stringVect;
	stringVect.push_back("Wasita");
	stringVect.push_back("car");
	stringVect.push_back("or");
	stringVect.push_back("acat");
	stringVect.push_back("I");
	stringVect.push_back("saw");
	std::vector<std::vector<std::string>> stringVect1;
	stringVect1.push_back(stringVect);

	REQUIRE(b.add(stringVect));
	
	REQUIRE(b.toVector() == stringVect1);

}


