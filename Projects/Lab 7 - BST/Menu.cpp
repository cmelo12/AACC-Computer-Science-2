#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Menu.h"
#include "utilities.h"

using namespace std;

void printHeader();

//search menu prototypes
void searchZip(BinarySearchTree<City>* myTree);
void searchId(BinarySearchTree<City>* myTree);
void searchArea(BinarySearchTree<City>* myTree);

//report menus prototypes
void listCities(BinarySearchTree<City>* myTree);
void searchDensity(BinarySearchTree<City>* myTree);
void listTimeZones(BinarySearchTree<City>* myTree);
void postOrder(BinarySearchTree<City>* myTree);

//Max/min menu prototypes
void maxLandArea(BinarySearchTree<City>* myTree);
void maxPopulation(BinarySearchTree<City>* myTree);
void minLandArea(BinarySearchTree<City>* myTree);
void minPopulation(BinarySearchTree<City>* myTree);
void maxDensity(BinarySearchTree<City>* myTree);
void minDensity(BinarySearchTree<City>* myTree);

//ADD PROTOTYPES TO MENU.H
//Edit menu prototypes
void editPopulation(BinarySearchTree<City>* myTree);
void editArea(BinarySearchTree<City>* myTree);


void mainMenu(BinarySearchTree<City>* myTree) {

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
		case 1: searchMenu(myTree);
			break;
		case 2: reportsMenu(myTree);
			break;
		case 3: maxminMenu(myTree);
			break;
		case 4: editMenu(myTree);
			break;
		case 5: exit(0);
		default: cout << "Invalid input. Try again." << endl;
			break;
		}//end switch

		cout << "\n";
	} while (userChoice != 5);

}//end main menu


void editMenu(BinarySearchTree<City>* myTree) {
	int userChoice = -1;

	do {
		cout << "Edit Menu" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Enter a number from the menu:" << endl;
		cout << "1. Edit Population." << endl;
		cout << "2. Edit land area." << endl;
		cout << "3. Return to main menu" << endl;

		cin >> userChoice;

		cout << "\n";

		switch (userChoice) {
		case 1: editPopulation(myTree);
			break;
		case 2: editArea(myTree);	
			break;
		case 3: return;
			break;
			
		default: {
				cout << "Invalid input. Try again." << endl;
				editMenu(myTree);
			}
			break;
		}//end switch

		cout << "\n";
	} while (userChoice != 3);


}//end editMenu

void editArea(BinarySearchTree<City>* myTree) {
	double userArea = 0;
	string userCity = " ";
	int subMenu = 0;

	cin.ignore();

	do {
		cout << "Edit Sub Menu" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Enter a number from the menu:" << endl;
		cout << "1. Increase Area." << endl;
		cout << "2. Decrease Area." << endl;
		cout << "3. Return." << endl;

		cin >> subMenu;

		cout << "\n";

		switch (subMenu){
		case 1: {
			cin.ignore();
			cout << "Enter the city you want to modify: " << endl;
			getline(cin, userCity);
			cout << "Enter the amount: " << endl;
			cin >> userArea;

			cout << endl;
			IncreaseArea edit(userArea, userCity);
			myTree->inOrderTraverse(edit);
			edit.found();
		}
			  break;

		case 2: {
			cin.ignore();
			cout << "Enter the city you want to modify: " << endl;
			getline(cin, userCity);
			cout << "Enter the amount: " << endl;
			cin >> userArea;

			cout << endl;
			DecreaseArea edit(userArea, userCity);
			myTree->inOrderTraverse(edit);
			edit.found();
		}
			  break;

		case 3: return;
			break;

		default: {
			cout << "Invalid input." << endl;
			return;
		}
			   break;
		}

	} while (subMenu != 3);
}//end editArea

void editPopulation(BinarySearchTree<City>* myTree) {
	int userPop = 0;
	string userCity = " ";
	int subMenu = 0;

	cin.ignore();

	do {
		cout << "Edit Sub Menu" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Enter a number from the menu:" << endl;
		cout << "1. Increase Population." << endl;
		cout << "2. Decrease Population." << endl;
		cout << "3. Return." << endl;

		cin >> subMenu;

		cout << "\n";

		switch (subMenu){
		case 1: {
			cin.ignore();
			cout << "Enter the city you want to modify: " << endl;
			getline(cin, userCity);
			cout << "Enter the amount: " << endl;
			cin >> userPop;

			cout << endl;
			IncreasePop edit(userPop, userCity);
			myTree->inOrderTraverse(edit);
			edit.found();
		}
			  break;
		case 2: {
			cin.ignore();
			cout << "Enter the city you want to modify: " << endl;
			getline(cin, userCity);
			cout << "Enter the amount: " << endl;
			cin >> userPop;

			cout << endl;
			DecreasePop edit(userPop, userCity);
			myTree->inOrderTraverse(edit);
			edit.found();
		}
		case 3: return;
			break;
			
		default: {
				cout << "Invalid input." << endl;
				return;
			}
			break;
		}
	
	} while (subMenu != 3);

}//end editPop

