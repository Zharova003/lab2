#ifndef LAB2_1_SEQUENCE_H
#define LAB2_1_SEQUENCE_H

#include "complex.h"

template <class T>
class Sequence {
private:

public:
    //constructors
//    Sequence() {};
//    Sequence(T* items, int count);

    // decomposition
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index) = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
    virtual int GetLength() = 0;
    virtual void Set(int index, T data) = 0;

    // Îïåðàöèè
    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item, int index) = 0;
    virtual Sequence <T>* Concat(Sequence <T>* list) = 0;
    //map, reduce, zip, unzip, where
    void map(T mapFunc(T arg))
    {
        for (int i = 0; i < GetLength(); i++)
        {
            Set(i, mapFunc(Get(i)));
        }
    }
    T reduce(T reduceFunc(T arg1, T arg2), T someValue)
    {
        T res = someValue;
        for (int i = 0; i < GetLength(); i++)
        {
            res = reduceFunc(Get(i), res);
        }
        return res;
    }
    bool SubSequenceSearch(Sequence<T>* seq)
    {
        bool result = false;
        for (int i = 0; i < GetLength() - seq->GetLength(); i++)
        {
            result = true;
            for (int j = 0; j < seq->GetLength(); j++)
            {
                result &= (Get(i + j) == (seq->Get(j)));
            };
            if (result == true)break;
        }
        return result;
    }
};




#endif //LAB2_1_SEQUENCE_H
