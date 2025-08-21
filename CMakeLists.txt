cmake_minimum_required(VERSION 3.22.1)
project(scara)

add_subdirectory(scara_ws/src/scara_description)
#add_subdirectory(math_ws/src/bumperbot_description)
#add_subdirectory(math_ws/src/bumperbot_controller)

set(CMAKE_CXX_STANDARD 20)