#include <stdio.h>
#include<conio.h>
void main()
{
    int array[50], position, i, n, value;
    clrscr();
    printf("Enter number of elements in the array\n");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for (i = 0; i < n; i++)
  {
    scanf("%d", &array[i]);
}
 printf("Please enter the location where you want to insert an new element\n");
    scanf("%d", &position);
    printf("Please enter the value\n");
    scanf("%d", &value);
    for (i = n - 1; i >= position - 1; i--)
    {
       array[i+1] = array[i];
    }
    array[position-1] = value;
    printf("Resultant array is\n");
    for (i = 0; i <= n; i++)
    {
       printf("%d\n", array[i]);
    }
    getch();
} 

