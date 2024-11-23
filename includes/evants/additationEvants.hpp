#include "../dataBaseClasses/dataBase.hpp"
#include "../evantSwitch.hpp"
using request = boost::beast::http::request<boost::beast::http::string_body>;
using response = boost::beast::http::response<boost::beast::http::string_body>; 
using FunctionPtr = void(*)(const request&, response&, DataBase&);

void addAdditationTransaction(const request &req, response &res, DataBase &db);
void updateAdditationTransaction(const request &req, response &res, DataBase &db);
void getAdditationTransactionsByInterval(const request &req, response &res, DataBase &db);
void deleteAdditationTransaction(const request &req, response &res, DataBase &db);


void additationEvantsInitalaizer(EvantSwitch& evantSwitch);