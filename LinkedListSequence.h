//
// Created by Александр on 07.05.2021.
//

#ifndef LAB2_1_LINKEDLISTSEQUENCE_H
#define LAB2_1_LINKEDLISTSEQUENCE_H

#include "Sequence.h"
#include "LInkedList.h"

template <class T>
class LinkedListSequence : public Sequence<T> {
private:
    LinkedList<T>* linkedList;
public:
    //constructor
    LinkedListSequence()
    {
        linkedList = new LinkedList<T>;
    };

    LinkedListSequence(T* items, int count)
    {
        linkedList = new LinkedList<T>(items, count);
    };

    LinkedListSequence(LinkedListSequence <T>& list)
    {
        linkedList = new LinkedList<T>;
        for (int i = 0; i < list.GetLength(); i++)
        {
            this->Append(list.Get(i));
        }
    };

    // operations
    T GetFirst()
    {
        return linkedList->GetFirst();
    }
    T GetLast()
    {
        return linkedList->GetLast();
    }
    T Get(int index)
    {
        return linkedList->Get(index);
    }
    LinkedListSequence<T>* GetSubsequence(int startIndex, int endIndex)
    {
        LinkedList<T>* bufList = new LinkedList<T>(*(linkedList->GetSubList(startIndex, endIndex)));
        LinkedListSequence<T>* bufListSeq = new LinkedListSequence<T>;
        for (int i = 0; i < bufList->GetLength(); i++)
        {
            bufListSeq->Append(bufList->Get(i));
        }
        delete bufList;
        return (LinkedListSequence<T>*)bufListSeq;
    }
    int GetLength()
    {
        return linkedList->GetLength();
    }
    void Set(int index, T data)
    {
        linkedList->Set(index, data);
    }
    void Append(T item)
    {
        linkedList->Append(item);
    }
    void Prepend(T item)
    {
        linkedList->Prepend(item);
    }
    void InsertAt(T item, int index)
    {
        linkedList->InsertAt(item, index);
    }
    Sequence <T>* Concat(Sequence <T>* list)
    {
        for (int i = 0; i < ((LinkedListSequence<T>*)list)->GetLength(); i++)
        {
            this->Append(((LinkedListSequence<T>*)list)->Get(i));
        }
        return (Sequence <T>*)this;
    };
    LinkedListSequence<T>* where(bool (*whereFunc)(T))
    {
        LinkedListSequence<T>* buf = new LinkedListSequence<T>;
        for (int i = 0; i < this->GetLength(); i++)
        {
            if ( whereFunc(this->Get(i)) ) buf->Append(this->Get(i));
        }
        return (LinkedListSequence<T>*)buf;
    };

};


#endif //LAB2_1_LINKEDLISTSEQUENCE_H
