#include <stdio.h>
#include <string.h>

void red () {
  printf("\033[1;31m");
}

void reset () {
  printf("\033[0m");
}

int main(){
    int curr= getchar();
    while(curr!=EOF){
        if(curr==10){
            red();
            printf("<3\n");
            reset();
        } else {
            printf("%c", curr);
        }
        curr = getchar();
    }
    red();
    printf("<3\n");
    reset();
    return 0;
}

// Resource https://www.reddit.com/r/cprogramming/comments/ja2z7m/text_color_for_printf_statement/