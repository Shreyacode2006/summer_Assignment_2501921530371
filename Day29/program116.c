#include <stdio.h>
#include <stdlib.h>

struct Inventory {

    int id;
    char name[50];
    int quantity;
    float price;
};


void addProduct();
void displayProducts();
void searchProduct();
void updateProduct();
void deleteProduct();


int main() {

    int choice;


    while(1) {

        printf("\n===== Inventory Management System =====\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Exit\n");


        printf("Enter choice: ");
        scanf("%d",&choice);



        switch(choice) {

            case 1:
                addProduct();
                break;

            case 2:
                displayProducts();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                updateProduct();
                break;

            case 5:
                deleteProduct();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }


    return 0;
}





void addProduct() {

    struct Inventory p;
    FILE *fp;


    fp=fopen("inventory.dat","ab");


    printf("\nEnter Product ID: ");
    scanf("%d",&p.id);


    printf("Enter Product Name: ");
    scanf("%s",p.name);


    printf("Enter Quantity: ");
    scanf("%d",&p.quantity);


    printf("Enter Price: ");
    scanf("%f",&p.price);



    fwrite(&p,sizeof(p),1,fp);


    fclose(fp);


    printf("Product added successfully!\n");
}






void displayProducts() {

    struct Inventory p;

    FILE *fp;


    fp=fopen("inventory.dat","rb");


    if(fp==NULL) {

        printf("No products found!\n");
        return;
    }



    printf("\nID\tName\tQuantity\tPrice\n");


    while(fread(&p,sizeof(p),1,fp)) {


        printf("%d\t%s\t%d\t\t%.2f\n",
        p.id,
        p.name,
        p.quantity,
        p.price);

    }


    fclose(fp);
}








void searchProduct() {

    struct Inventory p;

    FILE *fp;


    int id;
    int found=0;


    fp=fopen("inventory.dat","rb");


    printf("\nEnter Product ID: ");
    scanf("%d",&id);



    while(fread(&p,sizeof(p),1,fp)) {


        if(p.id==id) {


            printf("\nProduct Found\n");

            printf("ID: %d\n",p.id);

            printf("Name: %s\n",p.name);

            printf("Quantity: %d\n",p.quantity);

            printf("Price: %.2f\n",p.price);


            found=1;
            break;
        }
    }


    fclose(fp);



    if(!found)

        printf("Product not found!\n");
}








void updateProduct() {

    struct Inventory p;

    FILE *fp;


    int id;
    int found=0;



    fp=fopen("inventory.dat","rb+");


    printf("\nEnter Product ID to update: ");
    scanf("%d",&id);



    while(fread(&p,sizeof(p),1,fp)) {


        if(p.id==id) {


            printf("Enter new quantity: ");
            scanf("%d",&p.quantity);



            printf("Enter new price: ");
            scanf("%f",&p.price);



            fseek(fp,-sizeof(p),SEEK_CUR);


            fwrite(&p,sizeof(p),1,fp);



            found=1;
            break;
        }
    }



    fclose(fp);



    if(found)

        printf("Product updated successfully!\n");

    else

        printf("Product not found!\n");
}









void deleteProduct() {


    struct Inventory p;


    FILE *fp,*temp;


    int id;
    int found=0;



    fp=fopen("inventory.dat","rb");

    temp=fopen("temp.dat","wb");



    printf("\nEnter Product ID to delete: ");
    scanf("%d",&id);



    while(fread(&p,sizeof(p),1,fp)) {


        if(p.id!=id) {


            fwrite(&p,sizeof(p),1,temp);

        }

        else {

            found=1;
        }
    }



    fclose(fp);

    fclose(temp);



    remove("inventory.dat");

    rename("temp.dat","inventory.dat");



    if(found)

        printf("Product deleted successfully!\n");

    else

        printf("Product not found!\n");
}