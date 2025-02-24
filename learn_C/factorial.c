#include <stdio.h>

int main() {
  int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  unsigned long int factorial = 1;
  int i;

  /* calculate the factorial using a for loop  here*/
  int arr_len = sizeof(array)/sizeof(array[0]);
  printf("The size of the array is %d\n", arr_len);
  for (i = 0; i < arr_len; i++) {
    factorial = factorial*array[i];
  }

  printf("10! is %lu.\n", factorial);
}