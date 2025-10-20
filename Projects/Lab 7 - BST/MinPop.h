#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Visitor.h"

using namespace std;

class MinPop : public Visitor {
public:

	inline MinPop();
	inline ~MinPop();

	inline void visit(City& city);

	inline City getMinPop();
private:
	int minPopulation;
	City minCity;
};

MinPop::MinPop() : Visitor() {
	this->minPopulation = INT_MAX;
}

MinPop::~MinPop() {}

void MinPop::visit(City& city) {
	int cityPop = 0;

	cityPop = stoi(city.getPop());

	if (cityPop < minPopulation) {
		minPopulation = cityPop;
		minCity = city;
	}//end if

}//

City MinPop::getMinPop() {
	return minCity;

}
