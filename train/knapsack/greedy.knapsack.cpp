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

void swap(KS *a, KS *b) {
    KS t = *a;
    *a = *b;
    *b = t;
}
// 2 1 5 2 3
void sort() {
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= i + 1; j--) {
            if (k[j].rate > k[j - 1].rate) {
                swap(&k[j], &k[j - 1]);
            }
        }
    }
}

int main() {
    read();
    sort();
    for (int i = 0; i < n; i++) {
        KS t = k[i];
        printf("%d %d %d %.2f %s\n", t.w, t.v, t.u, t.rate, t.name);
    }

    for (int i = 0; i < n; i++) {
        KS t = k[i];
        if (W / t.w < t.u) {
            // printf("%d %d %d\n", W, t.w, W / t.w);
            k[i].ans = W / t.w;
        }

        W -= k[i].ans * k[i].w;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        KS t = k[i];
        ans += t.ans * t.v;
        printf("%s - %10d\n", t.name, t.ans);
    }
    printf("%d", ans);
}
