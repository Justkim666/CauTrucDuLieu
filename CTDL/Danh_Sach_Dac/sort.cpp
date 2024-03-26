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
    int i;
    L.Last = 0;
    for(i=5;i>=1;i--){
        L.Elements[5-i] = 2*i;
    }
    L.Last = 5;
    sort(&L);

    for(i=0;i<L.Last;i++){
        printf("%d ",L.Elements[i]);
    }
	return 0;
}
