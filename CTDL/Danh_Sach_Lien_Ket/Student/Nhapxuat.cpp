#include"Student.h"
void Showpassed(List L){
	float s;
	int n = 0;
	int i = 1;
	Position p = L;
	while(p->Next != NULL){
		s = (p->Next->Element.R1 + p->Next->Element.R2 + p->Next->Element.R3)/3;
		if(s >= 4.0){
			printf("\n%d - %s - %s - %.3f - %.3f - %.3f - %.3f", i, p->Next->Element.ID,p->Next->Element.Name,
		    p->Next->Element.R1, p->Next->Element.R2, p->Next->Element.R3, s);
		    i++;
		    n++;
		    p = p->Next;
		}
	}
	printf("\n%d students in total", n);
}
int main(){
	List L;
	Read_List(&L);
	Print_List(L); printf("\n");
	Showpassed(L);
	return 0;
}
