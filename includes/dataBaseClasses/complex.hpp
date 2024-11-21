#pragma once
#include <nlohmann/json.hpp>
#include <cppconn/connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <ctime>
class Complex{
public:
    Complex(sql::Connection* );
public:
    nlohmann::json complex(nlohmann::json &json);    
private:
    sql::Connection* connection;
public:
};