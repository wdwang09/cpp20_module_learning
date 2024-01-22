cmake_minimum_required(VERSION 3.28)
project(cpp20_module_learning)

if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # https://cmake.org/cmake/help/latest/manual/cmake-cxxmodules.7.html#compiler-support
    message(WARNING "Recommend using Clang to build.")
endif ()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(MODULE1_FILES
        module1.cppm
        submodule1.cppm
        submodule2_interface.cppm
        submodule2_impl.cppm
)

set(MODULE2_FILES module2.cppm)

add_executable(main1)
target_sources(main1 PUBLIC main.cpp
        PUBLIC
        FILE_SET CXX_MODULES
        FILES ${MODULE1_FILES} ${MODULE2_FILES}
)

add_library(module2 SHARED)
target_sources(module2
        PUBLIC
        FILE_SET CXX_MODULES
        FILES ${MODULE2_FILES}
)

add_library(module1 SHARED)
target_sources(module1
        PUBLIC
        FILE_SET CXX_MODULES
        FILES ${MODULE1_FILES}
)
target_link_libraries(module1 PUBLIC module2)

add_executable(main2 main.cpp)
target_link_libraries(main2 PRIVATE module1)
