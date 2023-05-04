#ifndef HEAP_DATE_H
#define HEAP_DATE_H

#include <iostream>
#include <string>

class Date {
public:
    Date() : day(0),month(0),year(0) {}
    Date(std::string date);
    int day;
    int month;
    int year;
    std::string notation();
    bool operator>(const Date& other);
    bool operator<(const Date& other);
    bool operator!=(const Date& other);
    Date(const Date& from);
};

Date::Date(const Date& from) {
    day = from.day;
    month = from.month;
    year = from.year;
}

Date::Date(std::string date) {
    day = (date[0]-'0')*10 + date[1]-'0';
    month = (date[3]-'0')*10 + date[4]-'0';
    year = 0;
    for(int i = 6; i < date.length(); i++) {
        year *= 10;
        year += date[i]-'0';
    }
}

std::string Date::notation() {
    std::string _day = std::to_string(day);
    std::string _month = std::to_string(month);
    std::string _year = std::to_string(year);
    if(day < 10) _day = '0' + std::to_string(day);
    if(month < 10) _month = '0' + std::to_string(month);
    if(year < 10) _year = "000" + std::to_string(year);
    else if(year < 100) _year = "00" + std::to_string(year);
    else if(year < 1000) _year = '0' + std::to_string(year);
    return _day + '-' + _month + '-' + _year;
}

bool Date::operator>(const Date &other) {
    if(year < other.year) return true;
    if(year > other.year) return false;
    if(month < other.month) return true;
    if(month > other.month) return false;
    if(day < other.day) return true;
    if(day > other.day) return false;
    return false;
}

bool Date::operator<(const Date &other) {
    if(year < other.year) return false;
    if(year > other.year) return true;
    if(month < other.month) return false;
    if(month > other.month) return true;
    if(day < other.day) return false;
    if(day > other.day) return true;
    return false;
}

bool Date::operator!=(const Date& other) {
    if(year != other.year) return true;
    if(month != other.month) return true;
    if(day != other.day) return true;
    return false;
}

#endif //HEAP_DATE_H
