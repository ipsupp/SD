cmake_minimum_required(VERSION 3.24)
project(lab_02_v1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_02_v1 main.cpp Collection.cpp Collection.h tests.cpp tests.h Tranzaction.cpp Tranzaction.h)
