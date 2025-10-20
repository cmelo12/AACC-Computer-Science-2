#pragma once

#include <vector>
#include <iostream>
#include "Visitor.h"

using namespace std;

class SearchStateId : public Visitor {
public:
	
	inline SearchStateId(string searchId);
	inline ~SearchStateId();

	inline void visit(City& city);

	inline vector<City> getIds();
private:
	string stateId;
	vector<City> matches;
};

SearchStateId::SearchStateId(string id) : Visitor() {
	this->stateId = id;
}

SearchStateId::~SearchStateId() {}

void SearchStateId::visit(City& city) {
	if (city.getID().compare(stateId) == 0) 
		matches.push_back(city);

}//

vector<City> SearchStateId::getIds() {
	return matches;
}



