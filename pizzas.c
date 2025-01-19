#include <stdio.h>
#include <stdlib.h>

int comp(const void* a,const void* b) {
    return *(int*)a - *(int*)b;
}

int main(){
    printf("Number of pizzas available: ");
    int pizzas;
    if(scanf("%d", &pizzas)!=1) return 1;
    if (pizzas<1) return 1;
    printf("Pizza slices\n");
    int slices, total_slices=0;
    for(int i=0; i<pizzas; i++){
        scanf("%d", &slices);
        total_slices+=slices;
    }
    int people;
    printf("How many people are there? ");
    if(scanf("%d", &people)!=1) return 1;
    printf("How many slices does each person want?\n");
    int * want = malloc(people*sizeof(int));
    for(int i=0; i<people; i++){
        printf("%d st person: ", i+1);
        scanf("%d", &want[i]);
    }
    qsort(want, people, sizeof(int), comp);
    int satisfied = 0, i=0;
    while(i<(people-1) && total_slices-want[i]>=0){
        satisfied++;
        total_slices -= want[i];
        i++;
    }
    printf("Satisfied %d\n", satisfied);
    free(want);
    return 0;
}