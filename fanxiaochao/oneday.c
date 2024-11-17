#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "yuanshen.h"
#include <time.h>

#define S 100
#define J 10

int *binary(int x);

int binary_helper(int x, int *sum);

void InsertSort(int *array, int size);

long fact(int x);
//1 3 5 7 9 11
//f(1) = 1
//f(n) = f(n - 1) + 2

//3 15 35 63 99
//f(1) = 3 					(n = 1)
//f(n) = f(n - 1) + 8n + 4 (n >= 2)
//f(2) = f(1) + 20
long jishu(int x)
{
	if(x == 1) return 1;

	return jishu(x - 1) + 2;
}

//3 15 35 63 99的数列
long fx(int n)
{
	if(n == 1)
	{
		return 3;
	}

	return fx(n - 1) + 8 * n - 4;
}

//偶数列
long fsx(int n)
{
	if(n == 1)
	{
		return 2;
	}

	return fsx(n - 1) + 2;
}

//斐波拉契数列
long FLB(int x)
{
	if(x == 1 || x == 2) return 1;

	return FLB(x - 1) + FLB(x - 2);
}


long adds(int n)
{
	if(n == 1) return 1;

	return adds(n - 1) + n;
}

int sumss(int array[], int size)
{
	if(size == 0) return array[0];

	return sumss(array, size - 1) + array[size];
}

int max(int array[], int size)
{
	if(size == 0)
	{
		return array[0];
	}

	if(max(array, size - 1) > array[size])
		return max(array, size - 1);
	else
		return array[size];
}

