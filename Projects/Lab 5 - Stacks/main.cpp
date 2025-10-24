/**
 * @file main.cpp
 * @brief The code uses a menu to handle both a user input implementation and a file read implementation.
 *          This program utilizes a templated ArrayStack of items set up to a maximum of 10 items.
 *          The program takes user input and uses it to separate vowels, numbers and mathematical symbols.
 *          Additionally, it reads an outside file to determine its highest and lowest values.
 * @author Caua Melo
 * @date 10/2024
 */
#include <iostream>
#include <unordered_set>
#include <string>
#include <fstream>
#include <iomanip>
#include "ArrayStack.h"
#include "LinkedStack.h"

using namespace std;

//function prototypes for user input program
bool isVowel(char character);
int operations(char oper, int num1, int num2);
void fillStacks(string user, ArrayStack<char>& vowels, ArrayStack<int>& numbers,
    ArrayStack<char>& operators, unordered_set<char>& trackVowels, 
    unordered_set<int>& trackNumbers);
void displayVowels(ArrayStack<char> vowels);
void displayNumbers(ArrayStack<int> numbers);
void displaySymbols(ArrayStack<char> operators);
void calculations(ArrayStack<int> numbers, ArrayStack<char> operators);
//function prototype for file based program
void readFile(LinkedStack<string>& datesLow, LinkedStack<string>& datesHigh,
                double& lowest, double& highest);
void outputLinkedList(LinkedStack<string>& datesLow, LinkedStack<string>& datesHigh,
    double lowest, double highest);
//menu prototype
void menu(string user, ArrayStack<char>& vowels, ArrayStack<int>& numbers,
    ArrayStack<char>& operators, unordered_set<char>& trackVowels,
    unordered_set<int>& trackNumbers, LinkedStack<string>& datesLow, 
    LinkedStack<string>& datesHigh);

/**
 * @brief The main function of the program. This function initializes Array Stacks and Linked Stacks
 *          and passes these to the menu method, that will then handle the variables according to two
 *          different prompts. 
 *        
 */
int main(){
    //variables user input program
    string user = " ";
    ArrayStack<char> vowels;
    ArrayStack<int> numbers;
    ArrayStack<char> operators;
    unordered_set<char> trackVowels;  
    unordered_set<int> trackNumbers;

    //variables for file program
    LinkedStack<string> datesLow;
    LinkedStack<string> datesHigh;

    menu(user, vowels, numbers, operators, trackVowels, trackNumbers, 
            datesLow, datesHigh);
 
}//end main

/**
 * @brief Displays a menu for user interaction and processes the selected options.
 *
 * This function presents a menu to the user that allows them to either
 * access the ArrayStack code or the LinkedStacks code, or exit the program.
 * Based on the user's selection, it either prompts for a sentence to fill
 * the stacks with vowels, numbers, and operators, or processes a file to
 * read or output information extracted from a file regarding highest and lowest
 * values of Bitcoin and when they happened.
 *
 * @param user A string reference to store user input.
 * @param vowels A reference to an ArrayStack of characters that stores vowels.
 * @param numbers A reference to an ArrayStack of integers that stores numbers.
 * @param operators A reference to an ArrayStack of characters that stores arithmetic operators.
 * @param trackVowels An unordered_set that tracks non-repeating vowels entered by the user.
 * @param trackNumbers An unordered_set that tracks non-repeating numbers entered by the user.
 * @param datesLow A reference to a LinkedStack that stores dates when Bitcoin values were low (from file).
 * @param datesHigh A reference to a LinkedStack that stores dates when Bitcoin values were high (from file).
 */
void menu(string user, ArrayStack<char>& vowels, ArrayStack<int>& numbers,
    ArrayStack<char>& operators, unordered_set<char>& trackVowels,
    unordered_set<int>& trackNumbers, LinkedStack<string>& datesLow,
    LinkedStack<string>& datesHigh) {

    int userMenu = 0;

    do {

        cout << "Menu" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Enter a number from the menu:" << endl;
        cout << "1. Access user input based program." << endl;
        cout << "2. Access file information." << endl;
        cout << "3. Exit." << endl;

        cin >> userMenu;
        cin.ignore();
        cout << endl;

        switch (userMenu) {
        case 1: {
            cout << "User input based program: " << endl;
            cout << "-------------------------------------------" << endl;
            cout << "Type a sentence that includes vowels, numbers (0-9) and add "
                << "operation symbols to the end: " << endl;

            getline(cin, user);
            fillStacks(user, vowels, numbers, operators, trackVowels, trackNumbers);
            displayVowels(vowels);
            displayNumbers(numbers);
            displaySymbols(operators);
            calculations(numbers, operators);
            break;
        }//case 1
        case 2: {
            double highest = -1.0;
            double lowest = 999999.9;
            cout << "File based program: " << endl;
            cout << "-------------------------------------------" << endl;
            readFile(datesLow, datesHigh, lowest, highest);
            outputLinkedList(datesLow, datesHigh, lowest, highest);
            cout << endl;
            break;
        }//case 2
        case 3: exit(0);
        default: cout << "Invalid input. Try again." << endl;
            break;

        }//end switch

        cout << "\n";
    } while (userMenu != 3);

}//end menu

