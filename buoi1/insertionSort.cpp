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

void insertionSort(recordType R[], int n) {
    for (int i = 0; i < n; i++) {
        recordType K = R[i];
        int j = i - 1;
        while (j >= 0 && K.key < R[j].key) {
            R[j + 1] = R[j];
            j--;
        }
        R[j + 1] = K;
    }
}

int main() {
    // printf("Hello World!");
    recordType R[MAXN];
    int n;
    ReadData(R, &n);

    printf("Before using insertionSort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d - %.2f\n", R[i].key, R[i].otherFields);
    }
    insertionSort(R, n);
    printf("After using insertionSort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d - %.2f\n", R[i].key, R[i].otherFields);
    }
    return 0;
}
