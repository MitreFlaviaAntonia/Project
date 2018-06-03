#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isprime(int x){
    if(x==0)
        return 0;
    int i=2;
    while(i<=x-1){
        if(x%i==0)
            return 0;
        i++;
    }
    return 1;
}
