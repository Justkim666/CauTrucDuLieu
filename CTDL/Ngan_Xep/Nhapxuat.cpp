#include"NganXep.h"
void print_Stack1(Stack *pS)
{
    int p = pS->Top_idx;
    while(p != MaxLength)
    {
        printf("%d ", pS->Elements[p]);
        pS->Top_idx++;
        p = p + 1;
    }
}
int main(){
	Stack S;
	read_Stack(&S);
	print_Stack1(&S);
	return 0;
}
