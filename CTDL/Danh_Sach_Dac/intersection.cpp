#include"AListLib.h"
void intersection(List L1, List L2, List *pL){
	MakeNull_List(pL);
	ElementType x;
	for(int i = 0; i < L1.Last; i++){
		x = L1.Elements[i];
		if(member(x, L2) == 1 && member(x, *pL) == 0){
			InsertSet(x, pL);
		}
	}
}
int main(){
    List L1,L2,L;
    int i;

    MakeNull_List(&L1);
    MakeNull_List(&L2);

    for(i=0;i<=5;i++){
        InsertSet(2*i, &L1);
    }
    for(i=4;i<=8;i++){
        InsertSet(2*i, &L2);
    }

    for(i=0;i<L1.Last;i++){
        printf("%d ",L1.Elements[i]);
    }
    printf("\n");
    for(i=0;i<L2.Last;i++){
        printf("%d ",L2.Elements[i]);
    }
    printf("\n");
    intersection(L1,L2,&L);
    for(i=0;i<L.Last;i++){
         printf("%d ",L.Elements[i]);
    }
	return 0;
}
