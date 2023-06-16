#include <stdio.h>
#include <stdlib.h>

typedef struct node { 
    int num;
    struct node* next; 
    } node;
 
int whatDoesItDo (node* head) { 
    
    struct node * current = head;
    struct node * other, *temp;

    if (current == NULL) 
        return head;

    other = current->next;

    if (other == NULL) 
        return head;
        
    other = other->next;
    temp = current->next;
    current->next = other->next;
    current = other->next;

    if (current == NULL) { 
        head->next = temp;
        return head; 
    } 

    other->next = current->next;
    current->next = temp; 
    return head;
    whatDoesItDo(head);
}