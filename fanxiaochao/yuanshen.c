#include "yuanshen.h"
#define SIZE 5

int add(int num1, int num2)
{
	return num1 + num2;
}

size_t my_strlen(const char* str)
{
	size_t length = 0;
	while (str[length++] != '\0');
	return length - 1;
}

void increasement()
{
	static int i;
	i++;
	printf("%d\n", i);
}

//int main() {
//	int array[SIZE] = {5, 4, 3, 2, 1};
//	int temp;
//	int k = 2;
//
//	for(int i = 1; i <= k; i++) {
//	temp = array[SIZE - 1];
//	for(int j = SIZE - 2; j >= 0; j--) {
//	array[j + 1] = array[j];
//	}
//	array[0] = temp;
//	}
//
//	PRINT(array);
//
//	for(int i = 1; i <= k; i++) {
//	temp = array[0];
//	for(int j = 0; j < SIZE - 1; j++) {
//	array[j] = array[j + 1];
//	}
//	array[SIZE - 1] = temp;
//	}
//
//	PRINT(array);
//}

int binarysearch(int array[], int len)
{
	int target = 1;

	int left, mid, right;

	left = 0;
	right = len - 1;
	mid = (left + right) / 2;

	while(left <= right)
	{
		mid = (left + right) / 2;

		if(target > array[mid])
		{
			left = mid + 1;
		}

		if(target < array[mid])
		{
			right = mid - 1;
		}

		if(target == array[mid])
		{
			break;
		}
	}

	if(left > right) return -1;

	return mid;
}

void reverse_i(int array[], int len)
{
	for (int i = 0; i < len / 2; i++)
	{
		int temp = array[i];
		array[i] = array[len - i - 1];
		array[len - i - 1] = temp;
	}
}

void reverse_c(char str[], int len)
{
	char* start = str; //"hello"
	char* end = str + len - 1;
	while(start < end)
	{
		char temp = * start;
		* start = * end;
		* end = temp;
		start++;
		end--;
	}
}

//三角形数
void triangleN(int n)
{
	int i;

	int s = 0;

	for(i = 1; i <= n; i++)
	{
		s += i;
		printf("%d ", s);
	}

	putchar('\n');
}

//四边形数
void quadrilateralN(int n)
{
	int i;

	int s, sum;
	s = sum = 0;
	for(i = 1; i <= n; i++)
	{
		sum += s += i;
		printf("%d ", sum);
	}

	putchar('\n');
}

//[2, n - 1]
int shusu1(int n)
{
	if(n < 2) return -1;

	int i;

	for(i = 2; i < n; i++)
	{
		if(n % i == 0) return -1;
	}

	return n;
}

//[2, n / 2]
int shusu2(int n)
{
	if(n < 2) return -1;

	int i;

	for(i = 2; i <= n / 2; i++)
	{
		if(n % i == 0) return -1;
	}

	return n;
}

//[2, sqrt(n)]
int shusu3(int n)
{
	if(n < 2) return -1;

	int i;

	for(i = 2; i* i <= n; i++)
	{
		if(n % i == 0) return -1;
	}

	return n;
}

//[1, N]中的真因子相加等于本身的数为完美数
void perfectN()
{
	int sum;

	int i, j;

	int count = 1;
	for(i = 1; i < 1000; i++)
	{
		sum = 1;
		for(j = 2; j* j <= i; j++)
		{
			if(i % j == 0)
			{
				sum += j;
				if (j != (i / j))
				{
					sum += i / j;
				}
			}
		}

		if(sum == i)
		{
			printf("%d\n ", i);
		}
	}
}

int A(int n, int m)
{
	if(m > n) return -1;
	m = m > n / 2 ? n - m : m;

	int s = 1;
	for(int i = m, j = n; i >= 1; i--, j--) s *= j;
	return s;
}

int C(int n, int m)
{
	if(m > n) return -1;
	return A(n, m) / A(m, m);
}

//	for (i = 0; i < SIZE - 1; i++)
//	{
//	for (j = 0; j < SIZE - i - 1; j++)
//	{
//	if (array[j] > array[j + 1])
//	{
//	t = array[j];
//	array[j] = array[j + 1];
//	array[j + 1] = t;
//	}
//	}
//	}
//
//	PRINT(array);

