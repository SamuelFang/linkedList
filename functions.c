#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>  
#include "headers.h"

void print_list(struct node *n){
    if (n == NULL) {
        printf("[ ]\n");
    }
    else{
        printf("[ ");
        while (n->next != NULL) {
            printf("%d ", n->i);
            n = n->next;
        }
        printf("]\n");
    }
}

struct node * insert_front(struct node *n, int d){
    struct node *head;
    head = (struct node*)malloc(sizeof(struct node)); 
    head->i = d;
    head->next = n;
    return head;
}

struct node * free_list(struct node *n){
    while (n != NULL) {
        printf("freeing node %d\n", n->i);
        struct node *n1 = n;
        n = n->next;
        free(n1);
    }
    return n;
}

struct node * remove_node(struct node *front, int data){
    struct node *n = front;
    if (n->i == data) {
        n = front-> next;
        free(front);
        return (n);
    }
    while (n->next != NULL) {
        if((n->next)->i == data){
            struct node *nextNode = n->next;
            n->next = nextNode->next;
            free(nextNode);
            n = n->next;
        }
        else{
            n = n->next;
        }
    }
    return front;
}

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