/*
*@file main.cpp
* 
* @brief This program takes a substring by user input and removes it from a linked Queue with items
*			extracted from a file, and it removes items from a Array Queue based on a multiple of
*			user input.
* 
* @author Caua Melo
* @since 10/2024
* 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "LinkedQueue.h"
#include "ArrayQueue.h"


using namespace std;

//prototypes
void firstToLast(ArrayQueue<string>& names);
void removeByMultiple(ArrayQueue<string>& names, int multiple);
void buildArray(ArrayQueue<string>& athletes);
void readFile(LinkedQueue<string>& athletes);
void substringSearch(LinkedQueue<string>& athletes);
//void menu(LinkedQueue<string>& athletes, ArrayQueue<string>& names);

/**
 * @brief Main function to handle queue operations for LinkedQueue and ArrayQueue.
 *
 * This function performs the following tasks:
 * - Initializes a LinkedQueue to store athlete data.
 * - Initializes an ArrayQueue to store names.
 * - Calls a menu (currently commented out) for queue operations.
 * - Handles file reading into the LinkedQueue.
 * - Searches for and removes substrings from the LinkedQueue.
 * - Builds the ArrayQueue.
 * - Prompts the user to input a number to specify the multiple for removal in the ArrayQueue.
 * - Removes elements from the ArrayQueue based on the specified multiple.
 * 
 */
int main(){
	
	LinkedQueue<string> athletes;
	ArrayQueue<string> names;
	int multiple = 0;
	
	//I could not make this menu work and I have no idea why. After a long time trying to 
	// trouble shoot it I decided to call the functions from main.
	//menu(athletes, names);	
	
	cout << "Linked Queue Handling: " << endl;
	cout << "----------------------------------" << endl;
	readFile(athletes);
	substringSearch(athletes);
	cout << endl;

	cout << "Array Queue Handling: " << endl;
	cout << "----------------------------------" << endl;
	buildArray(names);
	cout << "Input a number: ";
	cin >> multiple;
	cout << endl;
	removeByMultiple(names, multiple);
	
}//end main

/*void menu(LinkedQueue<string>& athletes, ArrayQueue<string>& names) {
	int userChoice = 0;
	int multiple = 0;

	do {
		cout << "Choose an option: " << endl;
		cout << "1. Substring search."<< endl;
		cout << "2. Multiple removal." << endl;
		cout << "3. Exit" << endl;

		cin >> userChoice;
		cin.ignore();
		cout << endl;

		switch (userChoice){
		case 1: {
			readFile(athletes);
			substringSearch(athletes);
			break;
		}
		case 2: {
			buildArray(names);
			cout << "Input a number ";
			cin >> multiple;
			cout << endl;

			removeByMultiple(names, multiple);
			break;
		}
		case 3: exit(0);
			break;
		default: cout << "Invalid input" << endl;
			break;
		}

	} while (userChoice != 3);

}//end menu*/

/**
 * @brief Searches for and removes a substring from a LinkedQueue of athlete names.
 *
 * This function prompts the user to input a string or substring, then searches for it in the
 * LinkedQueue of athlete names. If a match is found, the corresponding item is removed from the queue.
 * If no match is found, the user is notified. The function displays the updated queue after any removal.
 * The search and removal process is case-insensitive.
 *
 * The user is prompted whether they wish to remove another substring, and the process repeats
 * until the user enters 'N' or 'n'.
 *
 * @param athletes A reference to a LinkedQueue of strings containing athlete names.
 */
void substringSearch(LinkedQueue<string>& athletes) {
	char choice = ' ';
	
	do{
		LinkedQueue<string> tempQueue;
		LinkedQueue<string> display;
		bool found = false;
		string user = " ";
		string temp = " ";

		cout << "What string or substring are you looking to remove from the list? " << endl;
		getline(cin, user);
		cout << endl;

		transform(user.begin(), user.end(), user.begin(), [](unsigned char c) { return tolower(c); });

		while (!athletes.isEmpty()) {
			temp = athletes.peek();

			transform(temp.begin(), temp.end(), temp.begin(), [](unsigned char c) { return tolower(c); });

			if (temp.find(user) != string::npos) {
				found = true;
			}
			else {
				tempQueue.enqueue(temp);// tempqueue has the filtered version
			}
			athletes.dequeue();//athletes is empty
		}//end while

		if (found == false){
			cout << "\t" << "None of the items in the file match your substring." << endl;
		}
		else {
			cout << "List with item(s) removed: " << endl;
		}//end if else

		while (!tempQueue.isEmpty()) {
			temp = tempQueue.peek();
			cout << "\t-" << tempQueue.peek() << endl << "\n";
			tempQueue.dequeue();
			athletes.enqueue(temp);
		}//end while

		//athletes = tempQueue;

		cout << "Do you want to remove another item? (Y/N)" << endl;
		cin >> choice;
		cin.ignore();

	} while (tolower(choice) == 'y');


}//end substring 

/**
 * Reads data from the file "olympicAthletes-queueLab.txt" and enqueues each line into the given LinkedQueue.
 *
 * @param athletes A reference to a LinkedQueue of strings that will store the names of Olympic athletes.
 */
