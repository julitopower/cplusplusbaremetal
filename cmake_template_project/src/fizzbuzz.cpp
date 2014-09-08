#include <fizzbuzz.hpp>
#include <sstream>

/**
 * Out good all fizzbuzz implementation
 */
std::string fizzbuzz(int value) {
  std::stringstream ss;
  if (value % 3 == 0) ss << "Fizz";
  if (value % 5 == 0) ss << "Buzz";
  if (ss.str() == "") ss << value;
  return ss.str();
}
