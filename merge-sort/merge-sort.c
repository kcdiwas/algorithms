#include <stdio.h>

void merge(int A[], int p, int q, int r)
{
    int left = q - p + 1; // 3
    int right = r - q;    // 3

    int leftArr[left + 1]; // +1 for the sentinel card
    int rightArr[right + 1];

    for (int i = 0; i < left; i++)
    {
        leftArr[i] = A[p + i];
    }

    for (int j = 0; j < right; j++)
    {
        rightArr[j] = A[q + 1 + j];
    }

    leftArr[left] = 1000000000;
    rightArr[right] = 10000000000;

    int k;
    int i = 0;
    int j = 0;
    while (p != r)
    {
        if (leftArr[i] <= rightArr[j])
        {
            A[p] = leftArr[i];
            i = i + 1;
        }
        else
        {
            A[p] = rightArr[j];
            j = j + 1;
        }
        p++;
    }
}

void merge_sort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    int A[] = {2, 3, 5, 1, 2, 9};

    merge_sort(A, 0, 5);

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", A[i]);
    }
}