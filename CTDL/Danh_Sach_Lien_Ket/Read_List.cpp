#include"DSLK.h"
void read_List(List *L){
	MakeNull_List(L);
	int n;
	ElementType x;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		append(x, L);
	}
}
int main(){
	List L;
    Position p;
    Read_List(&L);
    p=L;
    while(p->Next!=NULL)
    {
       printf("%d ",p->Next->Element);
       p=p->Next;
    }
	return 0;
}
