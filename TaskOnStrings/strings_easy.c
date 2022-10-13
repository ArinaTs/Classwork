#include <stdio.h>
#include <malloc.h>

int main() {
	char* str;
	str = (char*)malloc(sizeof(char) * 100);

	gets(str); //аналог scanf дл€ строк
	puts(str); //аналог printf дл€ строк

	int size = 0;  // изменение длины введеной строки
	while (str[size] != '\0') {  // пока €чейка массива не равна символу конца строки
		size++;
	} 

	printf("String %s have len %d\n", str, size);
	
	str[5] = '\0'; // обрезает введеную ранее строку с указанного символа
	puts(str);

	free(str);
	return 0;
}