/**
 * @brief Outputs the highest and lowest Bitcoin values along with their corresponding dates.
 *
 * This function displays the highest and lowest values of Bitcoin, formatted to two decimal
 * places, along with the dates associated with these values. It retrieves the dates from two
 * linked stacks: one for the highest values and one for the lowest values. After displaying
 * each date, it removes them from the stack.
 *
 * @param datesLow A reference to a LinkedStack that stores dates associated with the lowest Bitcoin values.
 * @param datesHigh A reference to a LinkedStack that stores dates associated with the highest Bitcoin values.
 * @param lowest A double representing the lowest value of Bitcoin.
 * @param highest A double representing the highest value of Bitcoin.
 */
void outputLinkedList(LinkedStack<string>& datesLow, LinkedStack<string>& datesHigh,
                        double lowest, double highest) {
    cout << fixed << setprecision(2);

    cout << "Highest Value of Bitcoin: $" << highest << endl;
    cout << "Date of highest value: ";
    while (!datesHigh.isEmpty()) {
        cout << datesHigh.peek() << endl;
        datesHigh.pop();
    }//end while

    cout << "Lowest value of Bitcoin: $" << lowest << endl;
    cout << "Date of lowest value: ";
    while (!datesLow.isEmpty()) {
        cout << datesLow.peek() << endl;
        datesLow.pop();
    }//end while

}//end outputList

/**
 * @brief Reads Bitcoin values and their corresponding dates from a file and assigns the highest and
 *         lowest value (and dates of when they happen) to distinct LinkedStacks.
 *
 * This function opens a text file containing Bitcoin values and dates, checks for
 * successful file access, and initializes the highest and lowest Bitcoin values. It reads
 * the date and value pairs from the file, updating the highest and lowest values and their
 * corresponding dates stored in two linked stacks. If the highest or lowest value is found,
 * it replaces the previous date in the stack.
 *
 * @param datesLow A reference to a LinkedStack that stores dates associated with the lowest Bitcoin values.
 * @param datesHigh A reference to a LinkedStack that stores dates associated with the highest Bitcoin values.
 * @param lowest A reference to a double that will hold the lowest Bitcoin value found.
 * @param highest A reference to a double that will hold the highest Bitcoin value found.
 */
void readFile(LinkedStack<string>& datesLow, LinkedStack<string>& datesHigh, 
                double& lowest, double& highest) {
    ifstream infile("bitCoinValue-stackLab.txt");
    string value = " ";
    string date = " ";
    double temp = 0.0;

    if (!infile) {
        cout << "File not found." << endl;
        exit(0);
    }

    if (getline(infile, date) && getline(infile, value)) {
        highest = stod(value);
        lowest = stod(value);
        datesHigh.push(date);
        datesLow.push(date);
    }//end if

    while (getline(infile, date) && getline(infile, value)) {
        temp = stod(value);

        if (temp > highest) {
            highest = temp;
            datesHigh.pop();
            datesHigh.push(date);
        }//end if
        else if (temp == highest)
            datesHigh.push(date);

        if (temp < lowest) {
            lowest = temp;
            datesLow.pop();
            datesLow.push(date);
        }//end if
        else if (temp == lowest)
            datesLow.push(date);

    }//end while

    infile.close();

}//end read file


