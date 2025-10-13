cmake_minimum_required(VERSION 3.10)
project(ProjectEuler VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build type configuration
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Compiler warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Add OpenMP support
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    message(STATUS "OpenMP found and enabled")
endif()

# Project structure
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(PROJECT_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

# Include directories
include_directories(${PROJECT_INCLUDE_DIR})

# Collect source files
file(GLOB_RECURSE PROBLEM_SOURCES 
    "${PROJECT_SOURCE_DIR}/*.cpp"
    "problem_*.cpp"  # For existing files in root
)

# Add each problem as a separate executable
foreach(problem_src ${PROBLEM_SOURCES})
    get_filename_component(problem_name ${problem_src} NAME_WE)
    add_executable(${problem_name} ${problem_src})
    
    # Include directories
    target_include_directories(${problem_name} PRIVATE ${PROJECT_INCLUDE_DIR})
    
    # OpenMP support
    if(OpenMP_CXX_FOUND)
        target_link_libraries(${problem_name} PRIVATE OpenMP::OpenMP_CXX)
        if(MSVC)
            target_compile_options(${problem_name} PRIVATE /openmp:llvm)
        endif()
    endif()
endforeach()

# Installation rules
install(TARGETS ${EXECUTABLES}
    RUNTIME DESTINATION bin
)