#include"DSLK.h"
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
int main(){
	List L;
    Position p;
    L=(struct Node*)malloc(sizeof(struct Node));	
    L->Next=NULL;
	
    append(1, &L);
    append(5, &L);
    append(10, &L);
    append(-10, &L);	
    p=L;
    while(p->Next!=NULL)
    {
	    printf("%d ",p->Next->Element);
	    p=p->Next;
    }
    printf("\n");
	return 0;
}
