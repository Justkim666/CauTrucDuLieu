#include"DaThuc.h"
DaThuc DaoHam(DaThuc d){
	DaThuc T = khoitao();
	Position p = d;
	while(p->Next != NULL){
		p->Next->Element.heso *= p->Next->Element.bac;
		p->Next->Element.bac -= 1;
		if(p->Next->Element.bac >= 0){
			ChenDonThuc(p->Next->Element, &T);
		}
		p = p->Next;
	}
	return T;
}
int main(){
	DaThuc d, d_daoham;
	d = read();
	print(d);
	printf("\nDao ham cau ham so la\n");
	d_daoham = DaoHam(d);
	print(d_daoham);
	return 0;
}
