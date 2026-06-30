#include <stdio.h>
#include <stdlib.h>

struct Marksheet {

    int roll;
    char name[50];

    float sub1;
    float sub2;
    float sub3;

    float total;
    float percentage;
    char grade[5];
};


void addMarksheet();
void displayMarksheet();
void searchMarksheet();
void updateMarksheet();
void deleteMarksheet();


int main() {

    int choice;


    while(1) {

        printf("\n===== Marksheet Generation System =====\n");

        printf("1. Generate Marksheet\n");
        printf("2. Display Marksheet\n");
        printf("3. Search Student\n");
        printf("4. Update Marks\n");
        printf("5. Delete Marksheet\n");
        printf("6. Exit\n");


        printf("Enter choice: ");
        scanf("%d",&choice);



        switch(choice) {

            case 1:
                addMarksheet();
                break;

            case 2:
                displayMarksheet();
                break;

            case 3:
                searchMarksheet();
                break;

            case 4:
                updateMarksheet();
                break;

            case 5:
                deleteMarksheet();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }


    return 0;
}



void addMarksheet() {

    struct Marksheet m;

    FILE *fp;


    fp=fopen("marksheet.dat","ab");


    printf("\nEnter Roll Number: ");
    scanf("%d",&m.roll);


    printf("Enter Student Name: ");
    scanf("%s",m.name);



    printf("Enter Subject 1 Marks: ");
    scanf("%f",&m.sub1);


    printf("Enter Subject 2 Marks: ");
    scanf("%f",&m.sub2);


    printf("Enter Subject 3 Marks: ");
    scanf("%f",&m.sub3);



    m.total = m.sub1 + m.sub2 + m.sub3;


    m.percentage = m.total / 3;



    if(m.percentage >= 90)
        strcpy(m.grade,"A+");

    else if(m.percentage >= 75)
        strcpy(m.grade,"A");

    else if(m.percentage >= 60)
        strcpy(m.grade,"B");

    else if(m.percentage >= 40)
        strcpy(m.grade,"C");

    else
        strcpy(m.grade,"Fail");



    fwrite(&m,sizeof(m),1,fp);


    fclose(fp);



    printf("Marksheet generated successfully!\n");
}





void displayMarksheet() {


    struct Marksheet m;

    FILE *fp;


    fp=fopen("marksheet.dat","rb");


    if(fp==NULL) {

        printf("No records found!\n");
        return;
    }



    printf("\nRoll\tName\tTotal\tPercentage\tGrade\n");


    while(fread(&m,sizeof(m),1,fp)) {


        printf("%d\t%s\t%.2f\t%.2f%%\t\t%s\n",
        m.roll,
        m.name,
        m.total,
        m.percentage,
        m.grade);

    }


    fclose(fp);
}





void searchMarksheet() {


    struct Marksheet m;

    FILE *fp;


    int roll;
    int found=0;


    fp=fopen("marksheet.dat","rb");


    printf("\nEnter Roll Number: ");
    scanf("%d",&roll);



    while(fread(&m,sizeof(m),1,fp)) {


        if(m.roll==roll) {


            printf("\n----- Marksheet -----\n");

            printf("Name: %s\n",m.name);

            printf("Subject 1: %.2f\n",m.sub1);

            printf("Subject 2: %.2f\n",m.sub2);

            printf("Subject 3: %.2f\n",m.sub3);

            printf("Total: %.2f\n",m.total);

            printf("Percentage: %.2f%%\n",m.percentage);

            printf("Grade: %s\n",m.grade);


            found=1;

            break;
        }
    }


    fclose(fp);



    if(!found)

        printf("Student not found!\n");
}





void updateMarksheet() {


    struct Marksheet m;

    FILE *fp;


    int roll;
    int found=0;



    fp=fopen("marksheet.dat","rb+");


    printf("\nEnter Roll Number: ");
    scanf("%d",&roll);



    while(fread(&m,sizeof(m),1,fp)) {


        if(m.roll==roll) {


            printf("Enter new marks of subject 1: ");
            scanf("%f",&m.sub1);


            printf("Enter new marks of subject 2: ");
            scanf("%f",&m.sub2);


            printf("Enter new marks of subject 3: ");
            scanf("%f",&m.sub3);



            m.total=m.sub1+m.sub2+m.sub3;

            m.percentage=m.total/3;



            if(m.percentage>=90)
                strcpy(m.grade,"A+");

            else if(m.percentage>=75)
                strcpy(m.grade,"A");

            else if(m.percentage>=60)
                strcpy(m.grade,"B");

            else if(m.percentage>=40)
                strcpy(m.grade,"C");

            else
                strcpy(m.grade,"Fail");



            fseek(fp,-sizeof(m),SEEK_CUR);

            fwrite(&m,sizeof(m),1,fp);



            found=1;

            break;
        }
    }


    fclose(fp);



    if(found)

        printf("Updated successfully!\n");

    else

        printf("Student not found!\n");

}





void deleteMarksheet() {


    struct Marksheet m;

    FILE *fp,*temp;


    int roll;
    int found=0;



    fp=fopen("marksheet.dat","rb");

    temp=fopen("temp.dat","wb");



    printf("\nEnter Roll Number to delete: ");
    scanf("%d",&roll);



    while(fread(&m,sizeof(m),1,fp)) {


        if(m.roll!=roll)

            fwrite(&m,sizeof(m),1,temp);

        else

            found=1;
    }



    fclose(fp);

    fclose(temp);



    remove("marksheet.dat");

    rename("temp.dat","marksheet.dat");



    if(found)

        printf("Marksheet deleted successfully!\n");

    else

        printf("Student not found!\n");
}