// Problem 2: Array Transformation Cost Minimization
// Given an array, you can add or subtract K from any element.
// Find the minimum number of operations to make all elements equal,
// or print -1 if it is not possible.

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100005];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    if (k == 0) {
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[0]) {
                printf("-1\n");
                return 0;
            }
        }
        printf("0\n");
        return 0;
    }

    // Check feasibility
    for (int i = 1; i < n; i++) {
        if ((arr[i] - arr[0]) % k != 0) {
            printf("-1\n");
            return 0;
        }
    }

    qsort(arr, n, sizeof(int), compare);

    int median = arr[n / 2];
    int operations = 0;

    for (int i = 0; i < n; i++) {
        operations += abs(arr[i] - median) / k;
    }

    printf("%d\n", operations);
    return 0;
}
