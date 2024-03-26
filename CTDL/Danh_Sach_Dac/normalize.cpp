#include"AListLib.h"
void normalize(List *pL){
	Position Q, p = 1;
	while(p != pL->Last+1){
		Q = p + 1;
		while(Q != pL->Last+1){
			if(pL->Elements[Q-1] == pL->Elements[p-1]){
				Delete_List(Q, pL);
			}
			else Q = Q + 1;
		}
		p = p + 1;
	}
}
int main(){
	List L;
    int i;
    L.Last = 6;
    L.Elements[0] = 0;
    L.Elements[1] = 14;
    L.Elements[2] = 10;
    L.Elements[3] = -100;
    L.Elements[4] = 14;
    L.Elements[5] = 14;
    normalize(&L);
    for(i=0;i<L.Last;i++)
    {
        printf("%d ",L.Elements[i]);
    }
	return 0;
}
