cmake_minimum_required(VERSION 3.24)
project(LibManage)

set(CMAKE_CXX_STANDARD 17)

add_executable(LibManage main.cpp user.h reader.cpp reader.h manager.cpp manager.h Book.cpp Book.h dbFile.cpp dbFile.h menu.cpp menu.h global.h Manager.cpp Manager.h)
