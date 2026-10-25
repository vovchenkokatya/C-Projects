cmake_minimum_required(VERSION 4.3)
project(uni_labs C CXX)

set(CMAKE_C_STANDARD 11)

add_executable(uni_labs main.c)
add_executable(task_3_1 classwork/task_3.1.c)
add_executable(task_9_1 lab09/classwork/task_9.1.c)

add_executable(task_9_2 lab09/classwork/task_9.2.c)

add_executable(task_9_3
        lab09/classwork/task_9.3.c
        lab09/classwork/vector.c
)

add_executable(task_9_4a
        lab09/classwork/task_9.4a.c
        lab09/classwork/matrix.c
)

add_executable(task_9_4b
        lab09/classwork/task_9.4b.c
        lab09/classwork/matrix_flat.c
)
add_executable(task_3_1cpp lab1cpp/task_1.3.cpp)
add_executable(task_3_12 homework/task_3.12.c)
add_executable(task_3_23 homework/task_3.23.c)
add_executable(task_3_7 classwork/task_3.7.c)
add_executable(task_3_6 classwork/task_3.6.c)
add_executable(task_3_5 classwork/task_3.5.c)
add_executable(task_3_4 classwork/task_3.4.c)
add_executable(task_3_3 classwork/task_3.3.c)
add_executable(task_3_2 classwork/task_3.2.c)
