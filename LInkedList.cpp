//#include "LInkedList.h"
//
//template<typename T>
//LinkedList<T>::LinkedList()
//{
//head = NULL;
//tail = NULL;
//lenght = 0;
//}
//
//template<typename T>
//LinkedList<T>::LinkedList(T* items, int count)
//{
//    head = NULL;
//    tail = NULL;
//
//    for (int i = 0; i < count; i++)
//    {
//        Append(items[i]);
//    }
//}
//
//template<typename T>
//LinkedList<T>::LinkedList(LinkedList <T>& list)
//{
//    head = NULL;
//    tail = NULL;
//    for (int i = 0; i < list.lenght; i++)
//    {
//        Append(list.Get(i));
//    }
//}
//
//template<typename T>
//T LinkedList<T>::GetFirst()
//{
//    try {
//        if (lenght == 0) {throw OUT_OF_RANGE;}
//    } catch (ERRORS err) {
//        cout << "error" << err << endl;
//    }
////    return T(head->data);
//    try {
//        if (lenght == 0) {throw out_of_range("Stop! What r u doing?!");}
//    } catch (exception err) {
//        cerr << "error" << err.what() << endl;
//    }
////    return T(head->data);
//    if (lenght == 0) {return 0;};
//    return T(head->data);
//}
//
//template<typename T>
//T LinkedList<T>::GetLast()
//{
//    return T(tail->data);
//}
//
//template<typename T>
//Item<T>* LinkedList<T>::operator[](int index)
//{
//    if ((index == 0 && lenght == 0) || index<0 || index>=lenght)
//        return NULL;
//    //cout << "test - " << "index = " << index << endl;
//    Item<T>* buf = head;
//    //cout << "test - " << "lenght = " << lenght << endl;
//    //cout <<"test - "<<"head->data = "<< head->data<<endl;
//    for (int i = 0; i < index; i++)
//    {
//        buf = buf->next;
//    }
//    return buf;
//}
//
//template<typename T>
//T LinkedList<T>::Get(int index)
//{
//    assert(!(index == 0 && lenght == 0));
//
//    //cout << "test - " << "index = " << index << endl;
//    assert(index >= 0);
//    assert(index < lenght);
//    Item<T>* buf = head;
//    //cout << "test - " << "lenght = " << lenght << endl;
//    //cout <<"test - "<<"head->data = "<< head->data<<endl;
//    for (int i = 0; i < index; i++)
//    {
//        buf = buf->next;
//    }
//    return buf->data;
//}
//
//template<typename T>
//LinkedList<T>* LinkedList<T>::GetSubList(int startIndex, int endIndex)
//{
//    assert(startIndex >= 0);
//    assert(endIndex <= lenght);
//    LinkedList<T>* buf = new LinkedList<T>();
//    for (int i = startIndex; i <= endIndex; i++)
//    {
//        buf->Append(Get(i));
//    }
//    return buf;
//}
//
//template<typename T>
//int LinkedList<T>::GetLength()
//{
//    return lenght;
//}
//template<typename T>
//void LinkedList<T>::Set(int index, T data)
//{
//    assert(!(index == 0 && lenght == 0));
//
//    //cout << "test - " << "index = " << index << endl;
//    assert(index >= 0);
//    assert(index < lenght);
//    Item<T>* buf = head;
//    //cout << "test - " << "lenght = " << lenght << endl;
//    //cout <<"test - "<<"head->data = "<< head->data<<endl;
//    for (int i = 0; i < index; i++)
//    {
//        buf = buf->next;
//    }
//    buf->data = data;
//}
//template<typename T>
//void LinkedList<T>::Append(T item)
//{
//    lenght++;	//Увеличиваем число элементов на единицу
//    Item<T>* buf = new Item<T>;
//    buf->next = NULL;
//    buf->data = item;
//    if (head == NULL)
//    {
//        head = buf;
//        head->previous = NULL;
//        tail = head;
//    }
//    else
//    {
//        tail->next = buf;
//        buf->previous = tail;
//        tail = buf; // Смещаем хвост
//    }
//}
//template<typename T>
//void LinkedList<T>::Prepend(T item)
//{
//    lenght++;	//Увеличиваем число элементов на единицу
//    Item<T>* buf = new Item<T>;
//    buf->next = NULL;
//    buf->data = item;
//    if (head == NULL)
//    {
//        head = buf;
//        head->previous = NULL;
//        tail = head;
//    }
//    else
//    {
//        head->previous = buf;
//        buf->next = head;
//        head = buf; // Смещаем голову
//    }
//}
//template<typename T>
//void LinkedList<T>::InsertAt(T item, int index)
//{
//    assert(index>=0);
//    assert(index < lenght); //
//    Item<T>* itemBefor = (*this)[index];
//
//    if (itemBefor == NULL)
//        Append(item);
//    else
//    {
//        Item<T>* buf = new Item<T>;
//        buf->data = item;
//        buf->previous = itemBefor;
//        buf->next = itemBefor->next;
//        itemBefor->next->previous = buf;
//        itemBefor->next = buf;
//        lenght++;
//    }
//
//}
//
//template<typename T>
//LinkedList<T>* LinkedList<T>::Concat(LinkedList<T> *list)
//{
//    for (int i = 0; i < list->lenght; i++)
//        Append(list->Get(i));
//    return this;
//}
