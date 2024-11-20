#include "../../includes/dataBaseClasses/additationTable.hpp"
#include <cppconn/connection.h>

AdditationTable::AdditationTable(sql::Connection* conn):connection(conn){};