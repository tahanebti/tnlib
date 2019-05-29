cmake_minimum_required(VERSION 3.5.1)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(mutex)
add_executable(mutex_withLockGuard mutex_withLockGuard.cpp)
