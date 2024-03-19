
#include <stdio.h>
#define MAXN 1000
typedef int keyType;
typedef float otherFieldType;

typedef struct {
  keyType key;
  otherFieldType otherFields;
} recordType;

void swapRecord(recordType *a, recordType *b) {
  recordType c = *a;
  *a = *b;
  *b = c;
}

void ReadData(recordType R[], int *pN) {
  freopen("data.txt", "r", stdin);
  int n = 0;
  while (scanf("%d%f", &(R[n].key), &(R[n].otherFields)) != -1)
    n++;
  *pN = n;
}

int getPivot(recordType R[], int l, int r) {
  for (int i = l + 1; i <= r; i++) {
    if (R[i].key != R[i - 1].key) {
      if (R[i].key > R[i - 1].key)
        return i;
      return i - 1;
    }
  }
  return -1;
}

int _partition(recordType R[], int l, int r, int pivot) {
  while (l < r) {
    while (R[l].key < R[pivot].key)
      l++;
    while (R[r].key >= R[pivot].key)
      r--;
    if (l < r)
      swapRecord(&R[l], &R[r]);
  }
  return l;
}

void quickSort(recordType R[], int l, int r) {
  int pivot = getPivot(R, l, r);
  if (pivot == -1)
    return;
  int point = _partition(R, l, r, pivot);
  quickSort(R, l, point - 1); // [l; point - 1]
  quickSort(R, point, r);     // [point; r]
}

int main() {
  // printf("Hello World!");
  recordType R[MAXN];
  int n;
  ReadData(R, &n);

  printf("After using quickSort:\n");
  for (int i = 0; i < n; i++) {
    printf("%d - %.2f\n", R[i].key, R[i].otherFields);
  }
  quickSort(R, 0, n - 1);
  printf("Before using quickSort:\n");
  for (int i = 0; i < n; i++) {
    printf("%d - %.2f\n", R[i].key, R[i].otherFields);
  }
  return 0;
}
