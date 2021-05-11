#ifndef LAB2_1_QUEQUE_H
#define LAB2_1_QUEQUE_H

#include <cassert> // для assert
#include <iostream>

using namespace std;
#include "LinkedListSequence.h"
#include "complex.h"

template <class T>
class Queque {
private:
    LinkedListSequence<T>* dataListSequence;
    LinkedListSequence<int>* priorityListSequence;
public:
    //конструкторы
    Queque()
    {
        dataListSequence = new LinkedListSequence<T>;
        priorityListSequence = new LinkedListSequence<int>;
    };

    Queque(Queque<T>& queue) // конструктор копирования
    {
        dataListSequence = new LinkedListSequence<T>;
        priorityListSequence = new LinkedListSequence<int>;
        for (int i = 0; i< queue.GetLenght(); i++)
        {
            dataListSequence->Append(queue.getData(i));
            priorityListSequence->Append(queue.getPriority(i));
        }
    };

    Queque(T* data, int* priority, int len) {
        dataListSequence = new LinkedListSequence<T>;
        priorityListSequence = new LinkedListSequence<int>;
        for (int i = 0; i < len; i++) {
            dataListSequence->Append(data[i]);
            priorityListSequence->Append(priority[i]);
        }
    };
    Queque(LinkedListSequence<T>* data, LinkedListSequence<int>* priority) {
        dataListSequence = data;
        priorityListSequence = priority;
    }
    //декомпозиция
    void Push(const T& data, const int& priority) // добавить элемент в очередь
    {
        dataListSequence->Append(data);
        priorityListSequence->Append(priority);
    };

    Queque<T>* pop() // удалить элемент из начала очереди
    {
        Queque<T>* result = new Queque<T>();
        T datai = dataListSequence->Get(0);
        int pri = priorityListSequence->Get(0), number = 0;
        for (int i = 1; i < dataListSequence->GetLength(); i++) {
            if (pri > priorityListSequence->Get(i)) {
                datai = dataListSequence->Get(i);
                pri = priorityListSequence->Get(i);
                number = i;
            }
        }
        result->Push(datai, pri);
        if (number == 0) {
            dataListSequence = (LinkedListSequence<T>*)dataListSequence->GetSubsequence(1, dataListSequence->GetLength() - 1);
            priorityListSequence = (LinkedListSequence<int>*)priorityListSequence->GetSubsequence(1, dataListSequence->GetLength() - 1);
        } else {
            LinkedListSequence<T>* data;
            LinkedListSequence<int>* priority;
            data = (LinkedListSequence<T>*)dataListSequence->GetSubsequence(0, number - 1);
            priority = (LinkedListSequence<int>*)priorityListSequence->GetSubsequence(0, number - 1);
            for (int i = number + 1; i < dataListSequence->GetLength(); i++) {
                data->Append(dataListSequence->Get(i));
                priority->Append(priorityListSequence->Get(i));
            }
            dataListSequence = data;
            priorityListSequence = priority;
        }

        return result;
    };

    bool Empty()
    {
        return (dataListSequence->GetLength() < 1);
    };

