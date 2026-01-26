cmake_minimum_required(VERSION 3.10)

project(sample1)

include(FetchContent)
FetchContent_Declare(
  ystar
  GIT_REPOSITORY https://github.com/vs-123/ystar.git
  GIT_TAG        main
)
FetchContent_MakeAvailable(ystar)

add_executable(sample1 main.c)
target_link_libraries(sample1 PRIVATE ystar)
