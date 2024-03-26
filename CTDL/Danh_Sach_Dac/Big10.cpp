#include"AListLib.h"
void difference(List L1, List L2, List *pL){
	MakeNull_List(pL);
	for(int i = 0; i < L1.Last; i++){
		if(member(L1.Elements[i], L2) == 0){
			InsertSet(L1.Elements[i], pL);
		}
	}
}
int main(){
	List L, L1, L2;
	MakeNull_List(&L1);
	MakeNull_List(&L2);
	Read_List(&L1);
	Read_List(&L2);
	Print_List(L1); printf("\n");
	Print_List(L2); printf("\n");
	difference(L1, L2, &L);
	Print_List(L);
	return 0;
}
