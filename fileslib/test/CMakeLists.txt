enable_testing()
# generates main() for unit tests
add_definitions(-DBOOST_TEST_DYN_LINK) 

set(TEST_LIBRARIES
  ${Boost_LIBRARIES}
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
  fileslib
  )

set(TEST_FILES testLineCount.cpp)
file(COPY dummyfile DESTINATION .)

add_executable(tLineCount ${TEST_FILES})
target_link_libraries(tLineCount ${TEST_LIBRARIES})
add_executable(tWordCount ${TEST_FILES})
target_link_libraries(tWordCount ${TEST_LIBRARIES})

add_test(testLineCount tLineCount)
add_test(testWordCount tWordCount)