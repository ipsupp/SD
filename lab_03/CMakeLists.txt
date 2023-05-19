cmake_minimum_required(VERSION 3.24)
project(lab_03_v2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_03_v2 main.cpp VectorDinamic.h VectorDinamic.cpp test.cpp Collection.h Collection.cpp Tranzaction.h Tranzaction.cpp ATM.h ATM.cpp)
