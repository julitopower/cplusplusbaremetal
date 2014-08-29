#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// Only visible within this file -> private
static int END_FLAG = -1;

// Only vissible within this file -> private
static std::string fizzbuzz(int value);

int main(int argc, char** argv) {
  int value;

  while (true) {
    std::cout << "Introduce a Value> ";
    std::cin >> value;

    if(std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Value must be a number" << std::endl;
      continue;
    }

    if(value == END_FLAG)
      break;
    
    // Save one copy. It is safe to do since binding a temporary variable
    // to a const & extends the life of the temporary object until the
    // reference goes out of scope
    const std::string & aux = fizzbuzz(value);
    std::cout << aux <<  std::endl;
  }
}

std::string fizzbuzz(int value) {
  std::stringstream ss;
  if (value % 3 == 0) ss << "Fizz";
  if (value % 5 == 0) ss << "Buzz";
  if (ss.str() == "") ss << value;
  return ss.str();
}

