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

void selectionSort(recordType R[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minElement = i;
    for (int j = i + 1; j < n; j++) {
      if (R[j].key < R[minElement].key)
        minElement = j;
    }
    swapRecord(&R[i], &R[minElement]);
  }
}

int main() {
  // printf("Hello World!");
  recordType R[MAXN];
  int n;
  ReadData(R, &n);

  printf("Before using selectionSort:\n");
  for (int i = 0; i < n; i++) {
    printf("%d - %.2f\n", R[i].key, R[i].otherFields);
  }
  selectionSort(R, n);
  printf("After using selectionSort:\n");
  for (int i = 0; i < n; i++) {
    printf("%d - %.2f\n", R[i].key, R[i].otherFields);
  }
  return 0;
}
