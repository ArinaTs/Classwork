// библиотеки
#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>

// управл¤ющие консолью библиотеки
#include <windows.h>
#include <conio.h>

#define MENU_SIZE 3
#define MENU_SORT_SIZE 2

// основные ключи, которые могут пригодитьс¤

#define KEY_EXIT 27
#define KEY_ENTER 13
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_BACKSPACE 8

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

// объ¤вление главной функции
int main() {
    // настройки
    
    // задаЄм название консольного окна
    system("title Меню");

    // устанавливаем взаимодействие с русскими буквами
    SetConsoleCP(1251);         // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);   // установка кодовой страницы win-cp 1251 в поток вывода

    // получаем дескриптор окна дл¤ обращени¤ к консоли
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // отключение мигани¤ курсора в консоли (в нашем меню курсор лишний)
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);

    // задаЄм серый фон дл¤ окна консоли
    SetConsoleTextAttribute(hStdOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    // очищаем экран, чтобы настройка цвета применилась
    system("cls");

    // объ¤вление переменных
    int choose_pos;                    // переменна¤ дл¤ хранени¤ выбранного пункта меню
    int iKey;                          // переменна¤ дл¤ фиксации нажатой клавиши
    int exit_flag;                     // флаг на завершение программы
    COORD cursorPos;                   // управление положением курсора, чтобы мен¤ть выводимый текст

    char* menu[MENU_SIZE] = { "Алгоритмы", "Настройки", "Выход" };

    char* menu_set[MENU_SIZE] = { "Задать массив", "Посмотреть текущий массив", "Назад" };

    char* menu_alg[MENU_SIZE] = { "Поиск", "Сортировки", "Назад" };

    char* menu_search[MENU_SIZE] = { "Наивный поиск", "Бинарный поиск", "Назад" };

    char* menu_sort[MENU_SORT_SIZE] = { "Пузырьковая сортировка", "Назад" };

    // инициализаци¤ (заполнение значени¤ми) переменных
    exit_flag = 0;
    choose_pos = 0;

    while (!exit_flag) {
        /* 1. вывод меню с переключением */

        // сброс консоли в стартовое положение
        system("cls");
        iKey = 67;
        cursorPos = (COORD){ 0, 0 };
        SetConsoleCursorPosition(hStdOut, cursorPos);

        // контроль нажати¤ клавиш
        while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
            switch (iKey) {
            case KEY_ARROW_UP:
                choose_pos--;
                break;
            case KEY_ARROW_DOWN:
                choose_pos++;
                break;
            }

            system("cls");

            // зацикливание перелистывани¤ меню
            if (choose_pos < 0) { choose_pos = MENU_SIZE - 1; }
            if (choose_pos > MENU_SIZE - 1) { choose_pos = 0; }

            for (int i = 0; i < MENU_SIZE; i++) {
                cursorPos = (COORD){ 3, i };
                SetConsoleCursorPosition(hStdOut, cursorPos);
                printf("%s \n", menu[i]);
            }

            // обозначение выбранной позиции
            cursorPos = (COORD){ 0, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf("<<", iKey);
            cursorPos = (COORD){ strlen(menu[choose_pos]) + 3 + 1, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf(">>");

            // ожидание нового нажати¤ клавиши
            iKey = _getch();
        }

        /* 2. основна¤ часть программы */
        switch (choose_pos) {
        case 0:
            system("cls");
            while (!exit_flag) {
                /* 1. вывод меню с переключением */

                // сброс консоли в стартовое положение
                system("cls");
                iKey = 67;
                cursorPos = (COORD){ 0, 0 };
                SetConsoleCursorPosition(hStdOut, cursorPos);

                // контроль нажати¤ клавиш
                while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
                    switch (iKey) {
                    case KEY_ARROW_UP:
                        choose_pos--;
                        break;
                    case KEY_ARROW_DOWN:
                        choose_pos++;
                        break;
                    }

                    system("cls");

                    // зацикливание перелистывани¤ меню
                    if (choose_pos < 0) { choose_pos = MENU_SIZE - 1; }
                    if (choose_pos > MENU_SIZE - 1) { choose_pos = 0; }

                    for (int i = 0; i < MENU_SIZE; i++) {
                        cursorPos = (COORD){ 3, i };
                        SetConsoleCursorPosition(hStdOut, cursorPos);
                        printf("%s \n", menu_alg[i]);
                    }

                    // обозначение выбранной позиции
                    cursorPos = (COORD){ 0, choose_pos };
                    SetConsoleCursorPosition(hStdOut, cursorPos);
                    printf("<<", iKey);
                    cursorPos = (COORD){ strlen(menu_alg[choose_pos]) + 3 + 1, choose_pos };
                    SetConsoleCursorPosition(hStdOut, cursorPos);
                    printf(">>");

                    // ожидание нового нажати¤ клавиши
                    iKey = _getch();
                }

                /* 2. основна¤ часть программы */
                switch (choose_pos) {
                case 0:
                    system("cls");
                    while (!exit_flag) {

                        system("cls");
                        iKey = 67;
                        cursorPos = (COORD){ 0, 0 };
                        SetConsoleCursorPosition(hStdOut, cursorPos);

                        while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
                            switch (iKey) {
                            case KEY_ARROW_UP:
                                choose_pos--;
                                break;
                            case KEY_ARROW_DOWN:
                                choose_pos++;
                                break;
                            }

                            system("cls");

                            if (choose_pos < 0) { choose_pos = MENU_SIZE - 1; }
                            if (choose_pos > MENU_SIZE - 1) { choose_pos = 0; }

                            for (int i = 0; i < MENU_SIZE; i++) {
                                cursorPos = (COORD){ 3, i };
                                SetConsoleCursorPosition(hStdOut, cursorPos);
                                printf("%s \n", menu_search[i]);
                            }

                            cursorPos = (COORD){ 0, choose_pos };
                            SetConsoleCursorPosition(hStdOut, cursorPos);
                            printf("<<", iKey);
                            cursorPos = (COORD){ strlen(menu_search[choose_pos]) + 3 + 1, choose_pos };
                            SetConsoleCursorPosition(hStdOut, cursorPos);
                            printf(">>");

                            iKey = _getch();
                        }

                        switch (choose_pos) {
                        case 0:
                            system("cls");
                            printf("Тут должен быть наивный поиск\n");
                            system("pause");
                            break;
                        case 1:
                            system("cls");
                            printf("Тут должен быть бинарный поиск\n");
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            exit_flag = 1;
                            break;
                        }
                    }

                    if (exit_flag == 1) {
                        exit_flag = 0;
                    }
                    else {
                        system("pause");
                    }
                    break;
                case 1:
                    system("cls");
                    while (!exit_flag) {

                        system("cls");
                        iKey = 67;
                        cursorPos = (COORD){ 0, 0 };
                        SetConsoleCursorPosition(hStdOut, cursorPos);

                        while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
                            switch (iKey) {
                            case KEY_ARROW_UP:
                                choose_pos--;
                                break;
                            case KEY_ARROW_DOWN:
                                choose_pos++;
                                break;
                            }

                            system("cls");

                            if (choose_pos < 0) { choose_pos = MENU_SORT_SIZE - 1; }
                            if (choose_pos > MENU_SORT_SIZE - 1) { choose_pos = 0; }

                            for (int i = 0; i < MENU_SORT_SIZE; i++) {
                                cursorPos = (COORD){ 3, i };
                                SetConsoleCursorPosition(hStdOut, cursorPos);
                                printf("%s \n", menu_sort[i]);
                            }

                            cursorPos = (COORD){ 0, choose_pos };
                            SetConsoleCursorPosition(hStdOut, cursorPos);
                            printf("<<", iKey);
                            cursorPos = (COORD){ strlen(menu_sort[choose_pos]) + 3 + 1, choose_pos };
                            SetConsoleCursorPosition(hStdOut, cursorPos);
                            printf(">>");

                            iKey = _getch();
                        }

                        switch (choose_pos) {
                        case 0:
                            system("cls");
                            printf("Тут должна быть пузырьковая сортировка\n");
                            system("pause");
                            break;
                        case 1:
                            system("cls");
                            exit_flag = 1;
                            break;
                        }
                    }
                    if (exit_flag == 1) {
                        exit_flag = 0;
                    }
                    else {
                        system("pause");
                    }
                    break;
                    
                case 2:
                    system("cls");
                    exit_flag  = 1;
                    break;
                }
            }
            if (exit_flag == 1) {
                exit_flag = 0;
            }
            else {
                system("pause");
            }
            break;
        case 1:
            system("cls");
            while (!exit_flag) {

                system("cls");
                iKey = 67;
                cursorPos = (COORD){ 0, 0 };
                SetConsoleCursorPosition(hStdOut, cursorPos);

                while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
                    switch (iKey) {
                    case KEY_ARROW_UP:
                        choose_pos--;
                        break;
                    case KEY_ARROW_DOWN:
                        choose_pos++;
                        break;
                    }

                    system("cls");

                    if (choose_pos < 0) { choose_pos = MENU_SIZE - 1; }
                    if (choose_pos > MENU_SIZE - 1) { choose_pos = 0; }

                    for (int i = 0; i < MENU_SIZE; i++) {
                        cursorPos = (COORD){ 3, i };
                        SetConsoleCursorPosition(hStdOut, cursorPos);
                        printf("%s \n", menu_set[i]);
                    }

                    cursorPos = (COORD){ 0, choose_pos };
                    SetConsoleCursorPosition(hStdOut, cursorPos);
                    printf("<<", iKey);
                    cursorPos = (COORD){ strlen(menu_set[choose_pos]) + 3 + 1, choose_pos };
                    SetConsoleCursorPosition(hStdOut, cursorPos);
                    printf(">>");

                    iKey = _getch();
                }

                switch (choose_pos) {
                case 0:
                    system("cls");
                    printf("Тут должна быть функция задачи массива\n");
                    system("pause");
                    break;
                case 1:
                    system("cls");
                    printf("Тут можно посмотреть текущий массив\n");
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    printf("Тут можно вернуться назад\n");
                    system("pause");
                    break;
                }
            }
            system("pause");
            break;
        case 2:
            exit_flag = 1;
            break;
        }
    }

    // вывод результата
    system("cls");
    printf("Goodbay!\n");

    // завершение программы
    system("pause");
    return 0;
}