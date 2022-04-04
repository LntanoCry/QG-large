/****************************** 
* FileName		:	MySort.h
* Created Time  :	2022/4/3
* Author		:	Chen Runyu
* --------Introduction--------
* QG训练营的第三周大组任务
* 排序算法的实现
******************************/

#ifndef MYSORT_H_
#define MYSORT_H_

#include <stdio.h>

/* 用来打印数组 */
void PrintArray(int *arr, int length);

/* 获得数组的最大值 */
int Max(int *arr, int length);

/* 获得最小值 */
int Min(int *arr, int length);

/* 插入排序 */
void InsertSort(int *arr, int length); /* arr是指向数组的指针,length为数组长度 */

/* 归并排序,提供给用户使用的接口 */
void MergeSort(int *arr, int length); 

/* 执行归并排序的合并操作 */
void MergeArray(int *arr, int *temp, int left, int mid, int right); /* temp是临时数组 */

/* 执行归并排序的划分操作 */
void Merge_sort(int *arr, int *temp, int left, int right);  /* temp是临时数组 */

/* 快速排序,递归版 */
void QuickSort_Recursion(int *arr, int left, int right);

/* 寻找并返回枢轴存放位置 */
int Partition(int *arr, int left, int right);

/* 快速排序,非递归 */
void QuickSort(int *arr, int length);

/* 计数排序 */
void CountSort(int *arr, int length, int max, int min); /* max是数组中的最大值,min是最小值 */

/* 基数计数排序 */
void RadixCountSort(int *arr, int length);

/* 颜色排序 */
void ColorSort(int *arr, int length);

/* 用来交换 */
void swap(int *x, int *y);

/* 得到第K大的值 */
int FindKthLarge(int *arr, int left, int right, int k);

#endif /* MYSORT_H_ */