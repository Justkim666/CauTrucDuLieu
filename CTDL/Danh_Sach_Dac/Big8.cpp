#include"AListLib.h"
void even_(List L, List *even){
	MakeNull_List(even);
	for(int i = 0; i < L.Last; i++){
		if(L.Elements[i] % 2 == 0){
			InsertSet(L.Elements[i], even);
		}
	}
}
float getAvg_(List L){
	float s;
	for(int i = 0; i < L.Last; i++){
		s += L.Elements[i];
	}
	return s / L.Last;
}
int main(){
	List L, even;
	Read_List(&L);
	Print_List(L);printf("\n");
	even_(L, &even);
	Print_List(even);printf("\n");
	printf("%.3f", getAvg_(even));
	return 0;
}
