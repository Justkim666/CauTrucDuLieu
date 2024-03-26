#include<stdio.h>
#define MaxLength 500
//khai bao cau truc hang doi
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
	return Q.Rear - Q.Front+1 == MaxLength;
}
//them phan tu vao hang
void EnQueue(ElementType x, Queue *pQ){
	if(!Full_Queue(*pQ)){
		if(Empty_Queue(*pQ)){
			pQ->Front = 0;
		}
		if(pQ->Rear == MaxLength-1){
			//di chuyen tinh tien ra truoc front -1 vi tri
			for(int i = pQ->Front; i <= pQ->Rear; i++){
				pQ->Elements[i-pQ->Front] = pQ->Elements[i];
			}
			//xac dinh vi tri rear va front moi
			pQ->Rear = MaxLength - pQ->Front-1;
			pQ->Front = 0;
		}
		//tang rear de luu noi dung moi
		pQ->Rear = pQ->Rear+1;
		pQ->Elements[pQ->Rear] = x;
	}
	else printf("Loi: Hang day!");
}
//xoa phan tu ra khoi hang
void DeQueue(Queue *pQ){
	if(!Empty_Queue(*pQ)){
		pQ->Front = pQ->Front+1;
		if(pQ->Front > pQ->Rear){
			MakeNull_Queue(pQ);
		}
	}
	else printf("Loi: Hang rong!");
}
//lay noi dung tai vi tri tai vi tri dau hang
ElementType Front(Queue Q){
	return Q.Elements[Q.Front];
}
//nhap du lieu cho hang
void ReadQueue(Queue *pQ){
	MakeNull_Queue(pQ);
	ElementType x;
	int n;
	printf("\nNhap so luong phan tu cua hang : ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		printf("\nNhap phan tu thu %d : ", i+1);
		scanf("%d", &x);
		EnQueue(x, pQ);
	}
}
//hien thi hang
void PrintQueue(Queue Q){
	while(!Empty_Queue(Q)){
		printf("%d ", Front(Q));
		DeQueue(&Q);
	}
	printf("\n");
}
