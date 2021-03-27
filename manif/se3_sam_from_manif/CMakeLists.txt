project(manif_example)
# Find the Eigen library
find_package(Eigen3 REQUIRED)
# Find the manif library
find_package(manif REQUIRED)
add_executable(${PROJECT_NAME} se3_sam.cpp)

target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
# Add manif include directories to the target
target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC ${manif_INCLUDE_DIRS})


# add_executable(se3_sam se3_sam.cpp)


# set(CXX_11_EXAMPLE_TARGETS
#   se3_sam
# )

# # Link to manif
# foreach(target ${CXX_11_EXAMPLE_TARGETS})
#   target_link_libraries(${target} ${PROJECT_NAME})

#   if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
#     # GCC is not strict enough by default, so enable most of the warnings.
#     target_compile_options(${target} PRIVATE
#       -Werror=all
#       -Werror=extra
#       -Wno-unknown-pragmas
#       -Wno-sign-compare
#       -Wno-unused-parameter
#       -Wno-missing-field-initializers
#       )
#   endif()

# endforeach()

# # Set required C++11 flag
# if(CMAKE_VERSION VERSION_LESS "3.1")
#   set_target_properties(${CXX_11_EXAMPLE_TARGETS} PROPERTIES COMPILE_FLAGS "-std=c++11")
# else()
#   set_property(TARGET ${CXX_11_EXAMPLE_TARGETS} PROPERTY CXX_STANDARD 11)
#   set_property(TARGET ${CXX_11_EXAMPLE_TARGETS} PROPERTY CXX_STANDARD_REQUIRED ON)
#   set_property(TARGET ${CXX_11_EXAMPLE_TARGETS} PROPERTY CXX_EXTENSIONS OFF)
# endif()
