/*
Γράψτε ένα πρόγραμμα που για κάθε όρισμα από την γραμμή εντολών ελέγχει αν η 
συμβολοακολουθία του ορίσματος περιέχει μόνο ταιριαστές καρδιές. Οι ταιριαστές 
καρδιές ορίζονται ως εξής:

1. Μπορούν να περιέχουν μόνο χαρακτήρες ‘<’ και ‘3’.
2. Κάθε καρδιά που κλείνει (‘3’) πρέπει πρώτα να έχει ανοίξει (‘<’).
3. Όλες οι καρδιές που άνοιξαν κλείνουν.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    for(int i=1; i<argc; i++){
        int symbols=0, threes = 0, valid = 1;

        int length = strlen(argv[i]);
        char current[length];
        strcpy(current, argv[i]);

        //printf("Looking at arg[%d] with %s\n", i, current);

        for(int j=0; j<length && valid==1; j++){
            if(current[j]!='3' && current[j]!='<'){
                valid=0;
            } else if(current[j]=='3'){
                //printf("Found %c at index %d \n", current[j], j);
                threes++;
            } else {
                //printf("Found %c at index %d \n", current[j], j);
                symbols++;
            }
        }

        if(threes!=symbols){
            valid=0;
        }

       // printf("the current argument has %d < and %d 3\n", symbols, threes);

        if(valid==1){
            printf("%s: yes\n", current);
        } else {
            printf("%s: no\n", current);
        }
    }
    return 0;
}