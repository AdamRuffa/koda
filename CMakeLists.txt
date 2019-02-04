cmake_minimum_required(VERSION 3.12)
project(koda C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Ofast -Wall -Wextra")

file(GLOB_RECURSE koda-sources src/koda/*.[c|h])
add_library(koda ${koda-sources})

file(GLOB_RECURSE kodatest-sources src/test/*.[c|h])
add_executable(unittest-koda ${kodatest-sources})
target_link_libraries(unittest-koda koda)
find_package(PkgConfig REQUIRED)
pkg_search_module(CHECK REQUIRED check)
if( CHECK_FOUND )
    include_directories(${CHECK_INCLUDE_DIRS})
    message(STATUS "Using Check ${CHECK_VERSION}")
    target_link_libraries(unittest-koda ${CHECK})
endif()

