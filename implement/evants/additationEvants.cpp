#include "../../includes/evants/bankEvants.hpp"

void add_Additation_Transaction(const request &req, response &res, DataBase &db){
     nlohmann::json json = nlohmann::json::parse(req.body());

   
    bool ok = db.add_Additation_Transaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
   
};

void update_Additation_Transaction(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());

   
    bool ok = db.update_Additation_Transaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
}


void delete_Additation_Transaction(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());
    
    bool ok = db.delete_Additation_Transaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }

}



void additation_Evants_Initalaizer(EvantSwitch& evantSwitch){
    evantSwitch.addEvant("/add_Additation_Transaction", add_Additation_Transaction);
    evantSwitch.addEvant("/update_Additation_Transaction", update_Additation_Transaction);
    evantSwitch.addEvant("/delete_Additation_Transaction", delete_Additation_Transaction);

}
