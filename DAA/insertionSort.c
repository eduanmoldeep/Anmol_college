#include <stdio.h>
void inssort(int[], int);
void display(int[], int);
int main() {
  int a[20], n, i;
  printf("\nPrepared by: Anmol Arora\n");
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  printf("Enter %d elements in the array: ", n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  inssort(a, n);
  printf("\nThe sorted elements in the array are: ");
  display(a, n);
  return 0;
}
void inssort(int a[], int n) {
  int i, j, index;
  for (i = 1; i < n; i++) {
    index = a[i];
    j = i;
    while (j > 0 && a[j - 1] > index) {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = index;
  }
}
void display(int a[], int n) {
  printf("\t");
  for (int i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
  printf("\n");
}