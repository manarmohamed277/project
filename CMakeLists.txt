cmake_minimum_required(VERSION 3.28)
project(New_folder C)

set(CMAKE_C_STANDARD 99)

add_executable(New_folder main.c
        user.c
        user.h
        admin.h
        main.c
        struct.h
        selectmode.c
        selectmode.h
        admin.c
)