void maxminMenu(BinarySearchTree<City>* myTree) {
	int user = -1;

	do {
		cout << "Max/Min Menu" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Enter a number from the menu:" << endl;
		cout << "1. Display city with the biggest land area." << endl;
		cout << "2. Display city with the biggest population." << endl;
		cout << "3. Display city with the lowest land area." << endl;
		cout << "4. Display city with the lowest population." << endl;
		cout << "5. Display city with the biggest population density." << endl;
		cout << "6. Display city with the lowest population density." << endl;
		cout << "7. Return to main menu." << endl;
		cin >> user;

		cout << "\n";

		switch (user) {
		case 1: maxLandArea(myTree);
			break;
		case 2: maxPopulation(myTree);
			break;
		case 3: minLandArea(myTree);
			break;
		case 4: minPopulation(myTree);
			break;
		case 5: maxDensity(myTree);
			break;
		case 6: minDensity(myTree);
			break;
		case 7: return;
			break;
		default: {
			cout << "Invalid input. Try again." << endl;
			reportsMenu(myTree);
		}
			   break;
		}//end switch

		cout << "\n";
	} while (user != 7);

}//end reportsMenu

void minDensity(BinarySearchTree<City>* myTree) {
	City result;
	MinDensity findMin;
	int population = 0;
	int density = 0;

	cout << endl;
	myTree->inOrderTraverse(findMin);
	result = findMin.getMinCity();
	density = findMin.getMinDensity();

	population = stoi(result.getPop());

	//modified header
	cout << left
		<< setw(20) << "City"
		<< setw(15) << "State"
		<< setw(15) << "Population"
		<< setw(15) << "Land Area"
		<< setw(15) << "Population Density"
		<< endl;
	cout << string(120, '-') << endl;

	cout << left
		<< setw(20) << result.getCity()
		<< setw(15) << result.getState()
		<< setw(15) << intWithCommas(population)
		<< setw(15) << result.getArea()
		<< setw(15) << intWithCommas(density)
		<< endl;

}//end maxDen

void maxDensity(BinarySearchTree<City>* myTree) {
	City result;
	MaxDensity findMax;
	int population = 0;
	int density = 0;

	cout << endl;
	myTree->inOrderTraverse(findMax);
	result = findMax.getMaxCity();
	density = findMax.getMaxDensity();

	population = stoi(result.getPop());

	//modified header
	cout << left
		<< setw(20) << "City"
		<< setw(15) << "State"
		<< setw(15) << "Population"
		<< setw(15) << "Land Area"
		<< setw(15) << "Population Density"
		<< endl;
	cout << string(120, '-') << endl;

	cout << left
		<< setw(20) << result.getCity()
		<< setw(15) << result.getState()
		<< setw(15) << intWithCommas(population)
		<< setw(15) << result.getArea()
		<< setw(15) << intWithCommas(density)
		<< endl;

}//end maxDen

void minPopulation(BinarySearchTree<City>* myTree) {
	City result;
	MinPop findMinPop;
	int population = 0;

	cout << endl;
	myTree->inOrderTraverse(findMinPop);
	result = findMinPop.getMinPop();

	population = stoi(result.getPop());

	//modified header
	cout << left
		<< setw(20) << "City"
		<< setw(15) << "State"
		<< setw(15) << "Population"
		<< setw(15) << "Land Area"
		<< endl;
	cout << string(120, '-') << endl;

	cout << left
		<< setw(20) << result.getCity()
		<< setw(15) << result.getState()
		<< setw(15) << intWithCommas(population)
		<< setw(15) << result.getArea()
		<< endl;

}//end minPop

