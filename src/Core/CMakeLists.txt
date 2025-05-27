add_library(Core STATIC
  Core.cpp
)

target_link_libraries(Core
  PUBLIC 
    Utils
)

target_include_directories(Core
  PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)
