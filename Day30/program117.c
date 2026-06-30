#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {

    int roll;
    char name[50];
    int age;
    float marks;
};


struct Student students[MAX];

int count = 0;


void addStudent();
void displayStudent();
void searchStudent();
void updateStudent();
void deleteStudent();



int main() {

    int choice;


    while(1) {

        printf("\n===== Student Record System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");


        printf("Enter choice: ");
        scanf("%d",&choice);



        switch(choice) {

            case 1:
                addStudent();
                break;

            case 2:
                displayStudent();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

}






void addStudent() {


    if(count == MAX) {

        printf("Record limit reached!\n");
        return;
    }


    printf("\nEnter Roll Number: ");
    scanf("%d",&students[count].roll);


    printf("Enter Name: ");
    scanf("%s",students[count].name);


    printf("Enter Age: ");
    scanf("%d",&students[count].age);


    printf("Enter Marks: ");
    scanf("%f",&students[count].marks);



    count++;


    printf("Student added successfully!\n");
}








void displayStudent() {


    int i;


    if(count == 0) {

        printf("No records available!\n");
        return;
    }



    printf("\nRoll\tName\tAge\tMarks\n");


    for(i=0;i<count;i++) {


        printf("%d\t%s\t%d\t%.2f\n",
        students[i].roll,
        students[i].name,
        students[i].age,
        students[i].marks);

    }

}








void searchStudent() {


    int roll,i;
    int found=0;


    printf("\nEnter Roll Number to search: ");
    scanf("%d",&roll);



    for(i=0;i<count;i++) {


        if(students[i].roll == roll) {


            printf("\nStudent Found\n");

            printf("Roll: %d\n",students[i].roll);

            printf("Name: %s\n",students[i].name);

            printf("Age: %d\n",students[i].age);

            printf("Marks: %.2f\n",students[i].marks);


            found=1;
            break;
        }
    }



    if(!found)

        printf("Student not found!\n");

}








void updateStudent() {


    int roll,i;
    int found=0;



    printf("\nEnter Roll Number to update: ");
    scanf("%d",&roll);



    for(i=0;i<count;i++) {


        if(students[i].roll == roll) {


            printf("Enter new name: ");
            scanf("%s",students[i].name);



            printf("Enter new marks: ");
            scanf("%f",&students[i].marks);



            found=1;
            break;
        }
    }



    if(found)

        printf("Record updated successfully!\n");

    else

        printf("Student not found!\n");

}








void deleteStudent() {


    int roll,i,j;
    int found=0;



    printf("\nEnter Roll Number to delete: ");
    scanf("%d",&roll);



    for(i=0;i<count;i++) {


        if(students[i].roll == roll) {


            for(j=i;j<count-1;j++) {

                students[j]=students[j+1];

            }


            count--;


            found=1;
            break;
        }
    }



    if(found)

        printf("Record deleted successfully!\n");

    else

        printf("Student not found!\n");

}