    T getData (int index) {
        return dataListSequence->Get(index);
    };
    int getPriority (int index) {
        return priorityListSequence->Get(index);
    };
    void Set(T data, int priority, int index) {
        dataListSequence->Set(index, data);
        priorityListSequence->Set(index, priority);
    }
    int GetLenght () {
        return dataListSequence->GetLength();
    };

//functions
    void mapData(T mupFunc(T arg))
    {
        dataListSequence->map(mupFunc);
    };
    void mapPriority(int mupFunc(int arg))
    {
        priorityListSequence->map(mupFunc);
    };
    T reduceData(T reduceFunc(T arg1, T arg2), T someValue) {
        dataListSequence->reduce(reduceFunc, someValue);
    };
    int reducePriority(int reduceFunc(int arg1, int arg2), int someValue) {
        priorityListSequence->reduce(reduceFunc, someValue);
    };
    Queque<T>* whereData(bool(*whereFunc)(T))
    {
        LinkedListSequence<T>* bufd = new LinkedListSequence<T>();
        LinkedListSequence<int>* bufp = new LinkedListSequence<int>();
        int len = dataListSequence->GetLength();
        for (int i = 0; i < len; i++)
        {
            if (whereFunc(dataListSequence->Get(i))) {
                bufd->Append(dataListSequence->Get(i));
                bufp->Append(priorityListSequence->Get(i));
            }
        }
        Queque<T>* result = new Queque<T>(bufd, bufp);
        return result;
    };
    Queque<T>* wherePriority(bool(*whereFunc)(T))
    {
        LinkedListSequence<T>* bufd = new LinkedListSequence<T>();
        LinkedListSequence<int>* bufp = new LinkedListSequence<int>();
        int len = dataListSequence->GetLength();
        for (int i = 0; i < len; i++)
        {
            if (whereFunc(priorityListSequence->Get(i))) {
                bufd->Append(dataListSequence->Get(i));
                bufp->Append(priorityListSequence->Get(i));
            }
        }
        Queque<T>* result = new Queque<T>(bufd, bufp);
        return result;
    };
    bool SubQuequeSearch(Queque<T>& que)
    {
        return dataListSequence->SubSequenceSearch(que.dataListSequence);
    };
    Queque<T>* GetSubQueque(int startIndex, int endIndex)
    {
        Queque<T>* buf = new Queque<T>;
        for (int i = startIndex; i < endIndex; i++) {
            buf->Push(this->getData(i), this->getPriority(i));
        }
        return buf;
    };
    Queque<T>* doubleWhereData (bool(*whereFunc)(T)) { //разделить на 2 очереди
        LinkedListSequence<T>* bufd1 = new LinkedListSequence<T>();
        LinkedListSequence<int>* bufp1 = new LinkedListSequence<int>();
        LinkedListSequence<T>* bufd2 = new LinkedListSequence<T>();
        LinkedListSequence<int>* bufp2 = new LinkedListSequence<int>();
        int len = dataListSequence->GetLength();
        for (int i = 0; i < len; i++)
        {
            if (whereFunc(dataListSequence->Get(i))) {
                bufd1->Append(dataListSequence->Get(i));
                bufp1->Append(priorityListSequence->Get(i));
            } else {
                bufd2->Append(dataListSequence->Get(i));
                bufp2->Append(priorityListSequence->Get(i));
            }
        }
        dataListSequence = bufd1;
        priorityListSequence = bufp1;
        Queque<T>* result = new Queque<T>(bufd2, bufp2);
        return result;
    };
    Queque<T>* doubleWherePriority (bool(*whereFunc)(int)) {
        LinkedListSequence<T>* bufd1 = new LinkedListSequence<T>();
        LinkedListSequence<int>* bufp1 = new LinkedListSequence<int>();
        LinkedListSequence<T>* bufd2 = new LinkedListSequence<T>();
        LinkedListSequence<int>* bufp2 = new LinkedListSequence<int>();
        int len = dataListSequence->GetLength();
        for (int i = 0; i < len; i++)
        {
            if (whereFunc(priorityListSequence->Get(i))) {
                bufd1->Append(dataListSequence->Get(i));
                bufp1->Append(priorityListSequence->Get(i));
            } else {
                bufd2->Append(dataListSequence->Get(i));
                bufp2->Append(priorityListSequence->Get(i));
            }
        }
        dataListSequence = bufd1;
        priorityListSequence = bufp1;
        Queque<T>* result = new Queque<T>(bufd2, bufp2);
        return result;
    };
    Queque<T>* Concat(Queque<T>& que)
    {
        dataListSequence->Concat(que.dataListSequence);
        priorityListSequence->Concat(que.priorityListSequence);
        return this;
    };



};


#endif //LAB2_1_QUEQUE_H
