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
    bool addBankTransaction(nlohmann::json json);
    bool updateBankTransaction(nlohmann::json json);
    bool deleteBankTransaction(int id);
    
private:
    sql::Connection* connection;
public:
};