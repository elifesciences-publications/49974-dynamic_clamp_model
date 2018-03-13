cmake_minimum_required(VERSION 3.6)
project(dynamic_clamp_models)

set(CMAKE_VERBOSE_MAKEFILE ON)
add_definitions(-std=c99)


#link gsl library
include_directories(/usr/include)
link_directories(/usr/lib)
link_libraries(gsl gslcblas)


#link gtest
add_subdirectory(lib/gtest-1.7.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Add flag to run the model outside of the RELACS enviroment
add_definitions(-D__LOCAL_SIMULATION_ENV__)

add_subdirectory(src)

