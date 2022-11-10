#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node* next;
};

typedef struct node linkedlist;


//Function prototypes
void printlinkedlist(linkedlist* list); //prints a linkedlist
linkedlist* reverselist(linkedlist* list); //reverses a linkedlist
void freelist(linkedlist* list); //frees memory

int main() {
    
    int length;
    printf("Enter chosen length for linked list: \n");
    scanf("%d", &length);
    //if length of input is 1 or less than 1 than the input is wrong as there is no need to reverse
    if (length < 2){
        printf("Input is erroneous. \n");
        return -1;
    }
    
    linkedlist *head = NULL;
    linkedlist *tmp = NULL;
    int v;
    
    head = malloc(sizeof(struct node));
    printf("Enter value: \n");
    scanf("%d", &v);
    head->val = v;
    head->next = NULL;
    tmp = head;

    for(int i=1; i<length; i++){ //creates a linked list of given 'length' 
        tmp->next = malloc(sizeof(struct node));
        tmp = tmp->next;
        printf("Enter value: \n");
        scanf("%d", &v);
        tmp->val = v;
        tmp->next = NULL;
    } 

    printf("Original Linked List. \n");
    printlinkedlist(head);
    linkedlist* revhead = reverselist(head);
    printf("Reversed Linked List. \n");
    printlinkedlist(revhead);
    freelist(head);
    
    return 0;
}

void printlinkedlist(linkedlist* list){
    linkedlist* tmp = list;
    while(tmp!=NULL){
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}

linkedlist* reverselist(linkedlist* list){
    linkedlist* current = list;
    linkedlist* next = NULL;
    linkedlist* previous = NULL;

    while(current != NULL){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}

void freelist(linkedlist* list){
    linkedlist* t;
    while (list != NULL)
    {
        t = list;
        list = list->next;
        free(t);
    }
    
}
