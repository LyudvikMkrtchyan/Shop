#include "../../includes/dataBaseClasses/dataBase.hpp"
#include <cppconn/connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <memory>
#include <mysql_connection.h>
#include <mysql_driver.h>

template <typename Tp>
using Uptr = std::unique_ptr<Tp>;

DataBase::DataBase(sql::Connection* conn):AdditationTable(conn)
                                        , BankTable(conn)
                                        , CashTable(conn)
                                        , TransferTable(conn)
                                        , UsersTable(conn)
                                        , connection(conn){};



    
    


