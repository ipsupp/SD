cmake_minimum_required(VERSION 3.24)
project(lab_02)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_02 main.cpp Collection.h tests.cpp tests.h Tranzatie.cpp Tranzactie.h ATM.cpp ATM.h)
