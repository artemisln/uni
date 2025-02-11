#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char temp;
    char prev = '\0';
    while((temp = getchar())!=EOF){
        if(isalnum(prev)&&isalnum(temp)){
            printf("*%c", temp);
        } else {
            printf("%c", temp);
        }
        prev = temp;
    }
}