#include<stdio.h>
#include<locale.h>
#include<math.h>
int main() {
	setlocale(LC_ALL, "rus");
	int size = 0;
	printf("Введите размер массива: ");
	scanf_s("%d", &size);
	int mass[10000];
	while (size <= 0 || size > 10000) {
		printf("Введите корректный размер массива: ");
		scanf_s("%d", &size);
	}
	for (int i = 0; i < size; i++) {
		mass[i] = -10 + rand()%21;
	}
	printf("Массив состоит из чисел: \n");
	for (int i = 0; i < size; i++) {
		printf("%d ", mass[i]);
	}
	int number;
	printf("\nВведите число: ");
	scanf_s("%d", &number);
	int st;
	printf("Введите степень: ");
	scanf_s("%d", &st);
	for (int i = 0; i < size; i++) {
		if (mass[i] % number == 0) {
			mass[i] = pow(mass[i], st);
		}
	printf("%d ", mass[i]);
	}
	int mass1[10000];
	for (int i = size; i >= 0; i--) {
		mass1[size - i - 1] = mass[i];
	}
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", mass1[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}