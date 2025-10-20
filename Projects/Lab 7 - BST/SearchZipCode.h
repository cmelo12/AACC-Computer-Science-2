#pragma once

#include <vector>
#include <iostream>
#include "Visitor.h"

using namespace std;

class SearchZipCode : public Visitor {
public:
	inline SearchZipCode(string searchZip);
	inline ~SearchZipCode();

	inline void visit(City& city);

	inline vector<City> getZips();
private:
	string zipCode;
	vector<City> matches;
};

SearchZipCode::SearchZipCode(string zip) : Visitor() {
	this->zipCode = zip;
}

SearchZipCode::~SearchZipCode() {}

void SearchZipCode::visit(City& city) {
	if (city.getZip().compare(zipCode) == 0)
		matches.push_back(city);

}

vector<City> SearchZipCode::getZips() {
	return matches;
}


