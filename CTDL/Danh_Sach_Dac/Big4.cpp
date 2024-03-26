#include"AListLib.h"
void readList_(List *pL){
	MakeNull_List(pL);
	int n;
	ElementType x;
	printf("\nNhap so phan tu : ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		if(member(x, *pL) == 0){
			InsertSet(x, pL);
		}
	}
}
void Union(List L1, List L2, List *pL){
	MakeNull_List(pL);
	for(int i = 0; i < L1.Last; i++){
		InsertSet(L1.Elements[i], pL);
	}
	for(int j = 0; j < L2.Last; j++){
		if(member(L2.Elements[j], *pL) == 0){
			InsertSet(L2.Elements[j], pL);
		}
	}
}
int main(){
	List L1, L2, L;
	MakeNull_List(&L1);
	MakeNull_List(&L2);
	readList_(&L1);
	readList_(&L2);
	Print_List(L1); printf("\n");
	Print_List(L2); printf("\n");
	Union(L1, L2, &L);
	Print_List(L);
	return 0;
}
