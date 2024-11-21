#include "../../includes/dataBaseClasses/complex.hpp"
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>

Complex::Complex(sql::Connection* conn):connection(conn){};

nlohmann::json Complex::complex(nlohmann::json& json){
   nlohmann::json answerJson;
    double totalExpense = 0;
    int date = 0;

    const std::vector<std::string> tables = {"Bank", "Cashe", "Additional", "Transfer"};

    try {
        for (const auto& table : tables) {
            std::string query = "SELECT expense FROM " + table + " WHERE date = ?";
            std::unique_ptr<sql::PreparedStatement> pstmt(connection->prepareStatement(query));
            pstmt->setInt(1, date);

           std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
            while (res->next()) {
                totalExpense += res->getDouble("expense");
            }
        }
        answerJson["totalExpense"] = totalExpense;
    } catch (sql::SQLException& e) {
        std::cerr << "SQL Error in total: " << e.what() << std::endl;
    }

    return answerJson;
}