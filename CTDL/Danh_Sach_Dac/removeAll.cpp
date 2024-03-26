#include"AListLib.h"
void removeAll(ElementType x, List *pL){
	Position p = Locate(x, *pL);
	while(p <= pL->Last){
		Delete_List(p, pL);
		p = Locate(x, *pL);
	}
}
int main(){
	List L;
    int i;
    L.Last=0;
    for(i=0;i<5;i++)
    {  L.Elements[i] = 2*i;}
    L.Last=5;
    removeAll(0,&L);
    for(i=0;i<L.Last;i++)
    {    printf("%d ",L.Elements[i]);}
	return 0;
}
