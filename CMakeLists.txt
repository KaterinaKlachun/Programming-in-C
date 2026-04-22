cmake_minimum_required(VERSION 3.20)
project(AllLabs C)

set(CMAKE_C_STANDARD 11)

# Лаба 1
add_executable(lab1 "Лабораторные работы/lab1.c")

# Лаба 2
add_executable(lab2 "Лабораторные работы/lab2.c")

# Лаба 3
add_executable(lab3 "Лабораторные работы/lab3.c")

# Лаба 4 (с модулями)
add_executable(lab4
        "Лабораторные работы/lab4/main.c"
        "Лабораторные работы/lab4/triangle.c"
)

target_link_libraries(lab4 m)