cmake_minimum_required(VERSION 4.3)
project(uni_labs C CXX)

set(CMAKE_C_STANDARD 11)

add_executable(uni_labs main.c)
add_executable(task_3_1 classwork/task_3.1.c)


add_executable(task_12_1 lab12/classwork/task_12.1.cpp)
add_executable(task_12_2 lab12/classwork/task_12.2.cpp)
add_executable(task_12_3 lab12/classwork/task_12.3.cpp)
add_executable(task_12_4 lab12/classwork/task_12.4.cpp)
add_executable(task_12_5 lab12/classwork/task_12.5.cpp)
add_executable(task_12_7 lab12/homework/task_12.7.cpp)


add_executable(lab15
        lab15/testRational.cpp
        lab15/Rational.cpp
        lab15/Rational.h
)

add_executable(lab15_point
        lab15/Point.cpp
        lab15/Polygone.cpp
        lab15/testPoint.cpp
)
add_executable(task_3_12 homework/task_3.12.c)
add_executable(task_3_23 homework/task_3.23.c)
add_executable(task_3_7 classwork/task_3.7.c)
add_executable(task_3_6 classwork/task_3.6.c)
add_executable(task_3_5 classwork/task_3.5.c)
add_executable(task_3_4 classwork/task_3.4.c)
add_executable(task_3_3 classwork/task_3.3.c)
add_executable(task_3_2 classwork/task_3.2.c)