int main()
{
	//一个球从M米高度自由落下，每次落地后反弹回原高度的一半，再落下，再反弹。求它在第3次落地时，共经过多少米? 第3次反弹多高?？ 保留两位小数C语言
//	int array[] = {1, 1, 4, 114514, 1, 4};
//	printf("%ld\n", fx(5));
	
	int n = 7;
	int sum = 0;
	int tn = 1;
	for(int i = 1; i <= n; i++)
	{
		sum += i  * tn;
		tn = -tn;
	}
	printf("%d\n", sum);
	
//	int a, b, c;
//
//	scanf("%d%d%d", & a, & b, & c);
//
//	int temp;
//	if(b > a) temp = a, a = b, b = temp;
//	if(c > a) temp = a, a = c, c = temp;
//	if(b > c) temp = c, c = b, b = temp;
//
//	printf("%d %d %d %f\n", a, b, c, (a + b + c) / 3.0);
//	int array[10];
//
//	scanf("%d", &array[0]);
//
//	int m, min;
//
//	m = min = array[0];
//
//	int o_sum, ji_sum;
//	o_sum = ji_sum = 0;
//
//	if(array[0] % 2 == 0)
//	{
//	o_sum += array[0];
//	}
//	else ji_sum += array[0];
//
//	for(int i = 1; i < 10; i++)
//	{
//	scanf("%d", &array[i]);
//
//	if(array[i] > m)
//	{
//	m = array[i];
//	}
//
//	if(array[i] < min)
//	{
//	min = array[i];
//	}
//	if(array[i] % 2 == 0)
//	{
//	o_sum += array[i];
//	}
//	else
//	{
//	ji_sum += array[i];
//	}
//	}
//
//	printf("max %d min %d o %d ji %d\n", m, min, o_sum, ji_sum);

//	float score;
//	scanf("%f", &score);
//
//	char flag[12];
//
//	switch ((int)score/10)
//	{
//	case 1: case 2: case 3: case 4: case 5: case 6: strcpy(flag, "不及格");break;
//	case 7: strcpy(flag, "及格");break;
//	case 8: strcpy(flag, "良好");break;
//	case 9: case 10: strcpy(flag, "优秀");
//	}
//
//	printf("%s\n", flag);

//	int x, n;
//
//	scanf("%d%d", &x, &n);
//
//	int sum = 0;
//	for(int e = 1; x; x /= n, e *= 10)
//	{
//	sum = sum + (x % n) * e;
//	}
//
//	printf("%d进制 -> %d\n", n, sum);

//	double M = S;
//	int N = J;
//
//	double sum = M;
//
//	for(int i = 1; i < N; i++)
//	{
//	M /= 2;
//	sum += M * 2;
//	}
//
//	printf("%d次落地经过 %lf M\n%d次反弹 %lf M\n", N, sum, N, M);
//
//	M = S, N = J, sum = 0.0;
//
//	for(int i = 1; i <= N; i++)
//	{
//	sum += M;
//	M /= 2;
//	if(i < N) sum += M;
//	}
//
//	printf("\n%d次落地经过 %lf M\n%d次反弹 %lf M\n", N, sum, N, M);
//
//	M = S, N = J, sum = 0.0;
//
//	for(int i = 1; i <= N; i++)
//	{
//	sum += M;
//	M /= 2;
//	if(i == N) break;
//	sum += M;
//	}
//
//	printf("\n%d次落地经过 %lf M\n%d次反弹 %lf M\n", N, sum, N, M);
//
//	M = S, N = J, sum = 0.0;
//
//	for(int i = 2; i <= N; i++)
//	{
//	M /= 2;
//	sum += M * 2;
//	}
//
//	printf("\n%d次落地经过 %lf M\n%d次反弹 %lf M\n", N, sum, N, M);
	//输入一串由小写字母组成的明文,把每个字母向后循环位移5个位置变成密文后输出,‘z‘后,又从‘a'开始。例如输入“abxz”则变为“fgcd”
	//插入排序

//	int a;
//	scanf("%d", &a);
//
//	for(int i = 2; i * i <= a; i++)
//	{
//	if(a % i == 0)
//	{
//	printf("%d = %6d * %6d\n", a, i, a / i);
//	}
//	}

//	char array[64];
//
//	fgets(array, 64, stdin);
//
//	int sum = 0;
//	for(int i = 0; array[i] != 0;i++)
//	{
//	//a1b2c3
//	if((array[i] >= '0' && array[i] <= '9'))
//	{
//	sum = sum * 10 + (array[i] - '0');
//	}
//	}
//
//	printf("%d\n", sum);
//	int year, month, day;
//	int i = scanf("%4d/%2d/%2d", & year, & month, & day);
//	if(i == 3)
//	{
//	int sum = day;
//	switch(month - 1)
//	{
//	case 11:
//	sum += 31;
//	case 10:
//	sum += 30;
//	case 9:
//	sum += 31;
//	case 8:
//	sum += 30;
//	case 7:
//	sum += 31;
//	case 6:
//	sum += 31;
//	case 5:
//	sum += 30;
//	case 4:
//	sum += 31;
//	case 3:
//	sum += 30;
//	case 2:
//	sum += 31;
//	case 1:
//	if((year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0) sum += 29;
//	else sum += 28;
//	}
//
//	printf("%d/%d/%d is the %d day of %d\n", year, month, day, sum, year);
//	}
//	int a;
//	scanf("%d", &a);
//
//
//	int i, sum;
//	sum = 0;
//	for(i = 1; a != 0; a /= 2, i *= 10)
//	{
//	sum += (a % 2) * i;
//	}
//
//	printf("%d\n", sum);
//	int count = 0, i, j;
//	for(i = 1000; i <= 10000; i++)
//	{
//	for(j = 2; j* j <= i; j++)
//	{
//	if(i % j == 0) break;
//	}
//
//	if(j* j > i)
//	{
//	count++;
//	printf("%d ", i);
//	if(count == 10)
//	{
//	printf("\n");
//	count = 0;
//	}
//	}
//	}
//	char input[64];
//	gets(input);
//
//	int i, s;
//	for(i = 0, s = 0; input[i]; i++)
//	{
//	if(input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z')
//	{
//	input[s++] = input[i];
//	}
//	}
//	input[s] = '\0';
//
//	printf("%s", input);
//	long long int a = 0x7FFFFFFFFFFFFFFF;
//
//	int array[64] = {0};
//	int i = 0;
//	for(; a; a /= 2)
//	{
//		if(a % 2 == 1)
//		{
//			array[i] = a % 2;
//		}
//		i++;
//	}
//	int count = 0;
//	for(int i = 63; i >= 0; i--)
//	{
//		if(count == 8)
//		{
//			printf(" ");
//			count = 0;
//		}
//		printf("%d", array[i]);
//		count++;
//	}

//	for(int i = 1; i <= 500; i++)
//	{
//	int t = i;
//	int length = 1;
//	while(t)
//	{
//	length *= 10;
//	t /= 10;
//	}
//	if((i * i) % length == i)
//	{
//	printf("%d\n", i);
//	}
//	}
//	for(int i = 1; i <= 500; i++)
//	{
//	int a, t;
//	for(a = i * i, t = i; t != 0; a /=10, t /= 10)
//	{
//	if(a % 10 != t % 10) break;
//	}
//	if(t == 0)
//	{
//	printf("%d\n", i);
//	}
//	}

//	int yuan = 10;
//	for(int i = 0; i <= yuan; i++)
//	{
//
//	for(int n = yuan; n > i; n--)
//	{
//	printf(" ");
//	}
//
//	for(int j = 0; j <= i; j++)
//	{
//	printf("%d ", C(i, j));
//
//	}
//	putchar('\n');
//	}

//	for(int i = 9; i >= 1; i--)
//	{
//	for(int j = 1; j <= i; j++)
//	{
//	printf("%d*%d=%d\t", i, j, i * j);
//	}
//	printf("\n");
//	}
//	int array[20][40] = {0};
//
//	array[0][0] = 1;
//
//	for(int i = 1; i < 9; i++)
//	{
//	for(int n = 1; n < 2 * i; n++)
//	{
//	array[i][n] = array[i - 1][n] + array[i - 1][n - 1];
//	}
//	}
//
//	for(int i = 0; i < 9; i++)
//	{
//	for(int n = 9; n > i; n--)
//	{
//	printf(" ");
//	}
//	for(int j = 0; j < 2 * i; j++)
//	{
//	if(array[i][j] != 0)
//	{
//	printf("%d ", array[i][j]);
//	}
//	}
//
//	printf("\n");
//
//	}

//	int array[] = {3, 2, 1, 4, 6, 7, -1};
//	int size = sizeof(array) / sizeof(array[0]);
//	for(int i = 0; i < size - 1; i++)
//	{
//	for(int j = 0; j < size - i - 1; j++)
//	{
//	if(array[j] > array[j + 1])
//	{
//	int temp = array[j];
//	array[j] = array[j + 1];
//	array[j + 1] = temp;
//	}
//	}
//	}

//	PRINT(array, size);
//
//	for(int i = 0; i < size - 1; i++)
//	{
//	int pos = i;
//	for(int j = i + 1; j < size; j++)
//	{
//	if(array[j] > array[pos])
//	{
//	pos = j;
//	}
//	}
//
//	int temp = array[i];
//	array[i] = array[pos];
//	array[pos] = temp;
//	}
//
//	PRINT(array, size);

	//输入今天是星期几，求x天后星期几
//	int a = 3;
//	int x = 12;
//	switch((a + x) % 7)
//	{
//	case 1:
//	printf("%d天后,是星期一\n", x);
//	break;
//	case 2:
//	printf("%d天后,是星期二\n", x);
//	break;
//	case 3:
//	printf("%d天后,是星期三\n", x);
//	break;
//	case 4:
//	printf("%d天后,是星期四\n", x);
//	break;
//	case 5:
//	printf("%d天后,是星期五\n", x);
//	break;
//	case 6:
//	printf("%d天后,是星期六\n", x);
//	break;
//	case 0:
//	printf("%d天后,是星期日\n", x);
//	break;
//
//	}
//
//	char ai[] = "日一二三四五六";
//
//	printf("%d天后是星期%c%c", x, ai[2 * ((a + x) % 7)], ai[2 * ((a + x) % 7) + 1]);
//	int yuan = 10;
//	for(int i = 0; i <= yuan; i++)
//	{
//
////		for(int n = yuan; n > i; n--)
////		{
////			printf(" ");
////		}
//
//	for(int j = 0; j <= i; j++)
//	{
//	if(C(i, j) == 1) putchar('*');
//	else putchar(' ');
//	}
//	putchar('\n');
//	}
//
//	for(int i = 0; i <= yuan + 1;i++) printf("*");

//	for(int i = 1; i <= 9; i++)
//	{
//	for(int o = 9; o > i; o--) printf(" ");
//	for(int j = 1; j <= 2*i-1; j++)
//	{
//	printf("%d", i);
//	}
//	printf("\n");
//	}

//	for(int i = 1; i <= 9; i++)
//	{
//	for(int j = 1; j <= i; j++)
//	{
//	printf("%d*%d=%d\t", i,j,i*j);
//	}
//	putchar('\n');
//	}

//	int space = 0;
//	int danci = 0;
//	for(int i = 0; input[i] != '\0'; i++)
//	{
//	if(input[i] == ' ')
//	{
//	space = 0;
//	}else if(space == 0)
//	{
//	space = 1;
//	danci++;
//	}
//	}
//
//	printf("%d\n", danci);
//	for(int i = 1; i < size; ++i)
//	{
//	int j = i - 1;
//	int t = array[i];
//	while(j >= 0 && t < array[j])
//	{
//	array[j + 1] = array[j];
//	j--;
//	}
//
//	array[j + 1] = t;
//	}

//	for(int i = size - 1; i > 0; i--)
//	{
//	int j = i - 1;
//	int t = array[i];
//
//	while(j  >= 0 && t > array[j])
//	{
//	array[j + 1] = array[j];
//	j--;
//	}
//	array[j + 1] = t;
//	}
//
//	PRINT(array, size);

//	int sum = 0;
//	int sums = 0;
//	for(int i = 1; i <= 8; i++)
//	{
//	sums += (sum = sum * 10 + i);
//	printf("%d ", sum);
//	}
//
//	printf("%d\n", sums);
//	int cn = 0;
//	for(int i = 100; i < 1000; i++)
//	{
//	int t = i;
//	int sum = 0;
//	while(t){
//	sum += t % 10;
//	t /= 10;
//	}
//
//	if(sum==11)
//	{
//	cn++;
//	printf("%d ", i);
//	}
//	}
//
//	printf("%d\n", cn);
//	int x = 2;
//	printf("%d\n", (++x) + (x++));
//	int i,j;
//	for(i = 2; i <= 100; i++)
//	{
//	for(j = 2; j * j <= i; j++)
//	{
//	if(i%j == 0) break;
//	}
//
//	if(j * j > i) printf("%d ", i);
//	}
	//2
//	int i = fact(4);
//	printf("%d\n", i);
	
	long double an, bn, suml;
	suml = 0.0L;
	for(int n = 1; n <= 20; n++)
	{
		an = 2 * n;
		bn = 4 * n * n - 1;
		suml += an / bn;
		printf("%d -> %.19Lf\n", n, an / bn);
	}
	printf("Sum = %.19Lf\n", suml);
	
	suml = 0.0L;
	for(int n = 1; n <= 20; n++)
	{
		an = (1.0/(2*n - 1) + 1.0/(2*n+1))/2.0;
		suml += an;
		printf("%d -> %.19Lf\n", n, an);
	}
	printf("Sum = %.19Lf\n", suml);
	return 0;
}

long fact(int x)
{
	if(x == 1) return 1;
	else return x *fact(x - 1);
}
int binary_helper(int x, int *sum)
{
	int y = x % 2;
	if (x > 1)
	{
		binary_helper(x / 2, sum);
	}
	* sum = * sum *J + y; // 累加当前位
	return *sum;
}

int *binary(int x)
{
	static int sum = 0; // 静态变量，保持结果
	sum = 0; // 每次调用前重置sum
	binary_helper(x, & sum); // 递归计算
	return &sum;
}

//插入排序
void InsertSort(int *array, int size)
{
	/*

	for(int i = 1; i < size; i++)
	{
	for(int j = i - 1; j >= 0 && array[j] > array[j + 1]; j--)
	{
	int temp = array[j];
	array[j] = array[j + 1];
	array[j + 1] = temp;
	}
	}
	*/
	for(int i = 1; i < size; ++i)
	{
		int j = i - 1;
		int t = array[i];
		while(j >= 0 && t > array[j])
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = t;
	}
}

//a + aa + aaa ...
//f(n -1) * 10 + a = f(n)
long long int sums(int x, int a)
{
	if(x == 1) return a;
	return sums(x - 1, a) * 10 + a;
}

