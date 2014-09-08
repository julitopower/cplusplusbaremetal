# Define an executable and the libraries it depends on
add_executable(files main.cpp)
target_link_libraries(files fileslib)