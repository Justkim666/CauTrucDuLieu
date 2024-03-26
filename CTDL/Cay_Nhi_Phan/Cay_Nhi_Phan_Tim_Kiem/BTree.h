#include<stdio.h>
#include<stdlib.h>
//khai bao cay nhi phan tim kiem
typedef int KeyType;
struct Node{
	KeyType Key;
	struct Node* Left;
	struct Node* Right;
};
typedef struct Node* Tree;
//khoi tao cay TKNP rong
void MakeNull_Tree(Tree *T){
	(*T) = NULL;
}
//tim kiem mot nut co khoa x tren cay TKNP
Tree Search(KeyType x, Tree T){
	if(T != NULL){
		if(T->Key == x){
			return T;
		}
		else if(x > T->Key){
			return Search(x, T->Right);
		}
		else return Search(x, T->Left);
	}
	else return NULL;
}
//them mot nut co khoa x cho truoc vao cay TKNP
void Insert_Node(KeyType x, Tree *T){
	if((*T) == NULL){
		(*T) = (struct Node*)malloc(sizeof(struct Node));
		(*T)->Key = x;
		(*T)->Left = NULL;
		(*T)->Right = NULL;
	}
	else{
		if(x > (*T)->Key){
			Insert_Node(x, &(*T)->Right);
		}
		else if(x < (*T)->Key){
			Insert_Node(x, &(*T)->Left);
		}
	}
}
//xoa 1 node bat ki
KeyType deleteMin(Tree *T){
	KeyType k;
	if((*T)->Left == NULL){
		k = (*T)->Key;
		(*T) = (*T)->Right;
		return k;
	}
	else return deleteMin(&(*T)->Left);
}
void deleteNode(KeyType x, Tree *T){
	if((*T) != NULL){
		if(x > (*T)->Key){
			deleteNode(x, &(*T)->Right);
		}
		else if(x < (*T)->Key){
			deleteNode(x, &(*T)->Left);
		}
		else{
			if((*T)->Right == NULL && (*T)->Left == NULL){
				(*T) = NULL;
			}
			else{
				if((*T)->Left == NULL){
					(*T) = (*T)->Right;
				}
				else if((*T)->Right == NULL){
					(*T) = (*T)->Left;
				}
				else{
					(*T)->Key = deleteMin(&(*T)->Right);
				}
			}
		}
	}
}
//duyet tien tu
void preOrder(Tree T){
	if(T != NULL){
		printf("%d ", T->Key);
		NLR(T->Left);
		NLR(T->Right);
	}
}
//duyet trung tu
void inOrder(Tree T){
	if(T != NULL){
		LNR(T->Left);
		printf("%d ", T->Key);
		LNR(T->Right);
	}
}
//duyet hau tu
void posOrder(Tree T){
	if(T != NULL){
		LRN(T->Left);
		LRN(T->Right);
		printf("%d ", T->Key);
	}
}
//dem so node
int NumberofNode(Tree T){
	if(T == NULL){
		return 0;
	}
	else return 1+NumberofNode(T->Left)+NumberofNode(T->Right);
}
//tinh chieu cao cua cay
int hTree(Tree T){
	if(T != NULL){
		int left = hTree(T->Left)+1;
		int right = hTree(T->Right)+1;
		return left > right ? left : right;
	}
	else return -1;
}
//tinh chieu cao cua 1 node bat ki
int hNode(KeyType x, Tree T){
	if(T != NULL){
		if(T->Key == x){
			if(T->Left == NULL && T->Right == NULL){
				return 0;
			}
			else{
				int h = hTree(T);
				return h;
			}
		}
		else if(x < T->Key){
			return hNode(x, T->Left);
		}
		else return hNode(x, T->Right);
	}
	return -1;
}
//tim node dung truoc (duyet trung tu)
Tree Right_Most_Left(Tree T){
    Tree p = T;
    while(p->Right != NULL){
        p = p->Right;
    }
    return p;
}
Tree getPrevious(int x, Tree T){
    Tree p = T, rleft = NULL;
    while(p != NULL){
        if(p->Key == x){
            if(p->Left == NULL){
                return rleft;
            }
            else return Right_Most_Left(p->Left);
        }
        else if(x > p->Key){
            rleft = p;
            p = p->Right;
        }
        else p = p->Left;
    }
    return NULL;
}
//tim node dung sau(duyet trung tu)
Tree Left_Most_Right(Tree T){
    Tree p = T;
    while(p->Left != NULL){
        p = p->Left;
    }
    return p;
}
Tree getNext(int x, Tree T){
    Tree p = T, z = NULL;
    while(p != NULL){
        if(p->Key == x){
            if(p->Right == NULL){
                return z;
            }
            else return Left_Most_Right(p->Right);
        }
        else{
            if(x < p->Key){
                z = p;
                p = p->Left;
            }
            else p = p->Right;
        }
    }
    return NULL;
}
//tim nut cha
Tree getParent(int x, Tree T){
    Tree p = T;
    if(T->Key == x){
        return NULL;
    }
    else{
        while(p != NULL){
            if(p->Left->Key == x || p->Right->Key == x){
                return p;
            }
            else if(x < p->Key){
                p = p->Left;
            }
            else p = p->Right;
        }
    }
    return NULL;
}
//tim anh em ruot phai
Tree rightSibling(int x, Tree T){
    Tree p = T, Parent = NULL;
    if(T->Key == x){
        return NULL;
    }
    else{
        while(p != NULL){
            if(p->Key == x){
                if(Parent->Right != NULL){
                    return Parent->Right;
                }
                else return NULL;
            }
            else if(x > p->Key){
                Parent = p;
                p = p->Right;
            }
            else{
                Parent = p;
                p = p->Left;
            }
        }
    }
    return NULL;
}

// In duong di cua x
void printPath(int x, Tree T){
    Tree p = T;
    int found = 0;
    while(p != NULL){
        if(p->Key == x){
            printf("%d -> Tim thay", p->Key);
            found = 1;
            break;
        }
        else if(x > p->Key){
            printf("%d ", p->Key);
            p = p->Right;
        }
        else{
            printf("%d ",p->Key);
            p = p->Left;
        }
    }
    if(found == 0){
        printf("-> Khong thay");
    }
}











