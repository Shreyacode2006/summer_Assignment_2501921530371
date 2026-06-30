#include <stdio.h>
#include <stdlib.h>

struct Account {

    int accNo;
    char name[50];
    float balance;
};


void createAccount();
void displayAccounts();
void searchAccount();
void deposit();
void withdraw();
void deleteAccount();


int main() {

    int choice;


    while(1) {

        printf("\n===== Bank Account Management System =====\n");
        printf("1. Create Account\n");
        printf("2. Display Accounts\n");
        printf("3. Search Account\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Delete Account\n");
        printf("7. Exit\n");


        printf("Enter choice: ");
        scanf("%d",&choice);



        switch(choice) {

            case 1:
                createAccount();
                break;

            case 2:
                displayAccounts();
                break;

            case 3:
                searchAccount();
                break;

            case 4:
                deposit();
                break;

            case 5:
                withdraw();
                break;

            case 6:
                deleteAccount();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }


    return 0;
}



void createAccount() {

    struct Account a;
    FILE *fp;


    fp=fopen("bank.dat","ab");


    printf("\nEnter Account Number: ");
    scanf("%d",&a.accNo);


    printf("Enter Account Holder Name: ");
    scanf("%s",a.name);


    printf("Enter Initial Balance: ");
    scanf("%f",&a.balance);



    fwrite(&a,sizeof(a),1,fp);


    fclose(fp);


    printf("Account created successfully!\n");
}





void displayAccounts() {

    struct Account a;

    FILE *fp;


    fp=fopen("bank.dat","rb");


    if(fp==NULL) {

        printf("No accounts found!\n");
        return;
    }



    printf("\nAccount No\tName\tBalance\n");


    while(fread(&a,sizeof(a),1,fp)) {

        printf("%d\t\t%s\t%.2f\n",
        a.accNo,
        a.name,
        a.balance);
    }


    fclose(fp);
}






void searchAccount() {

    struct Account a;

    FILE *fp;


    int no;
    int found=0;



    fp=fopen("bank.dat","rb");


    printf("\nEnter Account Number: ");
    scanf("%d",&no);



    while(fread(&a,sizeof(a),1,fp)) {


        if(a.accNo==no) {


            printf("\nAccount Found\n");

            printf("Account No: %d\n",a.accNo);

            printf("Name: %s\n",a.name);

            printf("Balance: %.2f\n",a.balance);


            found=1;
            break;
        }
    }


    fclose(fp);



    if(!found)

        printf("Account not found!\n");
}






void deposit() {

    struct Account a;

    FILE *fp;


    int no;
    float amount;

    int found=0;



    fp=fopen("bank.dat","rb+");


    printf("\nEnter Account Number: ");
    scanf("%d",&no);



    while(fread(&a,sizeof(a),1,fp)) {


        if(a.accNo==no) {


            printf("Enter deposit amount: ");
            scanf("%f",&amount);


            a.balance += amount;


            fseek(fp,-sizeof(a),SEEK_CUR);


            fwrite(&a,sizeof(a),1,fp);


            printf("Money deposited successfully!\n");


            found=1;
            break;
        }
    }


    fclose(fp);



    if(!found)

        printf("Account not found!\n");
}





void withdraw() {

    struct Account a;

    FILE *fp;


    int no;
    float amount;

    int found=0;



    fp=fopen("bank.dat","rb+");


    printf("\nEnter Account Number: ");
    scanf("%d",&no);



    while(fread(&a,sizeof(a),1,fp)) {


        if(a.accNo==no) {


            printf("Enter withdrawal amount: ");
            scanf("%f",&amount);



            if(amount <= a.balance) {


                a.balance -= amount;


                fseek(fp,-sizeof(a),SEEK_CUR);


                fwrite(&a,sizeof(a),1,fp);


                printf("Withdrawal successful!\n");
            }

            else {

                printf("Insufficient balance!\n");
            }


            found=1;
            break;
        }
    }


    fclose(fp);



    if(!found)

        printf("Account not found!\n");
}






void deleteAccount() {


    struct Account a;

    FILE *fp,*temp;


    int no;
    int found=0;



    fp=fopen("bank.dat","rb");

    temp=fopen("temp.dat","wb");



    printf("\nEnter Account Number to delete: ");
    scanf("%d",&no);



    while(fread(&a,sizeof(a),1,fp)) {


        if(a.accNo!=no)

            fwrite(&a,sizeof(a),1,temp);

        else

            found=1;
    }



    fclose(fp);

    fclose(temp);



    remove("bank.dat");

    rename("temp.dat","bank.dat");



    if(found)

        printf("Account deleted successfully!\n");

    else

        printf("Account not found!\n");
}