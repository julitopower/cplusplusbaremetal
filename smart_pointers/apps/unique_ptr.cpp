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

// Alias for unique pointer to a Book
using bookPtr = std::unique_ptr<Book>;

int main(int argc, char** argv) {
  // Create a unique pointer to a book
  auto book = bookPtr { new Book {"My Awesome Book 1"} };
  
  // Unique pointer is not copiable but it is movable
  // Ownership is transferred to book2
  auto book2 = std::move(book);
  
  //book is now empty
  assert(!book);

  // And now book2 owns the pointer
  std::cout << "book2 owns " << book2.get()->getName() << std::endl;
  
  // Let's store the pointers in a vector
  auto v = std::vector<bookPtr>{};

  // Again we have to move, becuase unique_ptr in not copiable
  v.push_back(std::move(book2));
  v.push_back(bookPtr {new Book("Another book")});

  // Now book2 is empty
  assert(!book2);

  // And the books are in the vector
  for(auto it = v.begin() ; it != v.end() ; ++it)
  {
    std::cout << "vector contains " << (*it)->getName() << std::endl;
  }
  
  // We can get a unique pointer out of the list by moving it
  book = std::move(v.front());

  // The unique pointer left in the vector is empty but safe for destruction
  assert(!v.front());

  // Let's pop the back of the vector, where Another book is stored
  // This will cause the destruction of Another book.
  v.pop_back();

  std::cout << "I should see this message after the destructor of Another book gets called" << std::endl;
  return 0;

  // When we go out of scope, book will be destroyed, and it will free its owned pointer
  // which in this case points to My Awesome Book 1
}
