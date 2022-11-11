//Course Deliverable 7

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node* next;
};

typedef struct node linkedlist;

//Function Prototypes
linkedlist* chunkrev(linkedlist* head);
linkedlist* createlist();
void printlist(linkedlist* head);
void freelist(linkedlist* head);

//Global variables
int length, chunk;

int main(int argc, char** argv){
    printf("Input the length of linked list. \n");
    scanf("%d", &length);
    printf("Input the length of chunk.\n");
    scanf("%d", &chunk);
    if(chunk >= length){
        printf("Chunk input is erroneous.");
        return -1;
    }
    linkedlist* head = createlist();

    printlist(head);
    linkedlist* revhead = chunkrev(head);
    printlist(revhead);
    freelist(revhead);
}

/* attempt to chunk reverse without recursion
linkedlist* chunkrev(linkedlist* head){
    linkedlist* top = head; //First element of chunk
    linkedlist* bottom = head;
    int count = 1;
    linkedlist* start = NULL;

    while(top!=NULL){
        //Find bottom [element after last element of chunk] of current chunk
        for(int i=1; i<chunk && bottom!=NULL; i++){
            bottom = bottom->next;
        }
        printf("Bottom: %d \n", bottom->val);
        //reverse list till bottom 
        linkedlist* current = top;
        linkedlist* next = NULL;
        linkedlist* previous = bottom; //first element of chunk points to bottom
        while(current != bottom){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        printf("Start: %d \n", previous->val);
        if (count == 1){ // first chunk
            start = previous;
        }
        printf("Current: %d \n", current->val);
        current->next = bottom;
        count++;
        top = bottom; //first element of next chunk
        printf("Top: %d \n", top->val);
        printf("Count: %d \n", count);
    }
    return start;
}
*/

linkedlist* chunkrev(linkedlist* head){
    linkedlist* current = head;
    linkedlist* next = NULL;
    linkedlist* prev = NULL;
    int c = 0;

    while (current!=NULL && c < chunk)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        c++;
    }

    if( next != NULL){
        head->next = chunkrev(next);
    }

    return prev;
    
}

linkedlist* createlist(){
    linkedlist* head = malloc(sizeof(struct node));
    int val;
    printf("Input value.\n");
    scanf("%d", &val);
    head->val = val;
    head->next = NULL;
    linkedlist* temp = head;

    for(int i=1; i<length; i++)
    {   
        temp->next = malloc(sizeof(struct node));
        temp = temp->next;
        printf("Input value.\n");
        scanf("%d", &val);
        temp->val = val;
        temp->next = NULL;
    }
    return head;
}

void printlist(linkedlist* head){
    linkedlist* tmp = head;
    while(tmp!=NULL){
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
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
