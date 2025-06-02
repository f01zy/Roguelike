add_library(Entities STATIC
  ./Entity.cpp
  ./Player/Player.cpp
)

target_include_directories(Entities
  PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)
