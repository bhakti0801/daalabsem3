#include <stdio.h>

int main() {
    int a[100], n, target;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target: ");
    scanf("%d", &target);

    printf("Pairs: ");

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] + a[j] == target)
                printf("(%d, %d) ", a[i], a[j]);
        }
    }

    return 0;
}