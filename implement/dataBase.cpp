#include "../includes/dataBase.hpp"
#include <cppconn/connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <memory>
#include <mysql_connection.h>
#include <mysql_driver.h>
template <typename Tp>
using Uptr = std::unique_ptr<Tp>;

DataBase::DataBase(sql::Connection* conn):connection(conn){};


nlohmann::json DataBase::login(nlohmann::json& json){
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


sql::Connection* connect(std::string login, std::string password, std::string dataBaseNaem){
    Uptr<sql::mysql::MySQL_Driver> driver(sql::mysql::get_driver_instance());
    sql::Connection* connection;

    connection = driver->connect("tcp://127.0.0.1:9999", login, password);
    connection->setSchema(dataBaseNaem);
    return connection;
}


    
    


