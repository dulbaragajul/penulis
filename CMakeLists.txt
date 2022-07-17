cmake_minimum_required(VERSION 3.10)

project(Penulis VERSION 1.0)

add_link_options(
    LINKER:-lX11
)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/util"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/component"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/input"
)

add_executable(${PROJECT_NAME}
    "src/main.c"
    "src/util/font.c"
    "src/util/ui.c"
    "src/util/x.c"
    "src/util/file.c"
    "src/util/project.c"
    "src/util/list.c"
    "src/util/util.c"
    "src/component/subWin.c"
    "src/component/textArea.c"
    "src/input/input.c"
    "src/input/inputNormal.c"
    "src/input/inputShift.c"
    "src/input/inputChar.c"
    )
