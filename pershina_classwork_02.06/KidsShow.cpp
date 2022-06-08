#include "KidsShow.h"

KidsShow::KidsShow(int minAge, int maxAge, string name, Time_ time) : TVprogram(name, time) {
    this->minAge = minAge;
    this->maxAge = maxAge;
}

KidsShow::~KidsShow() {}

void KidsShow::setMinAge(int minAge) {
    this->minAge = minAge;
}

int KidsShow::getMinAge() const& {
    return minAge;
}

void KidsShow::setMaxAge(int maxAge) {
    this->maxAge = maxAge;
}

int KidsShow::getMaxAge() const& {
    return maxAge;
}

string KidsShow::toString() const& {
    string ans;
    ans += "Name : " + name;
    ans += " ";
    ans += "Time : " + time.toStringTime();
    ans += " ";
    ans += "Min age : " + getMinAge();
    ans += " ";
    ans += "Max age : " + getMaxAge();
    ans += " ";
    return ans;
}