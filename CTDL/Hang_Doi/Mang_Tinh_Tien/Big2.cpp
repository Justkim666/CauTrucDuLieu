#include"HangDoi.h"
int Timeforwork(Queue Q1, Queue Q2)
{
	int Time = 0;
	ElementType p1 = Front(Q1), p2 = Front(Q2);
	while(!Empty_Queue(Q1)){
		if(p1 == p2){
			DeQueue(&Q1);
			DeQueue(&Q2);
			p1 = Front(Q1);
			p2 = Front(Q2);
			Time++;
		}
		else{
			EnQueue(p1, &Q1);
			DeQueue(&Q1);
			p1 = Front(Q1);
			Time++;
		}
	}
	return Time;
}
int main(){
	Queue Q1, Q2;
	int n;
	MakeNull_Queue(&Q1);
	MakeNull_Queue(&Q2);
	printf("\nNhap so luong cong viec duoc giao : ");
	scanf("%d", &n);
	printf("\nNhap cong viec duoc giao");
	ReadQueue(&Q1);
	printf("\nNhap thu tu uu tien cua cong viec");
	ReadQueue(&Q2);
	printf("\nThoi gian can de thuc hien cong viec theo do uu tien la : %d", Timeforwork(Q1, Q2));
	return 0;
}
