#pragma once
#include "TVprogram.h"
class EducationalProgram :
    public TVprogram {
protected:
	string branchOfScience;
public:
	EducationalProgram(string branchOfScience, string name, Time_ time);
	~EducationalProgram();
	void setBranchOfScience(string branchOfScience);
	string getBranchOfScience()const&;
	virtual string type() const& override { return "Education"; }
	virtual string toString() const& override;
};