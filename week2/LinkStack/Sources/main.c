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
void Examine();		/* ϣ����һ�ֿ���ֱ�����������쳣����ĺ��� */
void MyLinkStack(); /* �����ܺ���ģ�� */

Linkstack stack;
int choice = 0;
Type val;		/* �����ݴ���ֵ */
char c;			/* ������ȡ�ַ� */

int main()
{
	ShowMenu();

	while (1)
	{
		
		printf("\t����������Ҫ���еĲ˵�����: ");
		while (scanf_s("%d", &choice, sizeof(int)) == 1)
		{
			if (choice != (int)choice)  /* ��������ĸ������� */
			{
				printf("\t��������������Ҫ���еĲ˵�����: ");
				continue;
			}
			break;
		}
		printf("\n");
		MyLinkStack();
		while ((c = getchar()) != EOF && c != '\n'); /* ��ջ����� */

		if (choice == 0)
		{
			printf("\t�������!\n");
			printf("\t��������������Ҫ���еĲ˵�����:\n ");
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
	printf("\t\t***************��ӭʹ�ø���ջ���Գ���***************\n");
	printf("\t\t*----------------------�˵�------------------------*\n");
	printf("\t\t*  (1)��������ջ        **   (2)��ջ(int)          *\n");
	printf("\t\t*  (3)��ջ              **   (4)���ջ��ֵ         *\n");
	printf("\t\t*  (5)�ж�ջ�Ƿ�Ϊ��    **   (6)���ջ�ĳ���       *\n");
	printf("\t\t*  (7)��ӡջ            **   (8)���ջԪ��         *\n");
	printf("\t\t*  (9)����ջ            **   (10)�˳�����          *\n");
	printf("\t\t****************************************************\n");
	printf("\t------------------------------------------------------------------\n");

}

void MyLinkStack()
{
	
	switch (choice)
	{
	case 1:
	
		InitLstack(&stack);
		printf("\t�ѳɹ������µĿ���ջ!\n");
		break;
	case 2:
		printf("����������Ҫ��ջ��ֵ: \n");
		if (scanf_s("%d", &val, sizeof(Type)) == 1)
		{
			if (PushLstack(&stack, val) == TRUE)
			{
				printf("\n%d �ѳɹ���ջ\n", val);
			}
			else
			{
				printf("\t����ʧ��.\n");
			}
		}
		else
		{
			printf("�������!\n");
		}
		break;
	case 3:
		if (PopLstack(&stack,&val) == TRUE)
		{
			printf("\t�ѳɹ���ջ!\n");
			printf("\t��ջ�ڵ��ֵΪ: %d\n", val);
			Sleep(800);
		}
		else
		{
			printf("\t��ջʧ��!\n");
		}
		break;
	case 4:
		if (GetTop(&stack, &val) == TRUE)
		{
			printf("\tջ��Ԫ�ص�ֵΪ: %d\n", val);
		}
		else
		{
			printf("\t���ֵʧ��!\n");
		}
		break;
	case 5:
		if (isempty(&stack) == TRUE)
		{
			printf("\t��ջΪ��ջ\n");
		}
		else
		{
			printf("\t��ջ��Ϊ��ջ\n");
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
			printf("\t���ʧ��!\n");
		}
		else
		{
			printf("\t��ճɹ�\n");
		}
		break;
	case 9:
		if (DestroyLstack(&stack) == FALSE)
		{
			printf("\t����ʧ��!\n");
		}
		else
		{
			printf("\t���ٳɹ�!\n");
		}
		break;
	case 10:
		exit(1);
		break;
	default:
		break;
	}
}