void readFile(LinkedQueue<string>& athletes) {
	ifstream infile("olympicAthletes-queueLab.txt");
	string line = " ";

	if (!infile) {
		cout << "File not found." << endl;
		exit(0);

	}//end if

	while (getline(infile, line)) {
		athletes.enqueue(line);

	}//end if

	infile.close();

}//end read

/**
 * @brief Reads athlete names from a file and enqueues them into an ArrayQueue.
 *
 * This function opens a file named "olympicAthletes-queueLab.txt" and reads each line, enqueuing
 * the lines into the provided ArrayQueue. If the file is not found, an error message is displayed,
 * and the program terminates. The file is closed after all lines have been read.
 *
 * @param athletes A reference to an ArrayQueue of strings where the athlete names will be stored.
 */
void buildArray(ArrayQueue<string>& athletes) {
	ifstream infile("olympicAthletes-queueLab.txt");
	string line = " ";

	if (!infile) {
		cout << "File not found." << endl;
		exit(0);

	}//end if

	while (getline(infile, line)) {
		athletes.enqueue(line);

	}//end if

	infile.close();

}//end buildArray

/**
 * @brief Removes elements from an ArrayQueue based on a user-specified multiple, repeating until only one element remains.
 *
 * This function iteratively removes elements from the ArrayQueue based on the provided multiple. It calculates the
 * index of the element to be removed, then rotates the queue to bring the target element to the front before removing it.
 * The process repeats until only one element remains in the queue. After each removal, the updated queue is displayed.
 *
 * @param names A reference to an ArrayQueue of strings containing the names.
 * @param multiple An integer specifying the multiple for selecting elements to remove.
 */
void removeByMultiple(ArrayQueue<string>& names, int multiple) {
	ArrayQueue<string> tempQ = names;
	int currentIndex = 0;
	int removeIndex = -1;
	int size = 0;
	string moving = " ";

	while (!tempQ.isEmpty()) {
		size++;
		tempQ.dequeue();
	}//end while

	while (size > 1) {

		removeIndex = (currentIndex + multiple - 1) % size;

		for (int i = 0; i < removeIndex; i++) {
			firstToLast(names);
		}

		cout << "Removing: " << names.peek() << endl;
		names.dequeue();
		size--;

		for(int i = removeIndex; i < size; i++){
			firstToLast(names);
		}//end for

		currentIndex = removeIndex % size;

		cout << "New list: " << endl;
		tempQ = names;

		while (!tempQ.isEmpty()) {
			cout << "\t-" << tempQ.peek() << endl;
			tempQ.dequeue();
		}
		cout << endl;
		
	}//end while

	cout << "Last item: " << names.peek() << endl;

}//end removebyMult

/**
 * @brief Moves the front element of an ArrayQueue to the back of the queue.
 *
 * This function takes the front element of the provided ArrayQueue, removes it from the front,
 * and enqueues it at the back. If the queue is empty, an error message is displayed.
 *
 * @param names A reference to an ArrayQueue of strings whose front element will be moved to the back.
 */
void firstToLast(ArrayQueue<string>& names) {
	string front = names.peek();

	if (names.isEmpty()) {
		cout << "Empty Queue" << endl;
	}

	names.dequeue();
	names.enqueue(front);

	
	/*checking state of the queue
	LinkedQueue<string> test;
	test = athletes;
	while (!test.isEmpty()) {
		cout << test.peek() << endl;
		test.dequeue();
	}*/
}//end firstToLast



//BCK UP do-while
/*void substringSearch(LinkedQueue<string>& athletes) {
	char choice = ' ';

	do{
		LinkedQueue<string> tempQueue;
		LinkedQueue<string> display;
		bool found = false;
		string user = " ";
		string temp = " ";

		cout << "What string or substring are you looking to remove from the list? " << endl;
		getline(cin, user);
		cout << endl;

		transform(user.begin(), user.end(), user.begin(), [](unsigned char c) { return tolower(c); });

		//debug: user
		cout << "User input: " << user << endl;

		while (!athletes.isEmpty()) {
			temp = athletes.peek();

			//debug temp
			//cout << "Checking: " << temp << endl;

			transform(temp.begin(), temp.end(), temp.begin(), [](unsigned char c) { return tolower(c); });

			if (temp.find(user) != string::npos) {
				found = true;
			}
			else {
				tempQueue.enqueue(temp);// tempqueue has the filtered version
			}
			athletes.dequeue();//athletes is empty
		}//end while
		//athletes = tempQueue;//two w the same info
		//display = tempQueue;

		if (found == false){
			cout << "\t" << "None of the items in the file match your substring." << endl;
		}
		else {
			cout << "List with item(s) removed: " << endl;
		}//end if else

		display = tempQueue;

		//LinkedQueue<string> display = athletes;
		while (!display.isEmpty()) {
			cout << "\t" << display.peek() << endl << "\n";
			display.dequeue();
		}//end while

		athletes = tempQueue;

		cout << "Do you want to remove another item? (Y/N)" << endl;
		cin >> choice;
		cin.ignore();

	} while (tolower(choice) == 'y');


}//end substring */

//Back up for (remove Mult)
/*for (int i = 0; i < removeIndex; i++) {
			//string moving;
			//moving = names.peek();
			names.enqueue(names.peek());//enqueues the non mult item to the back of the queue
			names.dequeue();
		}//end for*/