void minLandArea(BinarySearchTree<City>* myTree) {
	City result;
	MinLandArea findMin;
	int population = 0;

	cout << endl;
	myTree->inOrderTraverse(findMin);
	result = findMin.getMinArea();

	population = stoi(result.getPop());

	//modified header
	cout << left
		<< setw(20) << "City"
		<< setw(15) << "State"
		<< setw(15) << "Population"
		<< setw(15) << "Land Area"
		<< endl;
	cout << string(120, '-') << endl;

	cout << left
		<< setw(20) << result.getCity()
		<< setw(15) << result.getState()
		<< setw(15) << intWithCommas(population)
		<< setw(15) << result.getArea()
		<< endl;

}//end minLand

void maxPopulation(BinarySearchTree<City>* myTree) {
	City result;
	MaxPop findMaxPop;
	int population = 0;

	cout << endl;
	myTree->inOrderTraverse(findMaxPop);
	result = findMaxPop.getMaxPop();

	population = stoi(result.getPop());

	//modified header
	cout << left
		<< setw(20) << "City"
		<< setw(15) << "State"
		<< setw(15) << "Population"
		<< setw(15) << "Land Area"
		<< endl;
	cout << string(120, '-') << endl;

	cout << left
		<< setw(20) << result.getCity()
		<< setw(15) << result.getState()
		<< setw(15) << intWithCommas(population)
		<< setw(15) << result.getArea()
		<< endl;

}//end maxPop

void maxLandArea(BinarySearchTree<City>* myTree) {
	City result;
	MaxLandArea findMax;
	int population = 0;

	cout << endl;
	myTree->inOrderTraverse(findMax);
	result = findMax.getMaxArea();

	population = stoi(result.getPop());

	//modified header
	cout << left
		<< setw(20) << "City"
		<< setw(15) << "State"
		<< setw(15) << "Population"
		<< setw(15) << "Land Area"
		<< endl;
	cout << string(120, '-') << endl;

	cout << left
		<< setw(20) << result.getCity()
		<< setw(15) << result.getState()
		<< setw(15) << intWithCommas(population)
		<< setw(15) << result.getArea()
		<< endl;

}//end maxLand



void reportsMenu(BinarySearchTree<City>* myTree) {
	int user = -1;

	do {
		cout << "Reports Menu" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Enter a number from the menu:" << endl;
		cout << "1. List of all cities." << endl;
		cout << "2. List all cities and population density." << endl;
		cout << "3. List cities by time zone" << endl;
		cout << "4. Post order traverse display." << endl;
		cout << "5. Return to main menu." << endl;
		cin >> user;

		cout << "\n";

		switch (user) {
		case 1: listCities(myTree);
			break;
		case 2: searchDensity(myTree);
			break;
		case 3: listTimeZones(myTree);
			break;
		case 4: postOrder(myTree);
			break;
		case 5: return;
			break;
		default: {
			cout << "Invalid input. Try again." << endl;
			reportsMenu(myTree);
		}
			   break;
		}//end switch

		cout << "\n";
	} while (user != 5);

}//end reportsMenu

void postOrder(BinarySearchTree<City>* myTree) {
	cout << endl;
	printHeader();
	myTree->postOrderTraverse();

}//end postOrder

void listTimeZones(BinarySearchTree<City>* myTree) {
	string user = " ";
	vector<City> zones;
	vector<City> matchedUser;

	ListByTimeZone visit(zones);

	myTree->inOrderTraverse(visit);
	zones = visit.getTimeZones();

	cout << "Chooose what time zone to dislay " << endl;
	cout << "Enter the acronym (EX.: EST)" << endl;
	cout << "\tEastern Standard Time (EST)" << endl;
	cout << "\tCentral Standard Time (CST)" << endl;
	cout << "\tMountain Standard Time (MST)"<< endl;
	cout << "\tPacific Standard Time (PST)" << endl;
	cout << "\tHawaii Standard Time (HST)" << endl;

	cin.ignore();
	getline(cin, user);
	transform(user.begin(), user.end(), user.begin(), ::toupper);
	cout << endl;

	for (const auto& z : zones)
		if (user.compare(z.getTimeZone()) == 0)
			matchedUser.push_back(z);

	if (matchedUser.empty()){
		cout << "Input is invalid or inexistent. Try again." << endl;
		return;
	}//end if

	//modified header
	cout << left
		<< setw(20) << "City"
		<< setw(22) << "State"
		<< setw(15) << "Zip Code"
		<< endl;
	cout << string(120, '-') << endl;
	
	for (const auto& m : matchedUser){
		cout << left
			<< setw(20) << m.getCity()
			<< setw(22) << m.getState()
			<< setw(15) << m.getZip()
			<< endl;
	}//end for

}//end list zones

