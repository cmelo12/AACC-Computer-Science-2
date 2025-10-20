#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Visitor.h"

using namespace std;

class MaxPop : public Visitor {
public:

	inline MaxPop();
	inline ~MaxPop();

	inline void visit(City& city);

	inline City getMaxPop();
private:
	int maxPopulation;
	City maxCity;
};

MaxPop::MaxPop() : Visitor() {
	this->maxPopulation = 0;
}

MaxPop::~MaxPop() {}

void MaxPop::visit(City& city) {
	int cityPop = 0;

	cityPop = stoi(city.getPop());

	if (cityPop > maxPopulation) {
		maxPopulation = cityPop;
		maxCity = city;
	}//end if

}//

City MaxPop::getMaxPop() {
	return maxCity;

}//end max
