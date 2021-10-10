cmake_minimum_required(VERSION 3.19)
project(eglue_lib)
set(CMAKE_CXX_STANDARD 17)

find_package( Boost 1.76 COMPONENTS program_options REQUIRED )
add_library(eglue_lib SHARED library.cpp library.h)

target_compile_definitions(eglue_lib PUBLIC -DBOOSTFOUND=${Boost_FOUND})

if (${Boost_FOUND})
    include_directories( ${Boost_INCLUDE_DIR} )
    target_link_libraries( eglue_lib LINK_PUBLIC ${Boost_LIBRARIES} )
endif ()
