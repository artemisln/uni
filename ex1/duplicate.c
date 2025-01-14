#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ensure_unique(int i, int argc, char **argv);

int main(int argc, char *argv[]){
    int instances[argc];
    for(int i=1; i<argc; i++){
        instances[i]=1;
        for(int j=i+1; j<argc; j++){
            if (strcmp(argv[i], argv[j])==0){
                instances[i]++;
            }
        }
        if(instances[i]>1 && ensure_unique(i, argc, argv)){
            printf("dup: %s\n", argv[i]);
        }
    }
    return 0;
}

int ensure_unique(int i, int argc, char **argv){
    int first_instance = -1;
    for(int j=0; j<argc && first_instance==-1; j++){
        if(strcmp(argv[i],argv[j])==0){
            first_instance=j;
        }
    }
    if(i==first_instance) return 1;
    return 0;
}