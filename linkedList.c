#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *insertAtStart(struct node *, int);
struct node *insertAtEnd(struct node *, int);
struct node *display_ll(struct node *);

int main()
{
    start = create_ll(start);
    start = display_ll(start);
    start = insertAtStart(start, 100);
    printf("\n");
    display_ll(start);
}

struct node *create_ll(struct node *start)
{
    struct node *newNode, *ptr;
    int num;
    printf("\n< Enter -1 to end >\n");
    printf("\nEnter the data : ");
    scanf("%d", &num);
    while (num != -1)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = num;
        if (start == NULL)
        {
            newNode->next = NULL;
            start = newNode;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->next = NULL;
        }
        printf("Enter the Data : ");
        scanf("%d", &num);
    }
    return start;
}

struct node * display_ll(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

struct node *insertAtStart(struct node *start, int num)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = start;
    start = newNode;
    return start;
}