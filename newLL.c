/*
 * version 0.1.2
 * future update : Dynamic programming linkList Optimization
 * dont use address of the linklist if we have to change somthing inside the linkList
 * all operation working correctly! 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int item;
    struct Node *node;
} Node;

typedef struct LinkList
{
    struct Node *node; // to traverse form fist
} LinkList;

// void insertNodeAtLast(LinkList *h, Node *a); @deprecated
void insert(LinkList *h, int *data);
void *addNode(LinkList *h, Node *a);
void insertNodeAtIndex(LinkList *h, Node *a, int index);
int countNode(LinkList *h);
void display(LinkList *h);
Node *selectNode(LinkList *h, int index);
void delete(LinkList *h, int item);
void freeLinkList(LinkList *h);
void deleteIndex(LinkList *h, int index);
int getData(LinkList *h, int index);
// void swapPosition(Node* A, Node* B); @bug
void swapData(Node *A, Node *B);
// void quickSort(LinkList *L); @VeryHigh memory Usage !
Node *convertLinkListToNodeArray(LinkList *h, int totalNodes);

// add element at 0th index
void insert(LinkList *h, int *data)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->item = *data;
    new->node = h->node;
    h->node = new;
}

void insertNodeAtIndex(LinkList *h, Node *a, int index)
{
    Node *prev = h->node;
    Node *curr = h->node->node;
    int count = 0;
    if (index == 0)
    {
        a->node = prev;
        h->node = a;
        return;
    }
    else
        while (curr != NULL)
        {
            count++;
            if (count == index)
            {
                prev->node = a;
                a->node = curr;
                return;
            }
            curr = curr->node;
            prev = prev->node;
        }
    // this line will be executed if index is out of range
    prev->node = a;
}

// @deprecated waste of space and time
// void insertNodeAtLast(LinkList* h, Node* a)
// {
//     Node* prev = h->node;
//     Node* curr = h->node->node;
//     while(curr != NULL)
//     {
//         curr = curr->node;
//         prev = prev->node;
//     }
//     prev->node = a;
// }

// it will only swap address, @bug @deprecated
// canbe used to swap address of the nodeArray
// void swapPosition(Node* A, Node* B)
// {
//     void* temp = A->node;
//     A->node = B->node;
//     B->node = ((Node*) temp)->node;
// }

void swapData(Node *A, Node *B)
{
    int temp = A->item;
    A->item = B->item;
    B->item = temp;
}

Node *selectNode(LinkList *h, int index)
{
    int count = 0;
    Node *curr = h->node;
    while (curr != NULL)
    {
        if (count == index)
        {
            return curr;
        }
        curr = curr->node;
        count++;
    }
    printf("NO ELEMENT FOUND");
    return NULL;
}

int countNode(LinkList *h)
{
    Node *curr = h->node;
    int i = 0;
    while (curr != NULL)
    {
        i++;
        curr = curr->node;
    }
    return i;
}

void display(LinkList *h)
{
    Node *curr = h->node;
    while (curr != NULL)
    {
        printf("%d\t", curr->item);
        curr = curr->node;
    }
    printf("\n");
}

int countNodes(LinkList h)
{
    Node *curr = h.node;
    int count = 0;
    while (curr != NULL)
    {
        curr = curr->node;
        count++;
    }
    return count;
}

void delete(LinkList *h, int item)
{
    Node *prev = h->node;
    Node *curr = (h->node)->node;
    if (prev->item == item)
    {
        *prev = *curr;
        return;
    }

    while (curr != NULL)
    {
        if (curr->item == item)
        {
            prev->node = curr->node;
            return;
        }
        prev = prev->node;
        curr = curr->node;
    }
    printf("DIDN'T FOUND THE OBJECT\n");
}

void freeLinkList(LinkList *h)
{
    free(h);
    h->node = NULL;
}

void deleteIndex(LinkList *h, int index)
{
    int count = 0;
    Node *prev = h->node;
    Node *curr = (h->node)->node;
    if (index == 0)
    {
        *prev = *curr;
        return;
    }
    else
        while (curr != NULL)
        {
            count++;
            if (count == index)
            {
                prev->node = curr->node;
                return;
            }
            prev = prev->node;
            curr = curr->node;
        }
    printf("LinkListIndexOutOfBoundException: Index %d out of bounds for length %d", index, count);
    exit(0);
}

int getData(LinkList *head, int index)
{
    int count = 0;
    Node *curr = head->node;
    while (curr != NULL)
    {
        if (count == index)
            return curr->item;
        curr = curr->node;
        count++;
    }
    printf("LinkListIndexOutOfBoundException: Index %d out of bounds for length %d", index, count);
    exit(0);
}

void convertArrayToLinkList(LinkList *head, int a[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        insert(head, (a + i));
    }
}

/*
 * @copyright
 * convertLinkListToNodeArray(linklist head, how many nodes to convert into array)
 * better if delete the linklist after converting the LinkListToNodeArray()
 */
Node *convertLinkListToNodeArray(LinkList *h, int totalNodes)
{
    Node *array = (Node *)malloc(totalNodes * sizeof(Node));
    Node *curr = h->node;
    for (int i = 0; i < totalNodes && curr != NULL; i++)
    {
        *(array + i) = *curr;
        (array + i)->node = NULL; // deleting the relationship @nosubgrouping
        curr = curr->node;
    }
    return array;
}

int main(int argc, char **arguments)
{
    // LinkList head = {NULL};
    // int x = 34;
    // insert(&head, &x);
    // Node a = {342, NULL};
    // Node b = {32, NULL};
    // Node c = {42, NULL};
    // insertNodeAtIndex(&head, &a, 3);
    // insertNodeAtIndex(&head, &b, 3);
    // insertNodeAtIndex(&head, &c, 3);
    // printf("count: %d\n", countNode(&head));
    // display(&head);
    // swapData(selectNode(&head, 0), selectNode(&head, 3));
    // display(&head);
    // printf(" data %d  index %d\n",getData(&head, 3),3);
    // delete(&head, 34);
    // deleteIndex(&head, 2);
    // delete(&head,2343);
    // display(&head);
    // Node* g = convertLinkListToNodeArray(&head, countNode(&head));
    // for(int i = 0; i < countNode(&head); i++)
    // {
    //     printf("\n%d\n",(g+i)->item);
    // }
    return 0;
}