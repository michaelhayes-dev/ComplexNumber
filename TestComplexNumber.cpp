// Author:  Michael Hayes
// Date:    2/6/16
// Purpose: To implement a class that works with Complex Numbers

#include <iostream>
#include "ComplexNumber.h"

using namespace std;

int main () {
    ComplexNumber x, y;
    
    // test assignment via string (note, you may also want to test with
    // other values in addition to the one below)
    x = "4.3+3i";
    cout << "x = " << x << endl;
    
    // test multiple inputs with a single cin object
    cout << "Enter two complex numbers:  ";
    cin >> x >> y;
    cout << "You entered x = " << x << " and y = " << y << endl;
    
    // test assignment via input operator (try several values to ensure
    // correctness of your implementation)
    cout << "Please enter a complex number to test (type <CTRL-D> to exit):  ";
    cin >> x;
    while (!cin.eof()) {
        cout << "The complex number you entered is:  " << x << endl;
        cin >> x;
    }
    
    return 0;
}