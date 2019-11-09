#define CATCH_CONFIG_MAIN
#include "set.hpp"
#include "single_include/catch2/catch.hpp"

TEST_CASE( "char " ){
   set<char,10>  setObject;
   setObject.add('y');
   REQUIRE( setObject.contains('y') == 1);   
}

TEST_CASE( "char 3 array" ){
   std::array<char,3> firstArray={'a','b','c'};
   std::array<char,3> secondArray={'a','d','c'};
   set<std::array<char,3>,1>  setObject;
   setObject.add(firstArray);
   setObject.add(secondArray);
   REQUIRE(  setObject.max() == firstArray);   
}