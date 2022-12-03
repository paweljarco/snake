project(snake-board)

set(SOURCES
    Dummy.cpp
)

add_library(${PROJECT_NAME} OBJECT)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include)
