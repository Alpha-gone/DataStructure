#include<stdio.h>
#include<stdlib.h>

typedef char element;
typedef struct DQNode{
    element data;
    struct DQNode *llink;
    struct DQNode *rlink;
}DQNode;

typedef struct{
    DQNode *front, *rear;
}DQueType;

DQueType *createDQue(){
    DQueType *DQ;
    DQ = (DQueType*)malloc(sizeof(DQueType));
    DQ -> front = NULL;
    DQ -> rear = NULL;
    return DQ;
}

int isEmpty(DQueType *DQ){
    if(DQ -> front == NULL){
        printf("\n Linked Queue is empty! \n");
        return 1;
    }else{
        return 0;
    }
}

void insertFront(DQueType *DQ, element item){
    DQNode *newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode -> data = item;
    if (DQ -> front == NULL){
        DQ -> front = newNode;
        DQ -> rear = newNode;
        newNode -> rlink = NULL;
        newNode -> llink = NULL;
    }else{
        DQ -> front -> llink = newNode;
        newNode -> rlink = DQ -> front;
        newNode -> llink = NULL;
        DQ -> front = newNode;
    }
}
void insertRear(DQueType *DQ, element item){
    DQNode *newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode -> data = item;
    if(DQ -> rear ==NULL){
        DQ -> front = newNode;
        DQ -> rear = newNode;
        newNode -> rlink = NULL;
        newNode -> llink = NULL;
    }else{
        DQ -> rear -> rlink = newNode;
        newNode -> llink = DQ -> rear;
        newNode -> rlink = NULL;
        DQ -> rear = newNode;
    }
}

element deleteFront(DQueType *DQ){
    DQNode *old =  DQ -> front;
    element item;

    if(isEmpty(DQ)){
        return 0;
    }else{
        item = old -> data;

        if(DQ -> front -> rlink == NULL){
            DQ -> front = NULL;
            DQ -> rear = NULL;
        }else{
            DQ -> front = DQ -> front -> rlink;
            DQ -> front -> llink = NULL;
        }
        free(old);
        return item;
    }
}

element deleteRear(DQueType *DQ){
    DQNode *old = DQ -> rear;
    element item;

    if(isEmpty(DQ)){
        return 0;
    }else{
        item = old -> data;

        if(DQ -> rear -> llink == NULL){
            DQ -> front = NULL;
            DQ -> rear = NULL;
        }else{
            DQ -> rear = DQ -> rear -> llink;
            DQ -> rear -> rlink = NULL;
        }
        free(old);
        return item;
    }
}

element peekFront(DQueType *DQ){
    element item;

    if(isEmpty(DQ)){
        return 0;
    }else{
        item = DQ -> front -> data;
        return item;
    }
}

element peekRear(DQueType *DQ){
    element item;

    if(isEmpty(DQ)){
        return 0;
    }else{
        item = DQ -> rear -> data;
        return item;
    }
}

void printDQ(DQueType *DQ){
    DQNode *temp = DQ -> front;

    printf(" DqQue : [");
    while(temp){
        printf("%3c", temp -> data);
        temp = temp -> rlink;
    }
    printf(" ] ");
}

void main(){
    DQueType *DQ1 =  createDQue();
    element data;

    printf("\n ***** 데크 연산 ***** \n");

    printf("\n front 삽입 A>> ");
    insertFront(DQ1, 'A');
    printDQ(DQ1);

    printf("\n front 삽입 B>> ");
    insertFront(DQ1, 'B');
    printDQ(DQ1);

    printf("\n front 삽입 C>> ");
    insertFront(DQ1, 'C');
    printDQ(DQ1);

    printf("\n front 삭제 >> ");
    data = deleteFront(DQ1);
    printDQ(DQ1);
    printf("\t 삭제 데이터 : %c", data);

    printf("\n rear 삭제 >>");
    data = deleteRear(DQ1);
    printDQ(DQ1);
    printf("\t\t 삭제 데이터 : %c", data);

    printf("\n rear 삽입 D>> ");
    insertRear(DQ1, 'D');
    printDQ(DQ1);

    printf("\n front 삽입 E>> ");
    insertFront(DQ1, 'E');
    printDQ(DQ1);

    printf("\n front 삽입 F>> ");
    insertFront(DQ1, 'F');
    printDQ(DQ1);

    data = peekFront(DQ1);
    printf("\n peek Front item : %c", data);
    data = peekRear(DQ1);
    printf("\n peek Rear item : %c", data);

    getchar();

}