#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "variable.h"

char c[10000000];
char * get_pointer_to_text(){
    return c;
}
int main(){

    char dec_message[1000000];
    FILE *file_pointer;

    if ((file_pointer = fopen("test.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }

    // reads text until newline
    fscanf(file_pointer,"%[^\n]", c);

    //strcpy(dec_message,c);
    //printf("Data from the file:\n%s", dec_message);
    fclose(file_pointer);

    read_decrypted_message();
    crypt_message();
    print_crypted_message();
    read_crypted_message();
    decrypt_message();
    print_decrypted_message();
}
