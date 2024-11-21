#include "../../includes/evants/bankEvants.hpp"

void add_Bank_Transaction(const request &req, response &res, DataBase &db){
     nlohmann::json json = nlohmann::json::parse(req.body());

   
    bool ok = db.add_Bank_Transaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
   
};

void update_Bank_Transaction(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());

   
    bool ok = db.update_Bank_Transaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
}


void delete_Bank_Transaction(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());
    
    bool ok = db.delete_Bank_Transaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }

}



void bank_Evants_Initalaizer(EvantSwitch& evantSwitch){
    evantSwitch.addEvant("/add_Bank_Transaction", add_Bank_Transaction);
    evantSwitch.addEvant("/update_Bank_Transaction", update_Bank_Transaction);
    evantSwitch.addEvant("/delete_Bank_Transaction", delete_Bank_Transaction);

}