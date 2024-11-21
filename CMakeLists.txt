cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(MyProject)

set(SOURCES
    ./implement/dataBaseClasses/additationTable.cpp
    ./implement/dataBaseClasses/bankTable.cpp
    ./implement/dataBaseClasses/casheTable.cpp
    ./implement/dataBaseClasses/dataBase.cpp
    ./implement/dataBaseClasses/transferTable.cpp
    ./implement/dataBaseClasses/usersTables.cpp

    ./implement/evants/additationEvants.cpp
    ./implement/evants/bankEvants.cpp
    ./implement/evants/casheEvants.cpp
    ./implement/evants/complexEvants.cpp
    ./implement/evants/transferEvants.cpp
    ./implement/evants/usersEvants.cpp
    

    ./implement/evantSwitch.cpp
    ./implement/helperFunctions.cpp
    ./implement/main.cpp
    ./implement/network.cpp
    
)

add_executable(MyExecutable ${SOURCES})

set(MYSQL_LIB /usr/lib/x86_64-linux-gnu/libmysqlcppconn.so)

target_link_libraries(MyExecutable mysqlcppconn)