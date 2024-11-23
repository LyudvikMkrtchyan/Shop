#include "../../includes/dataBaseClasses/helperClass.hpp"

    std::string Helper::getLastDayOfMonthFromString(std::string date){
        int year    = 0;
        int month   = 0;
        int lastDay = 0;
        char result[11];
        
        std::sscanf(date.c_str(), "%d-%d", &year, &month);
    
        if (month == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                lastDay = 29;
            } else {
                lastDay = 28;
            }
        }else if (month == 4 || month == 6 || month == 9 || month == 11) {
            lastDay = 30;
        }else {
            lastDay = 31;
        }
        std::sprintf(result, "%04d-%02d-%02d", year, month, lastDay);

        return std::string(result);
    }
    std::string Helper::getFirstDayOfMonthFromString(std::string date){
        return date + "-01";
    }
    
