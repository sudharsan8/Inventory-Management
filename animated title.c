#include "project.h"
COORD coord= {0,0}; // this is global variable
//COORD--Console Cursor Coordinates
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void animated_title()
{
    char ch[]="INVENTORY MANAGEMENT SYSTEM",c;
     int i=strlen(ch),j,x=20,y=26,z=30;
        system("cls");
        system("color F4");

        for(j=0;j<i;j++)
        {
         if(j>=0&&j<10){
            gotoxy(x,5);
        printf("%c",ch[j]);
        Sleep(120);
        x+=4;}
        if(j>=10&&j<21){
            gotoxy(y,10);
        printf("%c",ch[j]);
        Sleep(120);
        y+=2;}
        if(j>=21){
            gotoxy(z,15);
        printf("%c",ch[j]);
        Sleep(120);
        z+=1;}

        }
        Sleep(1000);
}


