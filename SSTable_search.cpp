#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//ָ��ʵ��˳���
typedef int Elemtype;
//����˳���
typedef struct
{
	Elemtype* elem;  //ָ�룬�����Զ�������ѿռ����ʼ��ַ����elem
	int TableLen;  //�洢�ڶ�̬������Ԫ�صĸ���
}SSTable;

void ST_Init(SSTable& ST, int len)
{
	ST.TableLen = len + 1;  //��Ҫ������һ��λ�ã�ԭ����0��λ�ô�š��ڱ���
	ST.elem = (Elemtype*)malloc(sizeof(Elemtype) * ST.TableLen);  //ָ��elemָ���ÿ��Ԫ�ض���Elemtype���͵ģ�int��
	int i;
	srand(time(NULL));  //���������
	for (i = 1; i < ST.TableLen; i++)  //0��λ�����ڱ����������1��λ�ÿ�ʼ
	{
		ST.elem[i] = rand() % 100;  //%100ʹ�����ɵ��������0-99֮��
	}
}

//��ӡ˳���
void ST_Print(SSTable ST)
{
	int i;
	for (i = 1; i < ST.TableLen; i++)
	{
		printf("%3d", ST.elem[i]);  //������������ʣ�elem�൱��������
	}
	printf("\n");
}

int search_seq(SSTable ST, Elemtype key)
{
	ST.elem[0] = key;  //key����0��λ�ã���Ϊ�ڱ����ڱ��Ĵ��ڿ��п��ޣ��ڱ����ڵ�������ѭ���ж���������дi>=0
	int i;
	for (i = ST.TableLen - 1; ST.elem[i] != key; i--);
	return i;
}
int main()
{
	SSTable ST;
	ST_Init(ST, 10);
	ST_Print(ST);  //��ӡ˳����е�Ԫ�أ�˳����е�Ԫ��λ�ô�1��ʼ��
	Elemtype key;
	printf("������Ҫ���ҵ�keyֵ\n");
	scanf("%d", &key);
	int pos;  //���Һ������ص��±�λ��
	pos = search_seq(ST, key);
	if (pos)
	{
		printf("�ҵ��ˣ�λ��Ϊ%d\n", pos);
	}
	else
	{
		printf("û���ҵ�\n");
	}
	return 0;
}