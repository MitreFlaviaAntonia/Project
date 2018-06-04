#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
#include "variable.h"

int x;
char letter;
int vector[]={1,3,5,7};
char cr_message[90000];
char decr_message[9000];
char a[10000];

void read_decrypted_message(){

    char *p;
    int i;
    p = get_random();
    for ( i = 0; i < 1000; i++ ) {
        a[i]=*(p+i);
   }

}

void crypt_message(){
    int y;
    int k;
    int i=0;
    int length=0;
    strcpy(decr_message,a);
    while(i!=strlen(decr_message)){ //parcurge tot sirul de caractere necriptate

        x=0;

        while(!((x>=65&&x<=90)||(x>=97&&x<=122))){
            x=rand() %97;
            //x is a number that does not represent the ASCII code of a letter
        }
        y=x;
        letter=(char)y;
        x=rand() %4;
        x=vector[x];
        if(x==1)
            x=3;
        for(k=0;k<=x+1;k++){
            cr_message[length++]=letter;
        }

        while((x>=65&&x<=90)||(x>=97&&x<=122)){
            x=rand() %122;
            //x is a number that does represents the ASCII code of a letter
        }



        cr_message[length++]=letter;

        x=rand() %4;
        x=vector[x];

        for(k=0;k<=x-1;k++){
            cr_message[length++]=decr_message[i];
        }

        i++;
    }
    //the program crypts the message like this: a letter we don't care about appears n times, n is not a prime number
    //and a caracter we need, from the initial string appears m times, m is a prime number
    strcpy(c,cr_message);
}

void print_crypted_message(){

    printf("The crypted message is: \n");
    printf("%s",cr_message);

}
