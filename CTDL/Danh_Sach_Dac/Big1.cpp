#include"AListLib.h"
void Delete_x(ElementType x, List *pL){
	Position p = Locate(x, *pL);
	Delete_List(p, pL);
}
int main(){
	List L;
	int x;
	MakeNull_List(&L);
	Read_List(&L);
	Print_List(L);
	printf("\nNhap phan tu x can xoa : ");
	scanf("%d", &x);
	Delete_x(x, &L);
	printf("\nDanh sach sau khi xoa phan tu x\n");
	Print_List(L);
	return 0;
}
