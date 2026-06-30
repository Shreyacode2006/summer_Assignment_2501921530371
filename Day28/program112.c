#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {

    char name[50];
    char phone[15];
    char email[50];
};


void addContact();
void displayContacts();
void searchContact();
void updateContact();
void deleteContact();


int main() {

    int choice;


    while(1) {

        printf("\n===== Contact Management System =====\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");


        printf("Enter choice: ");
        scanf("%d",&choice);



        switch(choice) {

            case 1:
                addContact();
                break;

            case 2:
                displayContacts();
                break;

            case 3:
                searchContact();
                break;

            case 4:
                updateContact();
                break;

            case 5:
                deleteContact();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }


    return 0;
}





void addContact() {

    struct Contact c;
    FILE *fp;


    fp=fopen("contact.dat","ab");


    printf("\nEnter Name: ");
    scanf("%s",c.name);


    printf("Enter Phone Number: ");
    scanf("%s",c.phone);


    printf("Enter Email: ");
    scanf("%s",c.email);



    fwrite(&c,sizeof(c),1,fp);


    fclose(fp);


    printf("Contact added successfully!\n");
}






void displayContacts() {

    struct Contact c;

    FILE *fp;


    fp=fopen("contact.dat","rb");


    if(fp==NULL) {

        printf("No contacts found!\n");
        return;
    }



    printf("\nName\tPhone\tEmail\n");


    while(fread(&c,sizeof(c),1,fp)) {


        printf("%s\t%s\t%s\n",
        c.name,
        c.phone,
        c.email);

    }


    fclose(fp);
}







void searchContact() {

    struct Contact c;

    FILE *fp;


    char name[50];

    int found=0;



    fp=fopen("contact.dat","rb");


    printf("\nEnter name to search: ");
    scanf("%s",name);



    while(fread(&c,sizeof(c),1,fp)) {


        if(strcmp(c.name,name)==0) {


            printf("\nContact Found\n");

            printf("Name: %s\n",c.name);

            printf("Phone: %s\n",c.phone);

            printf("Email: %s\n",c.email);


            found=1;
            break;
        }
    }


    fclose(fp);



    if(!found)

        printf("Contact not found!\n");
}








void updateContact() {

    struct Contact c;

    FILE *fp;


    char name[50];

    int found=0;



    fp=fopen("contact.dat","rb+");


    printf("\nEnter name to update: ");
    scanf("%s",name);



    while(fread(&c,sizeof(c),1,fp)) {


        if(strcmp(c.name,name)==0) {


            printf("Enter new phone: ");
            scanf("%s",c.phone);


            printf("Enter new email: ");
            scanf("%s",c.email);



            fseek(fp,-sizeof(c),SEEK_CUR);


            fwrite(&c,sizeof(c),1,fp);



            found=1;
            break;
        }
    }



    fclose(fp);



    if(found)

        printf("Contact updated successfully!\n");

    else

        printf("Contact not found!\n");
}








void deleteContact() {

    struct Contact c;


    FILE *fp,*temp;


    char name[50];

    int found=0;



    fp=fopen("contact.dat","rb");

    temp=fopen("temp.dat","wb");



    printf("\nEnter name to delete: ");
    scanf("%s",name);



    while(fread(&c,sizeof(c),1,fp)) {


        if(strcmp(c.name,name)!=0) {


            fwrite(&c,sizeof(c),1,temp);

        }

        else {

            found=1;
        }
    }



    fclose(fp);

    fclose(temp);



    remove("contact.dat");

    rename("temp.dat","contact.dat");



    if(found)

        printf("Contact deleted successfully!\n");

    else

        printf("Contact not found!\n");
}