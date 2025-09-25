#include <stdio.h>
int main() {
  int count = 0, sum = 0, n, i, a[50];
  count++;
  printf("\nEnter the n value: ");
  scanf("%d", &n);
  count++;
  printf("\nEnter %d values to sum: ", n);
  for (i = 0; i < n; i++) {
    count++;
    scanf("%d", &a[i]);
  }
  count++;
  for (i = 0; i < n; i++) {
    count++;
    sum += a[i];
    count++;
  }
  count++;
  printf("\nThe sum of %d values is: %d and count = %d", n, sum, count);
  printf("\n\n--- Program by Anmol Arora ---\n");
  return 0;
}