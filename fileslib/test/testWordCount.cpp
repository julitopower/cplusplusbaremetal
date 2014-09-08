#define BOOST_TEST_MODULE WordCountTests
#include <boost/test/unit_test.hpp>

#include <files.hpp>

using namespace files;

BOOST_AUTO_TEST_CASE( testFileDoesNotExist )
{
  BOOST_CHECK_EQUAL(0, countWords(""));
}


BOOST_AUTO_TEST_CASE( testWordsCount )
{
  BOOST_CHECK_EQUAL(6, countWords("./dummyfile"));
}

