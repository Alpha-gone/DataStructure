#include<stdio.h>
typedef int element;
int i;

void binarySearch(element a[], int begin, int end, element key){
    int middle;

    i++;

    if(begin == end){
        if(key == a[begin]){
            printf("%d번째에 검색 성공!\n\n", i);
        }else{
            printf("%d번째에 검색 실패!\n\n", i);
        }
        return;
    }

    middle = (begin + end) / 2;
    if(key == a[middle]){
       printf("%d번째에 검색 성공!\n\n", i);
    }else if(key < a[middle] && (middle - 1 >=  begin)){
        binarySearch(a, begin, middle - 1, key);
    }else if(key > a[middle] && (middle + 1 <= end)){
        binarySearch(a, middle + 1, end, key);
    }else{
        printf("%d번째에 검색 실패!\n\n", i);
    }
}

void main(){
    element a[] = {1, 2, 8, 9, 11, 19, 29}, key;
    int n = 7;

    i = 0;
    printf("\n %d를 검색하라! ->> ", key = 11);
    binarySearch(a, 0, n - 1, key);

    i = 0;
    printf("\n %d를 검색하라! ->> ", key = 6);
    binarySearch(a, 0, n - 1, key);

    i = 0;
    printf("\n %d를 검색하라! ->> ", key = 2);
    binarySearch(a, 0, n - 1, key);

    getchar();
}