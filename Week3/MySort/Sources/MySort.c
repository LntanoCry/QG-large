/******************************
* FileName		:	MySort.c
* Created Time  :	2022/4/3
* Author		:	Chen Runyu
* --------Introduction--------
* This file is used to realize
* the algorithms in "MySort.h"
******************************/

#include <stdio.h>
#include <stdlib.h>
#include "MySort.h"
#include "LinkStack.h"

/* ��ӡ���� */
void PrintArray(int *arr, int length)
{
	int i;
	printf("������Ϊ: \n");
	printf("[");
	for (i = 0; i < length; i++)
	{
		printf("%d",arr[i]);
		if (i != length - 1) /* Ϊ�˴�ӡ��������� */
		{
			printf(",");
		}
	}
	printf("]\n");
}



/* �������� */
void InsertSort(int *arr, int length)
{
	int i, j, temp;
	for (i = 1; i < length; i++)  /* i�����������ֵ */
	{
		temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > temp; j--) /* j������ǰ������jҪ���Ե���0,�����һ��Ԫ�رȽ� */
			{
				arr[j + 1] = arr[j]; /* ����һλ */
			}
		arr[j + 1] = temp;
	}
}


/* �鲢����,�ṩ���û�ʹ�õĽӿ� */
void MergeSort(int *arr, int length)
{
	int *temp = (int *)malloc(length * sizeof(int)); /* ������Ϊ��ʱ��������ڴ� */

	if (temp)
	{
		Merge_sort(arr, temp, 0, length-1);
		free(temp);  /* �ͷ���ʱ������ڴ� */
	}
	else
	{
		printf("����:��ʱ�������ʧ��!\n");
	}
}

/* ִ�й鲢����ĺϲ����� */
void MergeArray(int *arr, int *temp, int left, int mid, int right)
{
	int lpos = left;     /* �����벿�ֵ�һ��Ԫ��			 */
	int rpos = mid + 1;	 /* ����Ұ벿�ֵ�һ��Ԫ��			 */
	int pos = left;		 /* ��Ǻϲ������ʱ����ĵ�һ��Ԫ�� */

	while (lpos <= mid && rpos <= right)  /* �Ƚ���������Ұ�����һ��Ԫ�� */
	{
		if (arr[lpos] < arr[rpos])
		{
			temp[pos++] = arr[lpos++];
		}
		else if (arr[lpos] > arr[rpos])
		{
			temp[pos++] = arr[rpos++];
		}
	}

	while (lpos <= mid)		/* ���Ұ벿��Ϊ��ʱ */
	{
		temp[pos++] = arr[lpos++];
	}

	while (rpos <= right)	/* ����벿��Ϊ��ʱ */
	{
		temp[pos++] = arr[rpos++];
	}

	while (left <= right)	/* ����ʱ���鸴�Ƹ�ԭ���� */
	{
		arr[left] = temp[left];
		left++;
	}
}

/* ִ�й鲢����Ļ��ֲ��� */
void Merge_sort(int *arr, int *temp, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;				/* �����м��		*/

		Merge_sort(arr, temp, left, mid);			/* �ݹ黮����벿�� */
		Merge_sort(arr, temp, mid + 1, right);		/* �ݹ黮���Ұ벿�� */

		MergeArray(arr, temp, left, mid, right);	/* ִ�кϲ�����		*/
	}
}

/* ��������,�ݹ�� */
void QuickSort_Recursion(int *arr, int left, int right)
{
	if (left < right)
	{
		int index = Partition(arr, left, right);
		QuickSort_Recursion(arr, left, index - 1);  /* �ݹ���� */
		QuickSort_Recursion(arr, index + 1, right);
	}
}

/* Ѱ�Ҳ������������� */
int Partition(int *arr, int left, int right)  /* ͬʱҲ�л������������ */
{
	int key = arr[left];
	if (left < right)
	{
		while (left < right)   /* ���޴�����,right=-1�ᱨ�� */
		{
			while (left < right && arr[right] >= key)
			{
				right--;
			}
			if (right > left)
			{
				arr[left++] = arr[right];
			}

			while (left < right && arr[left] <= key)
			{
				left++;     /* �������� */
			}
			if (left < right)
			{
				arr[right--] = arr[left];
			}
		}
	}
	arr[left] = key;  /* ��ʱleft=right,ȷ��������Ӧ��λ�ڵ�λ�� */
	return left;
}

/* ��������,�ǵݹ�ʵ�� */
void QuickSort(int *arr, int length)
{
	int left = 0;
	int right = length - 1;
	Linkstack st;
	InitLstack(&st);
	PushLstack(&st, right);
	PushLstack(&st, left);

	while (isempty(&st) != TRUE)
	{
		PopLstack(&st, &left);
		PopLstack(&st, &right);

		if (left < right)
		{
			int index = Partition(arr, left, right);   /* �˲�����ȫ��ͬ,����������λ���Ƿǵݹ鷽���Ĺؼ� */
            if (index > left)
            {
				PushLstack(&st, index - 1);
				PushLstack(&st, left);
            }
            if (right > index)
            {
				PushLstack(&st, right);
				PushLstack(&st, index+1);
            }
		}
	}
	ClearLstack(&st);
}

