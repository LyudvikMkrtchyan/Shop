#include "../../includes/dataBaseClasses/transferTable.hpp"
#include <cppconn/connection.h>

TransferTable::TransferTable(sql::Connection* conn):connection(conn){};