#include<stdio.h>
#define MaxLength 100
//khai bao cau truc ngan xep
typedef int ElementType;
typedef struct{
	ElementType Elements[MaxLength];
	int Top_idx;
}Stack;
//tao ngan xep rong
void MakeNull_Stack(Stack *S){
	S->Top_idx = MaxLength;
}
//kiem tra ngan xep rong
int Empty_Stack(Stack S){
	return S.Top_idx == MaxLength;
}
//kiem tra ngan xep day
int Full_Stack(Stack S){
	return S.Top_idx == 0;
}
//lay noi dung tai phan tu dinh
ElementType Top(Stack S){
	if(!Empty_Stack(S)){
		return S.Elements[S.Top_idx];
	}
	else printf("\nNgan xep rong!");
}
//xoa phan tu ra khoi ngan xep
void Pop(Stack *S){
	if(!Empty_Stack(*S)){
		S->Top_idx += 1;
	}
	else printf("\nNgan xep rong!");
}
//them phan tu vao ngan xep
void Push(ElementType x, Stack *S){
	if(!Full_Stack(*S)){
		S->Top_idx -= 1;
		S->Elements[S->Top_idx] = x;
	}
	else printf("\nNgan xep day!");
}
//nhap ngan xep
void read_Stack(Stack *S){
	MakeNull_Stack(S);
	ElementType x;
	int n;
	printf("\nNhap so phan tu cua ngan xep : ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		printf("\nNhap phan tu thu %d : ", i+1);
		scanf("%d", &x);
		Push(x, S);
	}
}
//hien thi ngan xep
void print_Stack(Stack *pS)
{
    int p = pS->Top_idx;
    while(p != MaxLength)
    {
        printf("%d ", pS->Elements[p]);
        pS->Top_idx++;
        p = p + 1;
    }
}
