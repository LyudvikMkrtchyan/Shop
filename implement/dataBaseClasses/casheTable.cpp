#include "../../includes/dataBaseClasses/casheTable.hpp"
#include <cppconn/connection.h>

CashTable::CashTable(sql::Connection* conn):connection(conn){};