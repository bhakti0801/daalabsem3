#include <stdio.h>

int main() {
    int choice;
    float balance = 0, amount;
    float transactions[5];
    int count = 0;
    int i;

    while (1) {
        printf("\n\n===== ATM MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Last 5 Transactions\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nCurrent Balance = %.2f\n", balance);
        }

        else if (choice == 2) {
            printf("\nEnter amount to deposit: ");
            scanf("%f", &amount);

            if (amount > 0) {
                balance = balance + amount;

                // Store transaction
                if (count < 5) {
                    transactions[count] = amount;
                    count++;
                }
                else {
                    for (i = 0; i < 4; i++)
                        transactions[i] = transactions[i + 1];

                    transactions[4] = amount;
                }

                printf("Money deposited successfully!\n");
            }
            else {
                printf("Invalid amount!\n");
            }
        }

        else if (choice == 3) {
            printf("\nEnter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount <= 0) {
                printf("Invalid amount!\n");
            }
            else if (amount > balance) {
                printf("Insufficient balance!\n");
            }
            else {
                balance = balance - amount;

                // Store withdrawal as negative
                if (count < 5) {
                    transactions[count] = -amount;
                    count++;
                }
                else {
                    for (i = 0; i < 4; i++)
                        transactions[i] = transactions[i + 1];

                    transactions[4] = -amount;
                }

                printf("Please collect your money.\n");
            }
        }

        else if (choice == 4) {
            printf("\n----- LAST 5 TRANSACTIONS -----\n");

            if (count == 0) {
                printf("No transactions yet.\n");
            }
            else {
                for (i = 0; i < count; i++) {

                    if (transactions[i] > 0)
                        printf("Deposit: +%.2f\n", transactions[i]);

                    else
                        printf("Withdrawal: %.2f\n", transactions[i]);
                }
            }
        }

        else if (choice == 5) {
            printf("\nThank you for using the ATM!\n");
            break;
        }

        else {
            printf("\nInvalid choice!\n");
        }
    }

    return 0;
}