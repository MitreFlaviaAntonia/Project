#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "functions.h"
#include "variable.h"

char crypted_message_2[900000];
char crp_message_copy[900000];
char decrypted_message_2[100000];

int count[9000];

void read_crypted_message(){

    strcpy(crypted_message_2,c);

}

void decrypt_message(){
    int iterator_1;
    int decrypted_message_2_length=0;
    char letter;
    char letter_code;
    int crypted_message_2_length;

    crypted_message_2_length=strlen(crypted_message_2);
    letter=crypted_message_2[0];

    for(iterator_1=0;iterator_1<=256;iterator_1++)
        count[iterator_1]=1; //any letter that is used in the program occurs
                            //at least once

    for(iterator_1=0;iterator_1<=crypted_message_2_length-2;iterator_1++){

        if(crypted_message_2[iterator_1]==crypted_message_2[iterator_1+1]){
            letter=crypted_message_2[iterator_1];
            letter_code=letter;
            letter_code=(int)letter_code;
            count[letter_code]++;
        }

        if((crypted_message_2[iterator_1]!=crypted_message_2[iterator_1+1])&&isprime(count[letter_code])){

            decrypted_message_2[decrypted_message_2_length]=crypted_message_2[iterator_1];
            decrypted_message_2[decrypted_message_2_length+1]='\0'; //to make sure the string has an end anytime
            decrypted_message_2_length++;
            count[letter_code]=1;

        }
        else
            if((crypted_message_2[iterator_1]!=crypted_message_2[iterator_1+1])&&!isprime(count[letter_code])){
                count[letter_code]=1;
            }

    }

    strcpy(crp_message_copy,crypted_message_2);
    strrev(crp_message_copy);
    letter=crp_message_copy[0];
    letter_code=letter;
    letter_code=(int)letter_code;
    count[letter_code]=1;
    iterator_1=0;
    if(crp_message_copy[iterator_1]!=crp_message_copy[iterator_1+1]){
        decrypted_message_2[decrypted_message_2_length]=crp_message_copy[0];
        decrypted_message_2_length++;
        decrypted_message_2[decrypted_message_2_length]='\0';

    }
    else{
    while(crp_message_copy[iterator_1]==crp_message_copy[iterator_1+1]){
        count[letter]++;
        iterator_1++;
   }

    if(isprime(count[letter])){
        decrypted_message_2[decrypted_message_2_length]=crp_message_copy[0];
        decrypted_message_2_length++;
    }
    decrypted_message_2[decrypted_message_2_length]='\0';}
}

void print_decrypted_message(){
    if(decrypted_message_2[0]!='\0'){
        printf("\n\n    The decrypted message is: \n\n");
        printf("    %s\n",decrypted_message_2);
    }
    else
    {
        printf("\n      You have no message! Try again.\n");
    }
}
