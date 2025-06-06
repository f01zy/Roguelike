set(
  FILES
    ./main.cpp
    ./Core/Game.cpp
    ./Core/Window/Window.cpp
    ./Core/Window/Scene/Scene.cpp
    ./Assets/Shader/Shader.cpp
    ./Assets/Texture/Texture.cpp
    ./Input/Input.cpp
    ./Camera/Camera.cpp
    ./Map/Map.cpp
    ./Entities/Entity.cpp
    ./Entities/Player/Player.cpp
    ./Entities/EntityManager/EntityManager.cpp
    ./Utils/Utils.cpp
    ./Figures/Figure.cpp
    ./Figures/Rectangle/Rectangle.cpp
    ./Renderer/Renderer.cpp
)

add_executable(main ${FILES})

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(main 
  PRIVATE
    OpenGL::GL
    GLEW
    glfw
    ${CMAKE_SOURCE_DIR}/lib/libSOIL.a
)
