/*
* version 0.0.1
* feature basic linklist and some little implementation
* upcomming feature array to linklist; release date 19-08-2023 (DD-MM-YYYY)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    int item;
    struct Node * node;
}Node;

typedef struct LinkList
{
    struct Node* node;
}LinkList;



void display(LinkList h){
    Node* curr = h.node;
    while (curr != NULL)
    {
        printf("%d\t",(curr->item));
        curr = curr->node;
    }
    printf("\n");
}


void delete(LinkList h,int item)
{
    Node* curr = h.node;
    while (curr != NULL)
    {
        if(curr->item == item)
        {
            curr->item = (curr->node)->item;
            curr->node = (curr->node)->node;
            return;
        }
        curr = curr->node;
    }
    printf("DIDN'T FOUND THE OBJECT\n");
}



void clearLL(LinkList h)
{
    h.node = NULL;
}



void deleteFromIndex(LinkList h, int index)
{
    int count = 0;
    Node* curr = h.node;
    while (curr != NULL)
    {
        if(count++ == index)
        {
            curr->item = (curr->node)->item;
            curr->node = (curr->node)->node;
            return;
        }
    }
    printf("LinkListIndexOutOfBoundException: Index %d out of bounds for length %d", index, count);
    exit(0);
}



int get(LinkList head, int index) {
    int count = 0;
    Node* curr = head.node;
    while (curr != NULL)
    {
        if(count == index)
            return curr->item;
        curr = curr->node;
        count++;
    }
    printf("LinkListIndexOutOfBoundException: Index %d out of bounds for length %d", index, count);
    exit(0);
}



void convertArrayToLinkList(LinkList head, int a[])
{
}

int main(char* arguments)
{
    LinkList head;
    Node a = {6, NULL};
    Node b = {5, &a};
    Node c = {4, &b};
    Node d = {3, &c};
    Node e = {2, &d};
    head.node = &e;
    display(head);
    delete(head,3);
    display(head);
    deleteFromIndex(head, 3);
    printf("%d", get(head, 2));
return 0;
}