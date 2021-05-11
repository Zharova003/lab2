#ifndef LAB2_1_TESTS_H
#define LAB2_1_TESTS_H

#include <iostream>
using namespace std;
#include "Queque.h"
#include "ArraySequence.h"
#include "Student.h"
#include <cstdlib>

int mupInt1 (int x);
int mupInt2 (int x);
int reduceInt (int x, int y);
bool intWhere1 (int element);
bool intWhere2 (int element);
template <class T>
void QPS(Queque<T>* x);
void testIntQueque();
float mupReal1 (float x);
float reduceReal (float x, float y);
bool RealWhere1 (float element);
void testRealQueque();
complex mupComplex1 (complex x);
complex reduceComplex (complex x, complex y);
bool ComplexWhere1 (complex element);
void testComplexQueque();
char* mupChar1 (char* x);
char* reduceChar (char* x, char* y);
bool CharWhere1 (char* element);
void testCharQueque();
Person mupPerson1 (Person x);
Person reducePerson (Person x, Person y);
bool wherePerson1 (Person element);
void QPSP(Queque<Person>* x);
void testPersonQueque();


#endif //LAB2_1_TESTS_H
