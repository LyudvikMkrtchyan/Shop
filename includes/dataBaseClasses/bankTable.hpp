#pragma once
#include "helperClass.hpp"
#include <nlohmann/json.hpp>
#include <cppconn/connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <ctime>
class BankTable:public Helper{
public:
    BankTable(sql::Connection* );
public:
    bool addBankTransaction(nlohmann::json json);
    bool updateBankTransaction(nlohmann::json json);
    bool deleteBankTransaction(nlohmann::json json);
    nlohmann::json getBankTransactionsByInterval(nlohmann::json json);
    int getBankTransactionsTotalByInterval(nlohmann::json);
    
private:
    sql::Connection* connection;
public:
};