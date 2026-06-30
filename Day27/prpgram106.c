#include <stdio.h>
#include <stdlib.h>

struct Salary {
    int empId;
    char name[50];
    float basicSalary;
    float allowance;
    float deduction;
    float netSalary;
};

void addSalary();
void displaySalary();
void searchSalary();
void updateSalary();
void deleteSalary();

int main() {

    int choice;

    while(1) {

        printf("\n===== Salary Management System =====\n");
        printf("1. Add Salary Record\n");
        printf("2. Display Salary Records\n");
        printf("3. Search Salary Record\n");
        printf("4. Update Salary Record\n");
        printf("5. Delete Salary Record\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);


        switch(choice) {

            case 1:
                addSalary();
                break;

            case 2:
                displaySalary();
                break;

            case 3:
                searchSalary();
                break;

            case 4:
                updateSalary();
                break;

            case 5:
                deleteSalary();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}



void addSalary() {

    struct Salary s;
    FILE *fp;

    fp = fopen("salary.dat","ab");


    printf("\nEnter Employee ID: ");
    scanf("%d",&s.empId);


    printf("Enter Employee Name: ");
    scanf("%s",s.name);


    printf("Enter Basic Salary: ");
    scanf("%f",&s.basicSalary);


    printf("Enter Allowance: ");
    scanf("%f",&s.allowance);


    printf("Enter Deduction: ");
    scanf("%f",&s.deduction);


    s.netSalary = s.basicSalary + s.allowance - s.deduction;


    fwrite(&s,sizeof(s),1,fp);


    fclose(fp);


    printf("Salary record added successfully!\n");
}




void displaySalary() {

    struct Salary s;

    FILE *fp;

    fp = fopen("salary.dat","rb");


    if(fp == NULL) {

        printf("No records found!\n");
        return;
    }


    printf("\nID\tName\tBasic\tAllow\tDeduct\tNet Salary\n");


    while(fread(&s,sizeof(s),1,fp)) {


        printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",
        s.empId,
        s.name,
        s.basicSalary,
        s.allowance,
        s.deduction,
        s.netSalary);
    }


    fclose(fp);
}





void searchSalary() {

    struct Salary s;

    FILE *fp;

    int id, found=0;


    fp=fopen("salary.dat","rb");


    printf("\nEnter Employee ID: ");
    scanf("%d",&id);



    while(fread(&s,sizeof(s),1,fp)) {


        if(s.empId==id) {


            printf("\nRecord Found\n");

            printf("Employee ID: %d\n",s.empId);
            printf("Name: %s\n",s.name);
            printf("Net Salary: %.2f\n",s.netSalary);


            found=1;
            break;
        }
    }


    fclose(fp);


    if(!found)

        printf("Record not found!\n");
}





void updateSalary() {

    struct Salary s;

    FILE *fp;

    int id,found=0;


    fp=fopen("salary.dat","rb+");


    printf("\nEnter Employee ID to update: ");
    scanf("%d",&id);



    while(fread(&s,sizeof(s),1,fp)) {


        if(s.empId==id) {


            printf("Enter new basic salary: ");
            scanf("%f",&s.basicSalary);


            printf("Enter new allowance: ");
            scanf("%f",&s.allowance);


            printf("Enter new deduction: ");
            scanf("%f",&s.deduction);



            s.netSalary =
            s.basicSalary+s.allowance-s.deduction;



            fseek(fp,-sizeof(s),SEEK_CUR);


            fwrite(&s,sizeof(s),1,fp);


            found=1;

            break;
        }
    }


    fclose(fp);



    if(found)

        printf("Salary updated successfully!\n");

    else

        printf("Record not found!\n");
}





void deleteSalary() {

    struct Salary s;

    FILE *fp,*temp;


    int id,found=0;


    fp=fopen("salary.dat","rb");

    temp=fopen("temp.dat","wb");



    printf("\nEnter Employee ID to delete: ");
    scanf("%d",&id);



    while(fread(&s,sizeof(s),1,fp)) {


        if(s.empId!=id) {

            fwrite(&s,sizeof(s),1,temp);

        }

        else {

            found=1;
        }
    }



    fclose(fp);

    fclose(temp);



    remove("salary.dat");

    rename("temp.dat","salary.dat");



    if(found)

        printf("Salary record deleted successfully!\n");

    else

        printf("Record not found!\n");
}