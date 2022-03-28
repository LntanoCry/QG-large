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

		printf("����������Ҫִ�еĲ˵�����: ");

		while (scanf_s("%d", &choose, sizeof(int)) == 1)
		{
			if (choose != (int)choose)  /* ��������ĸ������� */
			{
				printf("\t��������������Ҫ���еĲ˵�����: ");
				continue;
			}
			break;
		}
			
		switch (choose)
			{
			case 1:
				if (InitLqueue(&q) == TRUE)
				{
					printf("���г�ʼ���ɹ�\n");
				}
				else
				{
					printf("���г�ʼ��ʧ��!\n");
				}
				break;
			case 2:
				if (EnLqueue(q) == TRUE)
				{
					printf("��ӳɹ�!\n");
				}
				else
				{
					printf("���ʧ��!\n");
				}
				break;
			case 3:
				if (PopLqueue(q) == TRUE)
				{
					printf("���ӳɹ�!\n");
				}
				else
				{
					printf("����ʧ��!\n");
				}
				break;
			case 4:
				if (GetHeadLqueue(q) == TRUE)
				{
					printf("�ɹ��õ�����ֵ\n");
				}
				break;
			case 5:
				if (isempty(q) == TRUE)
				{
					printf("�ö���Ϊ�ն���!\n");
				}
				else
				{
					printf("��Ϊ�ն���!\n");
				}
				break;
			case 6:
				GetLength(q);
				break;
			case 7:
				if (TraverseLqueue(q, LPrint) == TRUE)
				{
					printf("��ӡ�ɹ�");
				}
				else
				{
					printf("���в�����!\n");
				}
				break;
			case 8:
				if (ClearLqueue(q) == TRUE)
				{
					printf("�ö����ѱ����!\n");
				}
				break;
			case 9:
				if (DestroyLqueue(&q) == TRUE)
				{
					printf("�ö����ѱ��ɹ�����!\n");
				}
				else
				{
					printf("����ʧ��!\n");
				}
				break;
			case 10:
				exit(1);
				break;
			default:
				break;
			}

		while ((c = getchar()) != EOF && c != '\n'); /* ��ջ����� */

		if (choose == 0)
		{
			printf("\t�������!\n");
			printf("\t��������������Ҫ���еĲ˵�����:\n ");
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
	printf("\t\t******************��ӭʹ�øó���********************\n");
	printf("\t\t*----------------------�˵�------------------------*\n");
	printf("\t\t*  (1)��ʼ������        **   (2)��Ӳ���           *\n");
	printf("\t\t****************************************************\n");
	printf("\t\t*  (3)���Ӳ���          **   (4)�õ�����ֵ         *\n");
	printf("\t\t****************************************************\n");
	printf("\t\t*  (5)�ж϶����Ƿ�Ϊ��  **   (6)��ö��еĳ���     *\n");
	printf("\t\t****************************************************\n");
	printf("\t\t*  (7)��ӡ����          **   (8)��ն���           *\n");
	printf("\t\t****************************************************\n");
	printf("\t\t*  (9)���ٶ���          **   (10)�˳�����          *\n");
	printf("\t\t****************************************************\n");
	printf("\t------------------------------------------------------------------\n");
}
