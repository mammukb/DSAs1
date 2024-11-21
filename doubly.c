#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *head = NULL, *temp, *newnode, *current;

void insertion();
void print_link();
void delete();

int main()
{
    while (1)
    {

        int x;
        printf("\n 1.INSERT \n 2.DELETE  \n 3.DISPLAY \n 4.EXIT \n");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            insertion();
            break;
        case 2:
            delete ();
            break;
        case 3:
            print_link();
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }
}
void print_link()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        printf(" <----> ");
        temp = temp->next;
    }
    printf("null");
}

void insertion()
{
    int x, p;

    if (head == NULL)
    {
        printf("Enter the data :");
        scanf("%d", &x);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
        current = newnode;
        return;
    }

    while (1)
    {
        int c;
        printf("\n1.insertion at beginning\n2.inerstion at any position \n3.insertion at end");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("enter your element:");
            scanf("%d", &x);
            temp = (struct node *)malloc(sizeof(struct node *));
            temp->next = head;
            temp->prev = NULL;
            temp->data = x;
            head = temp;
            return;
        case 2:
            printf("enter your position:");
            scanf("%d", &p);
            printf("enter your element:");
            scanf("%d", &x);
            newnode = (struct node *)malloc(sizeof(struct node *));
            temp = head;
            for (int i = 2; i < p; i++)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
            temp->prev = current;
            newnode->data = x;
            return;
        case 3:
            printf("Enter the data :");
            scanf("%d", &x);
            newnode = (struct node *)malloc(sizeof(struct node));
            current->next = newnode;
            newnode->data = x;
            newnode->next = NULL;
            newnode->prev = current;
            current = newnode;
            return;

        default:
            break;
        }
    }
}

void delete()
{
    while (1)
    {
        int c, x, i;
        printf("\n1.deletion at beginning \n2.deletion at any position \n 3.deletion at end \n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            head = head->next;
            return;
        case 2:
            printf("enter your position:");
            scanf("%d", &x);
            temp = head;
            for (i = 2; i < x; i++)
            {
                temp = temp->next;
            }     
            temp->next->next->prev = temp;
            temp->next=temp->next->next;
            return;
        case 3:

            temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            return;
        }
    }
}
