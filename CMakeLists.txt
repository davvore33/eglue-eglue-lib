cmake_minimum_required(VERSION 3.19)
project(eglue_lib)
set(CMAKE_CXX_STANDARD 17)

find_package( Boost COMPONENTS program_options REQUIRED )
add_library(eglue_lib SHARED library.cpp library.h)

target_compile_definitions(eglue_lib PUBLIC -DBOOSTFOUND=${Boost_FOUND})

if (${Boost_FOUND})
    include_directories( ${Boost_INCLUDE_DIR} )
    target_link_libraries( eglue_lib LINK_PUBLIC ${Boost_LIBRARIES} )
endif ()

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        mytest
        mytests.cc)

target_compile_definitions(mytest PUBLIC -DBOOSTFOUND=${Boost_FOUND})

target_include_directories(mytest PRIVATE "eglue-lib")
add_library(eglue-lib2 SHARED IMPORTED)
set_target_properties(eglue-lib2 PROPERTIES IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/libeglue_lib.so)

target_link_libraries(
        mytest
        gtest_main
        ${Boost_LIBRARIES}
        eglue-lib2
)

include(GoogleTest)
gtest_discover_tests(mytest)
