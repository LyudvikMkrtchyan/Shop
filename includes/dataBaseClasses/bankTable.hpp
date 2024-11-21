#pragma once
#include <nlohmann/json.hpp>
#include <cppconn/connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <ctime>
class BankTable{
public:
    BankTable(sql::Connection* );
public:
    bool add_Bank_Transaction(nlohmann::json json);
    bool update_Bank_Transaction(nlohmann::json json);
    bool delete_Bank_Transaction(nlohmann::json json);
    
private:
    sql::Connection* connection;
public:
};