cmake_minimum_required(VERSION 3.21)
project(Projet C)

set(CMAKE_C_STANDARD 99)

add_executable(Projet main.c individu.c individu.h population.c population.h)
