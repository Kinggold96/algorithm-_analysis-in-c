// binary_heap.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "brinary_heap.h"
#include <stdlib.h>

#define MinPQSize (10)
#define MinData (-32767)
struct HeapStruct {
    int Capacity;
    int Size;
    ElementType* Elements;
};


int main()
{
    
}

PriorityQueue Initialize(int MaxElement) {
    PriorityQueue H;
    if (MaxElement < MinPQSize)
        Error("Priority queue size is too small");
    H = malloc(sizeof(struct HeapStruct));
    if (H == NULL)
        FatalError("Out of space!!!");
    H->Elements = malloc((MaxElement + 1) * sizeof(ElementType));
    if (H->Elements == NULL)
        FatalError("Out of space!!!");
    H->Capacity = MaxElement;
    H->Size = 0;
    H->Elements[0] = MinData;
}

void Insert(ElementType X, PriorityQueue H) {
    int i;

    if (IsFull(H)) {
        Error("Priority queue id full");
        return;
    }
    for (i = ++H->Size; H->Elements[i/2]>X; i/2) {
        H->Elements[i] = H->Elements[i / 2];
        H->Elements[i] = X;
    }
}

ElementType DeletMin(PriorityQueue H) {
    int i, Child;
    ElementType MinElement, LastElement;
    if (IsEmpty(H)) {
        Error("Priority queue is empty");
        return H->Elements[0];
    }
    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];

    for (i = 1; i * 2 <= H->Size; i = Child) {
        Child = i * 2;
        if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child]) 
            Child++;
        if (LastElement > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            break;
    }
    H->Elements[i] = LastElement;
    return MinElement;

}

ElementType
FindMin(PriorityQueue H)
{
    if (!IsEmpty(H))
        return H->Elements[1];
    Error("Priority Queue is Empty");
    return H->Elements[0];
}

int
IsEmpty(PriorityQueue H)
{
    return H->Size == 0;
}

int
IsFull(PriorityQueue H)
{
    return H->Size == H->Capacity;
}

void
Destroy(PriorityQueue H)
{
    free(H->Elements);
    free(H);
}