#include "Show.h"

Show::Show(string topic, string name, Time_ time) : TVprogram(name, time) {
    this->topic = topic;
}

Show::~Show() {}

void Show::setTopic(string topic) {
   this->topic = topic;
}

string Show::getTopic() const& {
    return topic;
}

string Show::toString() const& {
    string ans;
    ans += "Name : " + name;
    ans += " ";
    ans += "Time : " + time.toStringTime();
    ans += " ";
    ans += "Topic : " + getTopic();
    ans += " ";
    return ans;
}
