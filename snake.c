#include "snake.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define N 20
#define M 40

int i,j,Field[N][M],x,y,Gy,Head,Tail,Game;

void ResetScreenPosition(){
HANDLE hOut;
COORD Position;
hOut = GetStHandle(STD_OUTPUT_HANDLE);
Position.X = 0;
Position.Y = 0;
SetConsoleCursorPosition(hOut,HANDLE);
}

void SnakeInitialization(){
//csináltam egy egy NxM-es üres tömböt ahhoz inicializálni tudjam a kígyómat
for(i=0; i<N; i++){
    for(j=0; j<M; j++){
        Field[i][j]=0;//az NxM -es tömb i és j értékeit 0-ra állítom ez azért kellet  hogy legyen amilyen értékre pozicionáljam a kígyót
    }
}
x=N/2; y=M/2; Gy = y; Head = 5; Tail = 1; Game = 0;
for(i=0; i<Head; i++){
    Gy++;
    Field[x][Gy-Head] = i+1;
    }
}

void CreateField(){
    //itt fogom létrehozni a pályám felső felét ami egy 20x40-es egység méretű NxM es
    for(i=0; i<=M+1; i++){
        //Kezdőértéknek a  201 es Ascii kod karakterét rakom be a nullára mert az felel meg nekem
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
    if(Field[i][j]==0)printf(" ");
    if(Field[i][j]>0 && Field[i][j]!=Head)printf("%c",176);
    if(Field[i][j]==Head)printf("%c",178);
    if(j==M-1){
        printf("%c\n",186);// ez pedig a függőleges része ezt egészen M-1 fogja írni
    }
   }
}
//itt ugyanúgy a  200-as Asci kerűl oda ahol i=0 ez a sarok ugyebár
for(i=0; i<=M+1; i++){
        if(i==0){
            printf("%c",200);
        }else if(i==M+1){
        printf("%c",188);//ha végigment az M-en és következik az M+1 akkor berakja a másik sarkat is
        }else{
        printf("%c",205);//mindenhol máhol az érték egy M ott írodik a 205-as ASCI ami egy vizszintes karakterforma
        }
    }
}
void Asciszamok(){
//Ezekre a karakterekre lesz szükségem a pálya kirajzolásához
printf("Asci 176: %c\n\n",176);
printf("Asci 178: %c\n\n",178);
printf("Asci 186: %c\n\n",186);
printf("Asci 187: %c\n\n",187);
printf("Asci 188: %c\n\n",188);
printf("Asci 200: %c\n\n",200);
printf("Asci 201: %c\n\n",201);
printf("Asci 205: %c\n\n",205);

}

