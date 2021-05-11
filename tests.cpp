#include "tests.h"
using namespace std;

int mupInt1 (int x) {
    return x + 10;
}

int mupInt2 (int x) {
    return x*x;
}

int reduceInt (int x, int y) {
    return x - y + 1;
}

bool intWhere1 (int element)
{
    return !(element % 2);
}

bool intWhere2 (int element)
{
    return (element < 50);
}

template <class T>
void QPS(Queque<T>* x) {
    for (int i = 0; i < x->GetLenght(); i++) {
        cout << "data " << x->getData(i) << " priority " << x->getPriority(i) << endl;
    }
    cout << endl;
}

void testIntQueque() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    Queque<int>* t1 = new Queque<int>(a, b, 10);
    cout << "queue A:" << endl;
    QPS(t1);
    cout << "all elements +10" << endl;
    t1->mapData(mupInt1);
    QPS(t1);
    cout << "B: 2-5 elements from A and push(reduceData, reducePriority)" << endl;
    Queque<int>* t2 = t1->GetSubQueque(2, 5);
    t2->mapPriority(mupInt2);
    t2->Push(t1->reduceData((reduceInt), 24), t1->reducePriority((reduceInt), 2));
    QPS(t2);
    cout << "save only %2 in A" << endl;
    t1 = t1->whereData(intWhere1);
    QPS(t1);
    cout << "concat A and B" << endl;
    QPS(t1->Concat(*t2));
    cout << "make 2 queue:" << endl;
    t1->mapPriority(mupInt2);
    t2 = t1->doubleWherePriority(intWhere2);
    cout << "priority^2 < 50 " << endl;
    QPS(t1);
    cout << "other element" << endl;
    QPS(t2);
    cout << "pop from others" << endl;
    QPS(t2->pop());
//    QPS(t2);
}

float mupReal1 (float x) {
    return x + 10;
}
float reduceReal (float x, float y) {
    return x - y;
}
bool RealWhere1 (float element) {
    return element <= 7;
}

void testRealQueque() {
    float a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    Queque<float>* t1 = new Queque<float>(a, b, 10);
    cout << "queue A:" << endl;
    QPS(t1);
    cout << "all elements +10" << endl;
    t1->mapData(mupReal1);
    QPS(t1);
    cout << "B: 2-5 elements from A and push(reduceData, reducePriority)" << endl;
    Queque<float>* t2 = t1->GetSubQueque(2, 5);
    t2->mapPriority(mupInt2);
    t2->Push(t1->reduceData((reduceReal), 1), t1->reducePriority((reduceInt), 2));
    QPS(t2);
    cout << "save only <= 7 in A" << endl;
    t1 = t1->whereData(RealWhere1);
    QPS(t1);
    cout << "concat A and B" << endl;
    QPS(t1->Concat(*t2));
    cout << "make 2 queue:" << endl;
    t1->mapPriority(mupInt2);
    t2 = t1->doubleWherePriority(intWhere2);
    cout << "priority^2 < 50 " << endl;
    QPS(t1);
    cout << "other element" << endl;
    QPS(t2);
    cout << "pop from others" << endl;
    QPS(t2->pop());
//    QPS(t2);
}

