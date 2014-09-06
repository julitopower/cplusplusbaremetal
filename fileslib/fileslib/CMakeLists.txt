set(public_lib_headers ../include/files.hpp)
set(lib_headers)
set(lib_src files.cpp)

add_library(fileslib ${lib_src} ${lib_headers} ${public_lib_headers})