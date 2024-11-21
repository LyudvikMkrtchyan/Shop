// Sumary of total

#include "../dataBaseClasses/dataBase.hpp"
#include "../evantSwitch.hpp"
using request = boost::beast::http::request<boost::beast::http::string_body>;
using response = boost::beast::http::response<boost::beast::http::string_body>; 
using FunctionPtr = void(*)(const request&, response&, DataBase&);

void complex(const request &req, response &res, DataBase &db);

void complex_Evants_Initalaizer(EvantSwitch& evantSwitch);