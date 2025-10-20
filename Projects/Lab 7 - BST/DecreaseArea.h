#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "Visitor.h"

using namespace std;

class DecreaseArea : public Visitor {
public:
	inline DecreaseArea(double userArea, const string& userCity);
	inline~DecreaseArea();

	inline void visit(City& city);

	inline int getNewArea() const;
	inline int getOldArea() const;
	inline City getOldCity() const;
	inline void found() const;

private:
	double newArea;
	double oldArea;
	string privCity;
	City theCity;
	bool cityFound = false;
};

DecreaseArea::DecreaseArea(double userArea, const string& userCity) : Visitor() {
	this->newArea = userArea;
	this->privCity = userCity;

}//end constructor

DecreaseArea::~DecreaseArea() {}

void DecreaseArea::visit(City& city) {
	string lowerCity;
	string lowerPrivCity;

	lowerCity = city.getCity();
	lowerPrivCity = privCity;

	transform(lowerCity.begin(), lowerCity.end(), lowerCity.begin(), ::tolower);
	transform(lowerPrivCity.begin(), lowerPrivCity.end(), lowerPrivCity.begin(), ::tolower);

	if (lowerCity == lowerPrivCity) {
		oldArea = stod(city.getArea());
		theCity = city;

		newArea = oldArea - newArea;

		city.setPop(to_string(newArea));
		cityFound = true;

		cout << left
			<< setw(20) << "City"
			<< setw(20) << "Old Population"
			<< setw(20) << "New Population"
			<< endl;
		cout << string(120, '-') << endl;

		cout << left
			<< setw(20) << city.getCity()
			<< setw(20) << oldArea
			<< setw(20) << newArea
			<< endl;

	}//end if

}//end visit

int DecreaseArea::getNewArea() const {
	return newArea;
}

int DecreaseArea::getOldArea() const {
	return oldArea;
}

City DecreaseArea::getOldCity() const {
	return theCity;
}

void DecreaseArea::found() const {
	cout << "\n";

	if (cityFound == true)
		cout << "\n";
	else
		cout << "City not found." << endl;

}



