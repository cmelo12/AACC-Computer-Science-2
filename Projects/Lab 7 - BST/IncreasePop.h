#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "Visitor.h"

using namespace std;

class IncreasePop : public Visitor {

public:
	inline IncreasePop(int userPop, const string& userCity);
	inline~IncreasePop();

	inline void visit(City& city);

	inline int getNewPop() const;
	inline int getOldPop() const;
	inline City getOldCity() const;
	inline void found() const;

private:
	int newPopulation;
	int oldPopulation;
	string privCity;
	City theCity;
	bool cityFound = false;
};

IncreasePop::IncreasePop(int userPop, const string& userCity) : Visitor() {
	this->newPopulation = userPop;
	this->privCity = userCity;

}//end constructor

IncreasePop::~IncreasePop() {}

void IncreasePop::visit(City& city) {
	string lowerCity;
	string lowerPrivCity;

	lowerCity = city.getCity();
	lowerPrivCity = privCity;

	transform(lowerCity.begin(), lowerCity.end(), lowerCity.begin(), ::tolower);
	transform(lowerPrivCity.begin(), lowerPrivCity.end(), lowerPrivCity.begin(), ::tolower);

	if (lowerCity == lowerPrivCity) {
		oldPopulation = stoi(city.getPop());
		theCity = city;
		
		newPopulation += oldPopulation;

		city.setPop(to_string(newPopulation));
		cityFound = true;
		
		cout << left
			<< setw(20) << "City"
			<< setw(20) << "Old Population"
			<< setw(20) << "New Population"
			<< endl;
		cout << string(120, '-') << endl;

		cout << left
			<< setw(20) << city.getCity()
			<< setw(20) << oldPopulation
			<< setw(20) << newPopulation
			<< endl;

	}//end if

}//end visit

int IncreasePop::getNewPop() const {
    return newPopulation;
}

int IncreasePop::getOldPop() const {
    return oldPopulation;
}

City IncreasePop::getOldCity() const {
    return theCity;
}

void IncreasePop::found() const {
	cout << "\n";

	if (cityFound == true)
		cout << "\n";
	else
		cout << "City not found." << endl;

}

