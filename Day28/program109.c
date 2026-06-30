#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Library {

    int bookId;
    char bookName[50];
    char author[50];
    int issued;   // 0 = available, 1 = issued
};


void addBook();
void displayBooks();
void searchBook();
void issueBook();
void deleteBook();


int main() {

    int choice;

    while(1) {

        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Delete Book\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);


        switch(choice) {

            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                deleteBook();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}



void addBook() {

    struct Library l;
    FILE *fp;


    fp=fopen("library.dat","ab");


    printf("\nEnter Book ID: ");
    scanf("%d",&l.bookId);


    printf("Enter Book Name: ");
    scanf("%s",l.bookName);


    printf("Enter Author Name: ");
    scanf("%s",l.author);


    l.issued=0;


    fwrite(&l,sizeof(l),1,fp);


    fclose(fp);


    printf("Book added successfully!\n");
}





void displayBooks() {

    struct Library l;

    FILE *fp;


    fp=fopen("library.dat","rb");


    if(fp==NULL) {

        printf("No books found!\n");
        return;
    }



    printf("\nID\tBook\tAuthor\tStatus\n");


    while(fread(&l,sizeof(l),1,fp)) {


        printf("%d\t%s\t%s\t%s\n",
        l.bookId,
        l.bookName,
        l.author,
        l.issued ? "Issued" : "Available");

    }


    fclose(fp);
}





void searchBook() {

    struct Library l;

    FILE *fp;

    int id;
    int found=0;


    fp=fopen("library.dat","rb");


    printf("\nEnter Book ID: ");
    scanf("%d",&id);



    while(fread(&l,sizeof(l),1,fp)) {


        if(l.bookId==id) {


            printf("\nBook Found\n");

            printf("Book ID: %d\n",l.bookId);

            printf("Book Name: %s\n",l.bookName);

            printf("Author: %s\n",l.author);

            printf("Status: %s\n",
            l.issued ? "Issued" : "Available");


            found=1;
            break;
        }
    }


    fclose(fp);



    if(!found)

        printf("Book not found!\n");
}





void issueBook() {

    struct Library l;

    FILE *fp;


    int id;
    int found=0;


    fp=fopen("library.dat","rb+");


    printf("\nEnter Book ID to issue: ");
    scanf("%d",&id);



    while(fread(&l,sizeof(l),1,fp)) {


        if(l.bookId==id) {


            if(l.issued==0) {


                l.issued=1;


                fseek(fp,-sizeof(l),SEEK_CUR);


                fwrite(&l,sizeof(l),1,fp);


                printf("Book issued successfully!\n");

            }

            else {

                printf("Book already issued!\n");
            }


            found=1;
            break;
        }
    }


    fclose(fp);



    if(!found)

        printf("Book not found!\n");
}






void deleteBook() {


    struct Library l;


    FILE *fp,*temp;


    int id;
    int found=0;



    fp=fopen("library.dat","rb");

    temp=fopen("temp.dat","wb");



    printf("\nEnter Book ID to delete: ");
    scanf("%d",&id);



    while(fread(&l,sizeof(l),1,fp)) {


        if(l.bookId!=id)

            fwrite(&l,sizeof(l),1,temp);

        else

            found=1;
    }



    fclose(fp);

    fclose(temp);



    remove("library.dat");

    rename("temp.dat","library.dat");



    if(found)

        printf("Book deleted successfully!\n");

    else

        printf("Book not found!\n");
}