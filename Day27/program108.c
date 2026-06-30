#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main() {
    int choice;

    while(1) {
        printf("\n===== Student Record Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
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
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void addStudent() {
    struct Student s;
    FILE *fp;

    fp = fopen("student.dat", "ab");

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf("%s", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);

    fclose(fp);

    printf("Student record added successfully!\n");
}


void displayStudents() {
    struct Student s;
    FILE *fp;

    fp = fopen("student.dat", "rb");

    if(fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\nRoll\tName\tMarks\n");

    while(fread(&s, sizeof(s), 1, fp)) {
        printf("%d\t%s\t%.2f\n", s.roll, s.name, s.marks);
    }

    fclose(fp);
}


void searchStudent() {
    struct Student s;
    FILE *fp;
    int roll, found = 0;

    fp = fopen("student.dat", "rb");

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    while(fread(&s, sizeof(s), 1, fp)) {
        if(s.roll == roll) {
            printf("\nStudent Found\n");
            printf("Roll: %d\n", s.roll);
            printf("Name: %s\n", s.name);
            printf("Marks: %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if(!found)
        printf("Student not found!\n");
}


void updateStudent() {
    struct Student s;
    FILE *fp;
    int roll, found = 0;

    fp = fopen("student.dat", "rb+");

    printf("Enter roll number to update: ");
    scanf("%d", &roll);

    while(fread(&s, sizeof(s), 1, fp)) {

        if(s.roll == roll) {

            printf("Enter new name: ");
            scanf("%s", s.name);

            printf("Enter new marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if(found)
        printf("Record updated successfully!\n");
    else
        printf("Student not found!\n");
}


void deleteStudent() {

    struct Student s;
    FILE *fp, *temp;
    int roll, found = 0;

    fp = fopen("student.dat", "rb");
    temp = fopen("temp.dat", "wb");

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);


    while(fread(&s, sizeof(s), 1, fp)) {

        if(s.roll != roll) {
            fwrite(&s, sizeof(s), 1, temp);
        }
        else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("student.dat");
    rename("temp.dat", "student.dat");


    if(found)
        printf("Record deleted successfully!\n");
    else
        printf("Student not found!\n");
}