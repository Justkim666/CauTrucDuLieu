#include"DaThuc.h"
void NhanDaThuc(DaThuc d1, DaThuc d2, DaThuc *pD){
	(*pD) = khoitao();
	ElementType s;
	Position p1 = d1, p2 = d2;
	while(p1->Next != NULL){
		p2 = d2;
		while(p2->Next != NULL){
			s.heso = p1->Next->Element.heso * p2->Next->Element.heso;
			s.bac = p1->Next->Element.bac + p2->Next->Element.bac;
			ChenDonThuc(s, pD);
			p2 = p2->Next;
		}
		p1 = p1->Next;
	}
}
int main(){
	DaThuc d1, d2, d;
	d1 = read();
	d2 = read();
	NhanDaThuc(d1, d2, &d);
	printf("("); print(d1); printf(")"); printf(" * "); printf("("); print(d2); printf(")");
	printf("  =  "); print(d);
	return 0;
}
