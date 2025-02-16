#include <stdio.h>
#include <string.h>

typedef int (*sort_order_cb)(int, int);

int asc_sort(int a, int b)
{
    return a > b;
}

int desc_sort(int a, int b)
{
    return a < b;
}

int *insertion_sort(int *, int *, int, sort_order_cb);

int main(int argc, char *argv[])
{
    sort_order_cb sortOrder = asc_sort;

    if (argc > 1)
    {
        if (strcmp(argv[1], "asc") == 0)
        {
            sortOrder = asc_sort;
        }
        else
        {
            sortOrder = desc_sort;
        }
    }
    int numbers[5] = {3, 5, 2, 2, 5};
    int sortedArr[5];

    insertion_sort(numbers, sortedArr, 5, sortOrder);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", sortedArr[i]);
    }
}

int *insertion_sort(int *arr, int *sortedArr, int arrlen, sort_order_cb sortby)
{
    sortedArr[0] = arr[0];

    for (int j = 1; j < arrlen; j++)
    {
        int i = j - 1;
        int key = arr[j];

        while (sortby(key, sortedArr[i]) && i >= 0)
        {
            sortedArr[i + 1] = sortedArr[i];
            i = i - 1;
        }
        sortedArr[i + 1] = key;
    }

    return sortedArr;
}
