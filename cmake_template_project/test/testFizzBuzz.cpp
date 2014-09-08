#define BOOST_TEST_MODULE FizzBuzzTests

#include <boost/test/unit_test.hpp>
#include <fizzbuzz.hpp>

BOOST_AUTO_TEST_CASE( testFizz )
{
  BOOST_CHECK_EQUAL("Fizz", fizzbuzz(3));
}

BOOST_AUTO_TEST_CASE( testBuzz )
{
  BOOST_CHECK_EQUAL("Buzz", fizzbuzz(5));
}

BOOST_AUTO_TEST_CASE( testFizzBuzz )
{
  BOOST_CHECK_EQUAL("FizzBuzz", fizzbuzz(15));
}
