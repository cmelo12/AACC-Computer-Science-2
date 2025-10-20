#pragma once
#include <string>
#include <iostream>

using namespace std;

/*int printWithCommas(int x){
    //int x = 1122334455;
    string str = to_string(x);


    int n2 = str.length() - 3;
    int end2 = (x >= 0) ? 0 : 1; // Support for negative numbers
    while (n2 > end2) {
        str.insert(n2, ",");
        n2 -= 3;
    }

    //cout << str << endl;
    return x;
}//end*/

//adding commas to numbers
inline string intWithCommas(int n) {
    string result = to_string(n); // Convert integer 'n' to a string and store it in 'result'

    // Loop to insert commas for thousands separators in the string
    for (int i = result.size() - 3; i > 0; i -= 3) {
        result.insert(i, ","); // Insert a comma after every three digits from the end
    }

    return result; // Return the formatted string
}//end intwithcommas

inline void printWithCommas(int x) {
   // int x = 1122334455;
    string str = to_string(x);


    int n2 = str.length() - 3;
    int end2 = (x >= 0) ? 0 : 1; // Support for negative numbers
    while (n2 > end2) {
        str.insert(n2, ",");
        n2 -= 3;
    }

    cout << str << endl;

}

//error trapping for integer

int getInteger(string prompt) {

    int x = 0;

    //cout << "enter x: ";
    cout << "Enter " << prompt;
    cin >> x;


    while (cin.fail()) {
        cout << "that's not an integer!" << endl;
        cin.clear();  //clear the error flags on cin
        cin.ignore(255, '\n'); //clear the stream
        //cout << "enter x: ";
        cout << "Enter " << prompt;
        cin >> x;
    }//end while

    return x;

}//end getInteger()


//convert to lowercase
string toLower(string& str) {
    string lower = "";
    char lowerCh = ' ';

    for (char ch : str) {
        //lowerCh = tolower(ch);
        //lower += lowerCh;
        ch = tolower(ch);
        lower += ch;
    }

    return lower;
}//end toLower()

//contains with case sensitivity
bool contains_caseInsensitive(string& bigString, string& substring) {
    string lowercaseBig = toLower(bigString);
    string lowersubstring = toLower(substring);
    bool found = true;

    if (lowercaseBig.find(lowersubstring) >= 0) {  //.find returns position of the string found
        found = true;
    }
    else
        found = false;

    return found;

}//end contain_caseInsensitive()