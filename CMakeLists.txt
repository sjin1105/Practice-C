cmake_minimum_required(VERSION 3.10)

SET(C_FILES pthread.c)
SET(EXE_NAME Runfile)

set( CMAKE_CXX_FLAGS "-O2 -W -Wall" )

SET ( CMAKE_VERBOSE_MAKEFILE true )

ADD_EXECUTABLE(${EXE_NAME} ${C_FILES})

# set pthread
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(${EXE_NAME} PRIVATE Threads::Threads)

# mkdir cmake
# cmake -H. -Bcmake
