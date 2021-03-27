project(manif_example)
# Find the Eigen library
find_package(Eigen3 REQUIRED)
# Find the manif library
find_package(manif REQUIRED)
add_executable(${PROJECT_NAME} se2_localization_ukfm.cpp)

target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIRS})
# Add manif include directories to the target
target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC ${manif_INCLUDE_DIRS})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)