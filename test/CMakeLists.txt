cmake_minimum_required(VERSION 3.14)
project(snake_test)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  snake_test
    GameTests.cpp
    SnakeTests.cpp
)
target_link_libraries(
    snake_test
    GTest::gtest_main
    snake-board
    snake-game
    snake-game_objects
)

include(GoogleTest)
gtest_discover_tests(snake_test)
