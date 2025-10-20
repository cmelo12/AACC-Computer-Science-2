#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Menu.h"
//#include "BinarySearchTree.h"
//#include "City.h"

using namespace std;

void build();
void buildTree(BinarySearchTree<City>* myTree);

void mainMenu(BinarySearchTree<City>* myTree);

int main(){
	
	BinarySearchTree<City>* myTree = new BinarySearchTree<City>();
	buildTree(myTree);
	
	mainMenu(myTree);
	

}//end main


void buildTree(BinarySearchTree<City>* myTree) {
	ifstream infile("USCities.csv");
	string line = " ";
	istringstream iss("");

	if (!infile) {
		cout << "File not found" << endl;
		exit(0);
	}

	getline(infile, line);

	while (getline(infile, line)) {
		City city(line);

		myTree->add(city);
	}

	infile.close();
}

void build() {

	ifstream infile("USCities.csv");
	string fileLine;
	string header;

	if (!infile) {
		cout << "File not found" << endl;
		return;
	}

	getline(infile, header);

	// Table headers
	cout << left
		<< setw(20) << "City"
		<< setw(10) << "State ID"
		<< setw(15) << "State"
		<< setw(10) << "Zip Code"
		<< setw(20) << "County"
		<< setw(15) << "Population"
		<< setw(15) << "Land Area"
		<< setw(10) << "Time Zone"
		<< endl;

	cout << string(120, '-') << endl;

	// Print each line of city information
	while (getline(infile, fileLine)) {
		City city(fileLine);

		cout << left
			<< setw(20) << city.getCity()
			<< setw(10) << city.getID()
			<< setw(15) << city.getState()
			<< setw(10) << city.getZip()
			<< setw(20) << city.getCounty()
			<< setw(15) << city.getPop()
			<< setw(15) << city.getArea()
			<< setw(10) << city.getTimeZone()
			<< endl;
	}

	infile.close();



}
 
/*void zipTester(BinarySearchTree<City>* myTree) {
	SearchZipCode zipTest("39153");

	myTree->inOrderTraverse(zipTest);

	vector<City> results = zipTest.getZips();

	cout << "Search Results" << endl;
	cout << "---------------------------------------------------" << endl;

	for (auto& r : results){
		cout << r.getCounty() << ", " << r.getCity() << ", " << r.getState()
			<< " " << r.getZip() << endl;
	}//end for

}//end zipteste*/

/*void mainMenu() {

	int userChoice = -1;

	do {
		cout << "Main Menu" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Enter a number from the menu:" << endl;
		cout << "1. Search menu" << endl;
		cout << "2. Generate reports" << endl;
		cout << "3. Maximums and minimums" << endl;
		cout << "4. Edit City data" << endl;
		cout << "5. Exit." << endl;

		cin >> userChoice;

		cout << "\n";

		switch (userChoice) {
		case 1: searchMenu();
			break;
		case 2: reportsMenu();
			break;
		case 3: maxminMenu();
			break;
		case 4: editMenu();
			break;
		case 5: exit(0);
		default: cout << "Invalid input. Try again." << endl;
			break;
		}//end switch

		cout << "\n";
	} while (userChoice != 5);

}//end main menu

void searchMenu() {
	int user = -1;

	do {
		cout << "Search Menu" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Enter a number from the menu:" << endl;
		cout << "1. Search by zipcode." << endl;
		cout << "2. Search by state ID (Ex. NY)" << endl;
		cout << "3. Search by min land area" << endl;
		cout << "4. Return to main menu" << endl;

		cin >> user;

		cout << "\n";

		switch (user) {
		case 1: {}
			break;
		case 2:
			break;
		case 3:
			break;
		case 4: mainMenu();
			break;
		default: {
				cout << "Invalid input. Try again." << endl;
				searchMenu();
			}
			break;
		}//end switch

		cout << "\n";
	} while (user != 5);

}//end search

void reportsMenu() {
	int userChoice = -1;

	do {
		cout << "Reports Menu" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Enter a number from the menu:" << endl;
		cout << "1. List all cities" << endl;
		cout << "2. List all cities and their population" << endl;
		cout << "3. List all cities by time zone" << endl;
		cout << "4. Post order traverse" << endl;
		cout << "5. Return to main menu." << endl;

		cin >> userChoice;

		cout << "\n";

		switch (userChoice) {
		case 1:
			break;
		case 2: ;
			break;
		case 3:
			break;
		case 4:
			break;
		case 5: mainMenu();
		default: {
			cout << "Invalid input. Try again." << endl;
			reportsMenu();
		}
			break;
		}//end switch

		cout << "\n";
	} while (userChoice != 6);

}//end report

void maxminMenu() {
	int userChoice = -1;

	do {
		cout << "Max/Min Menu" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Enter a number from the menu:" << endl;
		cout << "1. Maximum land area " << endl;
		cout << "2. Maximum population" << endl;
		cout << "3. Minimum land area " << endl;
		cout << "4. Minimum population" << endl;
		cout << "5. Maximum population density" << endl;
		cout << "6. Minimum population density " << endl;
		cout << "7. Return to main menu" << endl;

		cin >> userChoice;

		cout << "\n";

		switch (userChoice) {
		case 1:
			break;
		case 2:;
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7: mainMenu();
		default: {
			cout << "Invalid input. Try again." << endl;
			maxminMenu();
		}
			break;
		}//end switch

		cout << "\n";
	} while (userChoice != 6);

}//end max

void editMenu() {
	int user = -1;

	do {
		cout << "Edit Menu" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Enter a number from the menu:" << endl;
		cout << "1. Edit population." << endl;
		cout << "2. Edit land area" << endl;
		cout << "3. Return to main menu" << endl;

		cin >> user;

		cout << "\n";

		switch (user) {
		case 1:
			break;
		case 2:
			break;
		case 3: mainMenu();
		default: {
			cout << "Invalid input. Try again." << endl;
			editMenu();
		}
			break;
		}//end switch

		cout << "\n";
	} while (user != 5);
}//end edit*/


/*
	City test;

	cin >> test;

	cout << test;
*/

/* city test
	City c1;
	cout << c1;
	c1.setArea(123);
	c1.setCity("City");
	c1.setCounty("County");
	c1.setID("ID");
	c1.setPop(67);
	c1.setState("State");
	c1.setTimeZone("The time zone");
	c1.setZip(908);

	cout << endl;
	cout << c1;
*/