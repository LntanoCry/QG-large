/***************************************
* @filename		:main.c
* @version		:1.0
* @author		:Runyu Chen
* @created time	:2022/3/27
*------------REMIND--------------------
* This file is made to test LinkStack
***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "LinkStack.h"

void ShowMenu();
void Examine();		/* 希望有一种可以直接用来处理异常输入的函数 */
void MyLinkStack(); /* 主功能函数模块 */

Linkstack stack;
int choice = 0;
Type val;		/* 用来暂存数值 */
char c;			/* 用来读取字符 */

int main()
{
	ShowMenu();

	while (1)
	{
		
		printf("\t请输入你想要进行的菜单操作: ");
		while (scanf_s("%d", &choice, sizeof(int)) == 1)
		{
			if (choice != (int)choice)  /* 处理输入的浮点类型 */
			{
				printf("\t请重新输入你想要进行的菜单操作: ");
				continue;
			}
			break;
		}
		printf("\n");
		MyLinkStack();
		while ((c = getchar()) != EOF && c != '\n'); /* 清空缓冲区 */

		if (choice == 0)
		{
			printf("\t输入错误!\n");
			printf("\t请重新输入你想要进行的菜单操作:\n ");
		}

		Sleep(1000);
		system("cls");
		ShowMenu();
		
	}
	
	return 0;
}

void ShowMenu()
{
	printf("\n");
	printf("\n");
	printf("\t\t***************欢迎使用该链栈测试程序***************\n");
	printf("\t\t*----------------------菜单------------------------*\n");
	printf("\t\t*  (1)创建空链栈        **   (2)入栈(int)          *\n");
	printf("\t\t*  (3)出栈              **   (4)获得栈顶值         *\n");
	printf("\t\t*  (5)判断栈是否为空    **   (6)检测栈的长度       *\n");
	printf("\t\t*  (7)打印栈            **   (8)清空栈元素         *\n");
	printf("\t\t*  (9)销毁栈            **   (10)退出程序          *\n");
	printf("\t\t****************************************************\n");
	printf("\t------------------------------------------------------------------\n");

}

void MyLinkStack()
{
	
	switch (choice)
	{
	case 1:
	
		InitLstack(&stack);
		printf("\t已成功创建新的空链栈!\n");
		break;
	case 2:
		printf("请输入你想要入栈的值: \n");
		if (scanf_s("%d", &val, sizeof(Type)) == 1)
		{
			if (PushLstack(&stack, val) == TRUE)
			{
				printf("\n%d 已成功入栈\n", val);
			}
			else
			{
				printf("\t插入失败.\n");
			}
		}
		else
		{
			printf("输入错误!\n");
		}
		break;
	case 3:
		if (PopLstack(&stack,&val) == TRUE)
		{
			printf("\t已成功出栈!\n");
			printf("\t出栈节点的值为: %d\n", val);
			Sleep(800);
		}
		else
		{
			printf("\t出栈失败!\n");
		}
		break;
	case 4:
		if (GetTop(&stack, &val) == TRUE)
		{
			printf("\t栈顶元素的值为: %d\n", val);
		}
		else
		{
			printf("\t获得值失败!\n");
		}
		break;
	case 5:
		if (isempty(&stack) == TRUE)
		{
			printf("\t该栈为空栈\n");
		}
		else
		{
			printf("\t该栈不为空栈\n");
		}
		break;
	case 6:
		GetLength(&stack);
		break;
	case 7:
		PrintInt(&stack);
		system("\tpause");
		break;
	case 8:
		if (ClearLstack(&stack) == FALSE)
		{
			printf("\t清空失败!\n");
		}
		else
		{
			printf("\t清空成功\n");
		}
		break;
	case 9:
		if (DestroyLstack(&stack) == FALSE)
		{
			printf("\t销毁失败!\n");
		}
		else
		{
			printf("\t销毁成功!\n");
		}
		break;
	case 10:
		exit(1);
		break;
	default:
		break;
	}
}