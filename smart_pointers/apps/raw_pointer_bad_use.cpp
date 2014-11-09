void do_something(int * p_int) {
  delete p_int;
}

int main(int argc, char** argv)
{
  int * b = nullptr;

  // Each cycle we allocato memory but do not release it
  // Memory Leak!
  for(auto i = 0 ; i < 100 ; ++i)
    {
      b = new int {3};
    }

  // This function frees the pointer, but it is not obvious
  // from the call
  do_something(b);

  // Attempt to free a pointer that has already been release
  // Undefined behavior, probably dissaster
  delete b;
}
