#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {

    int id;
    char name[50];
    char author[50];
    int issued;
};


struct Book books[MAX];

int count = 0;


void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();



int main() {

    int choice;


    while(1) {

        printf("\n===== Mini Library System =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
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
                returnBook();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

}






void addBook() {


    if(count == MAX) {

        printf("Library is full!\n");
        return;
    }


    printf("\nEnter Book ID: ");
    scanf("%d",&books[count].id);


    printf("Enter Book Name: ");
    scanf("%s",books[count].name);


    printf("Enter Author Name: ");
    scanf("%s",books[count].author);


    books[count].issued = 0;


    count++;


    printf("Book added successfully!\n");

}








void displayBooks() {


    int i;


    if(count == 0) {

        printf("No books available!\n");
        return;
    }



    printf("\nID\tName\tAuthor\tStatus\n");



    for(i=0;i<count;i++) {


        printf("%d\t%s\t%s\t%s\n",
        books[i].id,
        books[i].name,
        books[i].author,
        books[i].issued ? "Issued" : "Available");

    }

}








void searchBook() {


    int id,i;
    int found=0;



    printf("\nEnter Book ID: ");
    scanf("%d",&id);



    for(i=0;i<count;i++) {


        if(books[i].id == id) {


            printf("\nBook Found\n");

            printf("Book ID: %d\n",books[i].id);

            printf("Name: %s\n",books[i].name);

            printf("Author: %s\n",books[i].author);

            printf("Status: %s\n",
            books[i].issued ? "Issued" : "Available");


            found=1;
            break;
        }
    }



    if(!found)

        printf("Book not found!\n");

}








void issueBook() {


    int id,i;
    int found=0;



    printf("\nEnter Book ID to issue: ");
    scanf("%d",&id);



    for(i=0;i<count;i++) {


        if(books[i].id == id) {


            if(books[i].issued == 0) {


                books[i].issued = 1;

                printf("Book issued successfully!\n");

            }

            else {

                printf("Book already issued!\n");

            }


            found=1;
            break;
        }
    }



    if(!found)

        printf("Book not found!\n");

}








void returnBook() {


    int id,i;
    int found=0;



    printf("\nEnter Book ID to return: ");
    scanf("%d",&id);



    for(i=0;i<count;i++) {


        if(books[i].id == id) {


            if(books[i].issued == 1) {


                books[i].issued = 0;

                printf("Book returned successfully!\n");

            }

            else {

                printf("Book is already available!\n");

            }


            found=1;
            break;
        }
    }



    if(!found)

        printf("Book not found!\n");

}