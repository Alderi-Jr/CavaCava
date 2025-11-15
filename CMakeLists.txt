cmake_minimum_required(VERSION 3.28)
project(GridWorld)

set(CMAKE_CXX_STANDARD 17)

# Caminho para SFML
set(SFML_DIR "C:/Tools/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(GridWorld src/main.cpp
        src/Grid.cpp
        src/Grid.h
)

target_link_libraries(GridWorld
        sfml-graphics
        sfml-window
        sfml-system
)
# Copiar DLLs automaticamente
add_custom_command(TARGET GridWorld POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "C:/Tools/SFML/bin"
        $<TARGET_FILE_DIR:GridWorld>
)
