#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "functions.h"
#include "variable.h"

char crypted_message_2[900000];
char crp_message_copy[9000];
char decrypted_message_2[10000];

int count[9000];

void read_crypted_message(){

    strcpy(crypted_message_2,c);
}

void decrypt_message(){
    int iterator_1;
    int iterator_2=0;
    int x;
    int p;

    p=strlen(crypted_message_2);
    x=crypted_message_2[0];

    for(iterator_1=0;iterator_1<=256;iterator_1++)
        count[iterator_1]=1;

    for(iterator_1=0;iterator_1<=p-2;iterator_1++){

        if(crypted_message_2[iterator_1]==crypted_message_2[iterator_1+1]){
            x=crypted_message_2[iterator_1];
            count[x]++;
        }

        if((crypted_message_2[iterator_1]!=crypted_message_2[iterator_1+1])&&(isprime(count[x]))){

            decrypted_message_2[iterator_2]=crypted_message_2[iterator_1];
            decrypted_message_2[iterator_2+1]='\0';
            iterator_2++;
            count[x]=1;

        }
        else
            if((!isprime(count[x]))&&(crypted_message_2[iterator_1]!=crypted_message_2[iterator_1+1])){
                count[x]=1;
            }

    }

    strcpy(crp_message_copy,crypted_message_2);
    strrev(crp_message_copy);
    x=crp_message_copy[0];
    count[x]=1;
    iterator_1=0;
    if(crp_message_copy[iterator_1]!=crp_message_copy[iterator_1+1]){
        decrypted_message_2[iterator_2]=crp_message_copy[0];
        iterator_2++;
        decrypted_message_2[iterator_2]='\0';

    }
    else{
    while(crp_message_copy[iterator_1]==crp_message_copy[iterator_1+1]){
        count[x]++;
        iterator_1++;
   }

    if(isprime(count[x])){
        decrypted_message_2[iterator_2]=crp_message_copy[0];
        iterator_2++;
    }
    decrypted_message_2[iterator_2]='\0';}
}

void print_decrypted_message(){
    if(decrypted_message_2[0]!='\0'){
        printf("\nThe decrypted message is: \n");
        printf("%s",decrypted_message_2);
    }
    else
    {
        printf("\nYou have no message! Try again.");
    }
}
