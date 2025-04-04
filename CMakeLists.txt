cmake_minimum_required(VERSION 3.30)
project(GeomAlg)

set(CMAKE_CXX_STANDARD 20)

if(NOT DEFINED FILE)
    message(FATAL_ERROR "Please pass -DFILE=<filename>")
endif ()

set(SOURCE_FILE "${CMAKE_SOURCE_DIR}/${FILE}.cpp")
set(EXECUTABLE_NAME "${FILE}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})

add_custom_target(run
    COMMAND ${EXECUTABLE_NAME}
        DEPENDS ${EXECUTABLE_NAME}
        WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
