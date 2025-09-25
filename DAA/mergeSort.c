#include <stdio.h>

// Function to merge two sorted halves
void merge(int arr[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2]; // temporary arrays
  for (int i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }
  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
}

// Recursive merge sort
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int main() {
  int n1, n2;

  printf("Enter size of first list: ");
  scanf("%d", &n1);
  int a[n1];
  printf("Enter %d elements:\n", n1);
  for (int i = 0; i < n1; i++)
    scanf("%d", &a[i]);

  printf("Enter size of second list: ");
  scanf("%d", &n2);
  int b[n2];
  printf("Enter %d elements:\n", n2);
  for (int i = 0; i < n2; i++)
    scanf("%d", &b[i]);

  int n = n1 + n2;
  int arr[n];
  for (int i = 0; i < n1; i++)
    arr[i] = a[i];
  for (int i = 0; i < n2; i++)
    arr[n1 + i] = b[i];

  printf("\nNow sorting the combined list using Merge Sort...\n");
  mergeSort(arr, 0, n - 1);
  printf("\n");
  printf("\nCode by Anmol Arora\n");
  printf("\nFinal Sorted Merged List:\n");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
