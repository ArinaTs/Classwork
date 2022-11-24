#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <locale.h>

#define N 25

struct Product {
	char name[100];
	float cost;
	int count;
	int ID;
};

void print(struct Product tovar) {
	printf("Name: %s\n", tovar.name);
	printf("Price: %.2f\n", tovar.cost);
	printf("Count: %d\n", tovar.count);
}

void addInStock(struct Product* stock, int stockSize, int* stockcount, struct Product tovar) {
	if (stockSize == (*stockcount)) {

	}
	strcpy(stock[*stockcount].name, tovar.name);
	stock[*stockcount].cost = tovar.cost;
	stock[*stockcount].count = tovar.count;
	stock[*stockcount].ID = tovar.ID;
	(*stockcount)++;
}

int Prodavec(struct Product* stock, int stockSize, int* stockcount) {
	int n = 1;
	
	while (n != 0) {
		printf("1. Добавить товар на склад\n2. Изменить товар\n0. Выход\nВаш выбор: ");
		scanf_s("%d", &n);
		if (n == 1) {
			struct Product tovar;
			tovar.ID = 100000 + (*stockcount) + 1; 
			printf("Введите имя товара: ");
			scanf("%s", tovar.name);
			printf("\nВведите стоимость товара 2: ");
			scanf_s("%f", &tovar.cost);
			printf("\nВведите количество товара: ");
			scanf_s("%d", &tovar.count);
			addInStock(stock, stockSize, stockcount, tovar);
		}
		else if (n == 2) {
			int tovar_id;
			scanf_s("%d", &tovar_id);
			for (int i = 0; i < stockcount; i++) {
				if (stock[i].ID == tovar_id) {
					char name[100];
					gets(name);
					strcpy(stock[i].name, name);
				}
				;
			}
		}
	}
	
}

int Pokupatel() {
	int n;
	printf("1. Добавить товар в корзину\n2. Отменить последнее добавление\n3. Очистить корзину");
	scanf_s("%d", &n);
	if (n == 1) {
		;
	}
	else if (n == 2) {
		;
	}
	else {
		;
	}
}

int Menu(struct Product* stock, int stockSize, int* stockcount) {
	int n;
	printf("Добро пожаловать в магазин! Выберите режим:\n1. Покупатель\n2. Продавец\nВаш выбор: ");
	scanf_s("%d", &n);
	if (n == 1) {
		return Pokupatel();
	}
	else {
		return Prodavec(stock, stockSize, stockcount);
	}
}



int main() {
	setlocale(LC_ALL, "rus");
	struct Product* stock = (struct Product*)malloc(sizeof(struct Product) * N);
	int stockSize = N, stockcount = 0;
	struct Product** basket = (struct Product**)malloc(sizeof(struct Product) * N);
	int basketSize = N, basketcount = 0;

	Menu(stock, stockSize, &stockcount);
	/*
	struct Product tovar1, tovar2;
	tovar1.ID = 100001; strcpy(tovar1.name, "Butter Derevenka"); tovar1.cost = 132.00; tovar1.count = 25;
	tovar2.ID = 100002; strcpy(tovar2.name, "Milk Derevenka"); tovar2.cost = 67.50; tovar2.count = 40;
	addInStock(stock, stockSize, &stockcount, tovar1);
	addInStock(stock, stockSize, &stockcount, tovar2);*/
	for (int i = 0; i < stockcount; i++) { print(stock[i]); printf("\n"); }
	
	return 0;
}