#pragma once
#include "Visitor.h"
#include <vector>
#include <iostream>

using namespace std;

class listAllCities : public Visitor {
public:

	inline listAllCities(const vector<City>& allCities);
	inline ~listAllCities();

	inline void visit(City& city);

	inline vector<City> getCities();
private:
	vector<City> cities;
};

listAllCities::listAllCities(const vector<City>& allCities) {
	this->cities = allCities;
}

listAllCities::~listAllCities() {}

void listAllCities::visit(City& city) {

	cities.push_back(city);

}//end visit 

vector<City> listAllCities::getCities() {
	return cities;

}//end vector

