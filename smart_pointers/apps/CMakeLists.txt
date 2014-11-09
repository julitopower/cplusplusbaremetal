# Define an executable and the libraries in depends on
add_executable(rawbad raw_pointer_bad_use.cpp)
add_executable(unique_ptr unique_ptr.cpp)
add_executable(shared_ptr shared_ptr.cpp)
add_executable(smart main.cpp)
