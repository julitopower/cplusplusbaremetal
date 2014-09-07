cmake_minimum_required(VERSION 2.8)
project(files_library)


find_package(Boost 1.4 COMPONENTS unit_test_framework)
enable_testing()


include_directories(./include)

add_subdirectory(fileslib)
add_subdirectory(apps)
add_subdirectory(test)