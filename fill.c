/*
Εκφώνηση: 
Αν έχετε χρησιμοποιήσει κάποιο πρόγραμμα ζωγραφικής στον υπολογιστή (π.χ., Paint),
ίσως έχετε κάνει χρήση του "κουβά", του εργαλείου δηλαδή που μας βοηθάει να γεμίζουμε
γρήγορα κλειστές επιφάνειες χωρίς εμπόδια. 
Για τις ανάγκες της εφαρμογής μας κάνουμε τις εξής παραδοχές: 
(1) έχουμε μόνο δύο χρώματα που αναπαρίστανται με 0 και 1, 
(2) το πρόγραμμά μας γεμίζει την εικόνα μόνο με το χρώμα 1, 
(3) οι εικόνες που χειριζόμαστε είναι τετραγωνικές και (4) το χρώμα μπορεί μόνο να γεμίζει 
επιφάνειες που επικοινωνούν ελεύθερα με το αρχικό σημείο κάνοντας μόνο κινήσεις πάνω, 
κάτω, αριστερά, δεξιά (όχι διαγώνια). Εάν ένα κελί περιέχει ήδη το χρώμα 1, το κελί
δεν θεωρείται ελεύθερο και δρα ως "τοίχος" για το γέμισμά μας.
Γράψτε ένα πρόγραμμα το οποίο παίρνει ως όρισμα το όνομα του αρχείου που περιέχει την
εικόνα και το αρχικό σημείο για γέμισμα και τυπώνει στην έξοδο την τελική εικόνα. Η πρώτη
σειρά του αρχείου περιέχει την διάσταση της εικόνας, η δεύτερη σειρά τις συντεταγμένες του
αρχικού σημείου και τέλος ακολουθεί η δισδιάστατη εικόνα
*/

#include <stdio.h>
#include <stdlib.h>

static int dim;
void printimage(int image[dim][dim], int dim);
void fillimage(int image[dim][dim], int dim, int row, int col);


int main(int argc, char *argv[]){
    // όρισμα: 1 αρχείο
    if(argc!=2){
        fprintf(stderr, "Incorrect amount of arguments\n");
        return 1;
    }
    FILE* f = fopen(argv[1], "r");
    char * firstLine = malloc(10*sizeof(int));
    fgets(firstLine, 8*sizeof(char), f);
    dim = atoi(firstLine);
    char * secondLine = malloc(10*sizeof(int));
    fgets(secondLine, 8*sizeof(char), f);

    // find starting box
    int row, col;
    sscanf(secondLine, "%d %d", &row, &col);
    
    // make image
    int image[dim][dim];
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            fscanf(f, "%1d", &image[i][j]);
        }
    }

    printf("Start image: \n");
    printimage(image, dim);

    fillimage(image, dim, row, col);
    printf("Finish image: \n");
    printimage(image, dim);
    return 0;
}

void fillimage(int image[dim][dim], int dim, int row, int col){
    if(row<0||row>=dim||col<0||col>=dim||image[row][col]==1) {
        return;
    }
    image[row][col]=1;
    fillimage(image, dim, row+1, col);
    fillimage(image, dim, row-1, col);
    fillimage(image, dim, row, col+1);
    fillimage(image, dim, row, col-1);
}

void printimage(int image[dim][dim], int dim){
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            printf("%d", image[i][j]);
        }
        printf("\n");
    }
}