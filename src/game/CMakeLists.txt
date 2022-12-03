project(snake-game)

set(SOURCES
    Game.cpp
)

add_library(${PROJECT_NAME} OBJECT)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
)
