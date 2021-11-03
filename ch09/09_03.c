#include<stdio.h>
typedef int element;
int size, i = 0;

int partition(element a[], int begin, int end){
    int pivot, L, R, t;
    element temp;
    L = begin;
    R = end;
    pivot = (int)((begin + end) / 2.0);

    printf("\n [ %d단계 : pivot = %d ] \n", ++i, a[pivot]);
    while (L < R){
        while ((a[L] < a[pivot]) && (L < R)){
            L++;
        }
        while ((a[R] >= a[pivot]) && (L < R)){
            R--;
        }
        if(L < R){
            temp = a[L];
            a[L] = a[R];
            a[R] = temp;

            if(L == pivot){
                pivot = R;
            }
        }              
    }
    temp = a[pivot];
    a[pivot] = a[R];
    a[R] = temp;

    for(t = 0; t < size; t++){
        printf(" %d", a[t]);
    }
    printf("\n");
    return R;
}

void quickSort(element a[], int begin, int end){
    int p;
    
    if(begin < end){
        p = partition(a, begin, end);
        quickSort(a, begin, p - 1);
        quickSort(a, p + 1, end);
    }
}

void main(){
    element list[8] = {69, 10, 30, 2, 16, 8, 31, 22};
    size = 8;

    printf("\n [ 초기 상태 ] \n");
    for(int i = 0; i < size; i++){
        printf(" %d", list[i]);
    }
    printf("\n");

    quickSort(list, 0, size - 1);

    getchar();
}