//	for (i = 0; i < SIZE - 1; i++)
//	{
//	int min = i;
//	for (j = i + 1; j < SIZE; j++)
//	{
//	if (array[j] > array[min]) min = j;
//	}
//
//	t = array[i];
//	array[i] = array[min];
//	array[min] = t;
//	}
//
//	PRINT(array);

//	printf("1234567\tHello\n");
//	printf("12\tWorld\n");
//{ 1, 2, 3, 4, 5}
// 4  4
// 3  3  4
// 2  2
// 1  1
//{ 1, 2, 3, 4, 5}
//	2  2
// 3  3
// 4  4
// 5  5
// 2  3  4  5  5
//把数组中的元素向后移动k个位置
//如{1, 2, 3, 4, 5}, 把元素移动2个位置, {4, 5, 1, 2, 3}
//思路: 把每一次移动看作成一次循环, 一次移动一个位置
//每次循环中, 因为移动会将数组中的最后一个元素移动会被挤掉，因此每次循环中最后一个元素应特殊考虑

//	for (int i = 1; i <= N; i++) {
//	temp = array[SIZE - 1]; //保存最后一位元素
//	//依次向后移动元素,同时舍弃掉最后一位元素
//	for (int j = SIZE - 2; j >= 0; j--)
//	array[j + 1] = array[j];
//	array[0] = temp;
//	}
//
//	PRINT(array);
//
//	for (int i = 1; i <= N; i++) {
//	temp = array[0];
//	for (int j = 0; j < SIZE - 1; j++)
//	array[j] = array[j + 1];
//	array[SIZE - 1] = temp;
//	}
//
//	PRINT(array);
//

//( )、[ ]、->、.  > 单目运算符 > 算数运算符 > 关系运算符 > 逻辑运算符 > 条件运算符 > 赋值运算符 > 逗号运算符
//单目运算符, 条件运算符, 赋值运算符结合方向是从右往左
//https://www.cnblogs.com/blogernice/articles/13156017.html
//	char arr[] = "hola";
//	reverse_c(arr, 4);
//	printf("%s\n", arr);
//
//	int array[] = { 1, 2, 3, 4, 5, 6};
//	reverse_i(array, 6);
//	PRINT(array, 6);
//	triangleN(5);
//	quadrilateralN(5);

//	for(int i = 1; i < S; i++)
//	{
//	if(shusu1(i) == i) printf("%d ", i);
//	if(shusu2(i) == i) printf("%d ", i);
//	if(shusu3(i) == i) printf("%d ", i);
//	}

//	putchar('\n');
//	for(int i = 1; i <= S; ++i) {
//	if( i / 2 * 2 == i && i % 2 == 0 && !(i % 2) && i % 2 != 1 && (i & 1) == 0 ) printf("%d\n", i);
//	}
//
//	int n = J;
//	double s = 0.0;
//	int o;
//	for(int i = 1; i <= n; i++)
//	{
//	o = 1;
//
//	for(int j = 1; j <= i; j++)
//	{
//	o *= j;
//	}
//
//	s += 1 / (double)o;
//	}
//
//	printf("%lf\n", s);

//	int a = S, b = 200;
//	for(int i = 1; i <= S; i++)
//	{
//	printf("%d ", rand() % (b - a + 1) + a);
//	}

//	int a = 240000000;
//	//24 % 2 = 0
//	//12 % 2 = 0
//	//6  % 2 = 0
//	//3  % 2 = 1
//	//1  % 2 == 1
//	unsigned long long int sum = 0;
//	unsigned long long int e;
//	for(e = 1; a != 0 ; a /= 2, e *= 10) {
//	sum = sum + (a % 2) * e;
//	}
//	printf("%llu\n", sum);
//	char binary_c[64] = {0};
//
//	long long int a = 1 << 31;
//	printf("%lld\n", a);
//	int s;
//	for(s = 0; a != 0; a /=2, s++)
//	{
//	binary_c[s] = '0' + a % 2;
//	}
//
//	for(int i = s - 1; i >= 0; i--)
//	{
//	printf("%c", binary_c[i]);

//小写字母x向后移动m位, m = 5, 'z' -> 'e'
//(x - 'a' + m) % 26 + 'a'
//(x - 'A' + m) % 26 + 'A'

