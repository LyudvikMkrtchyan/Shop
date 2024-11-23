cmake_minimum_required(VERSION 3.10)

project(MyProject)

set(SOURCES
    ./implement/dataBaseClasses/additationTable.cpp
    ./implement/dataBaseClasses/bankTable.cpp
    ./implement/dataBaseClasses/casheTable.cpp
    ./implement/dataBaseClasses/dataBase.cpp
    ./implement/dataBaseClasses/transferTable.cpp
    ./implement/dataBaseClasses/usersTables.cpp
    ./implement/dataBaseClasses/helperClass.cpp

    ./implement/evants/additationEvants.cpp
    ./implement/evants/cashEvants.cpp
    ./implement/evants/bankEvants.cpp
    ./implement/evants/complexEvants.cpp
    ./implement/evants/transferEvants.cpp
    ./implement/evants/usersEvants.cpp
    

    ./implement/evantSwitch.cpp
    ./implement/helperFunctions.cpp
    ./implement/main.cpp
    ./implement/network.cpp
    
)

add_executable(MyExecutable ${SOURCES})

target_link_libraries(MyExecutable mysqlcppconn)
