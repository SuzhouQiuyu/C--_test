#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 7  //Ԫ�ظ���
typedef int Elemtype;

//�ϲ������������飨low��mid��mid+1��high��
void Merge(Elemtype arr[], int low, int mid, int high)
{
	static Elemtype arr1[N];  //����ռ��ԭ����arrһ����
	//static���εı���ִֻ�г�ʼ��һ�Σ������ݹ��������ִ�и����
	int i, j, k;  //i��j������������arr1��k��������arr
	for (i = low; i <= high; i++)
	{
		arr1[i] = arr[i];  //��ԭ�����Ԫ��ȫ�����Ƶ��µ�����
		//������бȽϵ�������������arr1�����ȽϺ�Ľ������ԭ����arr��
	}
	k = low;  //k�������ν��ź����Ԫ�طŽ�����arr��
	//�ϲ�������������
	for (i = low, j = mid + 1; i <= mid && j <= high;)  //i��j�ֱ��������arr1��mid��ߺ��ұߵ����飬���Խ�k++���ڷֺź�
	{
		if (arr1[i] < arr1[j])
		{
			arr[k] = arr1[i];  //arr1��mid��ߵ�������iλ�õ�Ԫ�ظ��Ƹ�arr
			i++;  //iָ����һ��λ�õ�Ԫ��
			k++;  //ÿ����arr����һ��Ԫ�أ�k������ƶ�һ��λ��
		}
		else  //����С�ڵ��ڵ����
		{
			arr[k] = arr1[j];  //arr1��mid�ұߵ�������jλ�õ�Ԫ�ظ��Ƹ�arr
			j++;  //jָ����һ��λ�õ�Ԫ��
			k++;  //ÿ����arr����һ��Ԫ�أ�k������ƶ�һ��λ��
		}
	}
	//������arr1��mid��߻��ұߵ������ȱ�������������i��j�������ж���������forѭ��ʱ�����ܴ�����һ�������л���Ԫ��
	while (i <= mid)
	{
		arr[k] = arr1[i];  //arr1��mid��ߵ�����ʣ��Ԫ�ظ��Ƹ�arr
		i++;
		k++;
	}
	while (j <= high)
	{
		arr[k] = arr1[j];  //arr1��mid�ұߵ�����ʣ��Ԫ�ظ��Ƹ�arr
		j++;
		k++;
	}
}
//�鲢����
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
	MergeSort(arr, 0, 6);  //0��6Ϊ����arr����Ԫ�غ�ĩβԪ�ص��±�
	Print(arr);
	return 0;
}