#include <stdio.h>
#define INF 999
int n, cost[10][10], nears[10];
void readv();
void primsalg();
int findnextindex();
void readv() {
  int i, j;
  printf("\nEnter the number of nodes or vertices: ");
  scanf("%d", &n);
  printf("\nEnter the Cost Adjacency Matrix of the given graph:\n");
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      scanf("%d", &cost[i][j]);
      if (cost[i][j] == 0 && i != j) {
        cost[i][j] = INF; // no edge
      }
    }
  }
}
void primsalg() {
  int k, l, min, u, i, j, mincost = 0;
  int t[10][2]; // edges in MST
  min = INF;
  // Find initial minimum edge
  for (i = 1; i <= n; i++) {
    for (u = 1; u <= n; u++) {
      if (i != u && cost[i][u] < min) {
        min = cost[i][u];
        k = i;
        l = u;
      }
    }
  }
  t[1][0] = k;
  t[1][1] = l;
  printf("\nThe Minimum Cost Spanning Tree is...\n");
  printf("(%d,%d) --> %d", k, l, min);
  for (i = 1; i <= n; i++) {
    if (i != k) {
      if (cost[i][l] < cost[i][k])
        nears[i] = l;
      else
        nears[i] = k;
    }
  }
  nears[k] = nears[l] = 0;
  mincost = min;
  // Find remaining edges
  for (i = 2; i <= n - 1; i++) {
    j = findnextindex();
    t[i][0] = j;
    t[i][1] = nears[j];
    printf("\n(%d,%d) --> %d", t[i][0], t[i][1], cost[j][nears[j]]);
    mincost += cost[j][nears[j]];
    nears[j] = 0;
    for (k = 1; k <= n; k++) {
      if (nears[k] != 0 && cost[k][nears[k]] > cost[k][j]) {
        nears[k] = j;
      }
    }
  }
  printf("\nThe Required Minimum Cost of the Spanning Tree is: %d\n", mincost);
  printf("Code by Anmol Arora\n");
}

int findnextindex() {
  int min = INF, a, k = -1, p;
  for (a = 1; a <= n; a++) {
    p = nears[a];
    if (p != 0 && cost[a][p] < min) {
      min = cost[a][p];
      k = a;
    }
  }
  return k;
}
int main() {
  readv();
  primsalg();
  return 0;
}
