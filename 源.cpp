#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int hello(int *b)
//{
//	return *b = *b + 1;
//}
//int main()
//{
//	int a = 10;
//	hello(&a);
//	printf("%d", a);
//	return 0;
//}


//int hello(int &b)
//{
//	return b = b + 1; 
//}
//int main()
//{
//	int a = 10;
//	hello(a);
//	printf("%d", a);
//	return 0;
//}

//int modify(int *&p, int *q)  //&Ҫ���ڱ�����
//{
//	p = q;
//	return *p;
//}
//int main()
//{
//	int i = 10;
//	int *p = NULL;
//	int *q = &i;
//	modify(p, q);  //���������
//	printf("%d", *p);
//	return 0;
//}

//int modify(int** p, int* q)
//{
//	*p = q;
//	return **p;
//}
//int main()
//{
//	int i = 10;
//	int* p = NULL;	
//	int* q = &i;
//	modify(&p, q);
//	printf("%d", *p);
//	return 0;
//}

//����һ��ѧ����ѧ�ţ��������Ա��ýṹ��洢��ͨ��scanf��ȡ��Ȼ����ͨ��printf��ӡ���
//typedef struct student 
//{	
//	char number[10];
//	char name[10];
//	char sex;
//}stu;
//int main()
//{
//	stu s = {};
//	scanf("%s %s %c", &s.number, &s.name, &s.sex);
//	printf("%s %s %c", s.number, s.name, s.sex);
//	return 0;
//}

//ʹ��C++�����ã�ע���ύʱ�Ѵ���ѡΪC++���������������ַ�ָ�� char *p,  
//Ȼ�����Ӻ�����malloc����ռ䣨��СΪ100���ֽڣ���ͨ��fgets��ȡ�ַ�����
//Ȼ�����������н��������Ҫ���Ӻ���ʹ��C++�����ã�
//ע����C++�дӱ�׼�����ȡ�ַ�������Ҫʹ��fgets(p,100,stdin)
//#include <stdlib.h>
//void Print(char*& p)
//{
//	p = (char*)malloc(100);
//	fgets(p, 100, stdin);
//}
//int main()
//{
//	char* p = NULL;
//	Print(p);
//	puts(p);
//	free(p);
//	return 0;
//}


//void Pin(int*& p, int* q)
//{
//	p = q;
//}
//int main()
//{
//	int* p = NULL;
//	int i = 10;
//	int* q = &i;
//	Pin(p, q);
//	printf("%d", *p);
//	return 0;
//}
