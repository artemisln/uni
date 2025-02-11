#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc!=3) return 1;
    FILE *f = fopen(argv[1], "r");
    if(f==NULL) return 1;

    int wordsize = strlen(argv[2]);
    char * word = malloc(wordsize+1);
    strcpy(word, argv[2]);

    char line[1024];
    while(fgets(line, sizeof(line), f)){
        char *pos = line;
        char *start = line;
        int found = 0;
        while((pos = strstr(pos, word))){
            found = 1;
            // print whatever is in the line, before the word
            printf("%.*s", (int)(pos-line), line);
            // print the word, bold
            printf("\033[1m%s\033[0m", word);
            pos += wordsize;
            start = pos;
        }
        if(found){
            // print the rest of the line
            printf("%s", start);
        }
    }

    free(word);
    fclose(f);
    word = NULL;
}