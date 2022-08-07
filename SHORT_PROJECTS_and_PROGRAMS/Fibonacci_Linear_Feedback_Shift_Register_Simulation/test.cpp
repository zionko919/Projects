#include <iostream>
#include <string>

#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

// Given Test
BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

        FibLFSR l("1011011000110110");
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 1);
        BOOST_REQUIRE(l.step() == 1);
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 1);

        FibLFSR l2("1011011000110110");
        BOOST_REQUIRE(l2.generate(9) == 51);
}

// My Test 1
BOOST_AUTO_TEST_CASE(eightBitsThreeTaps) {
        FibLFSR l3("10010011"); // Too short so it will print out an error
        BOOST_REQUIRE(l3.step() == -777); // my unique code: you can't have negative number if everything is correct
}

// My Test 2
BOOST_AUTO_TEST_CASE(twentyBitsThreeTaps) {
        FibLFSR l4("10111111100011110101"); // Too long so it will print out an error
        BOOST_REQUIRE(l4.step() == -777); // my unique code: you can't have negative number if everything is correct
}
// My Test 3
BOOST_AUTO_TEST_CASE(notBinary) {
        FibLFSR l6("1001001014110100"); // Not a binary number
        BOOST_REQUIRE(l6.step() == -999); // my unique code: you can't have negative number if everything is correct
        FibLFSR l7("1001001019110100"); // Not a binary number
        BOOST_REQUIRE(l7.step() == -999); // my unique code: you can't have negative number if everything is correct
}

// My Test 4
BOOST_AUTO_TEST_CASE(newSixteenBitsThreeTaps) {

        FibLFSR l5("1001001010110100");
        BOOST_REQUIRE(l5.step() == 0); // 001001|0101101000
        BOOST_REQUIRE(l5.step() == 0); // 010010|1011010000
        BOOST_REQUIRE(l5.step() == 0); // 100101|0110100001
        BOOST_REQUIRE(l5.step() == 1); // 001010|1101000011
        BOOST_REQUIRE(l5.step() == 1); // 010101|1010000110
        BOOST_REQUIRE(l5.step() == 0); // 101011|0100001101
        BOOST_REQUIRE(l5.step() == 1); // 010110|1000011011
        BOOST_REQUIRE(l5.step() == 1); // 101101|0000110110

        FibLFSR l6("1001001010110100");
        BOOST_REQUIRE(l6.generate(8) == 27);
}
