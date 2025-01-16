/*
Γράψτε ένα πρόγραμμα που παίρνει δύο ορίσματα: 
(1) το όνομα του αρχείο που περιέχει όλα τα 
pokémon που έχουμε πιάσει με όλα τα δεδομένα τους και 
(2) την ημερομηνία που αναζητούμε και επιστρέφει 
αναλυτικές πληροφορίες για όλα τα pokémon που πιάστηκαν 
μετά από εκείνη την ημερομηνία ταξινομημένα. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *result;
    int day, month, year;
} Pokemon;

int compare(const void *a, const void *b) {
    Pokemon *p1 = (Pokemon *)a;
    Pokemon *p2 = (Pokemon *)b;
    if (p1->year != p2->year) return p1->year - p2->year;
    if (p1->month != p2->month) return p1->month - p2->month;
    return p1->day - p2->day;
}

int main(int argc, char *argv[]) {
    if (argc != 3) return 1;

    int day, month, year;
    sscanf(argv[2], "%d-%d-%d", &day, &month, &year);

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror("Error opening file");
        return 1;
    }

    char line[100], name[50], date[11], level[10];
    int ilevel, currday, currmonth, curryear;
    Pokemon *pokemons = NULL;
    int count = 0;

    fgets(line, sizeof(line), f); // Skip header
    while (fgets(line, sizeof(line), f)) {
        if (sscanf(line, " %49[^,], %10[^,], %9s", name, date, level) == 3) {
            ilevel = atoi(level);
            sscanf(date, "%d-%d-%d", &currday, &currmonth, &curryear);
            if (curryear > year || (curryear == year && currmonth > month) || (curryear == year && currmonth == month && currday >= day)) {
                pokemons = realloc(pokemons, (count + 1) * sizeof(Pokemon));
                pokemons[count].result = malloc(100 * sizeof(char));
                snprintf(pokemons[count].result, 100, "%s was caught on %s and is level %d", name, date, ilevel);
                pokemons[count].day = currday;
                pokemons[count].month = currmonth;
                pokemons[count].year = curryear;
                count++;
            }
        }
    }
    fclose(f);

    qsort(pokemons, count, sizeof(Pokemon), compare);

    for (int i = 0; i < count; i++) {
        printf("%s\n", pokemons[i].result);
        free(pokemons[i].result);
    }
    free(pokemons);

    return 0;
}