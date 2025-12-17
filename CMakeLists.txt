cmake_minimum_required(VERSION 3.10)
project(lab3 C)

set(CMAKE_C_STANDARD 11)

include_directories(headers)

set(SOURCES
    cfiles/main.c
    cfiles/house.c
    cfiles/housecont.c
    cfiles/Sorting.c
    cfiles/Tools.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".exe")
endif()