#include "../dataBaseClasses/dataBase.hpp"
#include "../evantSwitch.hpp"
using request = boost::beast::http::request<boost::beast::http::string_body>;
using response = boost::beast::http::response<boost::beast::http::string_body>; 
using FunctionPtr = void(*)(const request&, response&, DataBase&);

void addTransferTransaction(const request &req, response &res, DataBase &db);
void updateTransferTransaction(const request &req, response &res, DataBase &db);
void getTransferTransactionsByInterval(const request &req, response &res, DataBase &db);
void deleteTransferTransaction(const request &req, response &res, DataBase &db);


void transferEvantsInitalaizer(EvantSwitch& evantSwitch);