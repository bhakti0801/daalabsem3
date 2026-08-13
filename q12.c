#include <stdio.h>
#include <time.h>

int main() {
    int a[100], n, key;
    int low, high, mid, found = 0;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter sorted elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    clock_t start = clock();

    low = 0;
    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(a[mid] == key) {
            found = 1;
            break;
        }
        else if(a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    clock_t end = clock();

    if(found)
        printf("Element found at index %d\n", mid);
    else
        printf("Element not found\n");

    printf("Time taken: %f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}