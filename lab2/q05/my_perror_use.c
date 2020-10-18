/* my_perror_use.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void my_perror(const char *s){
    if (s == NULL){
        printf("%s\n",strerror(errno));
    }
    else{
        printf("%s : %s\n",s,strerror(errno));
    }
}
main (int argc, char *argv[]){

    FILE *f;

    if(argv < 2){
        printf("Usage : my_perror_use_file_name\n");
        exit(1);
    }

    if((f=fopen(argv[1],"r")) == NULL){
        my_perror("fopen");
        exit(1);
    }
    
    printf("Open a file \"%s\".\n",argv[1]);

    fclose(f);
}
