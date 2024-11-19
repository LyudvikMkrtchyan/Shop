cmake_minimum_required(VERSION 3.10)

project(MyProject)

set(SOURCES
    
    ./implement/evantSwitch.cpp
    ./implement/dataBase.cpp
    ./implement/helperFunctions.cpp
    ./implement/main.cpp
    ./implement/network.cpp
)

add_executable(MyExecutable ${SOURCES})

target_link_libraries(MyExecutable mysqlcppconn)
