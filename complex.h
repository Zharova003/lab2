#ifndef LAB2_1_COMPLEX_H
#define LAB2_1_COMPLEX_H

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

class complex {
private:
    int real, imagine;
public:
    complex() { real = 0; imagine = 0; }
    complex(int r, int i) { real = r; imagine = i; }
    complex(const complex& ri) { real = ri.real; imagine = ri.imagine; }
    complex& operator = (complex);
    complex operator + (complex);
    complex operator - (complex);
    complex operator * (complex&);
    complex operator / (complex&);
    complex& operator += (complex);
    complex& operator -= (complex);
    complex& operator *= (complex);
    complex& operator /=(complex);
    friend std::istream& operator >>(std::istream&, complex&);
    friend std::ostream& operator << (std::ostream&, const complex&);
    bool operator == (complex com);
    bool operator != (complex& com);
    bool operator > (complex& com);
    bool operator < (complex& com);
};


#endif //LAB2_1_COMPLEX_H
