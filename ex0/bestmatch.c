/*
Γράψτε ένα πρόγραμμα που διαβάζει ένα σύνολο από ονόματα ακολουθούμενα 
από έναν αριθμό που δηλώνει πόσο καλά μας ταιριάζει αυτό το άτομο και 
τυπώνει τα ονόματα από το μεγαλύτερο στο μικρότερο ταξινομημένα. 
Τα δεδομένα περιέχονται σε αρχείο που δίνεται ως πρώτο όρισμα. 
Το αρχείο θα περιέχει κάθε όνομα σε μια γραμμή της μορφής “όνομα,σκορ”.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_lists(char ** names, int * scores, FILE * f);
void sort_lists(char **names, int * scores);

static int n;

int main(int argc, char *argv[]){
    if(argc!=2){
        return 1;
    }
    FILE * f = fopen(argv[1], "r");
    if(f==NULL){
        return 1;
    }
    char ** names = malloc(100*sizeof(char*));
    for(int i = 0; i < 100; i++) {
        names[i] = malloc(100 * sizeof(char)); // Allocate memory for each string
    }
    int * scores = malloc(100*sizeof(int));
    create_lists(names, scores, f);
    sort_lists(names, scores);
    for(int i=0; i<n; i++){
        printf("%s,%d\n", names[i], scores[i]);
    }

    for(int i = 0; i < 100; i++) {
        free(names[i]); // Free each string
    }
    free(names);
    free(scores);
    return 0;
}

void create_lists(char ** names, int * scores, FILE * f){
    char line[100];
    int index = 0;
    while(fgets(line, sizeof(line), f) != NULL){
        sscanf(line, "%[^,],%d", names[index], &scores[index]);
        index++;
    }
    n = index;
}

void sort_lists(char **names, int * scores){
    int temp;
    char tempc[100];
    for(int i=n-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(scores[j]<scores[j+1]){
                temp = scores[j];
                scores[j] = scores[j+1];
                scores[j+1]=temp;
                strcpy(tempc, names[j]);
                strcpy(names[j], names[j+1]);
                strcpy(names[j+1], tempc);
            }
        }
    }
}