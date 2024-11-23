#include "../../includes/evants/complexEvants.hpp"
#include <nlohmann/json_fwd.hpp>

void getFinanceReporteByTransfer(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());
    
    nlohmann::json answerJson;

    int bankTotal     = db.getBankTransactionsTotalByInterval(json);
    int cashTotal     = db.getCashTransactionsTotalByInterval(json);
    int transferTotal = db.getTransferTransactionsTotalByInterval(json);

    int additationTotal = db.getAdditationTransactionsTotalByInterval(json);

    int total = additationTotal - bankTotal - cashTotal -transferTotal;
    
    answerJson["bankTotal"]       = bankTotal;
    answerJson["cashTotal"]       = cashTotal;
    answerJson["transferTotal"]   = transferTotal;
    answerJson["additationTotal"] = additationTotal;
    answerJson["total"]           = total;

    res.result(boost::beast::http::status::ok);
    res.set(boost::beast::http::field::content_type, "application/json");
    res.body() = answerJson.dump();
}

void getFinanceReporteWithoutTransfer(const request &req, response &res, DataBase &db){
    nlohmann::json json = nlohmann::json::parse(req.body());
    
    nlohmann::json answerJson;

    int bankTotal     = db.getBankTransactionsTotalByInterval(json);
    int cashTotal     = db.getCashTransactionsTotalByInterval(json);

    int additationTotal = db.getAdditationTransactionsTotalByInterval(json);

    int total = additationTotal - bankTotal - cashTotal;
    
    answerJson["bankTotal"]       = bankTotal;
    answerJson["cashTotal"]       = cashTotal;
    answerJson["additationTotal"] = additationTotal;
    answerJson["total"]           = total;

    res.result(boost::beast::http::status::ok);
    res.set(boost::beast::http::field::content_type, "application/json");
    res.body() = answerJson.dump();
}

void complexEvantsInitalaizer(EvantSwitch &evantSwitch){
    evantSwitch.addEvant("/getFinanceReporteWithoutTransfer", getFinanceReporteWithoutTransfer);
    evantSwitch.addEvant("/getFinanceReporteByTransfer", getFinanceReporteByTransfer);
}
