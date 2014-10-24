# Specify the minimum CMAKE version required
cmake_minimum_required(VERSION 2.8)

# Your project's name
project(tree_library)

# We use BOOST unit test framework, so we need to specify it
# This line guarantee that Boost is present and creates
# a couple of variable that come in handy when linking to
# boost related libraries
find_package(Boost 1.4 COMPONENTS unit_test_framework)
enable_testing()

# Make your header file accessible to the compiler
include_directories(./include)

# Instruct CMake to inspect the following subfolders
add_subdirectory(apps)
add_subdirectory(test)
add_subdirectory(include)
