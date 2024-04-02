#include <stdio.h>
#define maxn 1000
#define min(a, b) ((a) < (b) ? a : b)
typedef struct {
  float w, v, key;
  int ans, unit;
  char name[25];
} Knapsack;

int n = 0;
float w, ans;
Knapsack knapsacks[maxn];
typedef Knapsack recordType;

void init() {
  n = 0;
  ans = 0;
}

void swapRecord(recordType *a, recordType *b) {
  recordType c = *a;
  *a = *b;
  *b = c;
}

void bubbleSort(recordType R[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (R[j].key < R[j + 1].key) {
        swapRecord(&R[j], &R[j + 1]);
      }
    }
  }
}

void printAns(int num) {
  printf("\nPhuong an Cai Ba lo %d dung thuat toan THAM AN nhu sau:\n", num);
  printf("\nTrong luong cua ba lo = %-9.2f\n", w);
  printf(
      "|---|------------------|---------|---------|---------|-----------|\n");
  printf(
      "|STT|     Ten Do Vat   | T Luong | Gia Tri | Don Gia | Phuong an |\n");
  printf(
      "|---|------------------|---------|---------|---------|-----------|\n");
  for (int i = 0; i < n; i++) {
    printf("|%2d |%-18s|%9.2f|%9.2f|%9.2f|%6d     |\n", i + 1,
           knapsacks[i].name, knapsacks[i].w, knapsacks[i].v, knapsacks[i].key,
           knapsacks[i].ans);
    w = w + knapsacks[i].ans * knapsacks[i].w;
    ans = ans + knapsacks[i].ans * knapsacks[i].v;
  }
  printf(
      "|---|------------------|---------|---------|---------|-----------|\n");
  printf("Phuong an (theo thu tu key giam dan): X(");
  for (int i = 0; i < n - 1; i++) {
    printf("%d,", knapsacks[i].ans);
  }
  printf("%d)", knapsacks[n - 1].ans);
  printf("\nTrong luong = %-9.2f\n", w);
  printf("Gia tri = %-9.2f\n", ans);
}

void read(char *fname, int num) {
  FILE *f = fopen(fname, "r");
  fscanf(f, "%f", &w);
  while (!feof(f)) {
    Knapsack item;
    item.unit = 1;
    fscanf(f, "%f%f", &item.w, &item.v);
    if (num == 2)
      fscanf(f, "%d", &item.unit);
    fscanf(f, "%[^\n]", item.name);
    item.key = item.v / item.w;
    knapsacks[n] = item;
    n++;
  }
  n--;
  fclose(f);
}

void handleKnapsack1() {
  init();
  char fname[] = "CaiBalo1.txt";
  read(fname, 1);
  int w_t = w;
  for (int i = 0; i < n; i++) {
    Knapsack item = knapsacks[i];
    item.ans = w_t / item.w;
    w_t -= item.ans * item.w;
    knapsacks[i] = item;
  }
  printAns(1);
}

void handleKnapsack2() {
  init();
  char fname[] = "CaiBalo2.txt";
  read(fname, 2);
  int w_t = w;
  for (int i = 0; i < n; i++) {
    Knapsack item = knapsacks[i];
    item.ans = min(item.unit, w_t / item.w);
    w_t -= item.ans * item.w;
    knapsacks[i] = item;
  }
  printAns(2);
}

void handleKnapsack3() {
  init();
  char fname[] = "CaiBalo3.txt";
  read(fname, 3);
  int w_t = w;
  for (int i = 0; i < n; i++) {
    Knapsack item = knapsacks[i];
    item.ans = min(1, w_t / item.w);
    w_t -= item.ans * item.w;
    knapsacks[i] = item;
  }
  printAns(3);
}

int main() {
  // read();
  // bubbleSort(knapsacks, n);
  handleKnapsack1();
  printf("============================\n");
  handleKnapsack2();
  printf("============================\n");
  handleKnapsack3();
}
