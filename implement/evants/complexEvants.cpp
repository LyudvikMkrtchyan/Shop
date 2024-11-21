#include "../../includes/evants/complexEvants.hpp"

void complex(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());

    nlohmann::json answerJson;
    answerJson = db.complex(json);

    if(!answerJson.empty()){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
    res.set(boost::beast::http::field::content_type, "application/json");
    res.body() = answerJson.dump();
}


void complex_Evants_Initalaizer(EvantSwitch& evantSwitch){
    evantSwitch.addEvant("/complex", complex);
}