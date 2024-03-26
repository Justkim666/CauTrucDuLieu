#include"DSLK.h"
List readSet(){
	List L;
	MakeNull_List(&L);
	ElementType x;
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		if(member(x, L) == 0){
			addFirst(x, &L);
		}
	}
	return L;
}
int main(){
	List L;
    Position p;
    L = readSet();
    p=L;
    while(p->Next!=NULL)
    {
		printf("%d ",p->Next->Element);
		p=p->Next;
    }
    return 0;
}
