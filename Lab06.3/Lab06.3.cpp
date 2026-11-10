#include <iostream>
#include <iomanip>
#include <time.h>
#include <clocale>
using namespace std;

// Прототипи звичайних функцій
void Create(int* a, const int size, const int Low, const int High);
void Print(int* a, const int size);
int FindMaxEven(int* a, const int size);

// Прототипи шаблонів функцій для універсального опрацювання
template <typename T>
void CreateTemplate(T* a, const int size, const T Low, const T High);

template <typename T>
void PrintTemplate(T* a, const int size);

template <typename T>
T FindMaxEvenTemplate(T* a, const int size);

int main() {
    setlocale (LC_ALL, "ukr");
    // Ініціалізація генератора випадкових чисел
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n];
    int Low = -10;
    int High = 30;

    // 1. Робота зі звичайними функціями (для типу int)
    cout << "=== Звичайншi функцiї (int) ===" << endl;
    Create(a, n, Low, High);
    cout << "Масив:" << endl;
    Print(a, n);

    int maxEven = FindMaxEven(a, n);
    if (maxEven != -9999) {
        cout << "Найбiльший парний елемент = " << maxEven << endl << endl;
    }
    else {
        cout << "Парних елементiв не знайдено." << endl << endl;
    }

    // 2. Робота з шаблонами функцій (template) для різних типів даних
    cout << "=== Шаблони функцiй (Templates) ===" << endl;

    // Шаблон для масиву цілих чисел (int)
    int arrInt[n];
    CreateTemplate<int>(arrInt, n, -5, 25);
    cout << "Цiлочисельний масив:" << endl;
    PrintTemplate<int>(arrInt, n);
    cout << "Найбiльший парний (int) = " << FindMaxEvenTemplate<int>(arrInt, n) << endl << endl;

    // Шаблон для масиву дійсних чисел (double)
    double arrDouble[n];
    CreateTemplate<double>(arrDouble, n, -10.0, 20.0);
    cout << "Масив дiйсних чисел (double):" << endl;
    PrintTemplate<double>(arrDouble, n);
    cout << "Найбiльший парний (double) = " << FindMaxEvenTemplate<double>(arrDouble, n) << endl;

    return 0;
}

// --- Звичайні функції ---
void Create(int* a, const int size, const int Low, const int High) {
    setlocale(LC_ALL, "ukr");
    int i; // Змінна для циклу
    for (i = 0; i < size; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

void Print(int* a, const int size) {
    setlocale(LC_ALL, "ukr");
    int i; // Змінна для циклу
    for (i = 0; i < size; i++) {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

// Функція пошуку найбільшого парного елемента (звичайна)
int FindMaxEven(int* a, const int size) {
    setlocale(LC_ALL, "ukr");
    int max = -9999; // Початкове значення для перевірки
    int found = 0;   // Прапорець наявності парного елемента
    int i;           // Змінна для циклу

    for (i = 0; i < size; i++) {
        if (a[i] % 2 == 0) {
            if (!found || a[i] > max) {
                max = a[i];
                found = 1;
            }
        }
    }
    if (found) {
        return max;
    }
    else {
        return -9999; // Умовний код відсутності парних елементів
    }
}

// --- Шаблони функцій ---
template <typename T>
void CreateTemplate(T* a, const int size, const T Low, const T High) {
    setlocale(LC_ALL, "ukr");
    int i; // Змінна для циклу
    for (i = 0; i < size; i++) {
        a[i] = Low + rand() % (int)(High - Low + 1);
    }
}

template <typename T>
void PrintTemplate(T* a, const int size) {
    setlocale(LC_ALL, "ukr");
    int i; // Змінна для циклу
    for (i = 0; i < size; i++) {
        cout << setw(6) << a[i];
    }
    cout << endl;
}

template <typename T>
T FindMaxEvenTemplate(T* a, const int size) {
    setlocale(LC_ALL, "ukr");
    T max = T();
    int found = 0;
    int i; // Змінна для циклу

    for (i = 0; i < size; i++) {
        if ((int)a[i] % 2 == 0) {
            if (!found || a[i] > max) {
                max = a[i];
                found = 1;
            }
        }
    }
    return max;
}