#include <stdio.h>
#include <malloc.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "rus");
	char* str;
	int choose;
	str = (char*)malloc(sizeof(char) * 100);
	printf("������� ������: ");
	gets(str);
	int size = 0;

	while (str[size] != '\0') {
		size++;
	}
	printf("�������� �������� ��� �������:\n1. �������� ������.\n2. �������� ������.\n3. ���������� ������.\n4. ������� �������.\n0. �����.\n");
	printf("��� �����: ");
	scanf_s("%d", &choose);
	while (choose != 0) {
		if (choose == 1) {
			printf("������� ����� ������: ");
			getchar();
			gets(str);
			//?????
		}
		else if (choose == 2) {
			int del;
			printf("������� ��������: ");
			scanf_s("%d", &del);
			str[del] = '\0'; // �������� �������� ����� ������ � ���������� �������
			puts(str);

		}

		printf("������ ������� ���-�� ���?\n��� �����: ");
		scanf_s("%d", &choose);
	}
	free(str);
	return 0;
}