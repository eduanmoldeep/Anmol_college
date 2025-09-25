#include <stdio.h>
// Function prototypes
void bubblesort(int[], int);
int binsrch(int[], int, int, int);
void display(int[], int);
int main() {
  int a[20], n, key, pos = -1;
  printf("\nEnter the number of elements in array: ");
  scanf("%d", &n);
  printf("\nEnter %d elements in the array: ", n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printf("\nEnter the element to be searched: ");
  scanf("%d", &key);
  bubblesort(a, n);
  printf("\nThe sorted elements in the array are: ");
  display(a, n);
  pos = binsrch(a, key, 0, n - 1);
  if (pos != -1)
    printf("\nThe Element %d is found at position %d", key,
           pos + 1); // +1 for human-readable
  else
    printf("\nElement not found");
  printf("\nCode by Anmol Arora\n");
  return 0;
}
// Binary Search
int binsrch(int a[], int key, int low, int high) {
  int mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (key < a[mid])
      high = mid - 1;
    else if (key > a[mid])
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}
// Bubble Sort
void bubblesort(int a[], int n) {
  int i, j, temp, excg;
  int last = n - 1;
  for (i = 0; i < n - 1; i++) {
    excg = 0;
    for (j = 0; j < last; j++) {
      if (a[j] > a[j + 1]) {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        excg++;
      }
    }
    if (excg == 0) // no swaps → array already sorted
      break;
    last--; // optimization: last element already in place 
  }
}
// Display function
void display(int a[], int n) {
  printf("\t");
  for (int i = 0; i < n; i++)
    printf("%d\t", a[i]);
  printf("\n");
}