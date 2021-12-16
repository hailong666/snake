// SnakeFun.h: interface for the SnakeFun class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SNAKEFUN_H__6970883E_7BD0_42FF_9CF5_4032791465D8__INCLUDED_)
#define AFX_SNAKEFUN_H__6970883E_7BD0_42FF_9CF5_4032791465D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define HEX 27
#define SHU 100
void gotoxy(int x,int y);
void CreatSnake(void);//初始化蛇头
void TheGround(void);//初始化边界
void TheStart(void);//初始化开始界面
void HideCursor(void);//隐藏光标
void CreatFood(void);//制造界面
void SnakeMove(void);
struct SNAKE
	{
	int x;
	int y;
	struct SNAKE* next;
	};
void IncSnake(void);
void BecomeC(void);
void ShowSnake(void);
void DeletSnake(void);
void Check(void);


#endif // !defined(AFX_SNAKEFUN_H__6970883E_7BD0_42FF_9CF5_4032791465D8__INCLUDED_)
