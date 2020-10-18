/* main.c */

#include <stdio.h>
#include "./lib/q01.h"

int main(){

    void *handle;
    int (*add)(int,int), (*subtract)(int,int), (*multiply)(int,int),(*divide)(int,int);
    char *error;
    handle = dlopen ("./lib/")
    printf("add(10,5) = %d\n",add(10,5));
    printf("subtract(10,5) = %d\n",subtract(10,5));
    printf("multiply(10,5) = %d\n",multiply(10,5));
    printf("divide(10,5) = %d\n",divide(10,5));    
}
