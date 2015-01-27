//
//  complex.h
//  Lab2
//  COEN 70L Tuesday 2:15-5:00pm
//  Created by Ryan Lowe on 1/14/14.
//  Created by Giovanni Briggs on 1/14/14
//

#ifndef complex_h
#define complex_h
#include <iostream>
using namespace std;


class Complex{
public:
    Complex();
    Complex(double a, double b);
    Complex operator+(const Complex & name);
    Complex operator * (const Complex &);
    void setReal(double a);
    void setImag(double b);
    double getReal() const;
    double getImag() const;
    friend ostream& operator <<(ostream & out, const Complex& value);
    friend istream & operator >> (istream & in, Complex & r);
private:
    double _real;
    double _imag;
    
};

//setting real and imaginary to zero
Complex::Complex() {
    _real=0;
    _imag=0;
}
//set real and imaginary to variables
Complex::Complex(double a, double b){
    _real= a;
    _imag= b;
}
//overload the "+" operator
Complex Complex::operator + (const Complex & name){
    double result_r = _real + name._real;
    double result_i=_imag + name._imag;
    return Complex ( result_r, result_i);
    
}
//overload the "*" operator
Complex Complex::operator * (const Complex & name) {
    double result_r = (_real * name._real) - _imag * name._imag;
    double result_i = (_imag * name._real) + _real * name._imag;
    return Complex (result_r, result_i);
    
}
//set the value of real to a
void Complex::setReal(double a) {
    _real = a;
}
//set the value of imag to b
void Complex::setImag(double b) {
    _imag = b;
}
//return the value of real
double Complex::getReal()const{
    return _real;
}
//return the value of imaginary
double Complex::getImag()const {
    return _imag;
}
//overloads the "<<" operator
ostream& operator <<(ostream & out, const Complex& value){
    out << value._real << "+" << value._imag << "*i"<<endl;
    return out;
    
}

//overloads the ">>" operator
istream & operator >> (istream & in, Complex & r){
    double x;
    in >> x;
    double y;
    in>>y;
    r._real = x;
    r._imag = y;
    return in;
}
#endif