#include "../../includes/evants/bankEvants.hpp"
#include <nlohmann/json_fwd.hpp>

void addBankTransaction(const request &req, response &res, DataBase &db){
     nlohmann::json json = nlohmann::json::parse(req.body());
    std::cout << json.dump(4) << std::endl;
    std::cout << "addBankTransaction" << std::endl;
    bool ok = db.addBankTransaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }

   
};
void updateBankTransaction(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());

    std::cout << json.dump(4) << std::endl;
    bool ok = db.updateBankTransaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
}
void deleteBankTransaction(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());

    std::cout << json.dump(4) << std::endl;
    bool ok = db.deleteBankTransaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
}
void getBankTransactionsByInterval(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());
    nlohmann::json answerJson;

    answerJson = db.getBankTransactionsByInterval(json);
    std::cout << answerJson.dump(4) << std::endl;
    if(!answerJson.empty()){
          res.result(boost::beast::http::status::ok);
          res.set(boost::beast::http::field::content_type, "application/json");
          res.body() = answerJson.dump();
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }

    
}

void bankEvantsInitalaizer(EvantSwitch& evantSwitch){
    evantSwitch.addEvant("/addBankTransaction", addBankTransaction);
    evantSwitch.addEvant("/updateBankTransaction", updateBankTransaction);
    evantSwitch.addEvant("/getBankTransactionsByInterval", getBankTransactionsByInterval);
    evantSwitch.addEvant("/deleteBankTransaction", deleteBankTransaction);
}