/* �������� */
void CountSort(int *arr, int length, int max, int min)
{
	int range = max - min + 1;
	int *count = (int *)calloc(range+1, sizeof(int));  /* ����������鲢��ʼ��Ϊ0 */
	int i,j;    /* ѭ������ */
	/* �������� */
	for (i = 0; i < length; i++)  
	{
		count[arr[i] - min + 1]++;   /* ��ԭ����ת��Ϊ��������,ԭ������ֵ����˼�,��Ӧ��ֵΪ���� */
	}
	/* ����ִ��ͳ�Ʋ��� */
	for (i = 0; i < range; i++)
	{
		count[i + 1] += count[i];
	}
	/* ִ�з������ */
	int *temp = (int *)malloc(length * sizeof(int));  /* ��ʱ���鴢�� */
	for (j = 0; j < length; j++)
	{
		temp[count[arr[j] - min]++] = arr[j];  /* ���һ�����ֺ�����,ʵ����ͬ���ֵ��ȶ����� */
	}
	for (i = 0; i < length; i++)  /* ���ƻ�ԭ�������� */
	{
		arr[i] = temp[i];
	}

}

/* �����������ֵ */
int Max(int *arr, int length)
{
	int max = arr[0];
	int i;
	for (i = 0; i < length; i++) 
	{
		if (arr[i] > max) 
		{
			max = arr[i];
		}
	}
	return max;
}

/* �����Сֵ */
int Min(int *arr, int length)
{
	int min = arr[0];
	int i;
	for (i = 0; i < length; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

/* ������������ */
void RadixCountSort(int *arr, int length)
{
	/* ����������λ�� */
	int max = Max(arr, length);
	int bit = 0;
	if (max == 0)      
	{
		bit = 1;
	}
	while (max != 0)
	{
		max /= 10;
		bit++;
	}
	/* ʵ�ֻ������� */
	int i,j,m; /* ѭ������ */
	int **temp = (int **)malloc(10 * sizeof(int*));     /* ����һ����ά������ʱ��������,Ҳ���ǳ�ʼ����10��Ͱ */
	for (i = 0; i < 10; i++)
	{
		temp[i] = (int *)calloc(length, sizeof(int));
	}
	int *count = (int *)calloc(10 , sizeof(int));   /* �ü���������ÿ��������Ӧ��ֵ����ͬλ������Ӧ��Ͱ�����ֵ�λ�� */

	/* ��ò�ͬ��λ������,����ԭ�����е����ŵ���Ӧ��Ͱ��,��ȡ�ഢ�� */
	int rate = 1;  /* �����Բ�ͬλ��ȡ��ı��� */
	for (i = 0; i < bit; i++)
	{
		for (j = 0; j < length; j++)
		{
			for (m = 0; m < 10; m++)
			{
				count[m] = 0;
			}
			int remainder = (arr[j] / rate) % 10;  /* ���� */
			temp[remainder][count[remainder]] = arr[j];
			count[remainder]++; /* λ�ú��� */
		}
		rate *= 10;
	}
	/* ����ѭ����Ͱ�а�˳��ȡֵ */
	int index = 0;
	for (i = 0; i < 10; i++)
	{
		if (count[i] > 0)
		{
			for (j = 0; j < count[i]; j++)
			{
				arr[index] = temp[i][j];  /* ����ά�����е�ֵ����һά���� */
				if (index + 1 != 10)
				{
					index++;
				}
			}
		}
		count[i] = 0;  /* ���� */
	}
	free(temp);
	free(count);
}

/* �������� */
void swap(int *x, int *y) 
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/* ��ɫ���� */
void ColorSort(int *arr, int length)
{
	int p0, p1, p2;
	p0 = 0;
	p2 = length - 1;
	for (p1 = 0; p1 < length;p1++)
	{
		while (p1<p2 && arr[p1] == 2)  /* ���н���֮���µ�ֵ������Ȼ��2Ҳ������0,Ȼ����ʱ�����Ѿ������˽���,�ͻ����2��ǰ�Ĵ��� */
		{
			swap(&arr[p2], &arr[p1]);
			p2--;
		}
		if (arr[p1] == 0)
		{
			swap(&arr[p0], &arr[p1]);
			p0++;
		}
	}
}

/* �õ���K���ֵ */
int FindKthLarge(int *arr, int left, int right, int k)
{
	int pos = Partition(arr, left, right);
	while (pos != k)  /* �û����Ǵ�С���� */
	{
		if (pos >  k)
		{
			right = pos - 1;
			pos = Partition(arr, left, right);
		}
		if (pos <  k)
		{
			left = pos + 1;
			pos = Partition(arr, left, right);
		}
	}
	return arr[pos];
}

