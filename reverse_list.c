/*
Γράψτε μια συνάρτηση reverse_list η οποία παίρνει ως όρισμα μια λίστα ακεραίων 
τύπου List και επιστρέφει μια νέα λίστα με τους κόμβους της σε αντίστροφη σειρά 
σε σχέση με την αρχική.
*/

#include <stdio.h>
#include <stdlib.h>

// Ορισμός του struct node
typedef struct node {
    int value;
    struct node* next;
} *List;

// Συνάρτηση για την αντιστροφή της συνδεδεμένης λίστας
List reverse_list(List head) {
    List prev = NULL, current = head, next = NULL;
    while (current != NULL) {
        next = (*current).next;
        (*current).next = prev; 
        prev = current;
        current = next;

        /*
        Δεύτερη εντολή:  Στην ουσία, αντί το next να δείχνει στον επ΄όμενο κόμβο,
        δείχνει στον κόμβο που βρίσκεται πίσω του
        Τρίτη εντολή: Μετακινούμε τον prev μπροστά για να δείχνει στον 
        κόμβο που αντιστρέψαμε 
        Σημείωση, να θυμάμαι ότι η γραφή (*pointer).prev είναι ισοδύναμη
        με την γραφή pointer->prev οπότε θα μπορούσα να έιχα γράψει 
        current->next αντί για (*current).next
        */
    }
    return prev; // Νέο κεφάλι της αντιστραμμένης λίστας, γιατί όταν ολοκληρωθεί
    // η αντιστροφή, το prev δείχνει στον τελευταίο κόμβο της αρχικής λίστας, ο 
    // οποίος έχει γίνει ο πρώτος κόμβος της αντιστραμμένης λίστας
}

// Συνάρτηση για την εκτύπωση της λίστας
void print_list(List head) {
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

// Συνάρτηση που φτιάχνει νέο κόμβο
List create_node(int value) {
    List new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

int main() {
    // Δημιουργία της λίστας: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    List head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);
    head->next->next->next->next = create_node(5);

    printf("Αρχική λίστα:\n");
    print_list(head);

    head = reverse_list(head);

    printf("Αντιστραμμένη λίστα:\n");
    print_list(head);

    while (head != NULL) {
        List temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

// πηγή https://www.wscubetech.com/resources/c-programming/programs/reverse-linked-list