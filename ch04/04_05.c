#include<stdio.h>
#include<stdlib.h>

float coef;
typedef struct ListNode{
   float coef;
   int expo;
   struct ListNode* link;
}ListNode;

typedef struct ListHead{
    ListNode* head;
}ListHead;

ListHead* createLinkedList(void){
    ListHead* L;
    L = (ListHead*)malloc(sizeof(ListHead));
    L -> head = NULL;
    return L;
}

void appenTerm(ListHead* L, float coef, int expo){
    ListNode* newNode;
    ListNode* p;
    newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode -> coef = coef;
    newNode -> expo = expo;
    newNode -> link = NULL;

    if(L -> head == NULL){
        L -> head = newNode;
        return;
    }else{
        p = L -> head;
        while (p -> link != NULL){
            p = p -> link;
        }
        p -> link = newNode;
    }
}

void addPoly(ListHead* A, ListHead* B, ListHead* C){
    ListNode* pA = A -> head;
    ListNode* pB = B -> head;
    float sum;

    while(pA && pB){
        if(pA -> expo == pB -> expo){
            sum = pA -> coef + pB -> coef;
            appenTerm(C, sum, pA -> expo);
            pA = pA -> link; 
            pB = pB -> link;
        }else if(pA -> expo > pB -> expo){
            appenTerm(C, pA -> coef, pA -> expo);
            pA = pA -> link;
        }else{
            appenTerm(C, pB -> coef, pB -> expo);
            pB = pB -> link;
        }
    }

    for(;pA != NULL; pA = pA -> link){
        appenTerm(C, pA -> coef, pA -> expo);
    }

    for(;pB != NULL; pB = pB -> link){
        appenTerm(C, pB -> coef, pB -> expo);
    }
}

void printPoly(ListHead* L){
    ListNode* p = L -> head;
    for(; p; p = p -> link){
        printf("%3.0fx^%d", p -> coef, p -> expo);
        if( p -> link != NULL){
            printf(" +");
        }
    }
}

int main(void){
    ListHead *A, *B, *C;

    A = createLinkedList();
    B = createLinkedList();
    C = createLinkedList();

    appenTerm(A, 4, 3);
    appenTerm(A, 3, 2);
    appenTerm(A, 5, 1);
    printf("\n A(x) =");
    printPoly(A);

    appenTerm(B, 3, 4);
    appenTerm(B, 1, 3);
    appenTerm(B, 2, 1);
    appenTerm(B, 1, 0);
    printf("\n B(x) =");
    printPoly(B);

    addPoly(A, B, C);
    printf("\n C(x) =");
    printPoly(C);

    getchar();
}