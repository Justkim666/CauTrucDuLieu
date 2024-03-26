#include"AListLib.h"
void get(List L, List *odd, List *even){
	MakeNull_List(odd);
	MakeNull_List(even);
	for(int i = 0; i < L.Last; i++){
		if(L.Elements[i] % 2 == 0){
			InsertSet(L.Elements[i], even);
		}
		else InsertSet(L.Elements[i], odd);
	}
}
int main(){
	List L, odd, even;
	Read_List(&L);
	Print_List(L); printf("\n");
	get(L, &odd, &even);
	Print_List(odd); printf("\n");
	Print_List(even);
	return 0;
}
