cmake_minimum_required(VERSION 3.28)
project(New_folder C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(admin)
include_directories(selectMode)
include_directories(user)

add_executable(New_folder
        admin/admin.c
        admin/admin.h
        selectMode/selectmode.c
        selectMode/selectmode.h
        user/user.c
        user/user.h
        main.c
        struct.h
)
