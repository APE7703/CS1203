//Course Deliverable 13

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node* next;
};

typedef struct node linkedlist;

int length;

//Function Prototypes
linkedlist* insertionsort(linkedlist* head, int n);
linkedlist* sortedInsert(linkedlist* sorted, linkedlist* current);
void printlist(linkedlist* head);
void freelist(linkedlist* head);
linkedlist* fill(int n);


int main(int argc, char** argv){
    printf("Input length of linked list. \n");
    scanf("%d", &length);
    linkedlist* head = fill(length);
    printf("Unsorted List: ");
    printlist(head);
    head = insertionsort(head, length);
    printf("Sorted List: ");
    printlist(head);
    freelist(head);
}

linkedlist* insertionsort(linkedlist* head, int n){
    linkedlist* sorted = NULL;
    linkedlist* current= head;
    while (current!=NULL)
    {
        linkedlist* currentnext = current->next;
        sorted = sortedInsert(sorted, current);
        current = currentnext;
    }
    return sorted;
}

linkedlist* sortedInsert(linkedlist* sorted, linkedlist* current){
    if(sorted == NULL || sorted->val >= current->val){
        current->next = sorted;
        return current;
    }
    else
    {
        linkedlist* temp = sorted;
        while (temp->next != NULL && temp->next->val < current->val)
        {
            temp = temp->next;
        }
        current->next = temp->next;
        temp->next = current;        
    }
    return sorted;
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

linkedlist* fill(int n){
    linkedlist* head = malloc(sizeof(struct node));
    linkedlist* tmp = head;
    int v;
    if(n>0){
        printf("Input value. \n");
        scanf("%d", &v);
    }
    head->val = v;
    head->next = NULL;
    for(int i=1; i<n; i++){
        printf("Input value. \n");
        scanf("%d", &v);
        tmp->next = malloc(sizeof(struct node));
        tmp = tmp->next;
        tmp->val = v;
        tmp->next = NULL; 
    }

    return head;
}




