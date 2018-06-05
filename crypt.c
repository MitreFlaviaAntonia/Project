#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
#include "variable.h"


char crypted_message_1[90000000];
char decrypted_message_1[1000000];
char aux_string[10000000];

void read_decrypted_message(){

    char *pointer;
    int iterator;
    pointer = get_pointer_to_text();
    for ( iterator = 0; iterator < 1000000; iterator++ ) {
        aux_string[iterator]=*(pointer+iterator);
    }

}

void crypt_message(){

    int aux_1;
    int aux_2;
    char letter;
    int vector[]={1,3,5,7};
    int iterator_1=0;
    int iterator_2;
    int length=0;

    strcpy(decrypted_message_1,aux_string);

    while(iterator_1!=strlen(decrypted_message_1)){ //parcurge tot sirul de caractere necriptate

        aux_1=0;

        while(!((aux_1>=65&&aux_1<=90)||(aux_1>=97&&aux_1<=122))){
            aux_1=rand() %97;
            //x is a number that does not represent the ASCII code of a letter
        }

        aux_2=aux_1;        //The aux_1 variable keeps the code of a character
        letter=(char)aux_2; //We save the value in aux_2 and then we convert it to char
        aux_1=vector[rand() %4];    //aux_1 <= a random value from the vector[]

        if(aux_1==1)
            aux_1=3;    //if aux_1 = 1 then an unimportant "letter" occurs 2(prime) times, so we avoid that

        for(iterator_2=0; iterator_2<=aux_1+1; iterator_2++){
            crypted_message_1[length++]=letter;
        }

        while((aux_1>=65&&aux_1<=90)||(aux_1>=97&&aux_1<=122)){
            aux_1=rand() %122;
            //x is a number that does represents the ASCII code of a letter
        }

        crypted_message_1[length++]=letter;

        aux_1=rand() %4;
        aux_1=vector[aux_1];

        for(iterator_2=0;iterator_2<=aux_1-1;iterator_2++){
            crypted_message_1[length++]=decrypted_message_1[iterator_1];
        }

        iterator_1++;
    }
    //the program crypts the message like this: a letter we don't care about appears n times, n is not a prime number
    //and a caracter we need, from the initial string appears m times, m is a prime number
    strcpy(c,crypted_message_1);
}

void print_crypted_message(){

    printf("\n    The crypted message is: \n\n");
    printf("    %s",crypted_message_1);

}
