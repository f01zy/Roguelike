add_subdirectory(Utils)
add_subdirectory(Core)

add_executable(main main.cpp)

target_link_libraries(main 
  PRIVATE
    Core
)
