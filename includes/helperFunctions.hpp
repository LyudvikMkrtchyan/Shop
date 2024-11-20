#include "evantSwitch.hpp"

#include "./evants/usersEvants.hpp"
#include "./evants/bankEvants.hpp"

#include <boost/beast/http/status.hpp>
#include <nlohmann/json_fwd.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio.hpp>
#include <boost/beast/http/verb.hpp>
#include <fstream>




void evantSwitchInitalaiz(EvantSwitch& evantsMap);

nlohmann::json getConfig();
sql::Connection* connect(std::string, std::string, std::string, std::string, std::string);