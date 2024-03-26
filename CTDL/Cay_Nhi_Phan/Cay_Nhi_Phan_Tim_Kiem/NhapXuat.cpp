#include"BTree.h"
void readTree(Tree *T){
	KeyType x;
	int n;
	printf("\nNhap so luong node : ");
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		Insert_Node(x, &(*T));
	}
}
int main(){
	Tree T;
	MakeNull_Tree(&T);
	readTree(&T);
	LNR(T);
	return 0;
}
