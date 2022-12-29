project(snake-game)

set(SOURCES
    Game.cpp
)

add_library(${PROJECT_NAME} OBJECT)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include)

find_package(Qt6 REQUIRED COMPONENTS Core)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        snake-board
        snake-game_objects
        Qt6::Core
)
