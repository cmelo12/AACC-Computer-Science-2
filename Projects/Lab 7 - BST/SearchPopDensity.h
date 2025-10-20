#pragma once
#include "Visitor.h"
#include <vector>
#include <iostream>

using namespace std;

class SearchPopDensity : public Visitor {
public:

	inline SearchPopDensity(const vector<City>& allCities);
	inline ~SearchPopDensity();

	inline void visit(City& city);

	inline vector<City> getPopDensity();
private:
	vector<City> cities;
};

SearchPopDensity::SearchPopDensity(const vector<City>& allCities) {
	this->cities = allCities;
}

SearchPopDensity::~SearchPopDensity() {}

void SearchPopDensity::visit(City& city) {

	cities.push_back(city);

}//end visit 

vector<City> SearchPopDensity::getPopDensity() {
	return cities;

}//end vector
