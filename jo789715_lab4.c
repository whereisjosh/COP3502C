#include <stdio.h> 
#include <stdlib.h>

typedef struct node{
char letter; 
struct node* next;
}node;

int length(node* head){ //returns # of nodes in list
    int count = 0;
    
    while(head){
        count++;
        head = head->next;
    }

    return count;
}

char* toCString(node* head){
    int len = length(head);
    char* str = malloc(len + 1);
    int i = 0;

    while(head){
        str[i++] = head->letter;
        head = head->next;
    }
    
    str[i] = '\0';
    return str;
}

void insertChar(node** pHead, char c){ //inserts character at head of list
    node* newNode = malloc(sizeof(node));
    newNode->letter = c;
    newNode->next = *pHead;
    *pHead = newNode;
}

void deleteList(node** pHead){ //deletes nodes in the linked list
    node* current = *pHead;
    
    while(current){
        node* next = current->next;
        free(current);
        current = next;
    }
    
    *pHead = NULL;
}

int main(void){
    int i, strLen, numInputs;
    node* head= NULL;
    char* str; 
    char c;

    FILE* inFile = fopen("input.txt","r");
    fscanf(inFile, " %d\n", &numInputs);

    while (numInputs--> 0){  
        fscanf(inFile," %d\n",&strLen);
    
        for (i=0; i< strLen; i++){
            fscanf(inFile," %c", &c); 
            insertChar(&head, c);
        }

        str = toCString(head); 
        printf("String is: %s\n", str);
        free(str); 
        deleteList(&head);

        if (head != NULL){
            printf("deleteList is not correct!");
            break;
        }
    }

    fclose(inFile);
}