
#include "fatal.h"
#include "hash_book_code.h"
#include <stdlib.h>

#define MinTableSize (10)


Index
Hash(ElementType Key, int TableSize)
{
    return Key % TableSize;
}

static int NextPrime(int N)
{
    int i;

    if (N % 2 == 0)
        N++;
    for (; ; N += 2)
    {
        for (i = 3; i * i <= N; i += 2)
            if (N % i == 0)
                goto ContOuter;  /* Sorry about this! */
        return N;
    ContOuter:;
    }
}

struct ListNode {
    ElementType Element;
    Position Next;
};
typedef Position List;
struct HashTbl {
    int TableSize;
    List *TheLists;
};
HashTable InitializeTable(int TableSize) {
    HashTable H;
    int i;
    if (TableSize < MinTableSize) {
        Error("Table size to small");
        return NULL;
    }
    H = malloc(sizeof(struct HashTbl));
    if (H == NULL) {
        FatalError("Out of space");
    }
    H->TableSize = NextPrime(TableSize);
    H->TheLists = malloc(sizeof(List) * H->TableSize);
    if (H->TheLists == NULL) {
        FatalError("Out of space");
    }
    for (i = 0; i < H->TableSize; i++) {
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if (H->TheLists[i] == NULL)
            FatalError("Out of space");
        else
            H->TheLists[i] = NULL;
    }
    return H;
 }
Position Find(ElementType Key, HashTable H) {
    Position P;
    List L;
    L = H->TheLists[Hash(Key, H->TableSize)];
    P = L->Next;
    while (P != NULL && P->Element != Key)
        P = P->Next;
    return P;
}
void Insert(ElementType Key, HashTable H) {
    Position Pos, NewCell;
    List L;

    Pos = Find(Key, H);
    if (Pos == NULL) {
        NewCell = malloc(sizeof(struct ListNode ));
        if (NewCell == NULL) 
            FatalError("Out of space");
        else {
            L = H->TheLists[Hash(Key, H->TableSize)];
            NewCell->Next = L->Next;
            NewCell->Element = Key;
            L->Next = NewCell;
        }

    }
}

