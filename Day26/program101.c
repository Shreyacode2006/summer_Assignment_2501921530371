#include <stdio.h>

int main() {
    int pin, choice;
    float balance = 10000, amount;

    printf("Enter PIN: ");
    scanf("%d", &pin);

    if(pin == 1234) {

        do {
            printf("\n1. Check Balance");
            printf("\n2. Withdraw Money");
            printf("\n3. Deposit Money");
            printf("\n4. Exit");

            printf("\nEnter choice: ");
            scanf("%d", &choice);

            switch(choice) {

                case 1:
                    printf("Balance = %.2f", balance);
                    break;

                case 2:
                    printf("Enter withdrawal amount: ");
                    scanf("%f", &amount);

                    if(amount <= balance) {
                        balance -= amount;
                        printf("Please collect your money");
                    }
                    else
                        printf("Insufficient balance");

                    break;

                case 3:
                    printf("Enter deposit amount: ");
                    scanf("%f", &amount);

                    balance += amount;
                    printf("Money deposited successfully");
                    break;

                case 4:
                    printf("Thank you");
                    break;

                default:
                    printf("Invalid choice");
            }

        } while(choice != 4);

    }
    else
        printf("Wrong PIN");

    return 0;
}