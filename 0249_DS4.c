#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int num = 1000000;
void print(int *a, int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d\t", a[i]);
}
void radix_sort(int *a, int n) {
	int i, b[num], m = 0, exp = 1;
	for (i = 0; i < n; i++) {
		if (a[i] > m)
			m = a[i];
	}
	while (m / exp > 0) {
		int box[10] = { 0 };
		for (i = 0; i < n; i++)
			box[a[i] / exp % 10]++;
		for (i = 1; i < 10; i++)
			box[i] += box[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--box[a[i] / exp % 10]] = a[i];
		for (i = 0; i < n; i++)
			a[i] = b[i];
		exp *= 10;
	}
}
int main() {
	int i;
	srand(time(NULL));
	int arr[num];
	for (i = 0; i < num; i++)
		arr[i]=rand()%1000;
	radix_sort(&arr[0], num);
	return 0;
}
