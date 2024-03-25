cmake_minimum_required(VERSION 3.27)
project(csci_211)

set(CMAKE_CXX_STANDARD 17)

add_executable(csci_211 main.cpp
        eight_queens.cpp
        eight_queens.h
        eight_queens_1d.cpp
        eight_queens_1d.h
        eight_queens_nogoto.cpp
        eight_queens_nogoto.h
        eight_numbers.cpp
        eight_numbers.h)
