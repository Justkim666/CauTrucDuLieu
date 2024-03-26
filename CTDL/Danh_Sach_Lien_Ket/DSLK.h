#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MaxLength 100

/* ========== Khai bao danh lien ket ==========*/
typedef int ElementType;
struct Node{
	ElementType Element;
	struct Node* Next;
};
typedef struct Node* Position;
typedef Position List;
/* ========== Ket thuc khai bao ==========*/

//Tao dslk rong
void MakeNull_List(List *Header){
	(*Header) = (struct Node*)malloc(sizeof(struct Node));
	(*Header)->Next = NULL;
}

//Kiem tra dslk rong
int Empty_List(List L){
	return L->Next == NULL;
}

//Xen 1 phan tu vao trong dslk
void Insert_List(ElementType x, Position P, List *L){
	Position T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = x;
	T->Next = P->Next;
	P->Next = T;
}

//Xoa phan tu ra khoi dslk
void Delete_List(Position p, List *L){
	Position T;
	if(p->Next != NULL){
		T = p->Next;
		p->Next = T->Next;
		free(T);
	}
}

//Dinh vi 1 phan tu trong dslk
Position Locate(ElementType x, List L){
	Position p = L;
	while(p->Next != NULL){
		if(p->Next->Element == x){
			break;
		}
	}
	return p;
}

//Lay gia tri cua phan tu
ElementType Retrieve(Position p, List L){
	if(p->Next != NULL){
		return p->Next->Element;
	}
	else return NULL;
}

//Ham member
int member(ElementType x, List L){
	Position p = L; // dat p de duyet
	while(p->Next != NULL){
		if(p->Next->Element == x){
			return 1;
		}
		else p = p->Next;
	}
	return 0;
}

//Ham append
void append(ElementType x, List *L){
	Position p, T;
	p = (*L);
	T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = x;
	while(p->Next != NULL){
		p = p->Next;
	}
	p->Next = T;
	T->Next = NULL;
}

//Ham Read_List
void Read_List(List *L){
	MakeNull_List(L);
	ElementType x;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		append(x, L);
	}
}

//Ham addFirst
void addFirst(ElementType x, List *L){
	Position p, T;
	p = (*L);
	T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = x;
	T->Next = p->Next;
	p->Next = T;
}
