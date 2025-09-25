#include <stdio.h>
void bubblesort(int[], int);
void display(int[], int);
int main() {
  int a[20], n, i;
  printf("\nPrepared by: Anmol Arora\n");
  printf("Enter the number of elements in array: ");
  scanf("%d", &n);
  printf("Enter %d elements in the array: ", n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  bubblesort(a, n);
  printf("\nThe sorted elements in the array are: ");
  display(a, n);
  return 0;
}
void bubblesort(int a[], int n) {
  int i, j, temp, excg;
  int last = n - 1;
  for (i = 0; i < n - 1; i++) {
    excg = 0; // reset swap counter
    for (j = 0; j < last; j++) {
      if (a[j] > a[j + 1]) {
        // swap
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        excg++;
      }
    }
    if (excg == 0) {
      // no swaps means array is sorted
      break;
    }
    last--; // reduce the range for next pass }
  }
}
void display(int a[], int n) {
    printf("\t");
  for (int i = 0; i < n; i++)
    printf("%d\t", a[i]);
  printf("\n");
}
