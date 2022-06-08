#include "EducationalProgram.h"

EducationalProgram::EducationalProgram(string branchOfScience, string name, Time_ time) : TVprogram(name, time) {
    this->branchOfScience = branchOfScience;
}

EducationalProgram::~EducationalProgram() {}

void EducationalProgram::setBranchOfScience(string branchOfScience) {
    this->branchOfScience = branchOfScience;
}

string EducationalProgram::getBranchOfScience() const& {
    return branchOfScience;
}

string EducationalProgram::toString() const& {
    string ans;
    ans += "Name : " + name;
    ans += " ";
    ans += "Time : " + time.toStringTime();
    ans += " ";
    ans += "Description : " + getBranchOfScience() + " ";
    return ans;
}