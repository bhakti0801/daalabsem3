#include <stdio.h>
#include <time.h>

int main() {
    int a[100], n, key;
    int i, found = 0;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    clock_t start = clock();

    for(i = 0; i < n; i++) {
        if(a[i] == key) {
            found = 1;
            break;
        }
    }

    clock_t end = clock();

    if(found)
        printf("Element found at index %d\n", i);
    else
        printf("Element not found\n");

    printf("Time taken: %f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}