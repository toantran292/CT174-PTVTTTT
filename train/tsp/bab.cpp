#include <stdio.h>

float c[100][100];
float current_cost, best_cost = 9999;
int n;
int visited[100], x_best[100], x[100];

void bab(int i) {
    if (current_cost >= best_cost) return;

    for(int j = 1; j <= n; j++){
      if(!visited[j]){
        visited[j] = 1;
        x[i] = j;
        current_cost += (n - i) * 
      }
    }
}

int main() {
    freopen("tsp.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &c[i][j]);
        }
    }
}
