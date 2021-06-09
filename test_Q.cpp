#include <gtest/gtest.h>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Complex.h"
#include "Queque.h"
#include "tests.h"
#include "vector.h"


int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int b[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

TEST(DynamicArray, constructor1) {
    DynamicArray<int> *array = new DynamicArray<int>();
    EXPECT_EQ(array->GetSize(), 0);
}

TEST(DynamicArray, Constructor_2) {
    DynamicArray<int> *array = new DynamicArray<int>(10);
    EXPECT_EQ(array->GetSize(), 10);
    EXPECT_THROW(DynamicArray<int>(-1), length_error);
}

TEST(DynamicArray, Constructor_3) {
    DynamicArray<int> *array = new DynamicArray<int>(a, 10);
    EXPECT_EQ(array->GetSize(), 10);
    EXPECT_EQ(array->Get(3), 4);
    EXPECT_THROW(DynamicArray<int>(a, -1), length_error);
}

TEST(DynamicArray, Constructor_4) {
    DynamicArray<int> *array = new DynamicArray<int>(a, 10);
    DynamicArray<int> *array1 = new DynamicArray<int>(*array);
    EXPECT_EQ(array->GetSize(), array1->GetSize());
    EXPECT_EQ(array->Get(0), array1->Get(0));
    EXPECT_EQ(array->Get(3), array1->Get(3));
}

TEST(DynamicArray, Get) {
    DynamicArray<int> *array = new DynamicArray<int>();
    EXPECT_THROW(array->Get(-1), out_of_range);
    array->Resize(3);
    array->Set(0, 1);
    EXPECT_THROW(array->Get(-1), out_of_range);
    EXPECT_THROW(array->Get(5), out_of_range);
}

TEST(DynamicArray, getsize) {
    DynamicArray<int> *array = new DynamicArray<int>( 4);
    EXPECT_EQ(array->GetSize(), 4);
}
TEST(DynamicArray, Set) {
    DynamicArray<int> *array = new DynamicArray<int>();
    EXPECT_THROW(array->Set(1, 1), out_of_range);
    array->Resize(3);
    array->Set(1, 14);
    EXPECT_EQ(array->Get(1), 14);
    EXPECT_THROW(array->Set(-1, -1), out_of_range);
    EXPECT_THROW(array->Set(5, 5), out_of_range);
}
TEST(DynamicArray, resize) {
    DynamicArray<int> *array = new DynamicArray<int>(a, 10);
    EXPECT_THROW(array->Resize(-1), length_error);
    EXPECT_EQ(array->GetSize(), 10);
    array->Resize(4);
    EXPECT_EQ(array->GetSize(), 4);
}

//Linkedlist

TEST(LinkedList, Constructor_1) {
    LinkedList<int>*list = new LinkedList<int>();
    EXPECT_EQ(list->GetLength(), 0);
}
TEST(LinkedList, Constructor_2) {
    EXPECT_THROW(LinkedList<int>(a, -1), length_error);
    LinkedList<int>*list = new LinkedList<int>(a, 10);
    EXPECT_EQ(list->GetLength(), 10);
}
TEST(LinkedList, Constructor_3) {
    LinkedList<int>*list = new LinkedList<int>(a, 10);
    LinkedList<int>*list1 = new LinkedList<int>(*list);
    EXPECT_EQ(list->GetLength(), list1->GetLength());
}
TEST(LinkedList, GetFirst) {
    LinkedList<int>*list = new LinkedList<int>();
    EXPECT_THROW(list->GetFirst(), out_of_range);
    list->Append(1);
    EXPECT_EQ(list->GetFirst(), 1);
}
TEST(LinkedList, GetLast) {
    LinkedList<int>*list = new LinkedList<int>();
    EXPECT_THROW(list->GetLast(), out_of_range);
    list->Append(1);
    EXPECT_EQ(list->GetLast(), 1);
}
TEST(LinkedList, Get) {
    LinkedList<int>*list = new LinkedList<int>();
    EXPECT_THROW(list->Get(1), out_of_range);
    list->Append(1);
    EXPECT_THROW(list->Get(-1), out_of_range);
    EXPECT_THROW(list->Get(5), out_of_range);
    EXPECT_EQ(list->Get(0), 1);
}
TEST(LinkedList, Set) {
    LinkedList<int>*list = new LinkedList<int>();
    EXPECT_THROW(list->Set(1, 1), out_of_range);
    list->Append(1);
    list->Set(0, 3);
    EXPECT_THROW(list->Set(-1, -1), out_of_range);
    EXPECT_THROW(list->Set(5, 5), out_of_range);
    EXPECT_EQ(list->Get(0), 3);
}
TEST(LinkedList, GetSublist) {
    LinkedList<int>*list = new LinkedList<int>();
    EXPECT_THROW(list->GetSubList(1, 1), out_of_range);
    LinkedList<int>*list1 = new LinkedList<int>(a, 10);
    EXPECT_THROW(list1->GetSubList(11, 11), out_of_range);
    EXPECT_THROW(list1->GetSubList(-1, -1), out_of_range);
    list = list1->GetSubList(1, 5);
    EXPECT_EQ(list->GetLength(), 5);
    EXPECT_EQ(list->GetFirst(), list1->Get(1));
    EXPECT_EQ(list->GetLast(), list1->Get(5));
}
TEST(LinkedList, Append) {
    LinkedList<int>*list1 = new LinkedList<int>(a, 10);
    list1->Append(13);
    EXPECT_EQ(list1->GetLength(), 11);
    EXPECT_EQ(list1->GetLast(), 13);
}
TEST(LinkedList, Prepend) {
    LinkedList<int>*list1 = new LinkedList<int>(a, 10);
    list1->Prepend(13);
    EXPECT_EQ(list1->GetLength(), 11);
    EXPECT_EQ(list1->GetFirst(), 13);
}
TEST(LinkedList, InsertAt) {
    LinkedList<int>*list1 = new LinkedList<int>(a, 10);
    EXPECT_THROW(list1->InsertAt(-1, -1), out_of_range);
    EXPECT_THROW(list1->InsertAt(15, 15), out_of_range);
    list1->InsertAt(2, 7);
    EXPECT_EQ(list1->Get(7), 2);
}
TEST(LinkedList, Concat) {
    LinkedList<int>*list = new LinkedList<int>(a, 5);
    LinkedList<int>*list1 = new LinkedList<int>(a, 5);
    list->Concat(list1);
    EXPECT_EQ(list->GetLength(), list1->GetLength()*2);
    EXPECT_EQ(list->Get(5), 1);
}

//Queue

TEST(Queue, Constructor_1) {
    Queque<int> *q = new Queque<int>();
    EXPECT_EQ(q->GetLenght(), 0);
}
TEST(Queue, Constructor_2) {
    Queque<int> *q = new Queque<int>(a, b, 10);
    EXPECT_EQ(q->GetLenght(), 10);
    EXPECT_EQ(q->getData(0), 1);
    EXPECT_EQ(q->getPriority(0), 10);
}
TEST(Queue, Constructor_3) {
    Queque<int> *q = new Queque<int>(a, b, 10);
    Queque<int> *q1 = new Queque<int>(*q);
    EXPECT_EQ(q->GetLenght(), q1->GetLenght());
    EXPECT_EQ(q->getData(1), q1->getData(1));
    EXPECT_EQ(q->getPriority(1), q1->getPriority(1));

}
TEST(Queue, Constructor_4) {
    LinkedListSequence<int> *A = new LinkedListSequence<int>(a, 10);
    LinkedListSequence<int> *B = new LinkedListSequence<int>(b, 10);
    LinkedListSequence<int> *B1 = new LinkedListSequence<int>(b, 5);
    EXPECT_THROW(Queque<int>(A, B1), length_error);
    Queque<int> *q = new Queque<int>(A, B);
    EXPECT_EQ(q->GetLenght(), 10);
    EXPECT_EQ(q->getData(0), 1);
    EXPECT_EQ(q->getPriority(0), 10);
}
TEST(Queue, push) {
    Queque<int> *q = new Queque<int>();
    q->Push(1, 2);
    EXPECT_EQ(q->GetLenght(), 1);
    EXPECT_EQ(q->getData(0), 1);
    EXPECT_EQ(q->getPriority(0), 2);
}
TEST(Queue, pop) {
    Queque<int> *q1 = new Queque<int>();
    EXPECT_THROW(q1->pop(), out_of_range);
    Queque<int> *q = new Queque<int>(a, b, 10);
    q->pop();
    EXPECT_EQ(q->GetLenght(), 9);
    EXPECT_EQ(q->getData(8), 9);
}
TEST(Queue, map) {
    Queque<int> *q = new Queque<int>(a, b, 10);
    q->mapData(mupInt1);
    EXPECT_EQ(q->getData(0), 11);
    EXPECT_EQ(q->getData(9), 20);
}
TEST(Queue, reduce) {
    Queque<int> *q = new Queque<int>(a, b, 10);
    int c = q->reduceData(reduceInt, 1);
    EXPECT_EQ(c, 6);
}
TEST(Queue, where) {
    Queque<int> *q = new Queque<int>(a, b, 10);
    q = q->whereData(intWhere1);
    EXPECT_EQ(q->getData(0), 2);
    EXPECT_EQ(q->getData(4), 10);
}
TEST(Queue, getsubqueue) {
    Queque<int> *q = new Queque<int>(a, b, 10);
    q = q->GetSubQueque(1, 4);
    EXPECT_EQ(q->GetLenght(), 3);
    EXPECT_EQ(q->getData(0), 2);
    EXPECT_EQ(q->getData(1), 3);
}

TEST(Queue, concat) {
    Queque<int> *q = new Queque<int>(a, b, 5);
    Queque<int> *q1 = new Queque<int>(a, b, 10);
    q->Concat(*q1);
    EXPECT_EQ(q->GetLenght(), 15);
    EXPECT_EQ(q->getData(14), 10);
}
TEST(vector, Constructor_1) {
    Vector<int>* v = new Vector<int>();
    EXPECT_EQ(v->GetSize(), 0);
}
TEST(vector, Constructor_2) {
    Vector<int>* v = new Vector<int>(3);
    EXPECT_EQ(v->GetSize(), 3);
    EXPECT_THROW(Vector<int>(-1), length_error);
}
TEST(vector, Constructor_3) {
    Vector<int>* v = new Vector<int>(a, 10);
    EXPECT_EQ(v->GetSize(), 10);
    EXPECT_EQ(v->Get(0), 1);
}
TEST(vector, sum) {
    Vector<int>* v = new Vector<int>(a, 10);
    Vector<int>* v1 = new Vector<int>(b, 10);
    Vector<int>* v2 = v->sumVectors(v1);
    EXPECT_EQ(v2->Get(0), 11);
}
TEST(vector, multionscalar) {
    Vector<int>* v = new Vector<int>(a, 10);
    Vector<int>* v2 = v->multiValue(3);
    EXPECT_EQ(v2->Get(0), 3);
}
TEST(vector, norm) {
    int c[] = {3, 4};
    Vector<int>* v = new Vector<int>(c, 2);
    EXPECT_EQ(v->NormVector(), 5);
}
TEST(vector, scalarMulti) {
    int c1[] = {1, 2, 3};
    Vector<int>* v = new Vector<int>(c1, 3);
    int c2[] = {4, 5, 6};
    Vector<int>* v1 = new Vector<int>(c2, 3);
    EXPECT_EQ(v->ScalarMulti(v1), 32);
}






