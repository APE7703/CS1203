//Course Deliverable 5

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int val;
    struct node* next;
};

typedef struct node linkedlist;

//Function Prototypes
linkedlist* listcreate(); //creates a list of unknown length according to user input
void printhalflist(linkedlist* head); //prints first half of linked list
void printlist(linkedlist* head); //prints a linked list
void freelist(linkedlist* head);

int main(int argc, char** argv){

    linkedlist* head = listcreate();
    if (head == NULL){
        return -1;
    }

    printlist(head);
    printhalflist(head);
    freelist(head);
    
    return 0;
}

linkedlist* listcreate(){
    linkedlist* head = malloc(sizeof(struct node));
    linkedlist* temp = head;
    int val;
    printf("Input a negative value to stop linked list population. \n");
    printf("Input value. \n");
    scanf("%d", &val);
    if (val < 0){
        printf("Linked list input empty. \n");
        return NULL;
    }
    head->val = val;
    head->next = NULL;
    bool cond = true;
    while (cond)
    {
        printf("Input value. \n");
        scanf("%d", &val);  
        if (val < 0){
            cond = false;
            continue;
        }    
        temp->next = malloc(sizeof(struct node));
        temp = temp->next;
        temp->val = val;
        temp->next = NULL;
    }
    return head;
}

void printhalflist(linkedlist* head){
    linkedlist* slow = head;
    linkedlist* fast = head;
    while(fast!=NULL && fast->next != NULL){
        int v = slow->val;
        printf("%d ", v);
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("\n");
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

