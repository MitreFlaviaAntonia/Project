#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int x;
char litera;
int vector[]={1,3,5,7};
char cr_message[9000];
char decr_message[9000];

void read_decrypted_message(){

    printf("\nWrite something simple: ");
    gets(decr_message);

}

void crypt_message(){

    int k;
    int i=0;
    int length=0;

    while(i!=strlen(decr_message)){ //parcurge tot sirul de caractere necriptate

        x=-1;

        while(!((x>=65&&x<=90)||(x>=97&&x<=122))){
            x=rand() %122;
            //x is a number that represents the ASCII code of a letter
            //122 is the ASCII code of 'z'
        }

        litera=(char)x;
        x=rand() %4;
        x=vector[x];
        if(x==1)
            x=3;
        for(k=0;k<=x;k++){
            cr_message[length++]=litera;
        }

        while((x>=65&&x<=90)||(x>=97&&x<=122)){
            x=rand() %122;
            //x is a number that does not represents the ASCII code of a letter, it will write a random character from the ASCII code
        }



        cr_message[length++]=litera;

        x=rand() %4;
        x=vector[x];

        for(k=0;k<=x-1;k++){
            cr_message[length++]=decr_message[i];
        }

        i++;
    }
    //the program crypts the message like this: litera de numar neprim de ori, caracter random de numar neprim
    //de ori si caracter de care avem nevoie, luat din sirul nostru, de numar prim de ori
}

void print_crypted_message(){

    printf("The crypted message is: \n");
    printf("%s",cr_message);

}
