#include "../dataBaseClasses/dataBase.hpp"
#include "../evantSwitch.hpp"
using request = boost::beast::http::request<boost::beast::http::string_body>;
using response = boost::beast::http::response<boost::beast::http::string_body>; 
using FunctionPtr = void(*)(const request&, response&, DataBase&);

void getFinanceReporteByTransfer(const request &req, response &res, DataBase &db);
void getFinanceReporteWithoutTransfer(const request &req, response &res, DataBase &db);

void complexEvantsInitalaizer(EvantSwitch& evantSwitch);
