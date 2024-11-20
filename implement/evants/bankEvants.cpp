#include "../../includes/evants/bankEvants.hpp"

void addBankTransaction(const request &req, response &res, DataBase &db){
     nlohmann::json json = nlohmann::json::parse(req.body());

   
    bool ok = db.addBankTransaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
   
};
void updateBankTransaction(const request &req, response &res, DataBase &db){
         nlohmann::json json = nlohmann::json::parse(req.body());

   
    bool ok = db.updateBankTransaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
}



void bankEvantsInitalaizer(EvantSwitch& evantSwitch){
    evantSwitch.addEvant("/addBankTransaction", addBankTransaction);
    evantSwitch.addEvant("/updateBankTransaction", updateBankTransaction);
}