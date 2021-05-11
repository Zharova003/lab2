//
// Created by Александр on 07.05.2021.
//

#ifndef LAB2_1_ARRAYSEQUENCE_H
#define LAB2_1_ARRAYSEQUENCE_H

#include "Sequence.h"
#include "DynamicArray.h"

template <class T> class ArraySequence : public Sequence<T>
{
private:
    DynamicArray<T>* array;
public:
    // Constructors
    ArraySequence()
    {
        array = new DynamicArray<T>(0);
    } // Создать пустой список
    ArraySequence(T* arr, int count) {
        array = new DynamicArray<T>(0);
        array->Resize(count);
        for (int i = 0; i < count; i++)
        {
            array->Set(i, arr[i]);
        }
    }
    // Копировать элементы из переданного массива
    ArraySequence(ArraySequence <T>& list)
    {
        array = new DynamicArray<T>(0);
        array->Resize(list.GetLength());
        for (int i = 0; i < (list.GetLength()); i++)
        {
            array->Set(i, list.Get(i));
        }
    }// Создать на основе другого - Копирующий конструктор

    //Decomposition
    T GetFirst()
    {
        return this->Get(0);
    }
    T GetLast()
    {
        return this->Get(array->GetSize()-1);
    }
    T Get(int index)
    {
        return array->Get(index);
    }
    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex)
    {
        ArraySequence<T>* buf = new ArraySequence<T>;
        int dif = endIndex - startIndex+1;
        buf->Resize(dif);
        for (int i = 0; i< dif;i++)
        {
            buf->Set(i, this->Get(startIndex+i));
        }
        return buf;
    }
    int GetLength()
    {
        return array->GetSize();
    }
    void Set(int index, T value) //IndexOutOfRange
    {
        array->Set(index, value);
    }

    //
    // Сделать реализацию без resize в Append, Prepend, InsertAt
    void Append(T item)
    {
        DynamicArray<T>* new_array = new DynamicArray<T>(this->GetSize()+1);
        new_array->Set(this->GetSize(), item);
        for (int i=0; i<this->GetSize(); i++) {
            new_array->Set(i, this->Get(i));
        }
        array = new_array;
    }
    // Добавляет элемент в начало списка
    void Prepend(T item)
    {
        DynamicArray<T>* new_array = new DynamicArray<T>(this->GetSize()+1);
        new_array->Set(0, item);
        for (int i=0; i<this->GetSize(); i++) {
            new_array->Set(i+1, this->Get(i));
        }
        array = new_array;
    }
    void InsertAt(T item, int index)
    {
        try {
            if (index<0 || index >=this->GetSize()) {
                throw OUT_OF_RANGE;
            }
            int newSize = this->GetSize()+1;
            DynamicArray<T>* new_array = new DynamicArray<T>(newSize);
            int j=0;
            for (int i = 0; i<newSize; ++i) {
                if (i == index) {
                    new_array->Set(i, item);
                    continue;
                }
                new_array->Set(i, this->Get(j));
                j++;
            }
            array = new_array;
        } catch (ERRORS err) {
            cout << "error" << err << endl;
        }

    }
    Sequence <T>* Concat(Sequence <T>* list)
    {
        Sequence <T>* buf = NULL;
        int oldLenght = this->GetLength();
        this->Resize(this->GetLength() + ((ArraySequence <T>*)list)->GetLength());
        for (int i = 0 ;i < ((ArraySequence <T>*)list)->GetLength(); i++)
            this->Set(i + oldLenght,((ArraySequence <T>*)list)->Get(i));
        return (Sequence <T>*)buf;
    }
    /*bool1 subsequenceSearch()1111
    {
    }*/
    void Resize(int newSize)
    {
        array->Resize(newSize);
    }
};



#endif //LAB2_1_ARRAYSEQUENCE_H
