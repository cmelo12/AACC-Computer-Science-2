#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Visitor.h"

using namespace std;

class MinLandArea : public Visitor {
public:

	inline MinLandArea();
	inline ~MinLandArea();

	inline void visit(City& city);

	inline City getMinArea();
private:
	int minArea;
	City minCity;
};

MinLandArea::MinLandArea() : Visitor() {
	this->minArea = INT_MAX;
}

MinLandArea::~MinLandArea() {}

void MinLandArea::visit(City& city) {
	int cityArea = 0;
	cityArea = stoi(city.getArea());

	if (cityArea < minArea) {
		minArea = cityArea;
		minCity = city;
	}//end if

}//

City MinLandArea::getMinArea() {
	return minCity;

}//end max
