cmake_minimum_required(VERSION 3.24)
project(lab_02_v2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_02_v2 main.cpp Collection.h ATM.h Tranzaction.h Tranzaction.cpp ATM.cpp ATM.cpp tests.cpp Collection.cpp)
