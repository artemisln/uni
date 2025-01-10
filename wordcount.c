/*
Γράψτε ένα πρόγραμμα wordcount το οποίο διαβάζει ένα κείμενο από την πρότυπη είσοδο
(stdin) και τυπώνει στην πρότυπη έξοδο (stdout) τον αριθμό των λέξεων που διάβασε 
καθώς και το μέσο μήκος λέξης του κειμένου με ακρίβεια δύο δεκαδικών ψηφίων. 
Ως λέξη, ορίζουμε οποιαδήποτε ακολουθία συνεχόμενων χαρακτήρων A-Z, a-z και 0-9 
(μετράμε μόνο λέξεις με λατινικούς χαρακτήρες) και ως μήκος τον αριθμό των 
συνεχόμενων χαρακτήρων. Για παράδειγμα, το κείμενο "I'm a good person" έχει 
σύνολο 5 λέξεις και μέσο μήκος (1 + 1 + 1 + 4 + 6)/5 = 2.6 χαρακτήρες.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
    // Read text from stdin
    char* input_text;
    size_t bufsize = 32;
    input_text = (char *)malloc(bufsize * sizeof(char));
    printf("Type what you want\n");
    getline(&input_text, &bufsize, stdin);

    // previous stores whether the previous character read was an alphanumeric or not
    int index, sum_of_characters, word_count, previous = 0;

    while(input_text[index]!='\0'){
        if(isalnum(input_text[index])!=0){
            sum_of_characters++;
            if(previous==0){
                word_count++;
                previous=1;
            }
        } else {
            previous=0;
        }
        index++;
    }
    double average = 1.0*sum_of_characters/word_count;
    printf("Total words: %d \nAverage word length: %.2f \n", word_count, average);
    return 0;
}
