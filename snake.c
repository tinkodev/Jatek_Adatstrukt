#include "snake.h"
#include <stdio.h>
#include <stdlib.h>

#define N 20
#define M 40

void CreateField(){
    int i,j;
    for(i=0; i<=M+1; i++){
        if(i==0){
            printf("%c",201);
        }else if(i==M+1){
        printf("%c",187);
        }else{
        printf("%c",205);
        }
    }
printf("\n");
for(i=0; i<N; i++){
   printf("%c",186);
   for(j=0; j<M; j++){
    if(j==M-1){
        printf(" %c\n",186);
    }else{
    printf(" ");
    }
   }
}
for(i=0; i<=M+1; i++){
        if(i==0){
            printf("%c",200);
        }else if(i==M+1){
        printf("%c",188);
        }else{
        printf("%c",205);
        }
    }
}
void Asciszamok(){
printf("Asci 200: %c\n\n",200);
printf("Asci 201: %c\n\n",201);
printf("Asci 186: %c\n\n",186);
printf("Asci 205: %c\n\n",205);
printf("Asci 187: %c\n\n",187);
printf("Asci 188: %c\n\n",188);
}
