#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int max = a[0], second = a[1];

    if(second > max) {
        int temp = max;
        max = second;
        second = temp;
    }

    for(int i = 2; i < n; i++) {
        if(a[i] > max) {
            second = max;
            max = a[i];
        }
        else if(a[i] > second && a[i] != max) {
            second = a[i];
        }
    }

    printf("Second largest = %d", second);

    return 0;
}