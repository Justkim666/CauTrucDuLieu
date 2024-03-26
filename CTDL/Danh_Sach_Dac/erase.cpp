#include"AListLib.h"
void erase(ElementType x, List *pL){
	Position p = Locate(x, *pL);
	Delete_List(p, pL);
}
int main(){
	List L;
    int i;
    L.Last=0;
    for(i=0;i<10;i++)
    {  L.Elements[i] = 2*i;}
    L.Last=10;
    erase(0,&L);
    for(i=0;i<L.Last;i++)
    { printf("%d ",L.Elements[i]);}
	return 0;
}
