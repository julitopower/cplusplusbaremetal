#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
  // Let's make sure that a file path has been provided.
  // Keep in mind that argv[0] is always the name of the
  // program itself.
  if (argc < 2) {
    cout << "A path to a file must be provided" << endl;
    return 0;
  }
  
  cout << "Attempting to read file " << argv[1] << endl;

  // Get a handle to the file in read mode
  FILE* f = fopen(argv[1], "r");
  // If something goes wrong the handle gets initialized
  // Null
  if (f == 0) {
    cout << "Error while opening file" << endl;
    return 0;
  }

  // Now we read the file character by character until
  // we git the end of the file, which is represented
  // by EOF defined in cstdio
  int c;
  while((c = fgetc(f)) != EOF) {
    cout << char(c);
  }

  // Cleaning up
  fflush(f);
  fclose(f);
  return 1;
}
