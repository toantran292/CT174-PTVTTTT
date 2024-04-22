#include <stdio.h>

typedef struct {
    int u, v;
    float w;
} Tsp;

int par[100];
int cnt[100];
int n, n_tsp;
Tsp tsp[100];
float a[100][100];

int find(int u) {
    if (par[u] == u) return u;
    return find(par[u]);
}

int join(int u, int v) {
    if (cnt[u] > 1 || cnt[v] > 1) return 0;
    if (find(u) == find(v)) return 0;
    cnt[u]++;
    cnt[v]++;
    par[v] = u;
    return 1;
}

void swap(Tsp *a, Tsp *b) {
    Tsp t = *a;
    *a = *b;
    *b = t;
}
void sort() {
    for (int i = 0; i < n_tsp; i++) {
        for (int j = n_tsp - 1; j >= i + 1; j--) {
            if (tsp[j].w < tsp[j - 1].w) {
                swap(&tsp[j], &tsp[j - 1]);
            }
        }
    }
}

int main() {
    freopen("tsp.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) par[i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &tsp[n_tsp].w);
            tsp[n_tsp].u = i;
            tsp[n_tsp].v = j;
            a[i][j] = tsp[n_tsp].w;
            n_tsp++;
        }
    }
    sort();
    float ans = 0;
    for (int i = 0; i < n_tsp; i++) {
        // if (join(tsp[i].u, tsp[i].v)) {
        // printf("%c%c - %.2f\n", tsp[i].u + 97, tsp[i].v + 97, tsp[i].w);
        // ans += tsp[i].w;
        // }
    }
    for (int i = 0; i < n_tsp; i++) {
        if (tsp[i].w > 0) {
            if (join(tsp[i].u, tsp[i].v)) {
                printf("%c%c - %.2f\n", tsp[i].u + 97, tsp[i].v + 97, tsp[i].w);
                ans += tsp[i].w;
            }
        }
    }
    int u = -1, v = -1;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 1) {
            if (u == -1)
                u = i;
            else
                v = i;
        }
    }
    ans += a[u][v];
    printf("%c%c - %.2f\n", u + 97, v + 97, a[u][v]);

    printf("%.2f", ans);
}
// DSU
//
