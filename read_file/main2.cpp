#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
  // Let's make sure that a file path has been provided.
  // Keep in mind that argv[0] is always the name of the
  // program itself.
  if (argc < 2) {
    cout << "A path to a file must be provided" << endl;
    return 0;
  }
  
  cout << "Attempting to read file " << argv[1] << endl;

  // Create an Input File Stream, with input mode
  ifstream is(argv[1], ifstream::in);

  // Check that the stream was correctly created
  if(!is.good()) {
    cout << "Error while opening file" << endl;
    return 0;    
  }

  // Read and print until the end of the file
  char c = is.get();
  while (is.good()) {
    cout << c;
    c = is.get();
  }

  // Cleanup
  is.close();
  return 1;
}
