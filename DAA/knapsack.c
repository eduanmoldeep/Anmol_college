#include <stdio.h>
// Function prototypes void readf();
void knapsack(int, int);
void dsort(int n);
void display(int n);
// Global variables
int p[20], w[20], n, m;
double x[20], d[20], temp, res = 0.0, sum = 0.0;
// Input function 
void readf()
{
  int i;
  printf("\nEnter the number of items: ");
  scanf("%d", &n);
  printf("\nEnter the maximum capacity of the Knapsack: ");
  scanf("%d", &m);
  printf("\nEnter %d profits: ", n);
  for (i = 0; i < n; i++)
    scanf("%d", &p[i]);
  printf("\nEnter %d weights: ", n);
  for (i = 0; i < n; i++)
    scanf("%d", &w[i]);
  for (i = 0; i < n; i++)
    d[i] = (double)p[i] / w[i]; // profit/weight ratio
  dsort(n);
  knapsack(m, n);
  display(n);
}
// Sort by profit/weight ratio (descending) 
void dsort(int n)
{
  int i, j, t;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - 1; j++) {
      if (d[j] < d[j + 1]) {
        // Swap ratios 
        temp = d[j]; d[j]=d[j+1]; d[j + 1] = temp;
        // Swap profits 
        t = p[j]; p[j]=p[j+1]; p[j + 1] = t;
        // Swap weights 
        t = w[j]; w[j]=w[j+1]; w[j + 1] = t;
        w[j + 1] = t;
      }
    }
  }
}
// Display solution 
void display(int n)
{
  int i;
  sum = 0.0;
  res = 0.0;
  printf("\nThe Required Optimal Solution is:\n");
  printf("Profit\tWeight\tXvalue\n");
  for (i = 0; i < n; i++) {
    printf("%d\t%d\t%f\n", p[i], w[i], x[i]);
    sum = sum + (p[i] * x[i]);
    res = res + (w[i] * x[i]);
  }
  printf("\nThe Total Resultant Profit is: %f", sum);
  printf("\nThe Total Weight in the Knapsack is: %f", res);
  printf("\nCode by Anmol Arora\n");
}
// Knapsack logic
void knapsack(int m, int n) {
  int i, cu = m;
  for (i = 0; i < n; i++)
    x[i] = 0.0;
  for (i = 0; i < n; i++) {
    if (w[i] <= cu) {
      x[i] = 1.0;
      cu = cu - w[i];
    } else
      break;
  }
  if (i < n)
    x[i] = (double)cu / w[i];
}
// Main function 
int main()
{
  readf();
  return 0;
}