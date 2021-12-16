#include<stdio.h>
#include<stdlib.h>
#include "SnakeFun.h"
#include<windows.h>
#include"conio.h"
int a;
extern struct Food food;
extern struct SNAKE Snake;
extern struct SNAKE* head;
extern struct SNAKE* last;
extern speed;
int main(void)
{
 Snake.x=SHU/2;
Snake.y=HEX/2;
Snake.next=NULL;
head=&Snake;		
system("color B5");
TheStart();
	a=getch();	
	if(a==49)
		{  
	
		system("cls");
		system("color AF");
		TheGround();
		CreatFood();
		CreatSnake();
		while(1)
			{
				Sleep(speed);
				SnakeMove();
		//	ZDMove();
			
			}
		}
	else if(a==48)
	{
	exit(0);
	}
    else{
	system("cls");
	printf("请输入0或者1进入或者退出游戏!!!");
	Sleep(5000);
	 exit(0);
	}


getchar();
return 0;
}

