project(example)

add_executable(${PROJECT_NAME} example.cpp)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)