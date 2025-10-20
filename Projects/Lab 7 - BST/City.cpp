#include "City.h"
#include <string>
#include <iomanip>
#include <sstream>
//#include "utilities.h"

/**
 * @brief Default constructor for the City class.
 *        Initializes the City object with default values.
 */
City::City() {
    city = " ";
    stateID = " ";
    state = " ";
    zipCode = " ";
    county = " ";
    population = " ";
    landArea = " ";
    timeZone = " ";
} // end default constructor

/**
 * @brief Parameterized constructor that initializes the City object based on a formatted string.
 *        The string should contain city details like city, stateID, state, zipCode, county, population, landArea, timeZone.
 * @param line A formatted string with city details.
 */
City::City(string fileLine) {
    istringstream in(fileLine);
    string temp = " ";

    getline(in, city, ',');
    getline(in, stateID, ',');
    getline(in, state, ',');
    getline(in, zipCode, ',');
    getline(in, county, ',');
    getline(in, population, ',');
    getline(in, landArea, ',');
    getline(in, timeZone, ',');


} // end second constructor

/**
 * @brief Sets the name of the city.
 * @param city The name of the city.
 */
void City::setCity(string city) {
    this->city = city;
} // end setCity

/**
 * @brief Retrieves the name of the city.
 * @return The name of the city.
 */
string City::getCity() const {
    return city;
} // end getCity

/**
 * @brief Sets the state ID (abbreviation) for the city.
 * @param id The state ID (e.g., "CA" for California).
 */
void City::setID(string id){
    this->stateID = id;
} // end setID

/**
 * @brief Retrieves the state ID (abbreviation) of the city.
 * @return The state ID.
 */
string City::getID() const {
    return stateID;
} // end getID

/**
 * @brief Sets the full state name for the city.
 * @param state The full name of the state.
 */
void City::setState(string state) {
    this->state = state;
} // end setState

/**
 * @brief Retrieves the full name of the state for the city.
 * @return The full name of the state.
 */
string City::getState() const {
    return state;
} // end getState

/**
 * @brief Sets the zip code for the city.
 * @param zip The zip code of the city.
 */
void City::setZip(string zip) {
    this->zipCode = zip;
} // end setZip

/**
 * @brief Retrieves the zip code of the city.
 * @return The zip code of the city.
 */
string City::getZip() const {
    return zipCode;
} // end getZip

/**
 * @brief Sets the county where the city is located.
 * @param county The name of the county.
 */
void City::setCounty(string county) {
    this->county = county;
} // end setCounty

/**
 * @brief Retrieves the name of the county where the city is located.
 * @return The name of the county.
 */
string City::getCounty() const {
    return county;
} // end getCounty

/**
 * @brief Sets the population of the city.
 * @param pop The population of the city.
 */
void City::setPop(string pop) {
    this->population = pop;
} // end setPop

/**
 * @brief Retrieves the population of the city.
 * @return The population of the city.
 */
string City::getPop() const {
    return population;
} // end getPop

/**
 * @brief Sets the land area of the city in square miles.
 * @param area The land area of the city.
 */
void City::setArea(string area) {
    this->landArea = area;
} // end setArea

/**
 * @brief Retrieves the land area of the city in square miles.
 * @return The land area of the city.
 */
string City::getArea() const {
    return landArea;
} // end getArea

/**
 * @brief Sets the time zone of the city.
 * @param zone The time zone of the city.
 */
void City::setTimeZone(string zone) {
    this->timeZone = zone;
} // end setTimeZone

/**
 * @brief Retrieves the time zone of the city.
 * @return The time zone of the city.
 */
string City::getTimeZone() const {
    return timeZone;
} // end getTimeZone

bool City::operator==(const City& c) const {
    return(this->city == c.city &&
            this->county == c.county && 
            this->landArea == c.landArea && 
            this->state == c.state &&
            this->population == c.population &&
            this->zipCode == c.zipCode &&
            this->stateID == c.stateID && 
            this->timeZone == c.timeZone);

}//end ==

bool City::operator!=(const City& c) const {
    return(this->city != c.city ||
        this->county != c.county ||
        this->landArea != c.landArea ||
        this->state != c.state ||
        this->population != c.population ||
        this->zipCode != c.zipCode ||
        this->stateID != c.stateID ||
        this->timeZone != c.timeZone);

}//end !=

bool City::operator<(const City& c) const {
    return (this->population < c.population);

}//end <

bool City::operator>(const City& c) const {
    return (this->population > c.population);

}//end >

void City::operator+=(int pop) {
    this->population += pop;

}//end +=

ostream& operator<<(ostream& out, const City& c) {

    cout << left
        << setw(20) << c.getCity()
        << setw(10) << c.getID()
        << setw(22) << c.getState()
        << setw(10) << c.getZip()
        << setw(24) << c.getCounty()
        << setw(15) << c.getPop()
        << setw(15) << c.getArea()
        << setw(10) << c.getTimeZone()
        << endl;

    return out;

}//end <<

istream& operator>>(istream& in, City& c) {
    string city, iD, state, county, timeZone, zip = " ", pop = " ", area = " ";
    string temp;

    cout << "Enter city name: ";
    getline(cin, city);
    cout << endl;
    c.setCity(city);
    cout << "Enter city's county: ";
    getline(cin, county);
    c.setCounty(county);
    cout << endl;
    cout << "Enter the state the city is in: ";
    getline(cin, state);
    c.setState(state);
    cout << endl;
    cout << "Enter state ID (Ex.: NY): ";
    getline(cin, iD);
    c.setID(iD);
    cout << endl;
    cout << "Enter the city's zip code: ";
    getline(cin, zip);
    c.setZip(zip);
    cout << endl;
    cout << "Enter the city's population: ";
    getline(cin, pop);
    c.setPop(pop);
    cout << endl;
    cout << "Enter city's land area: ";
    getline(cin, area);
    c.setArea(area);
    cout << endl;
    cout << "Enter city's time zone: ";
    getline(cin, timeZone);
    c.setTimeZone(timeZone);
    cout << endl;
    
    return in;

}//end >>*/
