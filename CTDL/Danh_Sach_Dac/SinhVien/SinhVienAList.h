#include<stdio.h>
#include<conio.h>
#include<string.h>
#define Maxlength 40
/* ========== Khai bao danh sinh vien ==========*/
typedef struct{
	char MSSV[10];
	char HoTen[50];
	float DiemLT, DiemTH1, DiemTH2;
}SinhVien;
typedef SinhVien ElementType;
typedef int Position;
typedef struct{
	ElementType A[Maxlength];
	Position n;
}List;
/* ========== Ket thuc khai bao ==========*/

//Tao danh sach rong

void MakeNull_List(List *L){
	L->n = 0;
}

//Ham kiem tra danh sach rong

int Empty_List(List L){
	return L.n == 0;
}

//Ham kiem tra danh sach day

int Full_List(List L){
	return L.n == Maxlength;
}

//Ham tra ve vi tri phan tu dau tien trong danh sach

Position FirstList(List L){
	return 1;
}

//Ham tra ve vi tri sau phan tu cuoi trong danh sach

Position EndList(List L){
	return L.n + 1;
}

//Ham tra ve vi tri phan tu ke tiep P trong danh sach L

Position Next(Position P, List L){
	return P + 1;
}

//Ham tra ve vi tri phan tu truoc vi tri P trong danh sach L

Position Previous(Position P, List L){
	return P - 1;
}

//Ham tra ve noi dung phan tu tai vi tri P trong danh sach L

ElementType Retrieve(Position P, List L){
	return L.A[P-1];
}

//Ham kiem tra MSSV
int member(char MSSV[], List L){
	for(int i = 0; i < L.n; i++){
		if(strcmp(MSSV, L.A[i].MSSV) == 0){
			return 1;
		}
	}
	return 0;
}

//Them 1 sinh vien vao trong danh sach
void Insert_SinhVien(ElementType x, List *L){
	if(!member(x.MSSV, *L)){
		L->A[L->n] = x;
		L->n++;
	}
}
//Xoa 1 sinh vien ra khoi danh sach
void Delete_SinhVien(char MSSV[], List *L){
	Position p;
	for(int i = 0; i < L->n; i++){
		if(strcmp(MSSV, L->A[i].MSSV) == 0){
			p = i+1;
			break;
		}
	}
	for(int j = p; j < L->n; j++){
		L->A[j-1] = L->A[j];
	}
	L->n--;
}

//Ham in danh sach sinh vien
void Print_SV(List L){
	for(int i = 0; i < L.n; i++){
		printf("\n%s - %s - %.3f - %.3f - %.3f", L.A[i].MSSV, 
		L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
	}
}

//Xoa xuong dong
void Delete_linedown(char x[]){
	int len = strlen(x);
	if(x[len-1] = '\n'){
		x[len-1] = '\0';
	}
}

//Ham nhap danh sach sinh vien
void Read_SV(List *L){
	MakeNull_List(L);
	ElementType x;
	int n;
	printf("\nNhap so luong sinh vien : ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		printf("\nNhap MSSV : ");
		getchar(); scanf("%s", &x.MSSV);
		printf("\nNhap HoTen : ");
		getchar(); fgets(x.HoTen, sizeof(x.HoTen), stdin);
		Delete_linedown(x.HoTen);
		printf("\nNhap diem ly thuyet : ");
		scanf("%f", &x.DiemLT);
		printf("\nNhap diem TH1 : ");
		scanf("%f", &x.DiemTH1);
		printf("\nNhap diem TH2 : ");
		scanf("%f", &x.DiemTH2);
		Insert_SinhVien(x, L);
	}
}
