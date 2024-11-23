#pragma once
#include <nlohmann/json.hpp>
#include "helperClass.hpp"

#include <cppconn/connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <ctime>
class CashTable:public Helper{
public:
    CashTable(sql::Connection* );
    bool addCashTransaction(nlohmann::json json);
    bool updateCashTransaction(nlohmann::json json);
    bool deleteCashTransaction(nlohmann::json json);
    nlohmann::json getCashTransactionsByInterval(nlohmann::json json);
    int getCashTransactionsTotalByInterval(nlohmann::json);
    
private:
    sql::Connection* connection;
public:
};