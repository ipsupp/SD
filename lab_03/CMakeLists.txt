cmake_minimum_required(VERSION 3.24)
project(lab_03)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_03 main.cpp Collection.h Collection.cpp Tranzaction.h Tranzaction.cpp VectorDinamic.h VectorDinamic.cpp ATM.h ATM.cpp tests.h tests.cpp)
