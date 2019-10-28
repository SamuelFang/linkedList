#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>  
#include "headers.h"

int main() {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->next = NULL;
    printf("Printing empty list:\n");
    print_list(n);
    printf("Adding #s 0-9 to list.\n");
    int x;
    for (x = 0; x < 10; x++){
        n = insert_front(n, x);
    }
    printf("Printing list:\n");
    print_list(n);
    printf("Removing 9:\n");
    remove_node(n, 9);
    print_list(n);
    printf("Removing 4:\n");
    remove_node(n, 4);
    print_list(n);
    printf("Removing 0:\n");
    remove_node(n, 0);
    print_list(n);
    printf("Removing -1:\n");
    remove_node(n, -1);
    print_list(n);
    printf("Freeing list.\n");
    free_list(n);
    printf("Printing list:\n");
    print_list(n);
    printf("Did everything I could, but taking too much time\n");
    printf("Can't fix error having to do with the header\n");
}