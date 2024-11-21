#include "../../includes/dataBaseClasses/casheTable.hpp"
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <memory>

CasheTable::CasheTable(sql::Connection* conn):connection(conn){};

 bool CasheTable::add_Cashe_Transaction(nlohmann::json json){
        int expense = 0;
        int date    = 0; // I understand that the date cannot be an int, but this is the user's preference."
        std::string reasone;

        if(json.contains("expense")){
            expense = json["expense"];
        }else{
            std::cout << " Front not send expense" << std::endl;
            return false;
        }
        
        if(json.contains("date")){
            date = json["date"];
        }else{
            std::cout << " Front not send date" << std::endl;
            return false;
        }
        reasone = json.contains("reasone")? json["reasone"] : "";

        std::unique_ptr<sql::PreparedStatement> pstmt(connection->prepareStatement(R"(
            INSERT INTO Cashe
            (date, expense, reason)
            Values(?, ? ,?)
        )"));

        pstmt->setInt(1, date);
        pstmt->setInt(2, expense);
        pstmt->setString(3, reasone);

        bool ok = pstmt->execute();
       
        std::cout << "ok = " << ok << std::endl;

        return ok;

    }

    bool CasheTable::update_Cashe_Transaction(nlohmann::json json){
        int id = 0;
        int date = 0;
        int expense = 0;
        std::string reasone;

        if(json.contains("id")){
            id = json["id"];
        }else{
            std::cout << "update_Cashe_Transaction id not found" << std::endl;
            return false;
        }
        if(json.contains("date")){
            date = json["date"];
        }else{
            std::cout << "update_Cashe_Transaction date not found" << std::endl;
            return false;
        }
        if(json.contains("expense")){
            expense = json["expense"];
        }else{
            std::cout << "update_Cashe_Transaction expense not found" << std::endl;
            return false;
        }
        reasone = json.contains("reasone")? json["reasone"] : "";

        std::unique_ptr<sql::PreparedStatement> pstmt(connection->prepareStatement(R"(
            UPDATE Cashe
            SET date  = ?
            , reason  = ?
            , expense = ?
            WHERE id = ?
        )"));

        pstmt->setInt(1, date);
        pstmt->setString(2, reasone);
        pstmt->setInt(3, expense);
        pstmt->setInt(4, id);

        bool ok = pstmt->execute();

        return ok;
    }

    bool CasheTable::delete_Cashe_Transaction(nlohmann::json json){
        
        int id = 0;
        if(json.contains("id")){
            id = json["id"];
        }else{
            std::cout << "delete_Cashe_Transaction id not found" << std::endl;
            return false;
        }
        std::unique_ptr<sql::PreparedStatement> pstmt(connection->prepareStatement(R"(
            DELETE FROM Cashe
            WHERE id = ?
        )"));

        pstmt->setInt(1, id);

        bool ok = pstmt->execute();

        return ok;
    }



