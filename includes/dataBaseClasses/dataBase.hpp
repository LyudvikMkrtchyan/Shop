#pragma once
#include "additationTable.hpp"
#include "bankTable.hpp"
#include "casheTable.hpp"
#include "transferTable.hpp"
#include "usersTable.hpp"


#include <nlohmann/json.hpp>
#include <cppconn/connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <ctime>

#include <boost/beast.hpp>
class DataBase:public AdditationTable
              ,public BankTable
              ,public CasheTable
              ,public TransferTable
              ,public UsersTable  
                {
public:
    DataBase(sql::Connection* );
   
private:
    sql::Connection* connection;
public:
};
