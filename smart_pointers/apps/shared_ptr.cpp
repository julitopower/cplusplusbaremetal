#include <iostream>
#include <string>
#include <memory>
#include <cassert>
#include <vector>

namespace {

  class Book {
  public:
    Book(std::string & name) : _name(name) {}
    Book(std::string && name) : _name(name) {}

    ~Book() { std::cout << "Destructing book " << _name << std::endl; }

    std::string getName() const { return _name; }

  private:
    std::string _name;
  };

}

// Alias for shared pointer to a Book
using bookPtr = std::shared_ptr<Book>;

int main(int argc, char** argv) {
  // Create a shared pointer to a book
  auto book = bookPtr { new Book {"My Awesome Book 1"} };
  
  // Create another shared pointer pointing to the same book
  // This will increment the reference counter on the shared pointer
  auto book2 = book;
  
  // Both books have value
  assert(book && book2);

  // Let's store the pointers in a vector
  auto v = std::vector<bookPtr>{};

  v.push_back(book);
  v.push_back(book2); 
  v.push_back(bookPtr {new Book("Another book")});
  
  //At this stage there are 4 shared pointers pointing too May Awesome Book 1
  assert(book.use_count() == 4);

  // Both pointers are still valid
  assert(book && book2);

  // And the books are in the vector
  for(auto it = v.begin() ; it != v.end() ; ++it)
  {
    std::cout << "vector contains " << (*it)->getName() << std::endl;
  }
  
  // We can get a value from the vector using yet another shared pointer
  bookPtr book3 = v.front();
  assert(book.use_count() == 5);

  // The unique pointer left in the vector is intact
  assert(v.front());

  // A smart pointer is going to be removed from the Map. Becuase there is only
  // one smart pointer pointing to Another Book, the memory is going to be released.
  v.pop_back();

  std::cout << "I should see this message after the destructor of Another book gets called" << std::endl;

  // No memory is released here, becuase all the pointers left in the vector are also in book and book2

  std::cout << "No detructor called between this and the previous message" << std::endl;
  assert(book && book2);

  return 0;

  // Finally when all the shared pointers go out of scope, the last one for each raw pointer will
  // actually release it.
}
