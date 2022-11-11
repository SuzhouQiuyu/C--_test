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

//int modify(int *&p, int *q)  //&要紧邻变量名
//{
//	p = q;
//	return *p;
//}
//int main()
//{
//	int i = 10;
//	int *p = NULL;
//	int *q = &i;
//	modify(p, q);  //传入变量名
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

//输入一个学生的学号，姓名，性别，用结构体存储，通过scanf读取后，然后再通过printf打印输出
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

//使用C++的引用，注意提交时把代码选为C++；在主函数定义字符指针 char *p,  
//然后在子函数内malloc申请空间（大小为100个字节），通过fgets读取字符串，
//然后在主函数中进行输出；要求子函数使用C++的引用，
//注意在C++中从标准输入读取字符串，需要使用fgets(p,100,stdin)
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
