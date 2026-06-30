#include <stdio.h>
#include <string.h>

#define MAX 100

struct Employee {

    int id;
    char name[50];
    char department[50];
    float salary;
};


struct Employee emp[MAX];

int count = 0;


void addEmployee();
void displayEmployee();
void searchEmployee();
void updateEmployee();
void deleteEmployee();



int main() {

    int choice;


    while(1) {

        printf("\n===== Mini Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");


        printf("Enter choice: ");
        scanf("%d",&choice);



        switch(choice) {

            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployee();
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
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

}







void addEmployee() {


    if(count == MAX) {

        printf("Employee limit reached!\n");
        return;
    }


    printf("\nEnter Employee ID: ");
    scanf("%d",&emp[count].id);


    printf("Enter Name: ");
    scanf("%s",emp[count].name);


    printf("Enter Department: ");
    scanf("%s",emp[count].department);


    printf("Enter Salary: ");
    scanf("%f",&emp[count].salary);



    count++;


    printf("Employee added successfully!\n");

}








void displayEmployee() {


    int i;


    if(count == 0) {

        printf("No records available!\n");
        return;
    }



    printf("\nID\tName\tDepartment\tSalary\n");



    for(i=0;i<count;i++) {


        printf("%d\t%s\t%s\t\t%.2f\n",
        emp[i].id,
        emp[i].name,
        emp[i].department,
        emp[i].salary);

    }

}








void searchEmployee() {


    int id,i;
    int found=0;



    printf("\nEnter Employee ID: ");
    scanf("%d",&id);



    for(i=0;i<count;i++) {


        if(emp[i].id == id) {


            printf("\nEmployee Found\n");

            printf("ID: %d\n",emp[i].id);

            printf("Name: %s\n",emp[i].name);

            printf("Department: %s\n",emp[i].department);

            printf("Salary: %.2f\n",emp[i].salary);


            found=1;
            break;
        }
    }



    if(!found)

        printf("Employee not found!\n");

}









void updateEmployee() {


    int id,i;
    int found=0;



    printf("\nEnter Employee ID to update: ");
    scanf("%d",&id);



    for(i=0;i<count;i++) {


        if(emp[i].id == id) {


            printf("Enter new department: ");
            scanf("%s",emp[i].department);


            printf("Enter new salary: ");
            scanf("%f",&emp[i].salary);



            found=1;
            break;
        }
    }



    if(found)

        printf("Employee updated successfully!\n");

    else

        printf("Employee not found!\n");

}









void deleteEmployee() {


    int id,i,j;
    int found=0;



    printf("\nEnter Employee ID to delete: ");
    scanf("%d",&id);



    for(i=0;i<count;i++) {


        if(emp[i].id == id) {


            for(j=i;j<count-1;j++) {

                emp[j]=emp[j+1];

            }


            count--;


            found=1;
            break;
        }
    }



    if(found)

        printf("Employee deleted successfully!\n");

    else

        printf("Employee not found!\n");

}