set(
  FILES
    ./main.cpp
    ./ObjectsManager/ObjectsManager.cpp
    ./Core/Game.cpp
    ./Core/Window.cpp
    ./Core/Scene.cpp
    ./Assets/Shader/Shader.cpp
    ./Assets/Texture/Texture.cpp
    ./Input/Input.cpp
    ./Camera/Camera.cpp
    ./Map/Map.cpp
    ./Map/Minimap.cpp
    ./Entities/Entity.cpp
    ./Entities/Player/Player.cpp
    ./Entities/EntitiesManager/EntitiesManager.cpp
    ./Utils/Utils.cpp
    ./Utils/Collision.cpp
    ./Utils/RoomsMovement.cpp
    ./Figures/Figure.cpp
    ./Figures/Rectangle/Rectangle.cpp
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