void searchDensity(BinarySearchTree<City>* myTree) {
	vector<City> density;
	SearchPopDensity visit(density);

	cout << endl;
	myTree->inOrderTraverse(visit);
	density = visit.getPopDensity();

	cout << left
		<< setw(20) << "City"
		<< setw(15) << "Population"
		<< setw(15) << "Land Area"
		<< setw(15) << "Population Density"
		<< endl;
	cout << string(120, '-') << endl;

	for (const auto& c : density){
		cout << left
			<< setw(20) << c.getCity()
			<< setw(15) << c.getPop()
			<< setw(15) << c.getArea()
			<< setw(15) << intWithCommas(((stoi(c.getPop())) / stoi(c.getArea())))
			<< endl;
	}//end for

}//end searchDen

void listCities(BinarySearchTree<City>* myTree) {
	vector<City> allCities;

	listAllCities cityVisit(allCities);

	myTree->inOrderTraverse(cityVisit);
	allCities = cityVisit.getCities();

	printHeader();
	for (const auto& c : allCities)
		cout << c;

}//end allCities



void searchMenu(BinarySearchTree<City>* myTree) {
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
		case 1: searchZip(myTree);
			  break;
		case 2:searchId(myTree);
			break;
		case 3: searchArea(myTree);
			break;
		case 4: return;
			break;
		default: {
			cout << "Invalid input. Try again." << endl;
			searchMenu(myTree);
		}
			   break;
		}//end switch

		cout << "\n";
	} while (user != 5);

}//end searchMenu

void searchArea(BinarySearchTree<City>* myTree) {
	vector<City> results;
	string minArea = " ";

	cin.ignore();
	cout << "Enter a minimum land area to search for): " << endl;
	getline(cin, minArea);
	cout << endl;

	SearchMinArea search(minArea);
	myTree->inOrderTraverse(search);

	results = search.getAreas();

	if (results.empty())
		cout << "\nYour input had not matches\n";
	else
		printHeader();

	for (const auto& r : results) 
		cout << r;

}//end searchArea

void searchId(BinarySearchTree<City>* myTree) {
	vector<City> results;
	string id = " ";

	cin.ignore();
	cout << "Enter a state ID (Ex.: NY): ";
	getline(cin, id);
	cout << endl;

	transform(id.begin(), id.end(), id.begin(), ::toupper);

	SearchStateId search(id);
	myTree->inOrderTraverse(search);

	results = search.getIds();

	if (results.empty())
		cout << "\nYour input had not matches\n";
	else {
		//modified header
		cout << left
			<< setw(20) << "City"
			<< setw(10) << "Zip Code"
			<< setw(20) << "County"
			<< endl;
		cout << string(120, '-') << endl;
	}

	for (const auto& r : results) {
		cout << left
			<< setw(20) << r.getCity()
			<< setw(10) << r.getZip()
			<< setw(20) << r.getCounty()
			<< endl;
	}//end for*/

}//end searchid

void searchZip(BinarySearchTree<City>* myTree) {
	vector<City> results;
	string zip = " ";
	
	cin.ignore();
	cout << "Enter the zip code to search for: ";
	getline(cin, zip);
	cout << endl;

	SearchZipCode search(zip);
	myTree->inOrderTraverse(search);

	results = search.getZips();

	if (results.empty())
		cout << "\nYour input had not matches\n";
	else
		printHeader();

	for (const auto& r : results) {
		cout << r;
	}//end for

}//end searchzip


void printHeader() {
	cout << left
		<< setw(20) << "City"
		<< setw(10) << "State ID"
		<< setw(22) << "State"
		<< setw(10) << "Zip Code"
		<< setw(24) << "County"
		<< setw(15) << "Population"
		<< setw(15) << "Land Area"
		<< setw(10) << "Time Zone"
		<< endl;

	cout << string(120, '-') << endl;
}//end print header

/*ostream& operator<<(ostream& out, const City& c) {

    cout << left
        << setw(20) << c.getCity()
        << setw(10) << c.getID()
        << setw(15) << c.getState()
        << setw(10) << c.getZip()
        << setw(20) << c.getCounty()
        << setw(15) << c.getPop()
        << setw(15) << c.getArea()
        << setw(10) << c.getTimeZone()
        << endl;

    return out;

}//end <<*/
