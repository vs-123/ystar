cmake_minimum_required(VERSION 3.10)
project(ystar)

set(OUTPUT_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/dist/ystar.h")

add_custom_command(
    OUTPUT "${OUTPUT_HEADER}"
    COMMAND python3 "${CMAKE_CURRENT_SOURCE_DIR}/amalgamate.py" -o "${OUTPUT_HEADER}"
    DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/main.c" "${CMAKE_CURRENT_SOURCE_DIR}/src/ystar.c"
    COMMENT "Amalgamating ystar..."
    VERBATIM
)

add_custom_target(generate_ystar_h DEPENDS "${OUTPUT_HEADER}")
add_library(ystar INTERFACE)
add_dependencies(ystar generate_ystar_h)

target_include_directories(ystar INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/dist")
