//#include <stdio.h>
//
//void a1()
//__attribute__((__warning__("S")));
//
//void a1()
//{
//	int a = 101;
//	int sum = 0;
//	do
//	{
//	if (a % 2 == 0) sum += a;
//	a++;
//	}
//	while (a < 300);
//	printf("%d\n", sum);
//}
//
//void a2()
//{
//	int i = 100;
//	int count = 0;
//	do
//	{
//	i++;
//	if (i % 2 == 0 && i % 3 == 0)
//	{
//	printf("%d ", i);
//	count++;
//	if (count % 5 == 0)
//	{
//	putchar('\n');
//	}
//	}
//	}
//	while (i < 1000);
//}
//
//void a3()
//{
//	int a, b, c;
//	scanf("%d%d", &a, &b);
//
//	int m = a * b;
//
//	if (a < b)
//	{
//	int temp = a;
//	a = b;
//	b = temp;
//	}
//
//	c = a % b;
//
//	while (c)
//	{
//	a = b;
//	b = c;
//	c = a % b;
//	}
//
//	printf("最大公因数为 %d 最小公倍数为 %d\n", b, m / b);
//}
//
//void a4()
//{
//	int a, b, c;
//	scanf("%d%d", &a, &b);
//
//	int m = a * b;
//
//	if (a < b)
//	{
//	int temp = a;
//	a = b;
//	b = temp;
//	}
//
//	do
//	{
//	c = a % b;
//	a = b;
//	b = c;
//	}
//	while (c);
//
//	printf("最大公因数为 %d 最小公倍数为 %d\n", a, m / a);
//}
//
//void a5()
//{
//	int a, b, c;
//	scanf("%d%d", &a, &b);
//
//	int m = a * b;
//
//	if (a < b)
//	{
//	int temp = a;
//	a = b;
//	b = temp;
//	}
//
//	//for(c = a % b; c; a = b, b = c,c = a % b);
//	for (; c = a % b; a = b, b = c, c = a % b);
//	printf("最大公因数为 %d 最小公倍数为 %d\n", b, m / b);
//}
//
//void a6()
//{
//	int a, b, c;
//	scanf("%d%d", &a, &b);
//
//	int m = a * b;
//
//	if (a < b)
//	{
//	int temp = a;
//	a = b;
//	b = temp;
//	}
//
//	for (c = a % b; c; a = b, b = c, c = a % b);
//	printf("最大公因数为 %d 最小公倍数为 %d\n", b, m / b);
//}
//
//void a7()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//
//	int m = a * b;
//
//	if (a < b)
//	{
//	int temp = a;
//	a = b;
//	b = temp;
//	}
//
//	while (a != b)
//	{
//	if (a > b) a -= b;
//	else b -= a;
//	}
//
//	printf("最大公因数为 %d 最小公倍数为 %d\n", b, m / b);
//}
//
//void a8()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//
//	int m = a * b;
//
//	if (a < b)
//	{
//	int temp = a;
//	a = b;
//	b = temp;
//	}
//
//	do
//	{
//	if (a > b) a -= b;
//	else b -= a;
//	}
//	while (a != b);
//
//	printf("最大公因数为 %d 最小公倍数为 %d\n", b, m / b);
//}
//
//void a9()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//
//	int m = a * b;
//
//	if (a < b)
//	{
//	int temp = a;
//	a = b;
//	b = temp;
//	}
//
//	for (; a != b;)
//	{
//	if (a > b) a -= b;
//	else b -= a;
//	}
//
//	printf("最大公因数为 %d 最小公倍数为 %d\n", b, m / b);
//}
//
//void b1()
//{
//	char input[128];
//	gets(input);
//
//	int alpha = 0;
//	int number = 0;
//	int space = 0;
//	int others = 0;
//
//	int i = 0;
//
//	do
//	{
//	if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
//	{
//	alpha++;
//	}
//	else if (input[i] >= '0' && input[i] <= '9')
//	{
//	number++;
//	}
//	else if (input[i] == ' ')
//	{
//	space++;
//	}
//	else
//	{
//	others++;
//	}
//	i++;
//	}
//	while (input[i]);
//
//	printf("字母数为 %d 数字数为 %d 空格为 %d 其他字符为 %d\n", alpha, number, space, others);
//}
//
//void b2()
//{
//	char input[128];
//	gets(input);
//
//	int alpha = 0;
//	int number = 0;
//	int space = 0;
//	int others = 0;
//
//	int i = 0;
//
//	while (input[i])
//	{
//	if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
//	{
//	alpha++;
//	}
//	else if (input[i] >= '0' && input[i] <= '9')
//	{
//	number++;
//	}
//	else if (input[i] == ' ')
//	{
//	space++;
//	}
//	else
//	{
//	others++;
//	}
//	i++;
//	}
//
//	printf("字母数为 %d 数字数为 %d 空格为 %d 其他字符为 %d\n", alpha, number, space, others);
//}
//
//void b3()
//{
//	char input[128];
//	gets(input);
//
//	int alpha = 0;
//	int number = 0;
//	int space = 0;
//	int others = 0;
//
//	int i = 0;
//
//	while (input[i])
//	{
//	if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
//	{
//	alpha++;
//	}
//	else if (input[i] >= '0' && input[i] <= '9')
//	{
//	number++;
//	}
//	else if (input[i] == ' ')
//	{
//	space++;
//	}
//	else
//	{
//	others++;
//	}
//	i++;
//	}
//
//	printf("字母数为 %d 数字数为 %d 空格为 %d 其他字符为 %d\n", alpha, number, space, others);
//}
//
//void b4()
//{
//	char input[128];
//	gets(input);
//
//	int alpha = 0;
//	int number = 0;
//	int space = 0;
//	int others = 0;
//
//	for (int i = 0; input[i]; i++)
//	{
//	if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
//	{
//	alpha++;
//	}
//	else if (input[i] >= '0' && input[i] <= '9')
//	{
//	number++;
//	}
//	else if (input[i] == ' ')
//	{
//	space++;
//	}
//	else
//	{
//	others++;
//	}
//	}
//
//	printf("字母数为 %d 数字数为 %d 空格为 %d 其他字符为 %d\n", alpha, number, space, others);
//}
//
//void b5()
//{
//	long long sum = 0;
//	long long a = 0;
//	for (int i = 1; i <= 10; i++)
//	{
//	a = a * 10 + 3;
//	sum += a;
//	}
//	printf("%lld ", sum);
//}
//
//void b6()
//{
//	long long sum = 0;
//	long long a = 0;
//
//	int i = 1;
//
//	while (i <= 10)
//	{
//	a = a * 10 + 3;
//	sum += a;
//	i++;
//	}
//
//	printf("%lld\n", sum);
//}
//
//void b7()
//{
//	long long sum = 0;
//	long long a = 0;
//
//	int i = 1;
//
//	do
//	{
//	a = a * 10 + 3;
//	sum += a;
//	i++;
//	}
//	while (i <= 10);
//
//	printf("%lld\n", sum);
//}
////a + aa + aaa ...
////f(n - 1) * 10 + a = f(n)
//
//long long int F(int x, int a)
//{
//	if(x == 1) return a;
//	return F(x - 1, a) * 10 + a;
//}
//
//void print(int x)
//{
//	if(x > 1)
//	{
//	print(x / 10);
//	}
//
//	printf("%d ", x % 10);
//}
//
//#include <math.h>
//int main()
//{
////	//5
////
////	//3列为中间行
////	/*
////	*	' '		line
////	1	2		1	3-1=2
////	2	1		2	3-2=1
////	3	0		3	3-3=0
////	2	1		4	3-4=-1
////	1	2		5	3-5=-2
////	*/
////
////	/*
////	00*
////	0***
////	*****
////	0***
////	00*
////	*/
////	int i, j, k, m = 10;
////
////	int h = m / 2 + 1;
////
////	for(i = 1; i <= m; i++)
////	{
////	for(j = 1; j <= abs(h - i); j++)	putchar(' ');
////	for(k = 1; k <= abs(2 * h - 1 - 2 * (j - 1)); k++) putchar('#');
////	putchar('\n');
////	}
////
////	for(i = 1; i <= m; i++)
////	{
////	int c = h - i;
////
////	if(c < 0) c = -c;
////	for(j = 1; j <= c; j++)	putchar(' ');
////	for(k = 1; k <= 2 * h - 1 - 2 * (j - 1); k++) putchar('#');
////	putchar('\n');
////	}
////
////	for(i = 1; i <= h; i++)
////	{
////	for(j = 1; j <= h - i; j++)	putchar(' ');
////
////	for(k = 1; k <= 2 * h - 1 - 2 * (j - 1); k++) putchar('@');
////	putchar('\n');
////	}
////
////	for(i = 1; i < h; i++)
////	{
////	for(j = 1; j <= i; j++)	putchar(' ');
////
////	for(k = 1; k <= 2 * h - 1 - 2 * (j - 1); k++) putchar('@');
////	putchar('\n');
////	}
//	//设机为i 兔为35 - i
//
////	#define zong 572570959
////
////	for(long long i = 0; i <= zong; i++)
////	{
////	long long j = zong - i;
////
////	if(2 * i + 4 * j == 1145141918)
////	{
////	printf("鸡有 %lld 兔有 %lld\n", i, j);
////	}
////	}
//
//	return 0;
//}
#define PRINT(array, size)	\
	for(int i = 0; i < size; ++i)	\
		printf("%d ", array[i]);	\
	putchar('\n')
#include <stdio.h>

#define SIZE 10

int main()
{
	int a = 0X114514;

	printf("%d\n", ((char *)&a)[0] == 0x14);
}
