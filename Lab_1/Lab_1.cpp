#include <iostream>
#include <vector>
#include <stdio.h>
#include <conio.h>

using namespace std;

int binarySearch(const vector<int>& arr, int low, int high, int target) 
{
    int mid = low + (high - low) / 2;

    if (low > high)
        return -1; //обыскались

    if (arr[mid] == target) 
        return mid; //нашли

    else if (arr[mid] < target) 
        return binarySearch(arr, mid + 1, high, target); //правая

    else 
        return binarySearch(arr, low, mid - 1, target); //левая
}

int main() 
{
    int n = 0, target = 0;
    printf("Введите размер массива: ");
    scanf_s("%d", &n);

    vector<int> arr(n);
    printf("Введите элементы массива по возрастанию:\n");
    for (int i = 0; i < n; ++i) 
        scanf_s("%d", &arr[i]);

    printf("Введите элемент для поиска: ");
    scanf_s("%d", &target);

    int index = binarySearch(arr, 0, n - 1, target);
    if (index != -1) 
        printf("Элемент массива %d  найден на позиции %d", target, index + 1);
    else 
        printf("Элемент массива %d  не найден в массиве\n", target);

    _getch();
}