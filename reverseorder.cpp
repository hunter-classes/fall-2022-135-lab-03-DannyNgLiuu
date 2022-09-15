#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <sstream>
#include "reverseorder.h"

void reverse_order(std::string date1, std::string date2) {
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading. \n";
        exit(1);
    }

    std::string junk;
    getline(fin, junk);

    std::string dateInfo;
    double EastSt, EastEl, WestSt, WestEl;
    int month2 = std::stoi(date2.substr(0,2));
    int day2 = std::stoi(date2.substr(3,5));
    int month1 = std::stoi(date1.substr(0,2));
    int day1 = std::stoi(date1.substr(3,5));

    std::cout << "month: " << month2 << "\n";
    std::cout << "day: " << day2 << "\n";
    std::cout << "month: " << month1 << "\n";
    std::cout << "day: " << day1 << "\n";

    int totalDay = 1;

    int monthTemp = month2;
    int dayTemp = day2;

    while(!(monthTemp == month1) || !(dayTemp == day1)) {
        if(dayTemp == 0) {
            monthTemp--;
            if (monthTemp == 4 || monthTemp == 6 || monthTemp == 9 || monthTemp == 11) {
                dayTemp = 30;
            } else {
                dayTemp = 31;        
        }
        if(monthTemp == 2) {
            dayTemp = 28;
        }
        }
        totalDay++;
        dayTemp--;
    }

    int WestElArray [totalDay];
    std::string dateArray [totalDay];
    int i = 0;

    while(!(month2 == month1) || !(day2 == day1)) {
        if(day2 == 0) {
            month2--;
            if (month2 == 4 || month2 == 6 || month2 == 9 || month2 == 11) {
                day2 = 30;
            } else {
                day2 = 31;        
        }
        if(month2 == 2) {
            day2 = 28;
        }
        }
        std::cout << std::setw(2) << std::setfill('0') << std::to_string(month2) << "/" << std::setw(2) << std::setfill('0') << std::to_string(day2) << "/2018 \n ";
        std::ostringstream oss;
        auto cout_buff = std::cout.rdbuf(oss.rdbuf());
        std::cout << std::setw(2) << std::setfill('0') << std::to_string(month2) << "/" << std::setw(2) << std::setfill('0') << std::to_string(day2) << "/2018";
        std::cout.rdbuf(cout_buff);
        std::string dayTemp = oss.str();
        dateArray[i] = dayTemp;
        i++;
        day2--;
    }

    while(fin >> dateInfo >> EastSt >> EastEl >> WestSt >> WestEl) {
    fin.ignore(INT_MAX, '\n');
    int i = 0;
    int j = totalDay-1;
    if(dateInfo == dateArray[j]) {
        std::cout << "maybe";
        WestElArray[i] = WestEl;
        i++;
        j--;
    }
}
    for(int i = 0; i < totalDay; i++) {
        std::cout << dateArray[i] << "\n";
    }
}
