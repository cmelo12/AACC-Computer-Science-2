#include <iostream>
#include <string>

using namespace std;

int main() {
   
   int x = 1122334455;
   string str = to_string(x);
    
    
   int n2 = str.length() - 3;
   int end2 = (x >= 0) ? 0 : 1; // Support for negative numbers
   while (n2 > end2) {
      str.insert(n2, ",");
      n2 -= 3;
   }
   
   cout << str << endl;
   

   
   
   }   