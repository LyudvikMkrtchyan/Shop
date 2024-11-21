#include "../includes/dataBaseClasses/dataBase.hpp"
#include "../includes/network.hpp"
#include "../includes/helperFunctions.hpp"
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <thread>

EvantSwitch evantSwitch;

int main(){
    evantSwitchInitalaiz(evantSwitch);
    nlohmann::json config = getConfig();

    std::string dataBaseHost = config["dataBaseHost"];
    std::string dataBasePort = config["dataBasePort"];
    short serverPort         = config["serverPort"];

    sql::Connection* conn = connect("atlass", "123456", "Shop", dataBaseHost, dataBasePort);

    boost::asio::io_context context;
    boost::asio::ip::tcp::acceptor acceptor(context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), serverPort));
    DataBase db(conn);
    while(true){
        boost::asio::ip::tcp::socket socket(context);
        acceptor.accept(socket);
        std::thread(&session,std::move(socket), std::ref(db)).detach();
    }
}