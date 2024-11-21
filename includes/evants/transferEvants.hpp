#include "../dataBaseClasses/dataBase.hpp"
#include "../evantSwitch.hpp"
using request = boost::beast::http::request<boost::beast::http::string_body>;
using response = boost::beast::http::response<boost::beast::http::string_body>; 
using FunctionPtr = void(*)(const request&, response&, DataBase&);

void add_Transfer_Transaction(const request &req, response &res, DataBase &db);
void update_Transfer_Transaction(const request &req, response &res, DataBase &db);
void delete_Transfer_Transaction(const request &req, response &res, DataBase &db);

void transfer_Evants_Initalaizer(EvantSwitch& evantSwitch);