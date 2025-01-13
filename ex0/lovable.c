/*
Γράψτε ένα πρόγραμμα που διαβάζει ένα εύρος αριθμών από 
την κονσόλα (το εύρος είναι κλειστό, δηλαδή περιέχει τα όρια) 
και τυπώνει όλους τους αγαπήσιμους (lovable) αριθμούς. 
Ένας αριθμός είναι lovable αν είναι τέλειος κύβος (δηλαδή ένας 
άλλος ακέραιος υψωμένος στην 3η δύναμη) και ταυτόχρονα 
παλινδρομικός (δηλαδή διαβάζεται το ίδιο από αριστερά προς 
τα δεξιά και από δεξιά προς τα αριστερά). 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_lovable(long long int n);

int main(int argc, char *argv[]){
    if(argc!=3){
        return 1;
    }
    for(long long int i=atoll(argv[1]); i<=atoll(argv[2]); i++){
        if(is_lovable(i)){
            printf("%lld\n", i);
        }
    }
    return 0;
}

int is_lovable(long long int n){
    char number[20];
    sprintf(number, "%lld", n);
    int length = strlen(number);
    for(int i=0; i<length/2; i++){
        if(number[i]!=number[length-i-1]){
            return 0;
        }
    }
    for(long long int i=0; i*i*i<=n; i++){
        if(i*i*i==n){
            return 1;
        }
    }
    return 0;
}