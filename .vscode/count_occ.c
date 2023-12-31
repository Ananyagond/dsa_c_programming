#include<stdio.h>
int occur(int [], int, int);
 
int main()
{
    int size, a, count;
    int list[20];
    int i;
 
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    printf("Printing the list:\n");
    for (i = 0; i < size; i++)
    {
        list[i] = rand() % size;
        printf("%d", list[i]);
    }
    printf("\nEnter the key to find it's occurence: ");
    scanf("%d", &a);
    count = occur(list, size, a);
    printf("%d occurs for %d times.\n", a, count);
    return 0;
}
int occur(int list[], int size, int a)
{
    int i, count = 0;
 
    for (i = 0; i < size; i++)
    {
        if (list[i] == a)
        {
            count += 1;
        }
    }
    return count;
}