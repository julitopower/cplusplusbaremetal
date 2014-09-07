#define BOOST_TEST_MODULE LineCountTests
#include <boost/test/unit_test.hpp>

#include <files.hpp>

using namespace files;

BOOST_AUTO_TEST_CASE( testFileDoesNotExist )
{
  BOOST_CHECK_EQUAL(0, countLines(""));
}


BOOST_AUTO_TEST_CASE( testLinesCount )
{
  BOOST_CHECK_EQUAL(6, countLines("./dummyfile"));
}

