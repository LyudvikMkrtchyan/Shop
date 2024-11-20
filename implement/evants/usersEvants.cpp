#include "../../includes/evants/usersEvants.hpp"

void login(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());

    nlohmann::json answerJson;
    answerJson = db.login(json);

    if(!answerJson.empty()){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
    res.set(boost::beast::http::field::content_type, "application/json");
    res.body() = answerJson.dump();
}

void usersEvantsInitalaizer(EvantSwitch& evantSwitch){
    evantSwitch.addEvant("/login", login);
}
