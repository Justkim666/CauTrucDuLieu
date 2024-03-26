#include"AListLib.h"
float getAvg(List L){
	float tong = 0;
	for(int i = 0; i < L.Last; i++){
		tong += L.Elements[i];
	}
	return tong / L.Last;
}
int main(){
	
	List L;
    int i;
    L.Last=0;
    for(i=0;i<5;i++)
        L.Elements[i] = i+1;
    L.Last=5;
    printf("AVG = %.4f\n", getAvg(L));
}
