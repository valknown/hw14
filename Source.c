#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#define N 1000

int search_for_max(int *arr, int size, int k, int l);

int main(void)
{
    srand((unsigned int)time(NULL));
    setlocale(LC_CTYPE, "RUS");
    int arr[N];
    int size, k, l;
    printf("введите размер массива: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
		arr[i] = rand() % 100;
    }
    printf("\nвведите значения K и L: ");
    scanf("%d %d", &k, &l);
    int max = search_for_max(arr, size, k, l);
    if (max != -1)
    {
        printf("максимальное значение в диапазоне [%d; %d]: %d\n", k, l, max);
    }
    return 0;
}

int search_for_max(int *arr, int size, int k, int l)
{
    int max = arr[0];
    if (k < 0 || l >= size || k > l)
    {
        printf("ошибка в аргументах\n");
        return -1;
    }
    for (int i = k; i <= l; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}