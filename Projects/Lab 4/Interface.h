
/**
 * @file Interface.h
 * @brief This program creates an interface of methods to manipulate objects.
 *
 * @author Caua Melo
 * @date 09/2024
 */
#pragma once

using namespace std;

/**
 * @brief An interface defining the operations of a bag data structure.
 *
 * This interface outlines the essential operations for a bag, which is a collection
 * that allows duplicate items and provides methods for adding, removing, and querying
 * items within the bag. It is a template class to support various data types.
 *
 * @tparam T The type of items stored in the bag.
 */
template<typename T>
class BagInterface {
public:
/**
  * @brief Gets the number of items in the bag.
  *
  * @return int The total number of items in the bag.
  */
	virtual int getSize() const = 0;

/**
 * @brief Checks if the bag is empty.
 *
 * @return bool True if the bag is empty, false otherwise.
 */
	virtual bool isEmpty() const = 0;

/**
 * @brief Adds a new item to the bag.
 *
 * @param newItem The item to be added to the bag.
 * @return bool True if the item was successfully added, false otherwise.
 */
	virtual bool add(const T& newItem) = 0;  

/**
 * @brief Removes an item from the bag.
 *
 * @param anItem The item to be removed from the bag.
 * @return bool True if the item was successfully removed, false otherwise.
 */
	virtual bool remove(const T& anItem) = 0;

/**
 * @brief Clears all items from the bag.
 *
 * This method removes all items from the bag, leaving it empty.
 */
	virtual void clear() = 0;

/**
 * @brief Counts the occurrences of a specified item in the bag.
 *
 * @param searchItem The item whose occurrences are to be counted.
 * @return int The number of times the item occurs in the bag.
 */
	virtual int countItems(const T& searchItem) const = 0;

/**
 * @brief Checks if the bag contains a specified item.
 *
 * @param searchItem The item to be searched for in the bag.
 * @return bool True if the item is found, false otherwise.
 */
	virtual bool contains(const T& searchItem) const = 0;
};