complex mupComplex1 (complex x) {
    return x + complex(10, 10);
}
complex reduceComplex (complex x, complex y) {
    return x - y;
}
bool ComplexWhere1 (complex element) {
    complex a = complex(12, 0);
    return element > a;
}
void testComplexQueque() {
    complex a[] = {complex(1, 2), complex(), complex(3, 4), complex(5, 6), complex(7, 8), complex(9, 10), complex(11, 12)};
    int b[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    Queque<complex>* t1 = new Queque<complex>(a, b, 7);
    cout << "queue A:" << endl;
    QPS(t1);
    cout << "all elements +10" << endl;
    t1->mapData(mupComplex1);
    QPS(t1);
    cout << "B: 2-5 elements from A and push(reduceData, reducePriority)" << endl;
    Queque<complex>* t2 = t1->GetSubQueque(2, 5);
    t2->mapPriority(mupInt2);
    t2->Push(t1->reduceData((reduceComplex), complex()), t1->reducePriority((reduceInt), 2));
    QPS(t2);
    cout << "save only >7 in A" << endl;
    t1 = t1->whereData(ComplexWhere1);
    QPS(t1);
    cout << "concat A and B" << endl;
    QPS(t1->Concat(*t2));
    cout << "make 2 queue:" << endl;
    t1->mapPriority(mupInt2);
    t2 = t1->doubleWherePriority(intWhere2);
    cout << "priority^2 < 50 " << endl;
    QPS(t1);
    cout << "other element" << endl;
    QPS(t2);
    cout << "pop from others" << endl;
    QPS(t2->pop());
}

char* mupChar1 (char* x) {
    char* a = (char *)calloc(strlen(x)+1, sizeof(char));
    for (int i = 0; i < strlen(x); i++) {
        a[i] = x[i];
    }
    a[strlen(a)]='a';
    return a;
}
char* reduceChar (char* x, char* y) {
    char* a = (char *)calloc(strlen(x)+strlen(y), sizeof(char));
    for (int i = 0; i < strlen(x); i++) {
        a[i] = x[i];
    }
    for (int i = strlen(x); i < strlen(x)+strlen(y); i++) {
        a[i] = y[i - strlen(x)];
    }
    a[strlen(a)-1]='a';
    return a;
}
bool CharWhere1 (char* element) {
    return strlen(element) < 4;
}
void testCharQueque() {
    char *a[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    int b[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    Queque<char*>* t1 = new Queque<char*>(a, b, 10);
    cout << "queue A:" << endl;
    QPS(t1);
    cout << "all elements +a" << endl;
    t1->mapData(mupChar1);
    QPS(t1);
    cout << "B: 2-5 elements from A and push(reduceData, reducePriority)" << endl;
    Queque<char*>* t2 = t1->GetSubQueque(2, 5);
    t2->mapPriority(mupInt2);
    t2->Push(t1->reduceData((reduceChar), "b"), t1->reducePriority((reduceInt), 2));
    QPS(t2);
    cout << "in A save only element with len < 4 " << endl;
    t1 = t1->whereData(CharWhere1);
    QPS(t1);
    cout << "concat A and B" << endl;
    QPS(t1->Concat(*t2));
    cout << "make 2 queue:" << endl;
    t1->mapPriority(mupInt2);
    t2 = t1->doubleWherePriority(intWhere2);
    cout << "priority^2 < 50 " << endl;
    QPS(t1);
    cout << "other element" << endl;
    QPS(t2);
    cout << "pop from others" << endl;
    QPS(t2->pop());
}

Person mupPerson1 (Person x){
    x.setLN(mupChar1(x.getLN()));
    return x;
}
Person reducePerson (Person x, Person y) {
    Person a;
    a.setLN(reduceChar(x.getLN(), y.getLN()));
    return a;
}
bool wherePerson1 (Person element) {
    return strlen(element.getLN()) > 3;
}

void QPSP(Queque<Person>* x) {
    for (int i = 0; i < x->GetLenght(); i++) {
        cout << "name " << x->getData(i).getLN() << " priority " << x->getPriority(i) << endl;
    }
    cout << endl;
}

void testPersonQueque() {
    char *a[] = {"1as", "2", "3e", "4", "vanya", "6", "7", "8", "9i", "10"};
    std::cout << "Hello, World!1" << std::endl;
    Person *A[10];
    std::cout << "Hello, World!2" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "Hello, World! " << i << std::endl;
        A[i]->setLN(a[0]);
    }
    int b[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::cout << "Hello, World!3" << std::endl;
    Queque<Person>* t1 = new Queque<Person>(*A, b, 10);
    cout << "queue A:" << endl;
    QPSP(t1);
    cout << "all elements +a" << endl;
    t1->mapData(mupPerson1);
    std::cout << "Hello, World!" << std::endl;
    QPSP(t1);
    cout << "B: 2-5 elements from A and push(reduceData, reducePriority)" << endl;
    Queque<Person>* t2 = t1->GetSubQueque(2, 5);
    t2->mapPriority(mupInt2);
    Person c = Person();
    c.setLN("b");
    t2->Push(t1->reduceData((reducePerson), c), t1->reducePriority((reduceInt), 2));
    QPSP(t2);
    cout << "in A save only element with len > 3 " << endl;
    t1 = t1->whereData(wherePerson1);
    QPSP(t1);
    cout << "concat A and B" << endl;
    QPSP(t1->Concat(*t2));
    cout << "make 2 queue:" << endl;
    t1->mapPriority(mupInt2);
    t2 = t1->doubleWherePriority(intWhere2);
    cout << "priority^2 < 50 " << endl;
    QPSP(t1);
    cout << "other element" << endl;
    QPSP(t2);
    cout << "pop " << endl;
    QPSP(t2->pop());
}