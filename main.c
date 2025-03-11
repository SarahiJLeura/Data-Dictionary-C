#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Resources.h"
#include "Entity.h"
#include "Attribute.h"

FILE* createFile(char* name);
FILE* openFile(char* name);

int displayMainMenu();
int displayOptionsMenu();

int main(int argc, char *argv[]) {
    FILE *file;
    char fileName[MAX], entityName[MAX];
    int op1, op2, attrType, blockSize=0, dataNumber;

    printf("HOLA mundo\n");


    do{
        op1= displayMainMenu();
        switch (op1)
        {
            case 1:
                printf("Enter a name for the file. Ex.: <students.bin>\n");
                scanf("\n %[^\n]", fileName);
                file=createFile(fileName);
                if(file){
                    //fclose(file);
                    //file= openFile(fileName);
                    printf("--The file was created successfully--\n");
                }else{
                    printf("--An error occurred--\n");
                }
                break;
            case 2:
                printf("Enter the name file. Ex.: <students.bin>\n");
                scanf("\n %[^\n]", fileName);
                file=openFile(fileName);
                if(file){
                    printf("--The file was opened successfully--\n");
                }else{
                    printf("--An error occurred--\n");
                }
                break;
            default:
                printf("Come back soon!\n");
                break;
        }

        if (op1 != 3 && file != NULL){
            do{
                op2 = displayOptionsMenu();
                switch (op2)
                {
                    case 1:
                        /* code */
                        break;
                    case 2:
                        /* code */
                        break;
                    case 3:
                        /* code */
                        break;
                    case 4:
                        /* code */
                        break;
                    default:
                        printf("Returning to main menu...\n");
                        break;
                }
            }while(op2 != 5);
        }


    }while(op1 != 3);

    fclose(file);
    return 0;
}

FILE* createFile(char nombre[])
{
    FILE *f;
    long cab = 0;
    f = fopen(nombre, "ab");
    if (f == NULL) return NULL;
    fwrite(&cab, sizeof(long), 1, f);
    return f;
}

FILE* openFile(char nombre[])
{
    FILE *f;
    f=fopen(nombre,"rb+");
    return f;
}

int displayMainMenu(){
    int op;
    do{
        printf("--MAIN MENU--\n");
        printf("Select the option you want to perform:\n");
        printf("1. Create a new file\n");
        printf("2. Open existing file\n");
        printf("3. Exit\n");
        if (scanf("%d", &op) != 1) {
            while (getchar() != '\n');
            printf("-- Invalid input, please enter a number between 1 and 3 --\n");
            op = 0;
        }

        if (op > 3 || op < 1) {
            printf("-- Invalid option, please select a number between 1 and 3 --\n");
        }
    }while(op>3 || op<1);
    return op;
}

int displayOptionsMenu(){
    int op;
    do{
        printf("\n--OPTIONS MENU--\n");
        printf("Select the option you want to perform:\n");
        printf("1. Save\n");
        printf("2. Delete\n");
        printf("3. Datos\n");
        printf("4. Print\n");
        printf("5. Back\n");
        scanf("%d",&op);
        if (scanf("%d", &op) != 1) {
            while (getchar() != '\n');
            printf("-- Invalid input, please enter a number between 1 and 5 --\n");
            op = 0;
        }

        if (op > 5 || op < 1) {
            printf("-- Invalid option, please select a number between 1 and 5 --\n");
        }
    }while(op>5 || op<1);
    return op;
}