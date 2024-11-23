#pragma once
#include "helperClass.hpp"
#include <nlohmann/json.hpp>
#include <cppconn/connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <ctime>
class TransferTable:public Helper{
public:
    TransferTable(sql::Connection* );
public:
    bool addTransferTransaction(nlohmann::json json);
    bool updateTransferTransaction(nlohmann::json json);
    bool deleteTransferTransaction(nlohmann::json json);
    nlohmann::json getTransferTransactionsByInterval(nlohmann::json json);
    int getTransferTransactionsTotalByInterval(nlohmann::json);
    
private:
    sql::Connection* connection;
public:
};