/**
 * @brief Fills the vowel, number, and operator stacks based on the input string provided by the user.
 *
 * @details
 * - Iterates through each character in the `user` string.
 * - Vowels are pushed into the `vowels` stack if they are not repeated (Not in 'trackVowels' stack).
 * - Numbers are pushed into the `numbers` stack if they are not repeated (Not in 'trackNumbers' stack).
 * - Arithmetic operators are pushed into the `operators` stack.
 *
 * @param user The input string provided by the user containing vowels, digits, and arithmetic symbols.
 * @param vowels A reference to an `ArrayStack<char>` where unique vowels from the input string will be stored.
 * @param numbers A reference to an `ArrayStack<int>` where unique digits from the input string will be stored.
 * @param operators A reference to an `ArrayStack<char>` where arithmetic operators from the input string will be stored.
 * @param trackVowels A reference to an `unordered_set<char>` that tracks the unique vowels encountered in the input.
 * @param trackNumbers A reference to an `unordered_set<int>` that tracks the unique numbers encountered in the input.
 * 
 * @return void
 */
void fillStacks(string user, ArrayStack<char>& vowels, ArrayStack<int>& numbers,
    ArrayStack<char>& operators, unordered_set<char>& trackVowels,
    unordered_set<int>& trackNumbers) {

    int numConverted = 0;

    for (char c : user) {
        if ((isVowel(c)) && (trackVowels.find(c) == trackVowels.end())) {
            vowels.push(c);
            trackVowels.insert(c);
        }
        else if (isdigit(c)) {
            numConverted = int(c - '0');
            if (trackNumbers.find(numConverted) == trackNumbers.end()) {
                numbers.push(numConverted);
                trackNumbers.insert(numConverted);
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
            operators.push(c);
    }//end for

}//end fillstacks


/**
 * @brief Performs arithmetic calculations using numbers and operators from the provided stacks.
 *
 * @details
 * - Retrieves the top number from the `numbers` stack as the initial result.
 * - In a loop, pops operators and numbers from their respective stacks and performs arithmetic operations.
 * - The `operations` helper function is used to apply the operator to the current result and the next number.
 * - Continues processing until either the `operators` or `numbers` stack is empty.
 * - Outputs the final result after all calculations are complete.
 *
 * @param numbers An `ArrayStack<int>` containing the numbers used for calculations. The stack is modified during execution.
 * @param operators An `ArrayStack<char>` containing the arithmetic operators. The stack is modified during execution.
 *
 * @return void
 */
void calculations(ArrayStack<int> numbers, ArrayStack<char> operators) {
    int result = -99;
    int secondNumber = -99;
    char symbol = ' ';
    
    result = numbers.peek();
    numbers.pop();
    
    while (!operators.isEmpty() && !numbers.isEmpty()) {
        symbol = operators.peek();
        operators.pop();
        secondNumber = numbers.peek();
        numbers.pop();

        result = operations(symbol, result, secondNumber);
    }//end while

    cout << "\nResult: " << result << endl;
    

}//end calc

/**
 * @brief Displays the contents of the `numbers` stack by outputting each number in the stack.
 *
 * @details
 * - Iterates through the `numbers` stack.
 * - For each iteration, it prints the top number using `peek()`, and then removes it from the stack using `pop()`.
 * - Continues until the `numbers` stack is empty.
 * - Outputs the numbers in the order they are popped from the stack.
 *
 * @param numbers An `ArrayStack<int>` containing the numbers to be displayed. The stack is modified during execution.
 *
 * @return void 
 */
void displayNumbers(ArrayStack<int> numbers) {
    cout << "Numbers stack: " << endl;
    while (!numbers.isEmpty()) {
        cout << numbers.peek() << endl;
        numbers.pop();
    }//end while

    cout << "\n";

}//end numbers

/**
 * @brief Displays the contents of the `operators` stack by outputting each operator in the stack.
 *
 * @details
 * - Iterates through the `operators` stack.
 * - For each iteration, it prints the top operator using `peek()`, and then removes it from the stack using `pop()`.
 * - Continues until the `operators` stack is empty.
 * - Outputs the operators in the order they are popped from the stack.
 *
 * @param operators An `ArrayStack<char>` containing the arithmetic operators to be displayed. The stack is modified during execution.
 *
 * @return void 
 */
void displaySymbols(ArrayStack<char> operators) {
    cout << "Symbol stack: " << endl;
    while (!operators.isEmpty()) {
        cout << operators.peek() << endl;
        operators.pop();
    }//end while

    cout << "\n";

}//end display symbol

/**
 * @brief Displays the contents of the `vowels` stack by outputting each vowel.
 *
 * @details
 * - Iterates through the `vowels` stack.
 * - For each iteration, it prints the top vowel using `peek()`, and then removes it from the stack using `pop()`.
 * - Continues until the `vowels` stack is empty.
 * - Outputs the vowels in the order they are popped from the stack.
 *
 * @param vowels An `ArrayStack<char>` containing the vowels to be displayed. The stack is modified during execution.
 *
 * @return void 
 */
void displayVowels(ArrayStack<char> vowels) {
    cout << "Vowel Stack: " << endl;
    while (!vowels.isEmpty()) {
        cout << vowels.peek() << endl;
        vowels.pop();
    }//end while

    cout << "\n";

}//end display vowels

/**
 * @brief Performs an arithmetic operation between two numbers based on the provided operator stack.
 *
 * @details
 * - Takes an arithmetic operator and two integers as input.
 * - Based on the operator, performs the corresponding arithmetic operation
 *      through a switch:
 *   - `+`: Adds `num1` and `num2`.
 *   - `-`: Subtracts `num2` from `num1`.
 *   - `*`: Multiplies `num1` and `num2`.
 *   - `/`: Divides `num1` by `num2`, checking for division by zero. If `num2` is zero or negative, an error message is displayed, and the function returns `-99`.
 * - If the operator is invalid or unrecognized, prints an error message and returns `-99`.
 *
 * @param oper A `char` representing the arithmetic operator.
 * @param num1 An `int` representing the first operand.
 * @param num2 An `int` representing the second operand.
 *
 * @return int The result of the arithmetic operation, or `-99` if an invalid operator is provided or division by zero occurs.
 */
int operations(char oper, int num1, int num2) {
    switch (oper) {
    case '+': 
        return num1 + num2;
        break;
    case'-': 
        return num1 - num2;
        break;
    case'*': 
        return num1 * num2;
        break;
    case'/': {
        if (num2 <= 0) {
            cout << "Can't divide. Division by zero" << endl;
            return -99;
        }
        else
            return num1 / num2;
        }
        break;
    default: {
        cout << "Invalid or no operator" << endl;
        return -99;
    }
        break;
    }//end while

}//end operations

/**
 * @brief Determines whether a given character is a vowel.
 *
 * @details
 * - Converts the input character to lowercase.
 * - Checks if the character is one of the five vowels: 'a', 'e', 'i', 'o', or 'u'.
 * - Returns `true` if the character is a vowel, otherwise returns `false`.
 *
 * @param character A `char` representing the character to be checked.
 *
 * @return bool Returns `true` if the character is a vowel, otherwise returns `false`.
 */
bool isVowel(char character) {
    bool vowel = false;

    if (character == 'a' || character == 'e' || character == 'i'
        || character == 'o' || character == 'u')
        vowel = true;
 
    return vowel;
}//end vowel

//GOOD backup menu code
/*void menu(string user, ArrayStack<char>& vowels, ArrayStack<int>& numbers,
    ArrayStack<char>& operators, unordered_set<char>& trackVowels,
    unordered_set<int>& trackNumbers) {

    int userMenu = 0;

    do {

        cout << "Menu" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Enter a number from the menu:" << endl;
        cout << "1. Access ArrayStack code." << endl;
        cout << "2. Access LinkedStacks code." << endl;
        cout << "3. Exit." << endl;

        getline(cin, userMenu);
        //cin >> userMenu;
        //c/in.ignore();
        cout << endl;

        switch (userMenu) {
        case 1: {
            cout << "Type a sentence that includes vowels, numbers (0-9) and add "
                << "operation symbols to the end: " << endl;
            getline(cin, user);
            fillStacks(user, vowels, numbers, operators, trackVowels, trackNumbers);
            displayVowels(vowels);
            displayNumbers(numbers);
            displaySymbols(operators);
            calculations(numbers, operators);
            break;
        }
        case 2: {
            cout << "try" << endl;
            break;
        }
        case 3: exit(0);
        default: cout << "Invalid input. Try again." << endl;
            break;

        }//end switch

        cout << "\n";
    } while (userMenu != 3);

}//end menu*/

//program without the menu
/*cout << "File based program: " << endl;
    cout << "-----------------------------------------------" << endl;
    readFile(datesLow, datesHigh, lowest, highest);
    outputLinkedList(datesLow, datesHigh, lowest, highest);
    cout << endl;

    cout << "User input based program: " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Type a sentence that includes vowels, numbers (0-9) and add "
        << "operation symbols to the end: " << endl;

    getline(cin, user);
    fillStacks(user, vowels, numbers, operators, trackVowels, trackNumbers);
    displayVowels(vowels);
    displayNumbers(numbers);
    displaySymbols(operators);
    calculations(numbers, operators);
    */