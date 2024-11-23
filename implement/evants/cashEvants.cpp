#include "../../includes/evants/cashEvants.hpp"
#include <nlohmann/json_fwd.hpp>

void addCashTransaction(const request &req, response &res, DataBase &db){
     nlohmann::json json = nlohmann::json::parse(req.body());
    std::cout << json.dump(4) << std::endl;
    std::cout << "addCashTransaction is ran" << std::endl;
    bool ok = db.addCashTransaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }

   
};
void updateCashTransaction(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());

    std::cout << json.dump(4) << std::endl;
    bool ok = db.updateCashTransaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
}
void deleteCashTransaction(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());

    std::cout << json.dump(4) << std::endl;
    bool ok = db.deleteCashTransaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
}
void getCashTransactionsByInterval(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());
    nlohmann::json answerJson;

    answerJson = db.getCashTransactionsByInterval(json);
    std::cout << answerJson.dump(4) << std::endl;
    if(!answerJson.empty()){
          res.result(boost::beast::http::status::ok);
          res.set(boost::beast::http::field::content_type, "application/json");
          res.body() = answerJson.dump();
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }

    
}

void cashEvantsInitalaizer(EvantSwitch& evantSwitch){
    evantSwitch.addEvant("/addCashTransaction", addCashTransaction);
    evantSwitch.addEvant("/updateCashTransaction", updateCashTransaction);
    evantSwitch.addEvant("/getCashTransactionsByInterval", getCashTransactionsByInterval);
    evantSwitch.addEvant("/deleteCashTransaction", deleteCashTransaction);
}