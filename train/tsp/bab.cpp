#include <stdio.h>

float c[100][100];
float total, lower, smallest = 3.40282e+38;
int n;
int visited[100][100], x_best[100], x[100];

int hasCircle(int target) {
    for (int i = 0; i < n; i++) {
        if (visited[i][target]) return true;
    }
    return false;
}

float get_smallest_edge() {
    float m = 3.40282e+38;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && !visited[i][j] && c[i][j] < m) {
                m = c[i][j];
            }
    return m;
}

float get_lower(int i) { return total + (n - i) * get_smallest_edge(); }

void update_best_value() {
    if (total + c[x[n - 1]][0] < smallest) {
        smallest = total + c[x[n - 1]][0];

        for (int i = 0; i < n; i++) x_best[i] = x[i];
    }
}

void bab(int i) {
    for (int j = 0; j < n; j++) {
        if (x[i - 1] != j && !visited[x[i - 1]][j] && !hasCircle(j)) {
            total += c[x[i - 1]][j];
            lower = get_lower(i);
            if (lower < smallest) {
                x[i] = j;
                visited[x[i - 1]][j] = visited[j][x[i - 1]] = 1;

                if (i == n - 1) {
                    update_best_value();
                } else
                    bab(i + 1);
            }
            total -= c[x[i - 1]][j];
            visited[x[i - 1]][j] = visited[j][x[i - 1]] = 0;
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
    x[0] = 0;
    bab(1);

    for (int i = 0; i < n; i++) {
        printf("%c -> ", x_best[i] + 97);
    }
    printf("%c\n", x_best[0] + 97);
    printf("%.2f", smallest);
}
