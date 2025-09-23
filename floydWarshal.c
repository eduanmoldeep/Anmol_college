// #include <conio.h>
#include <stdio.h>
void readf();
void amin();
int cost[20][20], a[20][20];
int i, j, k, n;
void readf() {
  printf("\n Enter the number of vertices: ");
  scanf("%d", &n);
  printf("\n Enter the Cost adjacency matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &cost[i][j]);
      if (i != j && cost[i][j] == 0)
        cost[i][j] = 999; // infinity
      a[i][j] = cost[i][j];
    }
  }
}
void amin() {
  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (a[i][j] > a[i][k] + a[k][j]) {
          a[i][j] = a[i][k] + a[k][j];
        }
      }
    }
  }
  printf("\n The All-Pairs Shortest Path Matrix (Floyd-Warshall)");
  printf("\n (Program by Anmol Arora)\n");
  for (i = 0; i < n; i++) {
    printf("\n");
    for (j = 0; j < n; j++) {
      if (a[i][j] == 999)
        printf("INF\t");
      else
        printf("%d\t", a[i][j]);
    }
  }
}
int main() {
//   clrscr();
  readf();
  amin();
  printf("\n");
//   getch();
}