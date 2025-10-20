#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Visitor.h"

using namespace std;

class MaxDensity : public Visitor {
public:

	inline MaxDensity();
	inline ~MaxDensity();

	inline void visit(City& city);

	inline int getMaxDensity() const;
	inline City getMaxCity();
private:
	int maxDensity;
	City theCity;
};

MaxDensity::MaxDensity() : Visitor() {
	this->maxDensity = -1;
}

MaxDensity::~MaxDensity() {}

void MaxDensity::visit(City& city) {
	int cityArea = 0;
	int cityPop = 0;
	int cityDensity = 0;

	cityArea = stoi(city.getArea());
	cityPop = stoi(city.getPop());
	cityDensity = cityPop / cityArea;

	if (cityDensity > maxDensity) {
		maxDensity = cityDensity;
		theCity = city;
	}//end if

}//

City MaxDensity::getMaxCity() {
	return theCity;

}//end max

int MaxDensity::getMaxDensity() const {
	return maxDensity;
}

