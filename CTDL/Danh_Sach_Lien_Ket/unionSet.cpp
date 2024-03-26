#include"DSLK.h"
List unionSet(List L1, List L2){
	List L;
	MakeNull_List(&L);
	Position p1 = L1, p2 = L2;
	while(p1->Next != NULL){
		append(p1->Next->Element, &L);
		p1 = p1->Next;
	}
	while(p2->Next != NULL){
		if(member(p2->Next->Element, L) == 0){
			append(p2->Next->Element, &L);
		}
		p2 = p2->Next;
	}
	return L;
}
int main(){
	List L1,L2,L;
    int i;
	
    Position p;
    MakeNull_List(&L1);
    MakeNull_List(&L2);
    for(i=1;i<=3;i++)
	    append(i, &L1);
    for(i=2;i<=5;i++)
	    append(i, &L2);
    L = unionSet(L1,L2);
    p=L;
    while(p->Next!=NULL)
    {
		printf("%d ",p->Next->Element);
		p=p->Next;
    }
	return 0;
}
