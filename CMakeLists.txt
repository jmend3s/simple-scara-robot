cmake_minimum_required(VERSION 3.22.1)
project(scara)

add_subdirectory(scara_ws/src/cpp_examples)
add_subdirectory(scara_ws/src/scara_controller)
add_subdirectory(scara_ws/src/scara_description)
add_subdirectory(scara_ws/src/scara_moveit)
add_subdirectory(scara_ws/src/scara_msgs)
add_subdirectory(scara_ws/src/scara_utils)

set(CMAKE_CXX_STANDARD 20)