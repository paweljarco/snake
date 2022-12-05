project(snake-drawing_handler)

find_package(Qt6 REQUIRED COMPONENTS Gui)

set(SOURCES
    DrawingHandler.cpp
)

add_library(${PROJECT_NAME} OBJECT)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt6::Gui
        Qt6::Widgets
)
