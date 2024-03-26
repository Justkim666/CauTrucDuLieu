#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char ID[10];
	char Name[50];
	float R1, R2, R3;
}Student;
typedef Student ElementType;
struct Node{
	ElementType Element;
	struct Node* Next;
};
typedef struct Node* Position;
typedef Position List;

//Ham getList() - tra ve mot danh sach rong
List getList(){
	List L = (struct Node*)malloc(sizeof(struct Node));
	L->Next = NULL;
	return L;
}

//Ham locate() - tra ve vi tri xuat hien dau tien cua ma so ID trong danh sach L
struct Node* locate(char ID[], List L){
	Position p = L;
	while(p->Next != NULL){
		if(strcmp(p->Next->Element.ID, ID) == 0){
			break;
		}
		p = p->Next;
	}
	return p;
}

//Ham member() - Kiem tra thanh vien cua Student
int member(char ID[], List L){
	Position p = L;
	while(p->Next != NULL){
		if(strcmp(p->Next->Element.ID, ID) == 0){
			return 1;
		}
		p = p->Next;
	}
	return 0;
}

/* Ham append() - Neu chua co sinh vien => noi vao cuoi va tra ve 0
                - nguoc lai => tra ve 1 va ko noi bat ki sinh vien nao  */
void append(Student s, List *pL){
	Position p = (*pL), T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = s;
	while(p->Next != NULL){
		p = p->Next;
	}
	p->Next = T;
	T->Next = NULL;
}

//Ham insert() - Them student vao vi tri p
void insert(Student s, Position p, List *L){
	Position T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = s;
	T->Next = p->Next;
	p->Next = T;
}
void Delete_linedown(char x[]){
	int len = strlen(x);
	if(x[len-1] = '\n'){
		x[len-1] = '\0';
	}
}

//Ham Read_List() - Nhap danh sach Student
void Read_List(List *L){
	(*L) = getList();
	Position p = (*L);
	ElementType s;
	int n;
	printf("\nNhap so luong Student : ");
	scanf("%d", &n); // du \n
	for(int i = 0; i < n; i++){
		printf("\nNhap thong tin Student thu %d", i+1);
		printf("\nNhap ID : ");
		getchar;
		scanf("%s", s.ID); printf("\nNhap Ten : "); // du\n
		getchar();
		fgets(s.Name, sizeof(s.Name), stdin); //xoa \n
		Delete_linedown(s.Name);
		printf("\nNhap diem R1 : "); scanf("%f", &s.R1);
		printf("\nNhap diem R2 : "); scanf("%f", &s.R2);
		printf("\nNhap diem R3 : "); scanf("%f", &s.R3);
		if(member(s.ID, *L) == 0){
			append(s, L);
		}
	}
}

//Ham Print_List() - Hien thi Student
void Print_List(List L){
	Position p = L;
	int i = 1;
	while(p->Next != NULL){
		printf("\n%d - %s - %s - %.3f - %.3f - %.3f", i, p->Next->Element.ID,p->Next->Element.Name,
		p->Next->Element.R1, p->Next->Element.R2, p->Next->Element.R3);
		i++;
		p = p->Next;
	}
}
