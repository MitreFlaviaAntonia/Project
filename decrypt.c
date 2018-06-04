#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "functions.h"
#include "variable.h"

char crp_message[9000];
char crp_message2[9000];
char dec_message[9000];
char crp_message_x[9000];
char crp_message_x2[10000];
int count[9000];

void read_crypted_message(){

    strcpy(crp_message,c);
}

void decrypt_message(){
    int i;
    int j=0;
    int x;
    int p;

    p=strlen(crp_message);
    x=crp_message[0];

    for(i=0;i<=256;i++)
        count[i]=1;

    for(i=0;i<=p-2;i++){

        if(crp_message[i]==crp_message[i+1]){
            x=crp_message[i];
            count[x]++;
        }

        if((crp_message[i]!=crp_message[i+1])&&(isprime(count[x]))){

            dec_message[j]=crp_message[i];
            dec_message[j+1]='\0';
            j++;
            count[x]=1;

        }
        else
            if((!isprime(count[x]))&&(crp_message[i]!=crp_message[i+1])){
                count[x]=1;
            }

    }

    strcpy(crp_message2,crp_message);
    strrev(crp_message2);
    x=crp_message2[0];
    count[x]=1;
    i=0;
    if(crp_message2[i]!=crp_message2[i+1]){
        dec_message[j]=crp_message2[0];
        j++;
        dec_message[j]='\0';

    }
    else{
    while(crp_message2[i]==crp_message2[i+1]){
        count[x]++;
        i++;
   }

    if(isprime(count[x])){
        dec_message[j]=crp_message2[0];
        j++;
    }
    dec_message[j]='\0';}
}

void print_decrypted_message(){
    if(dec_message[0]!='\0'){
        printf("\nThe decrypted message is: \n");
        printf("%s",dec_message);
    }
    else
    {
        printf("\nYou have no message! Try again.");
    }
}
