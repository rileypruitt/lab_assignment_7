#include <stdio.h>
#define SIZE 9
int bubble_sort(int arr[], int size, int val);
void copy_array(int arr[], int source[], int size);
int selection_sort(int arr[], int size, int val);

int main(void) 
{
  int arr1[SIZE] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  int arr2[SIZE] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
  int bubble1[SIZE], selection1[SIZE], bubble2[SIZE], selection2[SIZE], swapcount;

  copy_array(bubble1, arr1, SIZE);
  printf("array 1 with bubble sort\n");
  for(int i = 0; i < SIZE; i++)
  {
    swapcount = bubble_sort(bubble1, SIZE, arr1[i]);
    printf("%d: %d\n", arr1[i], swapcount);
    copy_array(bubble1, arr1, SIZE);
  }
  swapcount = bubble_sort(bubble1, SIZE, -1);
  printf("%d\n", swapcount);

  copy_array(bubble2, arr2, SIZE);
  printf("\narray 2 with bubble sort\n");
  for(int i = 0; i < SIZE; i++)
  {
    swapcount = bubble_sort(bubble2, SIZE, arr2[i]);
    printf("%d: %d\n", arr2[i], swapcount);
    copy_array(bubble2, arr2, SIZE);
  }
  swapcount = bubble_sort(bubble2, SIZE, -1);
  printf("%d\n", swapcount);

  copy_array(selection1, arr1, SIZE);
  printf("\narray 1 with selection sort\n");
  for(int i = 0; i < SIZE; i++)
  {
    swapcount = selection_sort(selection1, SIZE, arr1[i]);
    printf("%d: %d\n", arr1[i], swapcount);
    copy_array(selection1, arr1, SIZE);
  }
  swapcount = selection_sort(selection1, SIZE, -1);
  printf("%d\n", swapcount);

  copy_array(selection2, arr2, SIZE);
  printf("\narray 2 with selection sort\n");
  for(int i = 0; i < SIZE; i++)
  {
    swapcount = selection_sort(selection2, SIZE, arr2[i]);
    printf("%d: %d\n", arr2[i], swapcount);
    copy_array(selection2, arr2, SIZE);
  }
  swapcount = selection_sort(selection2, SIZE, -1);
  printf("%d\n", swapcount);
}


void swap(int *x, int *y)
{
  int temp = *y;
  *y = *x;
  *x = temp;
}

int bubble_sort(int arr[], int size, int val)
{
  int total = 0;
  int valcount = 0;
  for(int i = 0; i < size - 1; i++)
  {
    for(int j = 0; j < size - i - 1; j++)
    {
      if(arr[j] > arr[j+1])
      {
        swap(&arr[j], &arr[j+1]);
        total++;
        if(arr[j] == val || arr[j+1] == val)
          valcount++;
      }
    }
  }
  if(valcount != 0)
    return valcount;
  else
    return total;
}

int selection_sort(int arr[], int size, int val)
{
  int total = 0;
  int valcount = 0;
  for(int i = 0; i < size; i++)
  {
    int min = i;
    for(int j = i + 1; j < size; j++)
    {
      if(arr[j] < arr[min])
        min = j;
    }
    if(min != i)
    {
      swap(&arr[min], &arr[i]);
      total ++;
      if(arr[min] == val || arr[i] == val)
        valcount ++;
    }
  }
  if(valcount != 0)
    return valcount;
  else
    return total;
}

void copy_array(int arr[], int source[], int size) 
{
  for(int i = 0; i < size; i++) 
  {
    arr[i] = source[i];
  }
}