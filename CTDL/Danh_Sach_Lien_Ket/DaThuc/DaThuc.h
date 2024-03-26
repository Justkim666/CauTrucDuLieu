#include<stdio.h>
#include<stdlib.h>
//khai bao
typedef struct{
	float heso;
	int bac;
}DonThuc;
typedef DonThuc ElementType;
struct Node{
	ElementType Element;
	struct Node* Next;
};
typedef struct Node* Position;
typedef Position DaThuc;
//lam rong
DaThuc khoitao(){
	DaThuc d;
	d = (struct Node*)malloc(sizeof(struct Node));
	d->Next = NULL;
	return d;
}
//chen don thuc
void ChenDonThuc(ElementType s, DaThuc *pD){
	Position p = (*pD), T;
	T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = s;
	int found = 0;
	while(p->Next != NULL && found == 0){
		if(s.bac == p->Next->Element.bac){
			p->Next->Element.heso += s.heso;
			found = 1;
		}
		else if(s.bac > p->Next->Element.bac){
			T->Next = p->Next;
	        p->Next = T;
	        found = 1;
		}
		else p = p->Next;
	}
	if(found == 0){ // chay den vi tri cuoi cung
		T->Next = p->Next;
	    p->Next = T;
	}
}
//read Dathuc
DaThuc read(){
	DaThuc d;
	d = khoitao();
	ElementType s;
	int n;
	printf("\nNhap so luong don thuc : ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%f", &s.heso);
		scanf("%d", &s.bac);
		ChenDonThuc(s, &d);
	}
	return d;
}
//print Dathuc
void print(DaThuc d){
	Position p = d;
	if(p->Next->Element.bac == 0){
		printf("1");
	}
	else if(p->Next->Element.bac > 0){
		printf("%.3fX^%d ", p->Next->Element.heso, p->Next->Element.bac);
	}
	p = p->Next;
	while(p->Next != NULL){
		if(p->Next->Element.heso < 0){
			p->Next->Element.heso *= -1;
			printf(" - ");
		}
		else printf(" + ");
		if(p->Next->Element.bac == 0){
			printf("1");
		}
		else if(p->Next->Element.bac > 0){
			printf("%.3fX^%d ", p->Next->Element.heso, p->Next->Element.bac);
		}
		p = p->Next;
	}
}
