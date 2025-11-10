//LINKEDLISTS
/**
 * @file main.cpp
 * @brief This program utilizes a templated LinkedList of items to load data from a file, and provides
 *        a menu for various operations on the list such as searching, counting frequency, and displaying items.
 *
 * @author Caua Melo
 * @date 09/2024
 */

#include <iostream>
#include "LinkedList.h"

void fillListFromFile(LinkedList<int>& numbers);
void menu(LinkedList<int>& numbers);

/**
 * @brief The main function serves as the entry point of the program. It initializes a LinkedList object to hold integers,
 *        populates it with data from a file using the function call fillsListFromFile(), and displays a menu for interacting with the list.
 *
 * @return int Returns 0 upon successful execution.
 */
int main(){
   
	LinkedList<int> numbers;

    fillListFromFile(numbers);
	menu(numbers);
    

}//end main

/**
 * @brief Presents a menu to the user for interacting with the LinkedList object.
 *        Options include searching for a value, counting frequency, and displaying items.
 *
 * @param numbers The LinkedList object on which operations will be performed.
 */
void menu(LinkedList<int>& numbers) {
    int userChoice = -1;

    do {

        cout << "Menu" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Enter a number from the menu:" << endl;
        cout << "1. Is the item there? (enter an item)" << endl;
        cout << "2. Count frequency of item." << endl;
        cout << "3. Number of the items." << endl;
        cout << "4. Display to nth item." << endl;
        cout << "5. Display from nth item to the end of the list." << endl;
        cout << "6. Display list in rows." << endl;
        cout << "7. Exit." << endl;

        cin >> userChoice;

        cout << "\n";

        switch (userChoice) {
            case 1: {
                int n = 0;
                cout << "What item are you looking for? ";
                cin >> n;
                numbers.searchVal(n);
                break;
            }
            case 2: {
                int n = 0;
                cin >> n;
                cout << "The item was found " << numbers.countFrequency(n) << " time(s)";
                break;
            }
            case 3: cout << "There are " << numbers.size() << " items in the list" << endl;
                break;
            case 4: {
                int n = 0;
                cout << "Enter a position in the list: ";
                cin >> n;
                numbers.displayFromFrontToN(n);
                cout << "This is the list from the start of the list to the " <<
                    n << " position.";
                break;
            }
            case 5: {
                int n = 0;
                cout << "Enter a position in the list: ";
                cin >> n;
                numbers.displayFromNtoEnd(n);
                cout << "This is the list from the " << n << " position to the end";
                break;
            }
            case 6: numbers.displayInRows();
                break;
            case 7: exit(0);
            default: cout << "Invalid input. Try again." << endl;
                break;
        }//end switch

            cout << "\n";
    } while (userChoice != 7);

}//end menu*/

/**
 * @brief Fills the LinkedList object with integer values read from a file named "linkedListData1.txt".
 *
 * @param list1 The LinkedList object to fill with data.
 */

void fillListFromFile(LinkedList<int>& list1) {
	ifstream infile("linkedListData1.txt");
	string line;
	int temp = 0;

	if (!infile) {
		cout << "File not found. Terminating program" << endl;
		exit(0);
	}//end if

	while (getline(infile, line)) {
		temp = stoi(line);

		list1.add(temp);
	}//end while

}//end fillListFromFile




