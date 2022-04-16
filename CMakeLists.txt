cmake_minimum_required(VERSION 3.0.0)
project(UJoy++ VERSION 0.1.0)

# cxx17
set(CMAKE_CXX_STANDARD 17)

include_directories(
    "src"
    "deps/UJoy/src"
)

link_directories(
    "deps/UJoy/build"
)

add_library(
    ${PROJECT_NAME}

    # wrapper
    src/UJoy++.cpp
)
target_link_libraries(
    ${PROJECT_NAME}
    UJoy
)

# add same example as in UJoy library
add_executable(
    ujoycpp_print_state

    "examples/print_state.cpp"
)
target_link_libraries(
    ujoycpp_print_state

    ${PROJECT_NAME}
)