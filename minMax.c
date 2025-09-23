#include <stdio.h>
int a[50], n;
int allMax, allMin;
void minmax(int i, int j);
int main() {
  int i;
  printf("Prepared by: Anmol Arora\n");
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  printf("Enter %d elements in the array:\n", n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printf("\nThe elements in the array are:\n");
  for (i = 0; i < n; i++)
    printf("%d\n", a[i]);
  // Initialize allMax and allMin with first element 
  allMax = allMin = a[0];
  minmax(0, n - 1);
  printf("\nThe minimum element of the list is: %d\n", allMin);
  printf("The maximum element of the list is: %d\n", allMax);
  return 0;
}
void minmax(int i, int j) {
  int gmax, gmin, hmax, hmin, mid;
  if (i == j) {
    // Only one element
    if (a[i] > allMax)
      allMax = a[i];
    if (a[i] < allMin)
      allMin = a[i];
  } else if (i == j - 1) {
    // Two elements
    if (a[i] > a[j]) {
      if (a[i] > allMax)
        allMax = a[i];
      if (a[j] < allMin)
        allMin = a[j];
    } else {
      if (a[j] > allMax)
        allMax = a[j];
      if (a[i] < allMin)
        allMin = a[i];
    }
  } else {
    // More than two elements, divide 
    int mid = (i + j) / 2;
    minmax(i, mid);
    minmax(mid + 1, j);
  }
}