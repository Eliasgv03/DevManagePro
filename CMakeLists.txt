cmake_minimum_required(VERSION 3.26)
project(DevManage)

set(CMAKE_CXX_STANDARD 17)

add_executable(DevManage main.cpp
        Desarrollador.cpp
        Desarrollador.h
        Jefe.cpp
        Jefe.h
        Tarea.cpp
        Tarea.h
        Proyecto.h
        Trabajador.cpp
        Trabajador.h
        Proyecto.cpp
        Menu.cpp
        Menu.h)
