#include<stdio.h>

void main(){
    int i;
    char *ptrarray[4] = {"Korea","Seoul","Mapo","152번지 2/3"};

    for(i = 0; i<4; i++){
        printf("\n %s", ptrarray[i]);
    }

    ptrarray[2] = "Jongno";
    printf("\n\n");

     for(i = 0; i<4; i++){
        printf("\n %s", ptrarray[i]);
    }
    
    getchar();
}