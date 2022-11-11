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
void selectionsort(linkedlist* head, int n); //performs selection sort on linked list
void printlist(linkedlist* head); //prints a linked list with provided head
void freelist(linkedlist* head); //frees memory of a linked list
linkedlist* fill(int n); //creates a linked list using user input of length n


int main(int argc, char** argv){
    printf("Input length of linked list. \n");
    scanf("%d", &length);
    linkedlist* head = fill(length);
    printf("Unsorted List: ");
    printlist(head);
    selectionsort(head, length);
    printf("Sorted List: ");
    printlist(head);
    freelist(head);
}

void selectionsort(linkedlist* head, int n){
    linkedlist* i;
    for(i=head; i!=NULL; i=i->next){
        linkedlist* p=i;
        linkedlist* j;
        for(j=i->next; j!=NULL; j=j->next){
            if(p->val > j->val){
                p = j;
            }  
        }
        int temp = i->val;
        i->val = p->val;
        p->val = temp;
    }
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
