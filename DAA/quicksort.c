#include <stdio.h>
void qsort(int[], int, int);
int partition(int[], int, int);
int main() {
  int a[40], i, n;
  printf("Prepared by: Anmol Arora\n");
  printf("Enter the number of elements (size): ");
  scanf("%d", &n);
  printf("Enter the elements to sort: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  qsort(a, 0, n - 1);
  printf("\nThe elements after sorting are: ");
  for (i = 0; i < n; i++)
    printf("%d\t", a[i]);
  printf("\n");
  return 0;
}
void qsort(int a[], int first, int last) {
  int j;
  if (first < last) {
    j = partition(a, first, last);
    qsort(a, first, j - 1);
    qsort(a, j + 1, last);
  }
}
int partition(int a[], int first, int last) {
  int pivot = a[first];
  int i = first + 1;
  int j = last;
  int temp;
  while (1) {
    while (i <= last && a[i] <= pivot)
      i++;
    while (a[j] > pivot)
      j--;
    if (i < j) {
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    } else {
      break;
    }
  }
  // Place pivot in correct position
  a[first] = a[j];
  a[j] = pivot;
  return j;
}