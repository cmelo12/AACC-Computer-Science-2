#pragma once
#include <iostream>
#include <string>

using namespace std;

//city,state_id,state_name,county_fips (zip code),county_name,population,land area (Sq miles),time zone

/**
 * @brief The City class represents a city with various attributes including
 *        city name, state, zip code, county, population, land area, and time zone.
 */
class City
{
private:
	/** @brief The name of the city. */
	string city;

	/** @brief The state abbreviation (State ID). */
	string stateID;

	/** @brief The full state name. */
	string state;

	/** @brief The zip code of the city. */
	//int zipCode;
    string zipCode;
	/** @brief The name of the county the city is located in. */
	string county;

	/** @brief The population of the city. */
	//int population;
    string population;

	/** @brief The land area of the city in square miles. */
	//double landArea;
    string landArea;

	/** @brief The time zone of the city. */
	string timeZone;

public:
    /**
     * @brief Default constructor for the City class.
     *        Initializes members to default values.
     */
    City();

    /**
     * @brief Parameterized constructor that initializes a City object based on a formatted input line.
     * @param line The string containing city details from the file,
     * that will be tokenized and formatted as city,stateID,state,zipCode,county,population,landArea,timeZone.
     */
    City(string fileLine);

    /**
     * @brief Sets the name of the city.
     * @param city The name of the city.
     */
    void setCity(string city);

    /**
     * @brief Retrieves the name of the city.
     * @return The name of the city.
     */
    string getCity() const;

    /**
     * @brief Sets the state ID (abbreviation).
     * @param id The state ID (e.g., "CA" for California).
     */
    void setID(string id);

    /**
     * @brief Retrieves the state ID (abbreviation).
     * @return The state ID.
     */
    string getID() const;

    /**
     * @brief Sets the full name of the state.
     * @param state The name of the state.
     */
    void setState(string state);

    /**
     * @brief Retrieves the full name of the state.
     * @return The name of the state.
     */
    string getState() const;

    /**
     * @brief Sets the zip code for the city.
     * @param zip The zip code of the city.
     */
    void setZip(string zip);

    /**
     * @brief Retrieves the zip code of the city.
     * @return The zip code of the city.
     */
    string getZip() const;

    /**
     * @brief Sets the name of the county where the city is located.
     * @param county The name of the county.
     */
    void setCounty(string county);

    /**
     * @brief Retrieves the name of the county where the city is located.
     * @return The name of the county.
     */
    string getCounty() const;

    /**
     * @brief Sets the population of the city.
     * @param pop The population of the city.
     */
    void setPop(string pop);

    /**
     * @brief Retrieves the population of the city.
     * @return The population of the city.
     */
    string getPop() const;

    /**
     * @brief Sets the land area of the city in square miles.
     * @param area The land area of the city.
     */
    void setArea(string area);

    /**
     * @brief Retrieves the land area of the city in square miles.
     * @return The land area of the city.
     */
    string getArea() const;

    /**
     * @brief Sets the time zone of the city.
     * @param zone The time zone of the city.
     */
    void setTimeZone(string zone);

    /**
     * @brief Retrieves the time zone of the city.
     * @return The time zone of the city.
     */
    string getTimeZone() const;

    bool operator==(const City& c) const;
    bool operator!=(const City& c) const;
    bool operator<(const City& c) const;
    bool operator>(const City& c) const;
    void operator+=(int pop);

    //friends
    friend ostream& operator<<(ostream& out, const City& c);
    friend istream& operator>>(istream& in, City& c);

};

