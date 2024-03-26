#include"AListLib.h"
float getAvg(List L){
	float s;
	for(int i = 0; i < L.Last; i++){
		s += L.Elements[i];
	}
	return s / L.Last;
}
int main(){
	List L;
	float result;
	Read_List(&L);
	Print_List(L);
	result = getAvg(L);
	printf("%.3f", result);
	return 0;
}
