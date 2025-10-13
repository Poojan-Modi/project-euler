cmake_minimum_required(VERSION 3.10)
project(ProjectEulerApp)

set(CMAKE_CXX_STANDARD 23)

# Add OpenMP support
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    message("OpenMP found!")
endif()

# Add source and include directories
include_directories(include)
file(GLOB PROBLEM_SOURCES "problems/*.cpp")

# Main executable (can be used to select problems)
add_executable(main src/main.cpp)

# Add each problem as a separate executable
foreach(problem_src ${PROBLEM_SOURCES})
    get_filename_component(problem_name ${problem_src} NAME_WE)
    add_executable(${problem_name} ${problem_src})
    target_include_directories(${problem_name} PRIVATE include)

    if(OpenMP_CXX_FOUND)
        target_link_libraries(${problem_name} PRIVATE OpenMP::OpenMP_CXX)

        # Enable LLVM OpenMP for MSVC
        if(MSVC)
            target_compile_options(${problem_name} PRIVATE /openmp:llvm)
        endif()
    endif()
endforeach()
