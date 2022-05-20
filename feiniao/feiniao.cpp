#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include <graphics.h>
#include"tb.h"
#define DIS 22
#define BLAN 9

int j;

typedef struct bird
{COORD pos;
 int score;
}BIRD;

void CheckWall(COORD wall[],BIRD*bird,int j);
void PrtBird(BIRD*bird,int x);
int CheckWin(COORD*wall,BIRD*bird);
void Begin(BIRD*bird);
BOOL SetConsoleColor(unsigned int wAttributes);
void Gotoxy(int x,int y);
BOOL SetConsoleColor(unsigned int wAttributes);
void HideCursor();

void main()
{BIRD bird={{22,10},0};
COORD wall[4]={{40,10},{60,6},{80,8},{100,4}};
int i,a,b;
char ch;



b=MessageBox(0, TEXT("\t       准备好了嘛~"),TEXT("我要飞~"),1);

if(b==1)  
{ system("mode con cols=120 lines=30");//窗口大小

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),117); 
j=MessageBox(0, TEXT("\t       简单→确定\n\n\t       偏难→取消"),TEXT("我要飞~"),1)+1;
while(CheckWin(wall,&bird))//小鸟运动
{
Begin(&bird);



CheckWall(wall,&bird,j);

PrtBird(&bird,0);
Sleep(200);
if(kbhit())
  {ch=getch();PrtBird(&bird,1);Sleep(30);
  if(ch==' ') {bird.pos.Y-=2;}
  }
else  {bird.pos.Y+=1;}
for(i=0;i<4;i++)  wall[i].X--;
}
a=MessageBox(0, TEXT("\t       再来一把！"),TEXT("我要飞~"),1);
if(a==1)  main();
exit(0);
}
else  {MessageBox(0, TEXT("\t     哼！我走！！"),TEXT("我要飞~"),0);exit(0);}
}

void CheckWall(COORD wall[],BIRD*bird,int j)//显示柱子
{int i;
HideCursor();
srand(time(NULL));
xx:COORD temp={wall[3].X+DIS,rand()%13+5};
COORD te;
if(temp.Y==wall[3].Y||(temp.Y-wall[3].Y)>15||(wall[3].Y-temp.Y)>15)  goto xx;
te=temp;

if(wall[0].X+2==10)
{wall[0]=wall[1];
wall[1]=wall[2];
wall[2]=wall[3];
wall[3]=temp;
}

for(i=0;i<4;++i)
{//上半
temp.X=wall[i].X+1;
/*SetConsoleColor(0x0C);*/

for(temp.Y=2;temp.Y<wall[i].Y;temp.Y++)
{Gotoxy(temp.X,temp.Y);printf("■■■■■■");}
temp.X--;
Gotoxy(temp.X,temp.Y);printf("■■■■■■");
//下半
temp.Y+=BLAN-j;
Gotoxy(temp.X,temp.Y);printf("■■■■■■");
temp.X++;
temp.Y++;
for(;(temp.Y)<26;temp.Y++)
{Gotoxy(temp.X,temp.Y);printf("■■■■■■");}
}


if(wall[0].X<=bird->pos.X-5&&wall[0].X+2>10)
{temp.X=te.X+1;
/*SetConsoleColor(0x0C);*/

for(temp.Y=2;temp.Y<te.Y;temp.Y++)
{Gotoxy(temp.X,temp.Y);printf("■■■■■■");}
temp.X--;
Gotoxy(temp.X,temp.Y);printf("■■■■■■");
//下半
temp.Y+=BLAN-j;
Gotoxy(temp.X,temp.Y);printf("■■■■■■");
temp.X++;
temp.Y++;
for(;(temp.Y)<26;temp.Y++)
{Gotoxy(temp.X,temp.Y);printf("■■■■■■");}
}


}

void PrtBird(BIRD*bird,int x)//显示小鸟
{/*SetConsoleColor(112);*/
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),114);  
if(x==0)
{Gotoxy(bird->pos.X,bird->pos.Y);
printf("□\n");
Gotoxy(bird->pos.X,bird->pos.Y+1);
printf("||");
}
if(x==1)
{
Gotoxy(bird->pos.X,bird->pos.Y);
printf("□\n");
Gotoxy(bird->pos.X,bird->pos.Y+1);
printf("<>");
}

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),117);  

}

int CheckWin(COORD*wall,BIRD*bird)//是否超出边界
{if(bird->pos.X>=wall->X)
   if(bird->pos.Y<=wall->Y||bird->pos.Y+1>=wall->Y+BLAN-j) return 0;
if(bird->pos.Y<1||bird->pos.Y+1>26)  return 0;
if(wall->X==10) (bird->score)++;
return 1;
}

void Begin(BIRD*bird)//上下边界和分数
{system("cls");
Gotoxy(0,26);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),113);  
printf("=====================================""=====================================""=====================================");
Gotoxy(0,1);
printf("=====================================""=====================================""=====================================");
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),116);  
printf("\n%4d",bird->score);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),117);  
}

void Gotoxy(int x,int y)//定位光标
{COORD pos={x,y};
HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hOutput,pos);
}

BOOL SetConsoleColor(unsigned int wAttributes)
{HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
if(hOutput==INVALID_HANDLE_VALUE)
{return FALSE;}
return SetConsoleTextAttribute(hOutput,wAttributes);
}


void HideCursor()//隐藏光标
{
	CONSOLE_CURSOR_INFO cursor;    
	cursor.bVisible = FALSE;    
	cursor.dwSize = sizeof(cursor);    
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorInfo(handle, &cursor);
}

