#include "evantSwitch.hpp"

#include "./evants/usersEvants.hpp"
#include "./evants/bankEvants.hpp"
#include "./evants/cashEvants.hpp"
#include "./evants/transferEvants.hpp"
#include "./evants/additationEvants.hpp"
#include "./evants/complexEvants.hpp"

#include <boost/beast/http/status.hpp>
#include <nlohmann/json_fwd.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio.hpp>
#include <boost/beast/http/verb.hpp>




void evantSwitchInitalaiz(EvantSwitch& evantsMap);

nlohmann::json getConfig();
sql::Connection* connect(std::string, std::string, std::string, std::string, std::string);