#include <stdio.h>
#include <stdlib.h>

struct Ticket {

    int ticketId;
    char name[50];
    char destination[50];
    int seats;
    float amount;
};


void bookTicket();
void displayTickets();
void searchTicket();
void cancelTicket();


int main() {

    int choice;


    while(1) {

        printf("\n===== Ticket Booking System =====\n");
        printf("1. Book Ticket\n");
        printf("2. Display Tickets\n");
        printf("3. Search Ticket\n");
        printf("4. Cancel Ticket\n");
        printf("5. Exit\n");


        printf("Enter choice: ");
        scanf("%d",&choice);



        switch(choice) {

            case 1:
                bookTicket();
                break;

            case 2:
                displayTickets();
                break;

            case 3:
                searchTicket();
                break;

            case 4:
                cancelTicket();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }


    return 0;
}



void bookTicket() {

    struct Ticket t;
    FILE *fp;


    fp=fopen("ticket.dat","ab");


    printf("\nEnter Ticket ID: ");
    scanf("%d",&t.ticketId);


    printf("Enter Passenger Name: ");
    scanf("%s",t.name);


    printf("Enter Destination: ");
    scanf("%s",t.destination);


    printf("Enter Number of Seats: ");
    scanf("%d",&t.seats);


    t.amount = t.seats * 500;


    fwrite(&t,sizeof(t),1,fp);


    fclose(fp);


    printf("Ticket booked successfully!\n");
    printf("Total Amount: %.2f\n",t.amount);
}





void displayTickets() {

    struct Ticket t;

    FILE *fp;


    fp=fopen("ticket.dat","rb");


    if(fp==NULL) {

        printf("No tickets found!\n");
        return;
    }



    printf("\nID\tName\tDestination\tSeats\tAmount\n");


    while(fread(&t,sizeof(t),1,fp)) {


        printf("%d\t%s\t%s\t\t%d\t%.2f\n",
        t.ticketId,
        t.name,
        t.destination,
        t.seats,
        t.amount);

    }


    fclose(fp);
}






void searchTicket() {

    struct Ticket t;

    FILE *fp;


    int id;
    int found=0;


    fp=fopen("ticket.dat","rb");


    printf("\nEnter Ticket ID: ");
    scanf("%d",&id);



    while(fread(&t,sizeof(t),1,fp)) {


        if(t.ticketId==id) {


            printf("\nTicket Found\n");

            printf("Ticket ID: %d\n",t.ticketId);

            printf("Passenger Name: %s\n",t.name);

            printf("Destination: %s\n",t.destination);

            printf("Seats: %d\n",t.seats);

            printf("Amount: %.2f\n",t.amount);


            found=1;
            break;
        }
    }


    fclose(fp);



    if(!found)

        printf("Ticket not found!\n");
}







void cancelTicket() {

    struct Ticket t;

    FILE *fp,*temp;


    int id;
    int found=0;



    fp=fopen("ticket.dat","rb");

    temp=fopen("temp.dat","wb");



    printf("\nEnter Ticket ID to cancel: ");
    scanf("%d",&id);



    while(fread(&t,sizeof(t),1,fp)) {


        if(t.ticketId!=id) {

            fwrite(&t,sizeof(t),1,temp);
        }

        else {

            found=1;
        }
    }



    fclose(fp);

    fclose(temp);



    remove("ticket.dat");

    rename("temp.dat","ticket.dat");



    if(found)

        printf("Ticket cancelled successfully!\n");

    else

        printf("Ticket not found!\n");
}