

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
    while (scanf("%d%f", &(R[n].key), &(R[n].otherFields)) != -1) n++;
    *pN = n;
}

void heapify(recordType R[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && R[l].key > R[largest].key) largest = l;
    if (r < n && R[r].key > R[largest].key) largest = r;

    if (largest != i) {
        swapRecord(&R[i], &R[largest]);
        heapify(R, n, largest);
    }
}

void heapSort(recordType R[], int n) {
    for (int i = (n - 2) / 2 ; i >= 0; i--) heapify(R, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swapRecord(&R[0], &R[i]);
        heapify(R, i, 0);
    }
}

int main() {
    // printf("Hello World!");
    recordType R[MAXN];
    int n;
    ReadData(R, &n);

    printf("Before using heapSort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d - %.2f\n", R[i].key, R[i].otherFields);
    }
    heapSort(R, n);
    printf("After using heapSort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d - %.2f\n", R[i].key, R[i].otherFields);
    }
    return 0;
}
