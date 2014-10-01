# Necessary for the custom command tests
include(CTest)

# generates main() for unit tests
add_definitions(-DBOOST_TEST_DYN_LINK) 

# Assign all the libraries necessary to compile the test
# to the variable TEST_LIBRARIES
set(TEST_LIBRARIES
  ${Boost_LIBRARIES}
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
  )

# Define an executable and the libraries it depends on
# This executable is not built by default, in order to get
# The tests built and run use the custom target tests
add_executable(testTree EXCLUDE_FROM_ALL testTree.cpp)
target_link_libraries(testTree ${TEST_LIBRARIES})

# Define a test that uses the executable we just defined
add_test(testTree testTree)

# Define a custom target that will force the build of the
# tests and will actually run the tests
set(CMAKE_CTEST_COMMAND ctest -V)
add_custom_target(tests COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS testTree)