#include"HangDoi.h"
int NumberofQueue(Queue Q){
	int count = 0;
	if(!Empty_Queue(Q)){
		for(int i = Q.Front; i <= Q.Rear; i++){
			count++;
		}
	}
	return count;
}
int main(){
	Queue Q;
	MakeNull_Queue(&Q);
	char c;
	ElementType x;
	int n;
	printf("\nNhap so thao tac tren hang doi Q : ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		getchar();
		scanf("%c", &c);
		if(c == 69){ //c = E
			scanf("%d", &x);
			EnQueue(x, &Q);
			printf("%d\n", NumberofQueue(Q));
		}
		if(c == 68){ // c = D
			if(Empty_Queue(Q)){
				printf("-1 ");
			}
			else printf("%d ", Front(Q));
			DeQueue(&Q);
			printf("%d\n", NumberofQueue(Q));
		}
	}
	return 0;
}
