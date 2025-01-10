add_library(core_lib STATIC
  core/editor.cpp
  core/buffer.cpp
)

add_executable(pim main.cpp)

target_include_directories(core_lib PUBLIC
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(pim
  core_lib
  ${CURSES_LIBRARIES}
)
