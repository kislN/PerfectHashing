cmake_minimum_required(VERSION 3.14)
project(PerfectHashing)

set(CMAKE_CXX_STANDARD 14)

add_executable(PerfectHashing main.cpp hash_function.h Quadratic.h Double.h Graphic.h Graph.h experiments.h real_life_experiments.h utils.h)