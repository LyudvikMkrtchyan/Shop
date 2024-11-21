#include "../../includes/evants/bankEvants.hpp"

void add_Transfer_Transaction(const request &req, response &res, DataBase &db){
     nlohmann::json json = nlohmann::json::parse(req.body());

   
    bool ok = db.add_Transfer_Transaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
   
};

void update_Transfer_Transaction(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());

   
    bool ok = db.update_Transfer_Transaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
}


void delete_Transfer_Transaction(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());
    
    bool ok = db.delete_Transfer_Transaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }

}



void transfer_Evants_Initalaizer(EvantSwitch& evantSwitch){
    evantSwitch.addEvant("/add_Transfer_Transaction", add_Transfer_Transaction);
    evantSwitch.addEvant("/update_Transfer_Transaction", update_Transfer_Transaction);
    evantSwitch.addEvant("/delete_Transfer_Transaction", delete_Transfer_Transaction);

}
