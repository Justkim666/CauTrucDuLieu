#include"DaThuc.h"
void CongDaThuc(DaThuc d1, DaThuc d2, DaThuc *pD){
	(*pD) = khoitao();
	Position p1 = d1, p2 = d2;
	while(p1->Next != NULL){
		ChenDonThuc(p1->Next->Element, pD);
		p1 = p1->Next;
	}
	while(p2->Next != NULL){
		ChenDonThuc(p2->Next->Element, pD);
		p2 = p2->Next;
	}
}
int main(){
	DaThuc d1, d2, d;
	d1 = read(); 
	d2 = read();
	CongDaThuc(d1, d2, &d);
	printf("  "); print(d1); printf("\n");
	printf("+\n");
    printf("  "); print(d2); printf("\n");
	printf("___________________________________________"); printf("\n\n");
	printf("  "); print(d);
	return 0;
}
