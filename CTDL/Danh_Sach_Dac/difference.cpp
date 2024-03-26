#include"AListLib.h"
void insertSet(ElementType x, List *L){
	L->Elements[L->Last] = x;
	L->Last++;
}
int member(ElementType x, List L){
	for(int i = 0; i < L.Last; i++){
		if(L.Elements[i] == x){
			return 1;
		}
	}
	return 0;
}
void difference(List L1, List L2, List *pL){
	MakeNull_List(pL);
	ElementType x;
	for(int i = 0; i < L1.Last; i++){
		x = L1.Elements[i];
		if(member(x, L2) == 0 && member(x, *pL) == 0){
			insertSet(x, pL);
		}
	}
}
int main(){
	List L1,L2,L;
    int i;

    MakeNull_List(&L1);
    MakeNull_List(&L2);

    for(i=0;i<=5;i++){
        insertSet(2*i, &L1);
    }
    for(i=4;i<=8;i++){
        insertSet(2*i, &L2);
    }

    for(i=0;i<L1.Last;i++){
        printf("%d ",L1.Elements[i]);
    }
    printf("\n");
    for(i=0;i<L2.Last;i++){
        printf("%d ",L2.Elements[i]);
    }
    printf("\n");
    difference(L1,L2,&L);
    for(i=0;i<L.Last;i++){
        printf("%d ",L.Elements[i]);
    }
	return 0;
}
