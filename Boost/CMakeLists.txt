cmake_minimum_required(VERSION 3.10)

project(playground)

add_executable(main main.cpp)

find_package(Boost REQUIRED)
# target_link_libraries(main PUBLIC Boost)
target_link_libraries(main PUBLIC ${Boost_libraries})