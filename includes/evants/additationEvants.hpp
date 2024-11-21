#include "../dataBaseClasses/dataBase.hpp"
#include "../evantSwitch.hpp"
using request = boost::beast::http::request<boost::beast::http::string_body>;
using response = boost::beast::http::response<boost::beast::http::string_body>; 
using FunctionPtr = void(*)(const request&, response&, DataBase&);

void add_Additation_Transaction(const request &req, response &res, DataBase &db);
void update_Additation_Transaction(const request &req, response &res, DataBase &db);
void delete_Additation_Transaction(const request &req, response &res, DataBase &db);

void additation_Evants_Initalaizer(EvantSwitch& evantSwitch);