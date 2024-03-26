#include"AListLib.h"
void removeAll(ElementType x, List *pL){
	Position p = Locate(x, *pL);
	while(p <= pL->Last){
		Delete_List(p, pL);
		p = Locate(x, *pL);
	}
}
int main(){
	List L;
	ElementType x;
	Read_List(&L);
	Print_List(L);
	scanf("%d", &x);
	removeAll(x, &L);
	Print_List(L);
}
