#include"AListLib.h"
void printOddNumbers(List L){
	for(int i = 0; i < L.Last; i++){
		if(L.Elements[i] % 2 != 0){
			printf("%d ", L.Elements[i]);
		}
	}
}
int main(){
	List L;
    int i;
    L.Last=0;
    for(i=0;i<5;i++)
    {
       L.Elements[i] = i;
    }
    L.Last=5;
    printOddNumbers(L);
	return 0;
}
