#include<stdio.h>
#define INDEX_SIZE 3

typedef int element;

typedef struct{
    int index;
    element key;
}iTable;

iTable indexTable[INDEX_SIZE];

void sequentialSearch2(element a[], int begin, int end, element key){
    int i = begin;

    printf("\n %d를 검색하라! ->> ", key);
    while (i < end && a[i] < key){
        i++;
    }
    if(a[i] == key){
        printf("%d번째에 검색 성공! \n\n", (i - begin) + 1);
    }else{
        printf("%d번째에 검색 실패! \n\n", (i - begin) + 1);
       }
}

void makeIndexTable(element a[], int size){
    int i, n;
    
    n = size / INDEX_SIZE;
    if(size % INDEX_SIZE > 0){
        n = n+1;
    }

    for(i = 0; i < INDEX_SIZE; i++){
        indexTable[i].index = i * n;
        indexTable[i].key = a[i * n];
    }
}


void indexSearch(element a[], int n, element key){
    int i, begin, end;

    if(key < a[0] || key > a[n - 1]){
        printf("\n찾는 키가 없습니다. 검색 실패! \n");
    }

    for(i = 0; i < INDEX_SIZE; i++){
        if((indexTable[i].key <= key) && (indexTable[i + 1].key > key)){
            begin = indexTable[i].index;
            end = indexTable[i + 1].index;
            break;
        }
    }

    if(i == INDEX_SIZE){
        begin = indexTable[i - 1].index;
        end = n;
    }

    sequentialSearch2(a, begin, end, key);
}

void main(){
    element a[] = {1, 2, 8, 9, 11, 19, 29};
    int n = 7;

    printf("\n\t <<< 색인 순차 검색 >>> \n");
    makeIndexTable(a, n);
    indexSearch(a, n, 9);
    indexSearch(a, n, 6);
    for(int i  = 0; i < INDEX_SIZE; i++){
        printf("%d\t%d\n", indexTable[i].index, indexTable[i].key);
    }
    getchar();
}