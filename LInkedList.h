#ifndef LAB2_1_LINKEDLIST_H
#define LAB2_1_LINKEDLIST_H

#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class Item {
public:
    T data;	// Любые данные
    Item<T>* next;	//Указатель на следующиий элемент в цепочке
};


template <typename T>
class LinkedList {
private:
    Item<T>* head;	// Голова списка
    Item<T>* tail;
    int lenght;	// Длинна списка
public:

// Конструкторы
    LinkedList()// Создать пустой список
    {
        head = NULL;
        tail = NULL;
        lenght = 0;
    };
    LinkedList(T* items, int count) //	Копировать элементы из переданного массива
    {
        head = NULL;
        tail = NULL;

        for (int i = 0; i < count; i++)
        {
            Append(items[i]);
        }
    }
    // Сделать реализацию LinkedList
    LinkedList(LinkedList <T>& list)  // Копирующий конструктор
    {
        head = NULL;
        tail = NULL;
        for (int i = 0; i < list.lenght; i++)
        {
            Append(list.Get(i));
        }
    };
// Декомпозиция
    T GetFirst() // Получить первый элемент в списке. Может выбрасывать исключения : − IndexOutOfRange(если список пуст)
    {
        try {
            if (lenght == 0) {throw out_of_range(": Index out of range! Linked List is empty!");}
            return T(head->data);
        } catch (out_of_range err) {
            cout << "error" << err.what() << endl;
        }
    }
    T GetLast() // Получить последний элемент в списке. Может выбрасывать исключения : − IndexOutOfRange(если список пуст)
    {
        try {
            if (lenght == 0) {throw out_of_range(": Index out of range! Linked List is empty!");}
            return T(tail->data);
        } catch (out_of_range err) {
            cout << "error" << err.what() << endl;
        }
    }
    T Get(int index)
    {
        try {
            if (lenght == 0) {throw out_of_range(": Index out of range! Linked List is empty!");}
            if (index >= lenght) {throw out_of_range(": Index out of range!");}
            if (index < 0) {throw out_of_range(": Index must be > 0");}
            Item<T>* buf = head;
            for (int i = 0; i < index; i++)
            {
                buf = buf->next;
            }
            return buf->data;
        } catch (out_of_range err) {
            cout << "error" << err.what() << endl;
        }

    };
    void Set(int index, T data)
    {
        try {
            if (lenght == 0) {throw out_of_range(": Index out of range! Linked List is empty!");}
            if (index >= lenght) {throw out_of_range(": Index out of range!");}
            if (index < 0) {throw out_of_range(": Index must be > 0");}
            Item<T>* buf = head;
            for (int i = 0; i < index; i++)
            {
                buf = buf->next;
            }
            buf->data = data;
        } catch (out_of_range err) {
            cout << "error" << err.what() << endl;
        }

    }
    // Получить список из всех элементов, начиная с startIndex и заканчивая endIndex.
    LinkedList<T>* GetSubList(int startIndex, int endIndex)
    {
        try {
            if (lenght == 0) {throw out_of_range(": Index out of range! Linked List is empty!");}
            if (startIndex >= lenght || endIndex >= lenght) {throw out_of_range(": Index out of range!");}
            if (startIndex < 0 || endIndex < 0) {throw out_of_range(": Index must be > 0");}
            LinkedList<T>* buf = new LinkedList<T>();
            for (int i = startIndex; i <= endIndex; i++)
            {
                buf->Append(Get(i));
            }
            return buf;
        } catch (out_of_range err) {
            cout << "error" << err.what() << endl;
        }
    };

    int GetLength()	// Получить длину списка
    {
        return lenght;
    }

// Операции

    // Добавляет элемент в конец списка
    void Append(T item)
    {
        lenght++;	//Увеличиваем число элементов на единицу
        Item<T>* buf = new Item<T>;
        buf->next = NULL;
        buf->data = item;
        if (head == NULL)
        {
            head = buf;
            tail = head;
        }
        else
        {
            tail->next = buf;
            tail = buf; // Смещаем хвост
        }
    }
    void Prepend(T item) // Добавляет элемент в начало списка
    {
        lenght++;	//Увеличиваем число элементов на единицу
        Item<T>* buf = new Item<T>;
        buf->next = NULL;
        buf->data = item;
        if (head == NULL)
        {
            head = buf;
            tail = head;
        }
        else
        {
            buf->next = head;
            head = buf; // Смещаем голову
        }
    }
    void InsertAt(T item, int index) // Вставляет элемент в заданную позицию.
    // Может выбрасывать исключения : − IndexOutOfRange(если индекс отрицательный или больше / равен числу элементов)
    {
        try {
            if (index >= lenght) {throw out_of_range(": Index out of range!");}
            if (index < 0) {throw out_of_range(": Index must be > 0");}
            if (index == 0) {
                Prepend(item);
            }
            else  {
                LinkedList<T> *left = this->GetSubList(0, index-1);
                LinkedList<T> *right = this->GetSubList(index, lenght-1);
                left->Append(item);
                left->Concat(right);
                head = left->head;
                tail = left->tail;
                lenght++;
            }
        } catch (out_of_range err) {
            cout << "error" << err.what() << endl;
        }
    }
    //Сцепляет два списка
    LinkedList<T>* Concat(LinkedList<T>* list)
    {
        for (int i = 0; i < list->lenght; i++)
            Append(list->Get(i));
        return this;
    }


};




#endif //LAB2_1_LINKEDLIST_H
