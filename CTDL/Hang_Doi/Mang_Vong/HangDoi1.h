#include<stdio.h>
#define MaxLength 10
//khai bao cau truc hang
typedef int ElementType;
typedef struct{
	ElementType Elements[MaxLength];
	int Front, Rear;
}Queue;
//tao hang rong
void MakeNull_Queue(Queue *pQ){
	pQ->Front = -1;
	pQ->Rear = -1;
}
//kiem tra hang rong
int Empty_Queue(Queue Q){
	return Q.Front == -1;
}
//kiem tra hang day
int Full_Queue(Queue Q){
	return (Q.Rear - Q.Front+1) % MaxLength == 0;
}
//xoa 1 phan tu ra khoi hang
void DeQueue(Queue *Q){
	if(!Empty_Queue(*Q)){
		//Neu hang chi co 1 phan tu
		if(Q->Front == Q->Rear){
			MakeNull_Queue(Q);
		}
		else{
			Q->Front = (Q->Front+1) % MaxLength;
		}
	}
	else printf("Loi: Hang rong!");
}
//them 1 phan tu vao hang
void EnQueue(ElementType x, Queue *Q){
	if(!Full_Queue(*Q)){
		if(Empty_Queue(*Q)){
			Q->Front = 0;
		}
		Q->Rear = (Q->Rear+1) % MaxLength;
		Q->Elements[Q->Rear] = x;
	}
	else printf("Loi: Hang day!");
}
//lay noi dung phan tu tai vi tri dau hang
ElementType Front(Queue Q){
	return Q.Elements[Q.Front];
}
//tao du lieu cho hang
void ReadQueue(Queue *Q){
	MakeNull_Queue(Q);
	ElementType x;
	int n;
	printf("\nNhap so luong phan tu cua hang : ");
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		printf("\nNhap noi dung phan tu thu %d : ", i+1);
		scanf("%d", &x);
		EnQueue(x, Q);
	}
}
//hien thi hang ra man hinh
void PrintQueue(Queue *Q){
	while(!Empty_Queue(*Q)){
		printf("%d ", Front(*Q));
		DeQueue(Q);
	}
	printf("\n");
}
