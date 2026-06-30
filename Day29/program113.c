#include <stdio.h>

int main() {

    int choice;
    float a, b, result;


    while(1) {

        printf("\n===== Menu Driven Calculator =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");


        printf("Enter your choice: ");
        scanf("%d",&choice);



        if(choice == 5) {
            printf("Calculator closed!\n");
            break;
        }



        printf("Enter first number: ");
        scanf("%f",&a);


        printf("Enter second number: ");
        scanf("%f",&b);



        switch(choice) {


            case 1:
                result = a + b;
                printf("Addition = %.2f\n", result);
                break;


            case 2:
                result = a - b;
                printf("Subtraction = %.2f\n", result);
                break;


            case 3:
                result = a * b;
                printf("Multiplication = %.2f\n", result);
                break;


            case 4:

                if(b != 0)
                    result = a / b;
                else {
                    printf("Cannot divide by zero!\n");
                    break;
                }

                printf("Division = %.2f\n", result);
                break;


            default:
                printf("Invalid choice!\n");
        }
    }


    return 0;
}