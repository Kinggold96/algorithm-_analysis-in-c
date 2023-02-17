#include "binomial_tree.h"
#define MaxTrees 128
typedef Position BinTree;
typedef struct BinNode* Position;
typedef struct Collection* BinQueue;
struct BinNode
{
	ElementType Element;
	Position LeftChild;
	Position NextSibling;
};
struct Collection
{
	int CurrentSize;
	BinTree TheTrees[MaxTrees];
};
/*合并二项堆*/
BinTree CombineTrees(BinTree T1, BinTree T2) {

	if (T1->Element > T2->Element)
		return CombineTrees(T2, T1);
	T2->NextSibling = T1->LeftChild;
	T1->LeftChild = T2;
	return T1;
}

/* 合并优先队列*/
BinQueue
Merge(BinQueue H1, BinQueue H2) {
	BinTree T1, T2, Carry = NULL;

}