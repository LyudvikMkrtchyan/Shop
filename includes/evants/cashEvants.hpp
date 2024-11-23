#include "../dataBaseClasses/dataBase.hpp"
#include "../evantSwitch.hpp"
using request = boost::beast::http::request<boost::beast::http::string_body>;
using response = boost::beast::http::response<boost::beast::http::string_body>; 
using FunctionPtr = void(*)(const request&, response&, DataBase&);

void addCashTransaction(const request &req, response &res, DataBase &db);
void updateCashTransaction(const request &req, response &res, DataBase &db);
void getCashTransactionsByInterval(const request &req, response &res, DataBase &db);
void deleteCashTransaction(const request &req, response &res, DataBase &db);


void cashEvantsInitalaizer(EvantSwitch& evantSwitch);