#include <stdio.h>

int findCelebrity(int M[][3], int n) {
    for (int c = 0; c < n; c++) {
        int knowsNobody = 1;
        int knownByEveryone = 1;

        // Check if the candidate knows anyone
        for (int i = 0; i < n; i++) {
            if (i != c && M[c][i] == 1) {
                knowsNobody = 0;
                break;
            }
        }

        // Check if everyone knows the candidate
        for (int i = 0; i < n; i++) {
            if (i != c && M[i][c] == 0) {
                knownByEveryone = 0;
                break;
            }
        }

        // Check both conditions
        if (knowsNobody && knownByEveryone) {
            return c;
        }
    }

    return -1;
}

int main() {
    int n = 3;

    int M[3][3] = {
        {0, 1, 1},
        {1, 0, 1},
        {0, 0, 0}
    };

    int celebrity = findCelebrity(M, n);

    if (celebrity == -1) {
        printf("No celebrity found\n");
    } else {
        printf("Celebrity is person %d\n", celebrity);
    }

    return 0;
}