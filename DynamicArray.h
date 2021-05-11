//
// Created by Александр on 07.05.2021.
//

#ifndef LAB2_1_DYNAMICARRAY_H
#define LAB2_1_DYNAMICARRAY_H
#include <cassert>

template <class T>
class DynamicArray {
private:
    T* data;
    int lenght;
public:
// Конструкторы
    DynamicArray(int size) //	Создать массив заданной длины
    {
        data = new T[size];
        lenght = size;
    }

    DynamicArray(T* items, int count) //	Копировать элементы из переданного массива
    {
        data = new T[count];
        lenght = count;
        for (int i = 0; i < lenght ; i++)
        {
            data[i] = items[i];
        }
    }

    DynamicArray(DynamicArray<T>& dynamicArray) //	Копирующий конструктор
    {
        lenght = dynamicArray.lenght;
        data = new T[lenght];
        for (int i = 0; i < lenght; i++)
        {
            data[i] = dynamicArray.Get(i);
        }
    }

// Декомпозиция

    // Получить элемент по индексу.
    // Может выбрасывать исключения :	− IndexOutOfRange(если индекс отрицательный, больше
    // или равен числу элементов или указывает на не заданный элемент)
    T Get(int index)
    {
        try {
            if (lenght == 0) { throw out_of_range(": Index out of range! Dynamic Array is empty!"); }
            if (index >= lenght) { throw out_of_range(": Index out of range!"); }
            if (index < 0) { throw out_of_range(": Index must be > 0"); }
            return data[index];
        } catch (out_of_range err) {
            cout << "error" << err.what() << endl;
        }
    }
    int GetSize() //	Получить размер массива
    {
        return lenght;
    }

// Операции
    void Set(int index, T value) // Задать элемент по индексу. Может выбросить IndexOutOfRange
    {
        try {
            if (lenght == 0) { throw out_of_range(": Index out of range! Dynamic Array is empty!"); }
            if (index >= lenght) { throw out_of_range(": Index out of range!"); }
            if (index < 0) { throw out_of_range(": Index must be > 0"); }
            data[index] = value;
        } catch (out_of_range err) {
            cout << "error" << err.what() << endl;
        }
    }

    // Изменить размер массива.Если размер увеличивается, все элементы копируются в начало новой памяти.
    // Если уменьшается – элементы, которые не помещаются, отбрасываются.
    void Resize(int newSize)
    {
        try {
            if (newSize < 0) {throw length_error(": Lenght must be > 0!");}
            T* newData = new T[newSize];
            for (int i = 0; i < newSize; i++)
                if (i > lenght) newData[i] = 0;
                else newData[i] = data[i];
            delete data;
            data = newData;
            lenght = newSize;
        } catch (length_error err) {
            cout << "error" << err.what() << endl;
        }
    }

};

enum ERRORS {
    OUT_OF_RANGE
};


#endif //LAB2_1_DYNAMICARRAY_H
