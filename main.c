#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "variable.h"

char c[10000];
char * get_random(){
    return c;
}
int main(){

    char dec_message[10000];
    FILE *fptr;

    if ((fptr = fopen("test.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }

    // reads text until newline
    fscanf(fptr,"%[^\n]", c);

    //strcpy(dec_message,c);
    //printf("Data from the file:\n%s", dec_message);
    fclose(fptr);

    read_decrypted_message();
    crypt_message();
    print_crypted_message();
    read_crypted_message();
    decrypt_message();
    print_decrypted_message();
    printf("\n");
}
