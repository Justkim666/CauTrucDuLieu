#include"AListLib.h"
void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
void sort(List *pL){
	for(int i = 0; i < pL->Last-1; i++){
		for(int j = i+1; j < pL->Last; j++){
			if(pL->Elements[i] > pL->Elements[j]){
				swap(&pL->Elements[i], &pL->Elements[j]);
			}
		}
	}
}
int main(){
	List L;
	Read_List(&L);
	Print_List(L);
	sort(&L);
	Print_List(L);
	return 0;
}
