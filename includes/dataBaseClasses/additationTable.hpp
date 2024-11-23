#pragma once
#include "helperClass.hpp"
#include <nlohmann/json.hpp>
#include <cppconn/connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <ctime>
class AdditationTable:public Helper{
public:
    AdditationTable(sql::Connection* );
public:
    bool addAdditationTransaction(nlohmann::json json);
    bool updateAdditationTransaction(nlohmann::json json);
    bool deleteAdditationTransaction(nlohmann::json json);
    nlohmann::json getAdditationTransactionsByInterval(nlohmann::json json);
    int getAdditationTransactionsTotalByInterval(nlohmann::json);
    
private:
    sql::Connection* connection;
public:
};