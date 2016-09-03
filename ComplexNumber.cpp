// Author:  Michael Hayes
// Date:    2/6/16
// Purpose: To demonstrate a well-defined class

#include "ComplexNumber.h"

//Parse function
//Use pointers to be able to directly change the values you pass in

void parseCN(double *r, double *i, const char* a){
    
    double real = 1, imag = 98765.123;
    string s = a;
    sscanf(a, "%lf%lf", &real, &imag);
    
    //Special Conditions
    
    //If the user only inputs one value then the imag var will not change and the program will enter the if loop
    if(imag == 98765.123){
        
        //if it is an imaginary number (there is an 'i' in the input) then swap the variables to the imag part will display first like it should
        if (s.find('i') != string::npos) {
            
            //if the character before the i is a minus then set it as a -1
            if(s[(s.find('i')-1)] == '-'){
                
                imag = -1;
                
                //see if the character before the minus sign is 0. If so, set the real part to 0 so it won't show
                if (s[(s.find('i')-2)] < '1'){
                    real = 0;
                }
            }
            
            else{
            imag = real;
            real = 0;
            }
        }
        //if it is a regular number then set the imaginary part to zero so it will display properly
        else{
            imag = 0;
        }
    }
    
    //finally set the values
    *r = real;
    *i = imag;

}

ComplexNumber::ComplexNumber(double rr, double ii) : r(rr), i(ii) {
}

//**********************
ComplexNumber::ComplexNumber(const char* a){
    
    double real, imag;
    double *realPt = &real, *imagPt = &imag;
    
    parseCN(realPt, imagPt, a);
    
    //finally set the values
    ComplexNumber::i = *imagPt;
    ComplexNumber::r = *realPt;
    
}

ComplexNumber operator+ (const ComplexNumber &a, const ComplexNumber &b) {
    ComplexNumber result;
    
    result.r = a.r + b.r;
    result.i = a.i + b.i;
    
    return result;
}

ComplexNumber operator- (const ComplexNumber &a, const ComplexNumber &b) {
    ComplexNumber result;
    
    result.r = a.r - b.r;
    result.i = a.i - b.i;
    
    return result;
}

ComplexNumber operator* (const ComplexNumber &a, const ComplexNumber &b) {
    ComplexNumber result;
    
    result.r = (a.r * b.r - a.i * b.i);
    result.i = (a.r * b.i + a.i * b.r);
    
    return result;
}

ComplexNumber operator/ (const ComplexNumber &a, const ComplexNumber &b) {
    ComplexNumber result;
    
    result.r = (a.r * b.r + a.i * b.i) / (b.r * b.r + b.i * b.i);
    result.i = (a.i * b.r - a.r * b.i) / (b.r * b.r + b.i * b.i);
    
    return result;
}

// This operator is a "pretty-print" replacement for the output operator in ComplexNumber.cpp

ostream& operator<< (ostream &out, const ComplexNumber &b) {
    
    bool rPrinted = false;
    
    if (b.r != 0 || (b.r == 0 && b.i == 0)) {
        out << b.r;
        rPrinted = true;
    }
    
    if (b.i > 0) {
        if (rPrinted) {
            out << "+";
        }
        if (b.i != 1) {
            out << b.i;
        }
        out << "i";
    } else if (b.i < 0) {
        if (b.i == -1) {
            out << "-";
        } else {
            out << b.i;
        }
        out << "i";
    }
    
    return out;
}


//********************
istream& operator>>(istream &in, ComplexNumber &c){
    
    double real, imag;
    double *realPt = &real, *imagPt = &imag;
    const char* a;
    string s;
    
    in >> s;
    a = s.c_str();
    
    parseCN(realPt, imagPt, a);
    
    c.i = imag;
    c.r = real;
    
    return in;
}




