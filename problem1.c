// Problem 1: Cyclic Substring Maximum Sum
// Find maximum sum of a cyclic substring with unique characters.

#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char s[100005];
    scanf("%s", s);

    int n = strlen(s);

    // Create doubled string
    char doubled[200010];
    strcpy(doubled, s);
    strcat(doubled, s);

    int freq[26] = {0};
    int left = 0, currentSum = 0, maxSum = 0;

    for (int right = 0; right < 2 * n; right++) {
        int idx = doubled[right] - 'a';

        // Maintain unique characters and window size <= n
        while (freq[idx] > 0 || (right - left + 1) > n) {
            int leftIdx = doubled[left] - 'a';
            freq[leftIdx]--;
            currentSum -= (leftIdx + 1);
            left++;
        }

        freq[idx]++;
        currentSum += (idx + 1);

        maxSum = max(maxSum, currentSum);
    }

    printf("%d\n", maxSum);
    return 0;
}
