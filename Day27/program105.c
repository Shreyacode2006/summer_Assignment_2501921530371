#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char department[50];
    float salary;
};

void addEmployee();
void displayEmployees();
void searchEmployee();
void updateEmployee();
void deleteEmployee();

int main() {

    int choice;

    while(1) {

        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                updateEmployee();
                break;

            case 5:
                deleteEmployee();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}


void addEmployee() {

    struct Employee e;
    FILE *fp;

    fp = fopen("employee.dat", "ab");

    printf("\nEnter Employee ID: ");
    scanf("%d", &e.id);

    printf("Enter Name: ");
    scanf("%s", e.name);

    printf("Enter Department: ");
    scanf("%s", e.department);

    printf("Enter Salary: ");
    scanf("%f", &e.salary);


    fwrite(&e, sizeof(e), 1, fp);

    fclose(fp);

    printf("Employee added successfully!\n");
}



void displayEmployees() {

    struct Employee e;
    FILE *fp;

    fp = fopen("employee.dat", "rb");


    if(fp == NULL) {
        printf("No employee records found!\n");
        return;
    }


    printf("\nID\tName\tDepartment\tSalary\n");


    while(fread(&e, sizeof(e), 1, fp)) {

        printf("%d\t%s\t%s\t\t%.2f\n",
        e.id, e.name, e.department, e.salary);
    }


    fclose(fp);
}



void searchEmployee() {

    struct Employee e;
    FILE *fp;
    int id, found = 0;


    fp = fopen("employee.dat", "rb");


    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);


    while(fread(&e, sizeof(e), 1, fp)) {

        if(e.id == id) {

            printf("\nEmployee Found\n");
            printf("ID: %d\n", e.id);
            printf("Name: %s\n", e.name);
            printf("Department: %s\n", e.department);
            printf("Salary: %.2f\n", e.salary);

            found = 1;
            break;
        }
    }


    fclose(fp);


    if(!found)
        printf("Employee not found!\n");
}




void updateEmployee() {

    struct Employee e;
    FILE *fp;

    int id;
    int found = 0;


    fp = fopen("employee.dat", "rb+");


    printf("\nEnter Employee ID to update: ");
    scanf("%d", &id);


    while(fread(&e, sizeof(e), 1, fp)) {

        if(e.id == id) {


            printf("Enter new name: ");
            scanf("%s", e.name);


            printf("Enter new department: ");
            scanf("%s", e.department);


            printf("Enter new salary: ");
            scanf("%f", &e.salary);


            fseek(fp, -sizeof(e), SEEK_CUR);

            fwrite(&e, sizeof(e), 1, fp);


            found = 1;
            break;
        }
    }


    fclose(fp);


    if(found)
        printf("Employee updated successfully!\n");

    else
        printf("Employee not found!\n");
}




void deleteEmployee() {

    struct Employee e;

    FILE *fp, *temp;

    int id;
    int found = 0;


    fp = fopen("employee.dat", "rb");
    temp = fopen("temp.dat", "wb");


    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);



    while(fread(&e, sizeof(e), 1, fp)) {


        if(e.id != id) {

            fwrite(&e, sizeof(e), 1, temp);

        }
        else {

            found = 1;
        }
    }


    fclose(fp);
    fclose(temp);


    remove("employee.dat");

    rename("temp.dat", "employee.dat");


    if(found)

        printf("Employee deleted successfully!\n");

    else

        printf("Employee not found!\n");
}