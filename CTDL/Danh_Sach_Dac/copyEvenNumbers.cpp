#include"AListLib.h"
void copyEvenNumbers(List L1, List *pL2){
	MakeNull_List(pL2);
	int j = 0;
	for(int i = 0; i < L1.Last; i++){
		if(L1.Elements[i] % 2 == 0){
			j++;
			Insert_List(L1.Elements[i], j, pL2);
		}
	}
}
int main(){
	List L1,L2;
    int i;
    MakeNull_List(&L1);
    for(i=0;i<=5;i++){
        Insert_List(i, L1.Last+1, &L1);
    }
    copyEvenNumbers(L1, &L2);
    for(i=0;i<L1.Last;i++){
        printf("%d ",L1.Elements[i]);
    }
    printf("\n");
    for(i=0;i<L2.Last;i++){
        printf("%d ",L2.Elements[i]);
    }
}
