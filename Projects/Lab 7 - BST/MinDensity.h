#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Visitor.h"

using namespace std;

class MinDensity : public Visitor {
public:

	inline MinDensity();
	inline ~MinDensity();

	inline void visit(City& city);

	inline int getMinDensity() const;
	inline City getMinCity();
private:
	int minDensity;
	City theCity;
};

MinDensity::MinDensity() : Visitor() {
	this->minDensity = INT_MAX;
}

MinDensity::~MinDensity() {}

void MinDensity::visit(City& city) {
	int cityArea = 0;
	int cityPop = 0;
	int cityDensity = 0;

	cityArea = stoi(city.getArea());
	cityPop = stoi(city.getPop());
	cityDensity = cityPop / cityArea;

	if (cityDensity < minDensity) {
		minDensity = cityDensity;
		theCity = city;
	}//end if

}//

City MinDensity::getMinCity() {
	return theCity;

}//end max

int MinDensity::getMinDensity() const {
	return minDensity;
}
