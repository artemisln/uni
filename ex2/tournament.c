/*
Γράψτε ένα πρόγραμμα που δέχεται ως ορίσματα όλα τα 
pokémon που διαγωνίζονται στο τουρνουά και στην συνέχεια 
τυπώνει στην πρότυπη έξοδο όλους τους αγώνες που θα 
γίνουν. Κάθε pokémon πρέπει να παίξει με κάθε άλλο ακριβώς δύο φορές.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc==1){
        return 1;
    }
    for(int i=1; i<argc; i++){
        for(int j=1; j<argc; j++){
            if(i!=j){
                printf("%s vs %s\n", argv[i], argv[j]);
            }
        }
    }
    return 0;
}