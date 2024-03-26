#include"DSLK.h"
void normalize(List *pL){
	Position p = (*pL), Q;
	while(p->Next != NULL){
		Q = p->Next;
		while(Q->Next != NULL){
			if(Q->Next->Element == p->Next->Element){
				Delete_List(Q, pL);
			}
			else
			Q = Q->Next;
		}
		p = p->Next;
	}
}
int main(){
    List L;
    Position p;
		
    L=(struct Node*)malloc(sizeof(struct Node));	
    L->Next=NULL;
	
    append(1, &L);
    append(1, &L);
    append(1, &L);

	
    normalize(&L);
    p=L;
    while(p->Next!=NULL)
   {
		printf("%d ",p->Next->Element);
		p=p->Next;
    }
	return 0;
}
