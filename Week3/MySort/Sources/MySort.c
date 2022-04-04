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

/* 打印数组 */
void PrintArray(int *arr, int length)
{
	int i;
	printf("该数组为: \n");
	printf("[");
	for (i = 0; i < length; i++)
	{
		printf("%d",arr[i]);
		if (i != length - 1) /* 为了打印数组的美观 */
		{
			printf(",");
		}
	}
	printf("]\n");
}



/* 插入排序 */
void InsertSort(int *arr, int length)
{
	int i, j, temp;
	for (i = 1; i < length; i++)  /* i决定待插入的值 */
	{
		temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > temp; j--) /* j用来向前遍历且j要可以等于0,即与第一个元素比较 */
			{
				arr[j + 1] = arr[j]; /* 后移一位 */
			}
		arr[j + 1] = temp;
	}
}


/* 归并排序,提供给用户使用的接口 */
void MergeSort(int *arr, int length)
{
	int *temp = (int *)malloc(length * sizeof(int)); /* 创建并为临时数组分配内存 */

	if (temp)
	{
		Merge_sort(arr, temp, 0, length-1);
		free(temp);  /* 释放临时数组的内存 */
	}
	else
	{
		printf("错误:临时数组分配失败!\n");
	}
}

/* 执行归并排序的合并操作 */
void MergeArray(int *arr, int *temp, int left, int mid, int right)
{
	int lpos = left;     /* 标记左半部分第一个元素			 */
	int rpos = mid + 1;	 /* 标记右半部分第一个元素			 */
	int pos = left;		 /* 标记合并后的临时数组的第一个元素 */

	while (lpos <= mid && rpos <= right)  /* 比较左半区和右半区第一个元素 */
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

	while (lpos <= mid)		/* 当右半部分为空时 */
	{
		temp[pos++] = arr[lpos++];
	}

	while (rpos <= right)	/* 当左半部分为空时 */
	{
		temp[pos++] = arr[rpos++];
	}

	while (left <= right)	/* 将临时数组复制给原数组 */
	{
		arr[left] = temp[left];
		left++;
	}
}

/* 执行归并排序的划分操作 */
void Merge_sort(int *arr, int *temp, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;				/* 划分中间点		*/

		Merge_sort(arr, temp, left, mid);			/* 递归划分左半部分 */
		Merge_sort(arr, temp, mid + 1, right);		/* 递归划分右半部分 */

		MergeArray(arr, temp, left, mid, right);	/* 执行合并操作		*/
	}
}

/* 快速排序,递归版 */
void QuickSort_Recursion(int *arr, int left, int right)
{
	if (left < right)
	{
		int index = Partition(arr, left, right);
		QuickSort_Recursion(arr, left, index - 1);  /* 递归操作 */
		QuickSort_Recursion(arr, index + 1, right);
	}
}

/* 寻找并返回枢轴索引 */
int Partition(int *arr, int left, int right)  /* 同时也有划分区域的作用 */
{
	int key = arr[left];
	if (left < right)
	{
		while (left < right)   /* 若无此条件,right=-1会报错 */
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
				left++;     /* 不断右移 */
			}
			if (left < right)
			{
				arr[right--] = arr[left];
			}
		}
	}
	arr[left] = key;  /* 此时left=right,确定了枢轴应该位于的位置 */
	return left;
}

/* 快速排序,非递归实现 */
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
			int index = Partition(arr, left, right);   /* 此操作完全相同,并且所处的位置是非递归方法的关键 */
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

/* 计数排序 */
void CountSort(int *arr, int length, int max, int min)
{
	int range = max - min + 1;
	int *count = (int *)calloc(range+1, sizeof(int));  /* 分配计数数组并初始化为0 */
	int i,j;    /* 循环变量 */
	/* 计数操作 */
	for (i = 0; i < length; i++)  
	{
		count[arr[i] - min + 1]++;   /* 将原数组转化为计数数组,原来的数值变成了键,对应的值为次数 */
	}
	/* 下面执行统计操作 */
	for (i = 0; i < range; i++)
	{
		count[i + 1] += count[i];
	}
	/* 执行分配操作 */
	int *temp = (int *)malloc(length * sizeof(int));  /* 临时数组储存 */
	for (j = 0; j < length; j++)
	{
		temp[count[arr[j] - min]++] = arr[j];  /* 填充一个数字后自增,实现相同数字的稳定排序 */
	}
	for (i = 0; i < length; i++)  /* 复制回原来的数组 */
	{
		arr[i] = temp[i];
	}

}

/* 获得数组的最大值 */
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

/* 获得最小值 */
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

/* 基数计数排序 */
void RadixCountSort(int *arr, int length)
{
	/* 获得最大数的位数 */
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
	/* 实现基数排序 */
	int i,j,m; /* 循环变量 */
	int **temp = (int **)malloc(10 * sizeof(int*));     /* 分配一个二维数组临时储存数据,也就是初始化了10个桶 */
	for (i = 0; i < 10; i++)
	{
		temp[i] = (int *)calloc(length, sizeof(int));
	}
	int *count = (int *)calloc(10 , sizeof(int));   /* 该计数数组中每个索引对应的值即不同位余数对应的桶中数字的位置 */

	/* 获得不同数位的余数,并把原数组中的数放到对应的桶中,即取余储存 */
	int rate = 1;  /* 用来对不同位数取余的变量 */
	for (i = 0; i < bit; i++)
	{
		for (j = 0; j < length; j++)
		{
			for (m = 0; m < 10; m++)
			{
				count[m] = 0;
			}
			int remainder = (arr[j] / rate) % 10;  /* 余数 */
			temp[remainder][count[remainder]] = arr[j];
			count[remainder]++; /* 位置后移 */
		}
		rate *= 10;
	}
	/* 进行循环从桶中按顺序取值 */
	int index = 0;
	for (i = 0; i < 10; i++)
	{
		if (count[i] > 0)
		{
			for (j = 0; j < count[i]; j++)
			{
				arr[index] = temp[i][j];  /* 将二维数组中的值放入一维数组 */
				if (index + 1 != 10)
				{
					index++;
				}
			}
		}
		count[i] = 0;  /* 置零 */
	}
	free(temp);
	free(count);
}

/* 用来交换 */
void swap(int *x, int *y) 
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/* 颜色排序 */
void ColorSort(int *arr, int length)
{
	int p0, p1, p2;
	p0 = 0;
	p2 = length - 1;
	for (p1 = 0; p1 < length;p1++)
	{
		while (p1<p2 && arr[p1] == 2)  /* 进行交换之后新的值可能仍然是2也可能是0,然而此时我们已经结束了交换,就会出现2在前的错误 */
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

/* 得到第K大的值 */
int FindKthLarge(int *arr, int left, int right, int k)
{
	int pos = Partition(arr, left, right);
	while (pos != k)  /* 该划分是从小到大 */
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

