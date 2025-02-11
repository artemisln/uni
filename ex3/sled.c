#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc<4) return 1;
    int storage = atoi(argv[1]);
    int items = argc-2;
    int found = 0;
    int a, b, c;
    for(int i=0; i<items; i++){
        a = atoi(argv[i+1]);
        for(int j=i+1; j<items; j++){
            b = atoi(argv[j+1]);
            for(int k=j+1; k<items+1; k++){
                c = atoi(argv[k+1]);
                if(a+b+c==storage){
                    printf("You can take 3 objects: %d + %d + %d = %d\n", a, b, c, storage);
                    found = 1;
                }
            }
        }
    }
    if(!found) printf("No 3 objects found to fill up your sled.\n");
}