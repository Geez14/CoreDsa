#include <stdio.h>

struct Node
{
    char data;
    struct Node *next;
};

typedef struct
{
    struct Node *head;
}linklist;

void trasverse(linklist l);

int  main()
{
    struct Node c = {54, NULL};
    struct Node b = {23, &c};
    struct Node a = {12, &b};
    linklist list = {&a};


    trasverse(list);
}

void trasverse(linklist l) {
    struct Node *curr = l.head;

    while(curr != NULL) {
        printf("%d ",curr->data);

        curr = curr->next;
    }
}


