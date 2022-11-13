// Course Deliverable 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int val;
    struct node * next;
};

typedef struct node linkedlist;

int main(){
    linkedlist node[4]; //array of linkedlist nodes
    linkedlist * head;
    srand(time(NULL));

    for(int i=0; i<4; i++){ //populate array
        node[i].val = rand()%100;
    }
    
    head = &node[0];
    node[0].next = &node[1];
    node[1].next = &node[2];
    node[2].next = &node[3];
    node[3].next = NULL;

    linkedlist *temp = head;

    while (temp!=NULL)
    {
        printf("%d ",temp->val);
        temp = temp->next;
    }
    printf("\n");

    return 0;
    
    temp = head;

    while (temp!=NULL)
    {
        linkedlist * next = temp->next;
        free(temp);
        temp = temp->next;
    }

}
