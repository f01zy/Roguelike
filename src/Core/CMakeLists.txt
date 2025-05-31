add_library(Core STATIC
  Core.cpp
  ./Window/Window.cpp
  ./Keyboard/Keyboard.cpp
  ./Figures/Triangle/Triangle.cpp
)

target_link_libraries(Core
  PUBLIC 
    Utils
    Map
)

target_include_directories(Core
  PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)
