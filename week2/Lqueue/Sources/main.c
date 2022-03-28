#include <stdlib.h>
#include <stdio.h>
#include "Lqueue.h"

void ShowMenu();

char c;
int choose = 0;
Lqueue* q;

int main()
{
	
	ShowMenu();

	while (1)
	{

		printf("请输入你想要执行的菜单操作: ");

		while (scanf_s("%d", &choose, sizeof(int)) == 1)
		{
			if (choose != (int)choose)  /* 处理输入的浮点类型 */
			{
				printf("\t请重新输入你想要进行的菜单操作: ");
				continue;
			}
			break;
		}
			
		switch (choose)
			{
			case 1:
				if (InitLqueue(&q) == TRUE)
				{
					printf("队列初始化成功\n");
				}
				else
				{
					printf("队列初始化失败!\n");
				}
				break;
			case 2:
				if (EnLqueue(q) == TRUE)
				{
					printf("入队成功!\n");
				}
				else
				{
					printf("入队失败!\n");
				}
				break;
			case 3:
				if (PopLqueue(q) == TRUE)
				{
					printf("出队成功!\n");
				}
				else
				{
					printf("出队失败!\n");
				}
				break;
			case 4:
				if (GetHeadLqueue(q) == TRUE)
				{
					printf("成功得到队首值\n");
				}
				break;
			case 5:
				if (isempty(q) == TRUE)
				{
					printf("该队列为空队列!\n");
				}
				else
				{
					printf("不为空队列!\n");
				}
				break;
			case 6:
				GetLength(q);
				break;
			case 7:
				if (TraverseLqueue(q, LPrint) == TRUE)
				{
					printf("打印成功");
				}
				else
				{
					printf("队列不存在!\n");
				}
				break;
			case 8:
				if (ClearLqueue(q) == TRUE)
				{
					printf("该队列已被清空!\n");
				}
				break;
			case 9:
				if (DestroyLqueue(&q) == TRUE)
				{
					printf("该队列已被成功销毁!\n");
				}
				else
				{
					printf("销毁失败!\n");
				}
				break;
			case 10:
				exit(1);
				break;
			default:
				break;
			}

		while ((c = getchar()) != EOF && c != '\n'); /* 清空缓冲区 */

		if (choose == 0)
		{
			printf("\t输入错误!\n");
			printf("\t请重新输入你想要进行的菜单操作:\n ");
		}

		system("pause");
		system("cls");
		ShowMenu();
		
	}

	return 0;
}


void ShowMenu()
{
	printf("\n");
	printf("\n");
	printf("\t\t******************欢迎使用该程序********************\n");
	printf("\t\t*----------------------菜单------------------------*\n");
	printf("\t\t*  (1)初始化队列        **   (2)入队操作           *\n");
	printf("\t\t****************************************************\n");
	printf("\t\t*  (3)出队操作          **   (4)得到队首值         *\n");
	printf("\t\t****************************************************\n");
	printf("\t\t*  (5)判断队列是否为空  **   (6)获得队列的长度     *\n");
	printf("\t\t****************************************************\n");
	printf("\t\t*  (7)打印队列          **   (8)清空队列           *\n");
	printf("\t\t****************************************************\n");
	printf("\t\t*  (9)销毁队列          **   (10)退出程序          *\n");
	printf("\t\t****************************************************\n");
	printf("\t------------------------------------------------------------------\n");
}
