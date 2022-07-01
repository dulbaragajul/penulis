cmake_minimum_required(VERSION 3.10)

project(Penulis VERSION 1.0)

add_link_options(
    LINKER:-lX11
)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/util"
)

add_executable(${PROJECT_NAME}
    "src/main.c"
    "src/util/font.c"
    "src/util/ui.c"
    "src/util/x.c"
    )
