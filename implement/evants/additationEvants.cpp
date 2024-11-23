#include "../../includes/evants/additationEvants.hpp"
#include <nlohmann/json_fwd.hpp>

void addAdditationTransaction(const request &req, response &res, DataBase &db){
     nlohmann::json json = nlohmann::json::parse(req.body());
    std::cout << json.dump(4) << std::endl;
    std::cout << "addAdditationTransaction" << std::endl;
    bool ok = db.addAdditationTransaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }

   
};
void updateAdditationTransaction(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());

    std::cout << json.dump(4) << std::endl;
    bool ok = db.updateAdditationTransaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
}
void deleteAdditationTransaction(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());

    std::cout << json.dump(4) << std::endl;
    bool ok = db.deleteAdditationTransaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
}
void getAdditationTransactionsByInterval(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());
    nlohmann::json answerJson;

    answerJson = db.getAdditationTransactionsByInterval(json);
    std::cout << answerJson.dump(4) << std::endl;
    if(!answerJson.empty()){
          res.result(boost::beast::http::status::ok);
          res.set(boost::beast::http::field::content_type, "application/json");
          res.body() = answerJson.dump();
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }

    
}

void additationEvantsInitalaizer(EvantSwitch& evantSwitch){
    evantSwitch.addEvant("/addAdditationTransaction", addAdditationTransaction);
    evantSwitch.addEvant("/updateAdditationTransaction", updateAdditationTransaction);
    evantSwitch.addEvant("/getAdditationTransactionsByInterval", getAdditationTransactionsByInterval);
    evantSwitch.addEvant("/deleteAdditationTransaction", deleteAdditationTransaction);
}
