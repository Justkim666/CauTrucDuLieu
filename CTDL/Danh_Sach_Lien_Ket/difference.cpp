#include"DSLK.h"
List difference(List L1, List L2){
	List L;
	MakeNull_List(&L);
	Position p1 = L1;
	while(p1->Next != NULL){
		p1 = p1->Next;
		if(member(p1->Element, L2) == 0){
			append(p1->Element, &L);
		}
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
    L = difference(L1,L2);
    p=L;
    while(p->Next!=NULL)
    {
        printf("%d ",p->Next->Element);
        p=p->Next;
    }
	return 0;
}
