#ifndef LAB2_1_STUDENT_H
#define LAB2_1_STUDENT_H

#include <cstring>
#include <iostream>

using namespace std;

class Person {
private:
    char* firstName;
    char* middleName;
    char* lastName;
    char* role;
    char* id;
public:
    Person() {
        firstName = NULL;
        middleName = NULL;
        lastName = NULL;
        role = NULL;
        id = NULL;
    };
    Person(char *information[]) {
        //if (strlen(information) < 5) {throw length_error(": Not enough information");}
        firstName = information[0];
        middleName = information[1];
        lastName = information[2];
        role = information[3];
        id = information[4];
    }
    char* getFN() {return firstName;}
    char* getMN(){return middleName;}
    char *getLN(){return lastName;}
    char *getR(){return role;}
    char *getID(){return id;}
    void setFN(char* name) {firstName = name;}
    void setMN(char* name) {middleName = name;}
    void setLN(char *name) {lastName = name;}
    void setR(char *name) {role = name;}
    void setID(char *name) {id = name;}
    void shortPrint() {cout << lastName << endl;}
    void allPrint() {
        cout << firstName << endl;
        cout << middleName << endl;
        cout << lastName << endl;
        cout << role << endl;
        cout << id << endl;
    }
};


#endif //LAB2_1_STUDENT_H
