#ifndef LAB2_1_VECTOR_H
#define LAB2_1_VECTOR_H

#include <iostream>
#include <cmath>

using namespace std;
#include "ArraySequence.h"
#include "complex.h"

template <class T>
class Vector {
private:
    ArraySequence<T> *array;
public:
    Vector() {
        array = new ArraySequence<T>();
    }
    Vector(int lenght) {
        array = new ArraySequence<T>(lenght);
    }
    Vector(T* data, int lenght) {
        array = new ArraySequence<T>(data, lenght);
    }

    int GetSize() {
        return array->GetLength();
    }

    T Get(int index) {
        return array->Get(index);

    }

    void resize(int length) {
        array->Resize(length);
    }

    void push_back(T &value) {
        array->Append(value);
    }

    void Set(T value, int index) {
        array->Set(index, value);
    }

    Vector<T>* sumVectors(Vector<T>* a) {
        if (a->GetSize() != this->GetSize()) {throw length_error("Different lenghtd");}
        Vector<T>* res = new Vector<T>(a->GetSize());
        for (int i = 0; i < a->GetSize(); i++) {
            res->Set(a->Get(i) + this->Get(i), i);
        }
        return res;
    }

    Vector<T>* multiValue(T value) {
        Vector<T>* res = new Vector<T>(this->GetSize());
        for (int i = 0; i < this->GetSize(); i++) {
            res->Set(array->Get(i) * value, i);
        }
        return res;
    }

    T NormVector() {
        T res = 0;
        for (int i = 0; i < this->GetSize(); i++) {
            res += array->Get(i) * array->Get(i);
        }
        res = sqrt(res);
        return res;
    }

    T ScalarMulti(Vector<T>* a) {
        if (a->GetSize() != this->GetSize()) {throw length_error("Different lenghts");}
        T res = 0;
        for (int i = 0; i < this->GetSize(); i++) {
            res += array->Get(i) * a->Get(i);
        }
        return res;
    }

//    Vector(Vector<T> &Vector) {
//        array = new ArraySequence<T>();
//        for (int i = 0; i < Vector)
//    }


};

#endif //LAB2_1_VECTOR_H
