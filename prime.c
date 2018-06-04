#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isprime(int number){
    if(number==0)
        return 0;
    int iterator=2;
    while(iterator<=number-1){
        if(number%iterator==0)
            return 0;
        iterator++;
    }
    return 1;
}
