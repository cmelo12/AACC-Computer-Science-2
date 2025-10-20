#pragma once
#include "Visitor.h"
#include <vector>
#include <iostream>

using namespace std;

class ListByTimeZone : public Visitor {
public:

	inline ListByTimeZone(const vector<City>& allZones);
	inline ~ListByTimeZone();

	inline void visit(City& city);

	inline vector<City> getTimeZones();
private:
	vector<City> cities;
};

ListByTimeZone::ListByTimeZone(const vector<City>& allZones) {
	this->cities = allZones;
}

ListByTimeZone::~ListByTimeZone() {}

void ListByTimeZone::visit(City& city) {

	cities.push_back(city);

}//end visit 

vector<City> ListByTimeZone::getTimeZones() {
	return cities;

}//end vector

