cmake_minimum_required(VERSION 3.13.0)
project(eigen_test)

set(CMAKE_CXX_STANDARD 14)

get_filename_component(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/.. ABSOLUTE)
get_filename_component(PROJECT_LIB_BINARY_DIR ${CMAKE_BINARY_DIR}/lib ABSOLUTE)

set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)
set(PROJECT_LIB_SOURCE_DIR ${PROJECT_DIR}/lib)
set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)
set(PROJECT_TEST_DIR ${PROJECT_DIR}/test)

find_package(PkgConfig)
pkg_search_module(Eigen3 REQUIRED eigen3)

include_directories(${Eigen3_INCLUDE_DIRS})

function(custom_executable target)
  add_executable(${target})
  target_sources(
    ${target}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/${target}.cpp
  )
endfunction()

custom_executable(pseudo_inverse)
