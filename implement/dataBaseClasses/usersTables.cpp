#include "../../includes/dataBaseClasses/usersTable.hpp"
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>

UsersTable::UsersTable(sql::Connection* conn):connection(conn){};

nlohmann::json UsersTable::login(nlohmann::json& json){
        nlohmann::json answerJson;
    
    std::string login;
    std::string password;

    if(json.contains("login")){
        login = json["login"];
    }else{
        std::cout << "Login is empty" << std::endl;
        return nlohmann::json();
    }
    if(json.contains("password")){
        password = json["password"];
    }else{
        std::cout << "Password is empty" << std::endl;
        return nlohmann::json();
    }

    std::unique_ptr<sql::PreparedStatement>pstmt(connection->prepareStatement(R"(
        SELECT role, id FROM Users
        WHERE login = ? AND password = ?
    )"));
    
    pstmt->setString(1, login);
    pstmt->setString(2, password);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
    res->next();
    std::string role = res->getString("role");
    int userId       = res->getInt("id");

    answerJson["userId"] = userId;
    answerJson["role"]   = role;

    return answerJson;
}