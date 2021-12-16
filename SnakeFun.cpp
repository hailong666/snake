// SnakeFun.cpp: implementation of the SnakeFun class.
//
//////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include "SnakeFun.h"
#include"windows.h"
#include"conio.h"
#include"stdlib.h"
#include"time.h"

struct Food
	{
	int x;
	int y;
	};
struct Food food;
struct SNAKE Snake;
struct SNAKE* head;
struct SNAKE* last;
struct SNAKE* Tlast;
int speed=300;
int Scount=1;
static int M;
void gotoxy(int x,int y)//定义到窗口的任意位置
{
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
    SetConsoleCursorPosition(hOut, pos);
	

}
void HideCursor(void)//隐藏光标
{
 CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void TheStart(void) //开始菜单打印
{

gotoxy(30,10);
printf("\t\t欢迎来到贪吃蛇世界\n");
printf("\n\t\t\t\t\t1:开始游戏");
printf("\n\t\t\t\t\t0:退出游戏");
HideCursor();

}
void TheGround(void)//创造边界
{	int m=0,n=0;
    char Ground[HEX][SHU]={0};
	gotoxy(0,0);
	for(m=0;m<HEX;m++)
	   {
		Ground[m][0]='#';
        Ground[m][SHU-1]='#';
		}
	for(n=0;n<SHU;n++)
	   {
	   Ground[0][n]='#';
       Ground[HEX-1][n]='#';
		}
    for(int i=0;i<HEX;i++)
	{
	   for(int k=0;k<SHU;k++)
	   {
	   printf("%c",Ground[i][k]);
	   
	   }
	   printf("\n");
	
	}
gotoxy(0,29);
printf("您当前的分数为%d分！",(Scount-1)*5);
gotoxy(101,13);
printf("用w，a，s，d控制上");
gotoxy(101,14);
printf("下左右");
gotoxy(101,15);
printf("每吃一个食物得5分");

}
void CreatFood(void) //创造食物
{  
	gotoxy(0,0);
	
	srand((unsigned)time(NULL)*1000);
	food.x=((unsigned)rand())%97+1;
	food.y=((unsigned)rand())%25+1;
	gotoxy(food.x,food.y);
    printf("@");

}
void CreatSnake(void)
{

  gotoxy(SHU/2,HEX/2);
  printf("*");



}
void SnakeMove(void)
{
	DeletSnake();
	Check();
		if((food.x==head->x)&&(food.y==head->y))
				{
				CreatFood();
				IncSnake();
				Scount=Scount+1;
				speed=speed-10;
				gotoxy(0,29);
				printf("您当前的分数为%d分！",(Scount-1)*5);
				}
	
	if(kbhit())
	{  
		M=getch();
		switch(M)
		{
			case 119:
			gotoxy(Snake.x,Snake.y);
				printf(" ");

				BecomeC();
				gotoxy(Snake.x,Snake.y=Snake.y-1);
				ShowSnake();

				break;
			case 115:
				gotoxy(Snake.x,Snake.y);
				printf(" ");

				BecomeC();
				gotoxy(Snake.x,Snake.y=Snake.y+1);
				ShowSnake();

				break;
			case 97:
				gotoxy(Snake.x,Snake.y);
				printf(" ");

				BecomeC();
				gotoxy(Snake.x=Snake.x-1,Snake.y);
				ShowSnake();

				break;
			case 100:
				gotoxy(Snake.x,Snake.y);
			printf(" ");

			BecomeC();
				gotoxy(Snake.x=Snake.x+1,Snake.y);
				ShowSnake();

				break;
		}
	}
	else
	{
		switch(M)
		{
			case 119:
				gotoxy(Snake.x,Snake.y);
				printf(" ");

				BecomeC();
				gotoxy(Snake.x,Snake.y=Snake.y-1);
				ShowSnake();

					break;
			case 115:
				gotoxy(Snake.x,Snake.y);
				printf(" ");

				BecomeC();
				gotoxy(Snake.x,Snake.y=Snake.y+1);
				ShowSnake();

					break;
			case 97:
				gotoxy(Snake.x,Snake.y);
				printf(" ");

				BecomeC();
				gotoxy(Snake.x=Snake.x-1,Snake.y);
				ShowSnake();

				break;
			case 100:
				gotoxy(Snake.x,Snake.y);
				printf(" ");

				BecomeC();
				gotoxy(Snake.x=Snake.x+1,Snake.y);
				ShowSnake();
				break;
					
		}
	
	
	
	}

}
void IncSnake(void)//增加小蛇的长度
{	

	last=head;
	while(1)
	{
	if(head->next==NULL)
		break;
	  head=head->next;
	}
	head->next=(struct SNAKE*)malloc(sizeof(Snake));
	head->next->x=head->x;
	head->next->y=head->y;
	head->next->next=NULL;
	head=last;

}
void BecomeC(void)//
{
	int x,y;
	int count=4;
	int help[4];
	last=head;
	while(1)
	{
				if(head->next==NULL)
				{
					return;
				}
					 if(head->next->next==NULL)
					{
						head->next->x=head->x;
						head->next->y=head->y;
						head=last;
						return;
					}
					
			if(head->next->next!=NULL&&Scount<=3)
			{
			
				x=head->next->x;
				y=head->next->y;
				head->next->x=head->x;
				head->next->y=head->y;
				head->next->next->x=x;
				head->next->next->y=y;
				head=head->next;
				head=last;
			return;
			}
			if(head->next->next!=NULL&&Scount>3)  //厉害的算法
			{
				
				while(1)
				{
					if(count==4)
					{
						help[count%4]=head->next->x;
						help[(count+1)%4]=head->next->y;
						head->next->x=head->x;
						head->next->y=head->y;
						head=head->next;
					
					}
					if(head->next==NULL)
					{
						head=last;
						return;
					}
					help[(count+2)%4]=head->next->x;
					help[(count+2+1)%4]=head->next->y;
					head->next->x=help[count%4];
					head->next->y=help[(count+1)%4];
					head=head->next;
					count=count+2;
				
				}
			
		
			}
 
	}


}
void ShowSnake(void)
{	last=head;
	while(head->next!=NULL)
	{
		gotoxy(head->x,head->y);
		printf("*");
		head=head->next;
	
	}
		gotoxy(head->x,head->y);
		printf("*");
		head=last;
}
void DeletSnake(void)
{
	
	if(head->next!=NULL)
	{
		last=head;
		while(1)
		{
			if(head->next==NULL)
				break;

			head=head->next;
		}
		gotoxy(head->x,head->y);
		printf(" ");
		head=last;
	}

}
void Check(void)
{
	if(head->x==0||head->y==0||head->x==100||head->y==27)
	{
		system("cls");
		gotoxy(45,15);
		printf("GAVE OVER!!!");
		Sleep(5000);
		exit(0);
	}
		last=head;
		if(head->next==NULL)
			return;
		if(head->next->next==NULL)
			return;
		if(head->next->next->next==NULL)
			return;
	while(head->next!=NULL)
	{
			head=head->next;
			

			if(last->x==head->x&&last->y==head->y)
			{
				system("cls");
				gotoxy(45,15);
				printf("GAVE OVER!!!");
				Sleep(5000);
				exit(0);
			}
			if(head->next==NULL){
			head=last;
			return;
			}
	
	}
	
	return;

}
























	
