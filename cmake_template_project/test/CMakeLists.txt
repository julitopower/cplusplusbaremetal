# generates main() for unit tests
add_definitions(-DBOOST_TEST_DYN_LINK) 

# Assign all the libraries necessary to compile the test
# to the variable TEST_LIBRARIES
set(TEST_LIBRARIES
  ${Boost_LIBRARIES}
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
  fizzbuzzlib
  )

# Define an executable and the libraries it depends on
add_executable(tFizzBuzz testFizzBuzz.cpp)
target_link_libraries(tFizzBuzz ${TEST_LIBRARIES})

# Define a test that uses the executable we just defined
add_test(testFizzBuzz tFizzBuzz)
