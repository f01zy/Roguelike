add_library(Core STATIC
  ./Core.cpp
  ./Window/Window.cpp
  ./Window/Figures/Figure.cpp
  ./Window/Figures/Rectangle/Rectangle.cpp
  ./Window/Shader/Shader.cpp
  ./Window/Texture/Texture.cpp
  ./Window/Scene/Scene.cpp
  ./Keyboard/Keyboard.cpp
)

target_link_libraries(Core
  PUBLIC 
    Utils
    Map
    Entities
)

target_include_directories(Core
  PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)
