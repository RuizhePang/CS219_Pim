find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(pim_tests
  core_tests.cpp
  mode_tests.cpp
  command_tests.cpp
)

target_link_libraries(pim_tests
  ${GTEST_LIBRARIES}
  core_lib
  modes_lib
  pthread
)

enable_testing()
add_test(NAME PimTests COMMAND pim_tests)
