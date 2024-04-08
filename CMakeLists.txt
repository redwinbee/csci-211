cmake_minimum_required(VERSION 3.27)
project(csci_211)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "*.cpp" "*.h")

add_executable(csci_211 ${SOURCES})
