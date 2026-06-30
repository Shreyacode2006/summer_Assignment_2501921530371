#include <stdio.h>

#define MAX 100

int arr[MAX];
int n = 0;


void insert();
void display();
void search();
void update();
void delete();
void sort();


int main() {

    int choice;


    while(1) {

        printf("\n===== Array Operations System =====\n");
        printf("1. Insert Element\n");
        printf("2. Display Array\n");
        printf("3. Search Element\n");
        printf("4. Update Element\n");
        printf("5. Delete Element\n");
        printf("6. Sort Array\n");
        printf("7. Exit\n");


        printf("Enter choice: ");
        scanf("%d",&choice);



        switch(choice) {

            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                update();
                break;

            case 5:
                delete();
                break;

            case 6:
                sort();
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}





void insert() {

    int value;


    if(n == MAX) {

        printf("Array is full!\n");
        return;
    }


    printf("Enter element: ");
    scanf("%d",&value);


    arr[n] = value;
    n++;


    printf("Element inserted successfully!\n");
}






void display() {

    int i;


    if(n == 0) {

        printf("Array is empty!\n");
        return;
    }


    printf("Array elements are:\n");


    for(i=0;i<n;i++) {

        printf("%d ",arr[i]);
    }


    printf("\n");
}







void search() {

    int value,i;
    int found=0;


    printf("Enter element to search: ");
    scanf("%d",&value);



    for(i=0;i<n;i++) {


        if(arr[i]==value) {

            printf("Element found at position %d\n",i+1);
            found=1;
            break;
        }
    }



    if(!found)

        printf("Element not found!\n");
}








void update() {

    int pos,value;


    printf("Enter position to update: ");
    scanf("%d",&pos);



    if(pos<1 || pos>n) {

        printf("Invalid position!\n");
        return;
    }


    printf("Enter new value: ");
    scanf("%d",&value);


    arr[pos-1]=value;


    printf("Element updated successfully!\n");
}








void delete() {

    int pos,i;


    printf("Enter position to delete: ");
    scanf("%d",&pos);



    if(pos<1 || pos>n) {

        printf("Invalid position!\n");
        return;
    }



    for(i=pos-1;i<n-1;i++) {

        arr[i]=arr[i+1];
    }


    n--;


    printf("Element deleted successfully!\n");
}








void sort() {

    int i,j,temp;


    for(i=0;i<n;i++) {

        for(j=i+1;j<n;j++) {


            if(arr[i]>arr[j]) {


                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }


    printf("Array sorted successfully!\n");
}