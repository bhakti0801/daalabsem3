#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j, flag = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    j = strlen(str) - 1;

    for(i = 0; i < j; i++, j++) {
        if(str[i] != str[j]) {
            flag = 0;
            break;
        }
    }

    if(flag)
        printf("Palindrome");
    else
        printf("Not a palindrome");

    return 0;
}