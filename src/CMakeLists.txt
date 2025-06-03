add_subdirectory(Utils)
add_subdirectory(Map)
add_subdirectory(Entities)
add_subdirectory(Core)

add_executable(main main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(main 
  PRIVATE
    Core
    OpenGL::GL
    GLEW
    glfw
    ${CMAKE_SOURCE_DIR}/lib/libSOIL.a
)
