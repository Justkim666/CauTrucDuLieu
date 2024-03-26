#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
struct Node{
  ElementType Element;
  struct Node* Next;
};
typedef struct Node* Position;
typedef Position List;

void MakeNull_List(List *L){
	(*L) = (struct Node*)malloc(sizeof(struct Node));
	(*L)->Next = NULL;
}

void append(ElementType x, List *L){
    Position p = (*L), T = (struct Node*)malloc(sizeof(struct Node));
    T->Element = x;
    while(p->Next != NULL){
        p = p->Next;
    }
    p->Next = T;
    T->Next = NULL;
}

void Read_List(List *L){
    MakeNull_List(L);
    ElementType x;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        append(x, L);
    }
}

void Print_List(List L){
    Position p = L;
    while(p->Next != NULL){
        printf("%d ", p->Next->Element);
        p = p->Next;
    }
}

List odd(List L){
    List L_odd;
    MakeNull_List(&L_odd);
    Position p = L;
    while(p->Next != NULL){
        if(p->Next->Element % 2 == 0){
            append(p->Next->Element, &L_odd);
        }
        p = p->Next;
    }
    return L_odd;
}

float getAvg(List L){
    float s = 0;
    int n = 0;
    Position p = L;
    while(p->Next != NULL){
        s += p->Next->Element;
        n++;
        p = p->Next;
    }
    return s/n;
}

int main(){
    List L, L_odd;
    Read_List(&L);
    Print_List(L);
    L_odd = odd(L);
    printf("\n");
    Print_List(L_odd);
    printf("\n");
    printf("%.3f", getAvg(L_odd));
    return 0;
}
