// Author:  Michael Hayes
// Date:    2/6/16
// Purpose: To demonstrate a well-defined C++ class

#ifndef COMPLEX_NUMBER
#define COMPLEX_NUMBER

#include <iostream>
using namespace std;

class ComplexNumber {
public:
    ComplexNumber(double real = 0.0, double imag = 0.0);
    ComplexNumber(const char *);
    
    friend ComplexNumber operator+ (const ComplexNumber &a, const ComplexNumber &b);
    friend ComplexNumber operator- (const ComplexNumber &a, const ComplexNumber &b);
    friend ComplexNumber operator* (const ComplexNumber &a, const ComplexNumber &b);
    friend ComplexNumber operator/ (const ComplexNumber &a, const ComplexNumber &b);
    
    friend ostream&      operator<<(ostream &out,           const ComplexNumber &c);
    friend istream&      operator>>(istream &in ,           ComplexNumber &c);
    
private:
    double r;
    double i;
};

#endif  // COMPLEX_NUMBER
