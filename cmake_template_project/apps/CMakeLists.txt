set(SRC main.cpp)

# Define an executable and the libraries in depends on
add_executable(fizzbuzz main.cpp)
target_link_libraries(fizzbuzz fizzbuzzlib)