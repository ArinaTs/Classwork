#include<stdio.h>
#include<locale.h>
int main() {
	setlocale(LC_ALL, "rus");
	int size = 0;
	printf("������� ������ �������: ");
	scanf_s("%d", &size);
	int mass[10000];
	while (size <= 0 || size > 10000) {
		printf("������� ���������� ������ �������: ");
		scanf_s("%d", &size);
	}
	for (int i = 0; i < size; i++) {
		mass[i] = -10 + rand()%21;
	}
	printf("������ ������� �� �����: \n");
	for (int i = 0; i < size; i++) {
		printf("%d ", mass[i]);
	}
	system("pause");
	return 0;
}