#include"NganXep.h"
void binary(ElementType x){
	Stack S;
	MakeNull_Stack(&S);
	int r;
	while(x/2 != 0){
		r = x % 2;
		Push(r, &S);
		x = x/2;
	}
	r = x % 2;
	Push(r, &S);
	print_Stack(&S);
}
int main(){
	ElementType x;
	scanf("%d", &x);
	binary(x);
	return 0;
}
