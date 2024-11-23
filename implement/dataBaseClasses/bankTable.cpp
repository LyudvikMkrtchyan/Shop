#include "../../includes/dataBaseClasses/bankTable.hpp"
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <memory>


    BankTable::BankTable(sql::Connection* conn):connection(conn){};

    bool BankTable::addBankTransaction(nlohmann::json json){
        int expense = 0;
        std::string date;       
        std::string reasone;
      

        if(json.contains("expense") && (json["expense"] > 0)){
            expense = json["expense"];
        }else{
            std::cout << " Front  send nod valid expense" << std::endl;
            return false;
        }
        
        if(json.contains("date") && (json["date"] != "")){
            date = json["date"];
        }else{
            std::cout << " Front not send date" << std::endl;
            return false;
        }
        std::cout << "ok" <<std::endl;
        if(json.contains("reason")){
            reasone = json["reason"];
        }
        std::cout << "ok" <<std::endl;

        std::unique_ptr<sql::PreparedStatement> pstmt(connection->prepareStatement(R"(
            INSERT INTO Bank
            (date, expense, reason)
            Values(?, ? ,?)
        )"));

        pstmt->setString(1, date);
        pstmt->setInt(2, expense);
        pstmt->setString(3, reasone);

        bool ok = pstmt->execute();
       
        std::cout << "ok = " << ok << std::endl;

        return !ok;

    }

    bool BankTable::updateBankTransaction(nlohmann::json json){
        int id = 0;
        std::string date;
        int expense = 0;
        std::string reasone;

        if(json.contains("id")){
            id = json["id"];
        }else{
            std::cout << "updateBankTransaction id not found" << std::endl;
            return false;
        }
        if(json.contains("date")){
            date = json["date"];
        }else{
            std::cout << "updateBankTransaction date not found" << std::endl;
            return false;
        }
        if(json.contains("expense")){
            expense = json["expense"];
        }else{
            std::cout << "updateBankTransaction expense not found" << std::endl;
            return false;
        }
        reasone = json.contains("reason")? json["reason"] : "";

        std::unique_ptr<sql::PreparedStatement> pstmt(connection->prepareStatement(R"(
            UPDATE Bank
            SET date  = ?
            , reason  = ?
            , expense = ?
            WHERE id = ?
        )"));

        pstmt->setString(1, date);
        pstmt->setString(2, reasone);
        pstmt->setInt(3, expense);
        pstmt->setInt(4, id);

        bool ok = pstmt->execute();

        return !ok;
    }

    bool BankTable::deleteBankTransaction(nlohmann::json json){
        int id;
        if(json.contains("id")){
            id = json["id"];
        }else{
            std::cout << "Front not send id" << std::endl;
        }
        std::unique_ptr<sql::PreparedStatement> pstmt(connection->prepareStatement(R"(
            DELETE FROM Bank
            WHERE id = ?
        )"));

        pstmt->setInt(1, id);

        bool ok = pstmt->execute();

        return !ok;
    }
    nlohmann::json BankTable::getBankTransactionsByInterval(nlohmann::json json){
        std::string startDate;
        std::string endDate;
        
        std::cout << "JsonFIle" << json.dump(4) << std::endl;
        if(json.contains("startDate")){
            std::string rowStartDate = json["startDate"];
            startDate = getFirstDayOfMonthFromString(rowStartDate);
        }else{
            std::cout << "frontend dont send startDate" << std::endl;
            return {};
        }
        
        if(json.contains("endDate")){
            std::string rowEndDate = json["endDate"];
            endDate = getLastDayOfMonthFromString(rowEndDate); 
        }else{
             std::cout << "frontend dont send endDate" << std::endl;
            return {};
        }
        std::cout << "start date = " << startDate << std::endl;
        std::cout << "end date   = " << endDate << std::endl;
        std::unique_ptr<sql::PreparedStatement> pstmt(connection->prepareStatement(R"(
            SELECT *
            FROM Bank
            WHERE date BETWEEN ? AND ?;

        )"));
        pstmt->setString(1, startDate);
        pstmt->setString(2, endDate);
       
        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
       
        nlohmann::json transacions = nlohmann::json::array();
        nlohmann::json answerJson;
        int total = 0;
       
        while(res->next()){
            int id             = res->getInt("id");
            std::string date   = res->getString("date");
            std::string reason = res->getString("reason");
            int expense        = res->getInt("expense");

            nlohmann::json tmp;
            tmp["id"]      = id;
            tmp["date"]    = date;
            tmp["reason"]  = reason;
            tmp["expense"] = expense;

            transacions.push_back(tmp);
            total += expense;

        }
        answerJson["transactions"] = transacions;
        answerJson["total"]        = total;

        return answerJson;

    }
    int BankTable::getBankTransactionsTotalByInterval(nlohmann::json json){
        std::string startDate;
        std::string endDate;
        
        std::cout << "JsonFIle" << json.dump(4) << std::endl;
        if(json.contains("startDate")){
            std::string rowStartDate = json["startDate"];
            startDate = getFirstDayOfMonthFromString(rowStartDate);
        }else{
            std::cout << "frontend dont send startDate" << std::endl;
            return {};
        }
        
        if(json.contains("endDate")){
            std::string rowEndDate = json["endDate"];
            endDate = getLastDayOfMonthFromString(rowEndDate); 
        }else{
             std::cout << "frontend dont send endDate" << std::endl;
            return {};
        }
        std::cout << "start date = " << startDate << std::endl;
        std::cout << "end date   = " << endDate << std::endl;
        
        std::unique_ptr<sql::PreparedStatement> pstmt(connection->prepareStatement(R"(
           SELECT SUM(expense) AS total_expense
            FROM Bank
            WHERE date BETWEEN ? AND ?;

        )"));
        pstmt->setString(1, startDate);
        pstmt->setString(2, endDate);
       
        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
        int totalSume = 0;
        if(res->next()){
            totalSume = res->getInt("total_expense");
        }
        return totalSume;
        
    }
    
    



