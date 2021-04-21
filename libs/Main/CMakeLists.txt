cmake_minimum_required(VERSION 3.10.0)
project(libs_example VERSION 0.1.0)

include(CTest)
enable_testing()


add_executable(libs_example main.cpp)

# target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC "../Adder")
target_link_directories(${PROJECT_NAME} PUBLIC "../Adder/build")
target_link_libraries(${PROJECT_NAME} Adder)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
