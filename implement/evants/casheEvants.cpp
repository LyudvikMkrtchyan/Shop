#include "../../includes/evants/bankEvants.hpp"

void add_Cashe_Transaction(const request &req, response &res, DataBase &db){
     nlohmann::json json = nlohmann::json::parse(req.body());

   
    bool ok = db.add_Cashe_Transaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
   
};

void update_Cashe_Transaction(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());

   
    bool ok = db.update_Cashe_Transaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
}


void delete_Cashe_Transaction(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());
    
    bool ok = db.delete_Cashe_Transaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }

}



void cashe_Evants_Initalaizer(EvantSwitch& evantSwitch){
    evantSwitch.addEvant("/add_Cashe_Transaction", add_Cashe_Transaction);
    evantSwitch.addEvant("/update_Cashe_Transaction", update_Cashe_Transaction);
    evantSwitch.addEvant("/delete_Cashe_Transaction", delete_Cashe_Transaction);

}
