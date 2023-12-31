#include<stdio.h>
int main() {
    int a[10], i, j, n, temp;
    printf("Enter number of elements in the array: \n");
    scanf("%d", &n);
    printf("Input %d array values: \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d  \n", a[i]);

    return 0;
}
