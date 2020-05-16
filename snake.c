#include "snake.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#define N 20
#define M 40

int i,j,Field[N][M],x,y,Gy,Head,Tail,Game,Frogs,a,b,var,dir,Score,HighScore,Speed,Level;
char Name[20];


FILE *f;



void Gameover(){//Játék vége :D
printf("\a");
Sleep(1500);
system("Cls");
if(Score>HighScore){
    printf("Uj rekord gratulalok %d!!!!!!!!\n\n",Score);
    //printf("Ki dontott rekordot kerem a nevet?\n");
    //scanf("%s",Name);
    system("pause");
    f=fopen("highscore.txt","w");
           //fprintf(f,"%s:",Name);
    fprintf(f,"%d",Score);
    fclose(f);

}
system("Cls");
printf("\n\n                          GAME OVER !!!!!!!");
printf("                              Pontszam: %d \n\n",Score);
Game = 1;
if(Score == 25 || Score > 45){
printf("                          Szint 1 teljesitve!\n\n");
}
printf("Nyomjon ENTER-t az uj jatekhoz vagy ESC-et hogy kilepjen!");
}

void TailRemove()
{
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            if(Field[i][j]==Tail)
            {
                Field[i][j]=0;
            }
        }
    }
    Tail++;
}
int Keyboard_hit(){
if(_kbhit())
    return getch();
    else
        return -1;
}

void Movement(){
var = Keyboard_hit();
var = tolower(var);//nem számít a caps lock aktiválva van vagy nincs ugyis kisbetüsítek
if(((var == 'd' || var == 'a')  || (var == 'w' || var  == 's'))//mivel hogy mindegyik feltétel tljesűl ezért folyamatosan mozog csak írányt kell váltanom
&&abs(dir-var)>5) dir = var;
if(dir == 'd'){
    y++;
    if(Field[x][y]!=0 && Field[x][y]!=-1) Gameover();//lekezem hogya saját magának megy akkor legyen vége a játéknak
    if(y==M-1) y=0;//ha belemegy a falbaa kigyó másik felől ugyanúgy jelenjen meg
    Head++;
    if(Field[x][y]==-1){
        Frogs=0;
        Score+=5;
        Tail-=2;
    }
    Field[x][y] = Head;
}
if(dir == 'w'){
    x--;
    if(Field[x][y]!=0 && Field[x][y]!=-1) Gameover();
    if(x==-1) x = N-1;
    if(Field[x][y]==-1){
        Frogs=0;
        Score+=5;
           Tail-=2;
    }
    Head++;
    Field[x][y] = Head;
}
if(dir == 'a'){
    y--;
    if(Field[x][y]!=0 && Field[x][y]!=-1) Gameover();
    if(y==0) y = M-1;
    if(Field[x][y]==-1){
        Frogs=0;
        Score+=5;
           Tail-=2;
    }
    Head++;
    Field[x][y] = Head;
}
if(dir == 's'){
    x++;
    if(Field[x][y]!=0 && Field[x][y]!=-1) Gameover();
    if(x==N-1) x = 0;
    if(Field[x][y]==-1){
        Frogs=0;
        Score+=5;
           Tail-=2;
    }
    Head++;
    Field[x][y] = Head;
}
}

void Random(){
    srand(time(0));
    a = 1 + rand() % 18;//random pozíciot generálok a Békának persze N és M között
    b = 1 + rand() % 38;//

    if(Frogs == 0 && Field[a][b]==0){//megnézem hogy vane már értéke a békának és hogy ürese a pálya ha nincsen akkor Random egyet berakok a Fieldbe
     Field[a][b] = -1;
     Frogs = 1;
    }
}

void GameLoop()
{
    while(Game==0)
    {
        CreateField();
        ResetScreenPosition();
        Random();
        Movement();
        TailRemove();
        Sleep(99);
    }
}
//A kijelző frissítése ahhoz hogy úgy tünjön a kigyó mozog, frissítem a képernyőt mindig ugyanarra a pozícióra
void ResetScreenPosition()
{
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut,Position);
}

void SnakeInitialization()
{
        f=fopen("highscore.txt","r");//Azért olvasom be hogy Game overnél legyen amivel összehasonlítja
        fscanf(f,"%d",&HighScore);
        fclose(f);
//csináltam egy egy NxM-es üres tömböt ahhoz inicializálni tudjam a kígyómat
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            Field[i][j]=0;//az NxM -es tömb i és j értékeit 0-ra állítom ez azért kellet  hogy legyen amilyen értékre pozicionáljam a kígyót
        }
    }
    x=N/2;
    y=M/2;
    Gy = y;
    Head = 5;
    Tail = 1;
    Game = 0;
    Frogs = 0;
    dir = 'd';
    for(i=0; i<Head; i++)
    {
        Gy++;
        Field[x][Gy-Head] = i+1;
    }
}

void CreateField()
{
    //itt fogom létrehozni a pályám felső felét ami egy 20x40-es egység méretű NxM es
    for(i=0; i<=M+1; i++)
    {
        //Kezdőértéknek a  201 es Ascii kod karakterét rakom be a nullára mert az felel meg nekem
        if(i==0)
        {
            printf("%c",201);
        }
        else if(i==M+1)
        {
            printf("%c",187);
        }
        else
        {
            printf("%c",205);
        }
    }
    printf("Szint: 1");
    printf(" Jelenlegi pontszam: %d Rekord pontszam: %d",Score,HighScore);
    printf("\n");
    for(i=0; i<N; i++)
    {
        printf("%c",186);

        for(j=0; j<M; j++)
        {
            if(Field[i][j]==0)printf(" ");
            if(Field[i][j]>0 && Field[i][j]!=Head)printf("%c",176);
            if(Field[i][j]==Head)printf("%c",178);
            if(Field[i][j]==-1)printf("%c",15);
            if(j==M-1)
            {
                printf("%c\n",186);// ez pedig a függőleges része ezt egészen M-1 fogja írni
            }
        }
    }
//itt ugyanúgy a  200-as Asci kerűl oda ahol i=0 ez a sarok ugyebár
    for(i=0; i<=M+1; i++)
    {
        if(i==0)
        {
            printf("%c",200);
        }
        else if(i==M+1)
        {
            printf("%c",188);//ha végigment az M-en és következik az M+1 akkor berakja a másik sarkat is
        }
        else
        {
            printf("%c",205);//mindenhol máhol az érték egy M ott írodik a 205-as ASCI ami egy vizszintes karakterforma
        }
    }
}
void Asciszamok()
{
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

