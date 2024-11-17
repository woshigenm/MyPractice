#include <stdint.h>
#include <stdio.h>

#define PRINT(array, size) \
	for(int i = 0; i < size; i++) \
		printf("%d ", array[i]); \
	putchar('\n');

int add(int num1, int num2);

void increasement();

size_t my_strlen(const char* str);

int binarysearch(int array[], int len);

void reverse_i(int array[], int len);

void reverse_c(char str[], int len);

void triangleN(int n);

void quadrilateralN(int n);

int shusu1(int n);

int shusu2(int n);

int shusu3(int n);

void perfectN();

int C(int n, int m);

int A(int n, int m);


