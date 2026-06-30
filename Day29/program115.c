#include <stdio.h>
#include <string.h>

void length();
void copy();
void concatenate();
void compare();
void reverse();
void palindrome();


int main() {

    int choice;


    while(1) {

        printf("\n===== String Operations System =====\n");
        printf("1. Find String Length\n");
        printf("2. Copy String\n");
        printf("3. Concatenate String\n");
        printf("4. Compare String\n");
        printf("5. Reverse String\n");
        printf("6. Check Palindrome\n");
        printf("7. Exit\n");


        printf("Enter choice: ");
        scanf("%d",&choice);



        switch(choice) {

            case 1:
                length();
                break;

            case 2:
                copy();
                break;

            case 3:
                concatenate();
                break;

            case 4:
                compare();
                break;

            case 5:
                reverse();
                break;

            case 6:
                palindrome();
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }


    return 0;
}






void length() {

    char str[100];


    printf("Enter string: ");
    scanf("%s",str);


    printf("Length = %d\n",strlen(str));
}







void copy() {

    char str1[100],str2[100];


    printf("Enter string: ");
    scanf("%s",str1);


    strcpy(str2,str1);


    printf("Copied string: %s\n",str2);
}








void concatenate() {

    char str1[100],str2[100];


    printf("Enter first string: ");
    scanf("%s",str1);


    printf("Enter second string: ");
    scanf("%s",str2);



    strcat(str1,str2);


    printf("Concatenated string: %s\n",str1);
}








void compare() {

    char str1[100],str2[100];


    printf("Enter first string: ");
    scanf("%s",str1);


    printf("Enter second string: ");
    scanf("%s",str2);



    if(strcmp(str1,str2)==0)

        printf("Strings are equal\n");

    else

        printf("Strings are not equal\n");
}








void reverse() {

    char str[100],temp;

    int i,len;



    printf("Enter string: ");
    scanf("%s",str);



    len=strlen(str);



    for(i=0;i<len/2;i++) {


        temp=str[i];

        str[i]=str[len-i-1];

        str[len-i-1]=temp;
    }



    printf("Reverse string: %s\n",str);
}








void palindrome() {

    char str[100];

    int i,len,flag=1;



    printf("Enter string: ");
    scanf("%s",str);



    len=strlen(str);



    for(i=0;i<len/2;i++) {


        if(str[i]!=str[len-i-1]) {

            flag=0;
            break;
        }
    }



    if(flag)

        printf("String is Palindrome\n");

    else

        printf("String is not Palindrome\n");
}