#include<stdio.h>
#include<stdlib.h>
//khai bao cay nhi phan
typedef int DataType;
struct Node{
	DataType Data;
	struct Node* Left;
	struct Node* Right;
};
typedef struct Node* Tree;
//tao cay rong
void MakeNull_Tree(Tree *T){
	T = NULL;
}
//kiem tra cay rong
int Empty_Tree(Tree T){
	return T == NULL;
}
//xac dinh cay con trai cua 1 nut
Tree Left_Child(Tree T){
	if(T != NULL){
		return T->Left;
	}
	else return NULL;
}
//xac dinh cay con phai cua 1 nut
Tree Right_Child(Tree T){
	if(T != NULL){
		return T->Right;
	}
	else return NULL;
}
//kiem tra nut la
int isLeaf(Tree T){
	if(T != NULL){
		return (T->Left == NULL && T->Right == NULL);
	}
	else return 0;
}
//xac dinh so nut cua cay
int Number_node(Tree T){
	if(!Empty_Tree(T)){
		return 1 + Number_node(T->Left) + Number_node(T->Right);
	}
	else return 0;
}
//tao cay moi tu 2 cay co san
Tree Create2(DataType v, Tree l, Tree r){
	Tree N;
	N = (struct Node*)malloc(sizeof(struct Node));
	N->Data = v;
	N->Left = l;
	N->Right = r;
	return N;
}
//duyet tien tu
void PreOrder(Tree T){
	if(T != NULL){
		printf("%d ", T->Data);
		PreOrder(T->Left);
		PreOrder(T->Right);
	}
}
//duyet trung tu
void InOrder(Tree T){
	if(T != NULL){
		InOrder(T->Left);
		printf("%d ", T->Data);
		InOrder(T->Right);
	}
}
//duyet hau tu
void PosOrder(Tree T){
	if(T != NULL){
		PosOrder(T->Left);
		PosOrder(T->Right);
		printf("%d ", T->Data);
	}
}























