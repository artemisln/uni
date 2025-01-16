/*
Γράψτε ένα πρόγραμμα που διαβάζει το κείμενο που δίνεται από την πρότυπη 
είσοδο (stdin) και τυπώνει την κάθε λέξη χαρακτήρα στην πρότυπη έξοδο 
(stdout) με το πρόθεμα “pika”. Οι λέξεις χωρίζονται με κενούς (whitespace) 
χαρακτήρες. Αριθμοί ή σημεία στίξης δεν θεωρούνται λέξεις.
*/

#include <stdio.h>
#include <ctype.h>

int main(){
    int temp = getchar();
    int prev = 10;
    while(temp!=EOF){
        if((prev==32 || prev==10) && isalpha(temp)){
            printf(" pika%c", temp);
        } else {
            printf("%c", temp);
        }
        prev = temp;
        temp = getchar();
    }
    return 0;
}