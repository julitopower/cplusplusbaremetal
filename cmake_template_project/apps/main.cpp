#include <iostream>
#include <string>
#include <limits>
#include <fizzbuzz.hpp>

// Only visible within this file -> private
static int END_FLAG = -1;

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
