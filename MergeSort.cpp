#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 7  //元素个数
typedef int Elemtype;

//合并两个有序数组（low到mid和mid+1到high）
void Merge(Elemtype arr[], int low, int mid, int high)
{
	static Elemtype arr1[N];  //额外空间和原数组arr一样大
	//static修饰的变量只执行初始化一次，后续递归操作不再执行该语句
	int i, j, k;  //i和j用来遍历数组arr1，k用来遍历arr
	for (i = low; i <= high; i++)
	{
		arr1[i] = arr[i];  //将原数组的元素全部复制到新的数组
		//而后进行比较的数组是新数组arr1，将比较后的结果存在原数组arr中
	}
	k = low;  //k用来依次将排好序的元素放进数组arr中
	//合并两个有序数组
	for (i = low, j = mid + 1; i <= mid && j <= high;)  //i和j分别遍历数组arr1中mid左边和右边的数组，可以将k++放在分号后
	{
		if (arr1[i] < arr1[j])
		{
			arr[k] = arr1[i];  //arr1中mid左边的数组中i位置的元素复制给arr
			i++;  //i指向下一个位置的元素
			k++;  //每次往arr放入一个元素，k都向后移动一个位置
		}
		else  //包括小于等于的情况
		{
			arr[k] = arr1[j];  //arr1中mid右边的数组中j位置的元素复制给arr
			j++;  //j指向下一个位置的元素
			k++;  //每次往arr放入一个元素，k都向后移动一个位置
		}
	}
	//当数组arr1中mid左边或右边的数组先遍历结束，即当i或j不满足判断条件跳出for循环时，可能存在另一半数组中还有元素
	while (i <= mid)
	{
		arr[k] = arr1[i];  //arr1中mid左边的数组剩余元素复制给arr
		i++;
		k++;
	}
	while (j <= high)
	{
		arr[k] = arr1[j];  //arr1中mid右边的数组剩余元素复制给arr
		j++;
		k++;
	}
}
//归并排序
void MergeSort(Elemtype arr[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(arr, low, mid);
		MergeSort(arr, mid + 1, high);
		Merge(arr, low, mid, high);
	}
}

void Print(Elemtype* arr)
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("%3d", arr[i]);
	}
}

int main()
{
	int arr[N] = { 49,38,65,97,76,13,27 };
	MergeSort(arr, 0, 6);  //0和6为数组arr的首元素和末尾元素的下标
	Print(arr);
	return 0;
}