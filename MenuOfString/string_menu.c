#include <stdio.h>
#include <malloc.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "rus");
	char* str;
	int choose;
	str = (char*)malloc(sizeof(char) * 100);
	printf("Введите строку: ");
	gets(str);
	int size = 0;

	while (str[size] != '\0') {
		size++;
	}
	printf("Выберите действия над строкой:\n1. Заменить строку.\n2. Обрезать строку.\n3. Развернуть строку.\n4. Сменить регистр.\n0. Выход.\n");
	printf("Ваш выбор: ");
	scanf_s("%d", &choose);
	while (choose != 0) {
		if (choose == 1) {
			printf("Введите новую строку: ");
			getchar();
			gets(str);
			//?????
		}
		else if (choose == 2) {
			int del;
			printf("Введите значение: ");
			scanf_s("%d", &del);
			str[del] = '\0'; // обрезает введеную ранее строку с указанного символа
			puts(str);

		}

		printf("Хотите сделать что-то ещё?\nВаш выбор: ");
		scanf_s("%d", &choose);
	}
	free(str);
	return 0;
}