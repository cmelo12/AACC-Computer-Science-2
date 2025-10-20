#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Visitor.h"

using namespace std;

class SearchMinArea : public Visitor {
public:

	inline SearchMinArea(string searchId);
	inline ~SearchMinArea();

	inline void visit(City& city);

	inline vector<City> getAreas();
private:
	string landArea;
	vector<City> matches;
};

SearchMinArea::SearchMinArea(string area) : Visitor() {
	this->landArea = area;
}

SearchMinArea::~SearchMinArea() {}

void SearchMinArea::visit(City& city) {
	int cityArea = 0;
	int privateArea = 0;

	cityArea = stoi(city.getArea());
	privateArea = stoi(landArea);

	if (cityArea >= privateArea)
		matches.push_back(city);

}//

vector<City> SearchMinArea::getAreas() {
	return matches;
}
