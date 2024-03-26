#include"DSLK.h"
List intersection(List L1, List L2){
	List L;
	MakeNull_List(&L);
	Position p = L1;
	while(p->Next != NULL){
		if(member(p->Next->Element, L2) == 1){
			append(p->Next->Element, &L);
		}
		p = p->Next;
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
    for(i=-1;i<=2;i++)
	    append(i, &L2);
    L = intersection(L1,L2);
    p=L;
    while(p->Next!=NULL)
    {
	    printf("%d ",p->Next->Element);
		p=p->Next;
    } 
	return 0;
}
