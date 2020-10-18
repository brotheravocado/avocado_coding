/* main.c */
#include <stdio.h>
#include <dlfcn.h>
#include "./lib/q01.h"

int main(){
    void *handle;
    int (*add)(int,int), (*subtract)(int,int), (*multiply)(int,int), (*divide)(int,int);
    char *error;

    handle = dlopen("./lib/libdl.so", RTLD_LAZY);
    if (!handle){
        fputs (dlerror(),stderr);
        exit(1);
    }
        add = dlsym(handle, "add");
        if ((error = dlerror()) != NULL){
            fprintf (stderr, "%s", error);
            exit(1);
        }
        subtract = dlsym(handle, "subtract");
        if ((error = dlerror()) != NULL){
            fprintf (stderr, "%s", error);
            exit(1);
        }
        multiply = dlsym(handle, "multiply");
        if ((error = dlerror()) != NULL){
            fprintf (stderr, "%s", error);
            exit(1);
        }
        divide = dlsym(handle, "divide");
        if ((error = dlerror()) != NULL){
            fprintf (stderr, "%s", error);
            exit(1);
        }
    printf("add(10,5) = %d\n",add(10,5));
    printf("subtract(10,5) = %d\n",subtract(10,5));
    printf("multiply(10,5) = %d\n",multiply(10,5));
    printf("divide(10,5) = %d\n",divide(10,5));    
    dlclose(handle);
}
