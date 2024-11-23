#include "../../includes/evants/transferEvants.hpp"
#include <nlohmann/json_fwd.hpp>

void addTransferTransaction(const request &req, response &res, DataBase &db){
     nlohmann::json json = nlohmann::json::parse(req.body());
    std::cout << json.dump(4) << std::endl;
    std::cout << "addTransferTransaction is ran" << std::endl;
    bool ok = db.addTransferTransaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }

   
};
void updateTransferTransaction(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());

    std::cout << json.dump(4) << std::endl;
    bool ok = db.updateTransferTransaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
}
void deleteTransferTransaction(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());

    std::cout << json.dump(4) << std::endl;
    bool ok = db.deleteTransferTransaction(json);

    if(ok){
        res.result(boost::beast::http::status::ok);
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }
}
void getTransferTransactionsByInterval(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());
    nlohmann::json answerJson;

    answerJson = db.getTransferTransactionsByInterval(json);
    std::cout << answerJson.dump(4) << std::endl;
    if(!answerJson.empty()){
          res.result(boost::beast::http::status::ok);
          res.set(boost::beast::http::field::content_type, "application/json");
          res.body() = answerJson.dump();
    }else{
        res.result(boost::beast::http::status::unauthorized);
    }

    
}

void transferEvantsInitalaizer(EvantSwitch& evantSwitch){
    evantSwitch.addEvant("/addTransferTransaction", addTransferTransaction);
    evantSwitch.addEvant("/updateTransferTransaction", updateTransferTransaction);
    evantSwitch.addEvant("/getTransferTransactionsByInterval", getTransferTransactionsByInterval);
    evantSwitch.addEvant("/deleteTransferTransaction", deleteTransferTransaction);
}
