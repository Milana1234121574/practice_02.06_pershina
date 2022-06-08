#include "Movie.h"

Movie::Movie(string description, int year, string name, Time_ time) : TVprogram(name, time) {
    this->description = description;
    this->year = year;
}

Movie::~Movie() {}

void Movie::setDescription(string description) {
    this->description = description;
}

string Movie::getDescription() const& {
    return description;
}

void Movie::setYear(int year) {
    this->year = year;
}

int Movie::getYear() const& {
    return year;
}

string Movie::toString() const& {
    string ans;
    ans += "Name : " + name;
    ans += " ";
    ans += "Time : " + time.toStringTime();
    ans += " ";
    ans += "Description : " + getDescription() + " ";
    ans += " ";
    ans += "Year : " + getYear();
    return ans;
}