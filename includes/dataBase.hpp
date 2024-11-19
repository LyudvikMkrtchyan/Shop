#pragma once
#include <nlohmann/json.hpp>
#include <cppconn/connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <ctime>
class DataBase{
public:
    DataBase(sql::Connection* );
    nlohmann::json login(nlohmann::json& json);
private:
    sql::Connection* connection;
public:
};
sql::Connection* connect(std::string, std::string, std::string);