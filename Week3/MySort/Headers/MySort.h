/****************************** 
* FileName		:	MySort.h
* Created Time  :	2022/4/3
* Author		:	Chen Runyu
* --------Introduction--------
* QGѵ��Ӫ�ĵ����ܴ�������
* �����㷨��ʵ��
******************************/

#ifndef MYSORT_H_
#define MYSORT_H_

#include <stdio.h>

/* ������ӡ���� */
void PrintArray(int *arr, int length);

/* �����������ֵ */
int Max(int *arr, int length);

/* �����Сֵ */
int Min(int *arr, int length);

/* �������� */
void InsertSort(int *arr, int length); /* arr��ָ�������ָ��,lengthΪ���鳤�� */

/* �鲢����,�ṩ���û�ʹ�õĽӿ� */
void MergeSort(int *arr, int length); 

/* ִ�й鲢����ĺϲ����� */
void MergeArray(int *arr, int *temp, int left, int mid, int right); /* temp����ʱ���� */

/* ִ�й鲢����Ļ��ֲ��� */
void Merge_sort(int *arr, int *temp, int left, int right);  /* temp����ʱ���� */

/* ��������,�ݹ�� */
void QuickSort_Recursion(int *arr, int left, int right);

/* Ѱ�Ҳ�����������λ�� */
int Partition(int *arr, int left, int right);

/* ��������,�ǵݹ� */
void QuickSort(int *arr, int length);

/* �������� */
void CountSort(int *arr, int length, int max, int min); /* max�������е����ֵ,min����Сֵ */

/* ������������ */
void RadixCountSort(int *arr, int length);

/* ��ɫ���� */
void ColorSort(int *arr, int length);

/* �������� */
void swap(int *x, int *y);

/* �õ���K���ֵ */
int FindKthLarge(int *arr, int left, int right, int k);

#endif /* MYSORT_H_ */