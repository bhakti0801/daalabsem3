#include <stdio.h>

int main() {
    int n, m;

    printf("Enter size of first array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter sorted first array: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter size of second array: ");
    scanf("%d", &m);

    int b[m];
    printf("Enter sorted second array: ");
    for(int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    int c[n + m];
    int i = 0, j = 0, k = 0;

    while(i < n && j < m) {
        if(a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while(i < n)
        c[k++] = a[i++];

    while(j < m)
        c[k++] = b[j++];

    printf("Merged array: ");
    for(i = 0; i < n + m; i++)
        printf("%d ", c[i]);

    return 0;
} 