#include <iostream>
#include <string>

#include "LFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
// insert boost path to unit test below
#include <boost/test/included/unit_test.hpp> 
/* Note: originally, the line above was: "#include <boost/test/unit_test.hpp>" */

BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo) {

  LFSR l("00111", 2);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  
  LFSR l2("00111", 2);
  BOOST_REQUIRE(l2.generate(8) == 198);

  // create a 32 bit input string
  LFSR l4("00011000000110000001100000011000", 28);

  // make sure getLength() works
  BOOST_REQUIRE(l4.getLength() == 32);

  // make sure getSeed() works
  BOOST_REQUIRE(l4.getSeed() == "00011000000110000001100000011000");

  // make sure step() works for 32 bit input
  BOOST_REQUIRE(l4.step() == 1);
  BOOST_REQUIRE(l4.step() == 1);
  BOOST_REQUIRE(l4.step() == 0);
  BOOST_REQUIRE(l4.step() == 1);
  BOOST_REQUIRE(l4.step() == 1);
  BOOST_REQUIRE(l4.step() == 0);

  //reset the seed
  l4.setSeed("00011000000110000001100000011000");

  // make sure setSeed() works
  BOOST_REQUIRE(l4.getSeed() == "00011000000110000001100000011000");

  // make sure generate() works
  BOOST_REQUIRE(l4.generate(2) == 3);
  // reset seed
  l4.setSeed("00011000000110000001100000011000");
  BOOST_REQUIRE(l4.generate(3) == 6);
  // reset seed
  l4.setSeed("00011000000110000001100000011000");
  BOOST_REQUIRE(l4.generate(4) == 13);

}