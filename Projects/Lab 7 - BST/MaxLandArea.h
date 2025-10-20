#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Visitor.h"

using namespace std;

class MaxLandArea : public Visitor {
public:

	inline MaxLandArea();
	inline ~MaxLandArea();

	inline void visit(City& city);

	inline City getMaxArea();
private:
	int maxArea;
	City maxCity;
};

MaxLandArea::MaxLandArea() : Visitor() {
	this->maxArea = 0;
}

MaxLandArea::~MaxLandArea() {}

void MaxLandArea::visit(City& city) {
	int cityArea = 0;
	
	cityArea = stoi(city.getArea());
	
	if (cityArea > maxArea)	{
		maxArea = cityArea;
		maxCity = city;
	}//end if

}//

City MaxLandArea::getMaxArea() {
	return maxCity;

}//end max


/*#include <vector>
#include <iostream>
#include "Visitor.h"

using namespace std;

class MaxLandArea : public Visitor {
public:
	inline MaxLandArea(string searchArea);
	inline ~MaxLandArea();

	inline void visit(City city);

	inline vector<City> getAreas();
private:
	string area;
	vector<City> matches;
};

MaxLandArea::MaxLandArea(string zip) : Visitor() {
	this->area = zip;
}

MaxLandArea::~MaxLandArea() {}

void MaxLandArea::visit(City city) {
	matches.push_back(city);

}//end visit

vector<City> MaxLandArea::getAreas() {
	return matches;
}


*/