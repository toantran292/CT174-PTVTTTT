#include <stdio.h>

typedef struct {
    int w, v, u, ans;
    float rate;
    char name[20];
} KS;

int W, n;
KS k[100];

void read() {
    freopen("CaiBalo2.txt", "r", stdin);
    scanf("%d", &W);
    KS temp;
    while (scanf("%d%d%d %[^\n]", &temp.w, &temp.v, &temp.u, temp.name) != -1) {
        temp.rate = temp.v * 1.0f / temp.w;
        temp.ans = temp.u;
        k[n++] = temp;
    }
}

int current_cost, best_cost = -1, total;
int u_best[100];

void update_best_cost(int current_cost) {
    if (current_cost > best_cost) {
        best_cost = current_cost;

        for (int i = 0; i < n; i++) u_best[i] = k[i].ans;
    }
}
void swap(KS *a, KS *b) {
    KS t = *a;
    *a = *b;
    *b = t;
}

void sort() {
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= i + 1; j--) {
            if (k[j].rate > k[j - 1].rate) {
                swap(&k[j], &k[j - 1]);
            }
        }
    }
}

void bab(int i) {
    if (current_cost <= best_cost) return;

    int maxJ = k[i].ans;
    if (maxJ > W / k[i].w) maxJ = W / k[i].w;

    for (int j = maxJ; j >= 0; j--) {
        k[i].ans = j;
        total += j * k[i].v;
        W -= j * k[i].w;

        if (i == n - 1)
            update_best_cost(total);
        else {
            current_cost = total + W * k[i + 1].rate;
            bab(i + 1);
        }

        total -= j * k[i].v;
        W += j * k[i].w;
    }
}
// 2 1 1 0 3
int main() {
    read();
    sort();
    bab(0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += u_best[i] * k[i].v;
        printf("%s - %10d\n", k[i].name, u_best[i]);
    }
    printf("%d", ans);
}
