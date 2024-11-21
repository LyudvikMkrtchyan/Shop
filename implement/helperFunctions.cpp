#include "../includes/helperFunctions.hpp"

template <typename Tp>
using Uptr = std::unique_ptr<Tp>;

void evantSwitchInitalaiz(EvantSwitch &evantsMap){
    users_Evants_Initalaizer(evantsMap);
    bank_Evants_Initalaizer(evantsMap);
    cashe_Evants_Initalaizer(evantsMap);
    transfer_Evants_Initalaizer(evantsMap);
    additation_Evants_Initalaizer(evantsMap);
    complex_Evants_Initalaizer(evantsMap);
}

nlohmann::json getConfig(){
    nlohmann::json config;

    std::ifstream configFile("../configFile.json");
    if(!configFile.is_open()){
        std::cout << "Erorr can not open config File" << std::endl;
        exit(-1);
    }

    configFile >> config;
    configFile.close();

    if(!config.contains("dataBaseHost")){
        std::cout << "Error database host empty" << std::endl;
        exit(-1);
    }
    if(!config.contains("dataBasePort")){
        std::cout << "Error database port empty" << std::endl;
        exit(-1);

    }
    if(!config.contains("serverPort")){
        std::cout << "Error server port empty" << std::endl;
        exit(-1);
    }

    return config;
}

sql::Connection* connect(std::string login, std::string password, std::string dataBaseNaem, std::string dataBaseHost, std::string dataBasePort){
    Uptr<sql::mysql::MySQL_Driver> driver(sql::mysql::get_driver_instance());
    sql::Connection* connection;

    std::string hostName = "tcp://" + dataBaseHost + ":" + dataBasePort;

    connection = driver->connect(hostName, login, password);
    connection->setSchema(dataBaseNaem);
    return connection;
}