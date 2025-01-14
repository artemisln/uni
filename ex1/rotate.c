#include <stdio.h>
#include <stdlib.h>
static int rows, cols;
int main(int argc, char *argv[]){
    if(argc!=2){
        return 1;
    }
    FILE * f = fopen(argv[1], "r");
    fscanf(f, "%d %d", &rows, &cols);
    int matrix[rows][cols];
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            fscanf(f, "%d", &matrix[i][j]);
        }
    }
    for(int j=cols-1; j>=0; j--){
        for(int i=0; i<rows; i++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}