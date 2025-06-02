add_library(Map STATIC
  ./Map.cpp
)

target_link_libraries(Map
  PUBLIC
    Utils
)

target_include_directories(Map
  PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)
