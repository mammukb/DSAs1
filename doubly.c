#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
}*head=NULL,*temp,*newnode;

int main() 
{
    while(1){
    
    int i, x;
    printf("\n 1.INSERT \n 2.DELETE  \n 3.DISPLAY \n 4.EXIT \n");
    scanf("%d", &x);

    switch (x)
    {
    case 1:
        insert();
        break;
    case 2:
         delete();
        break;
    case 3:
        display();
        break;
    case 4:
        return 0;
    default:
        break;
    }
    }
}

void insert() {
    int x, p;

    if (head == NULL)
    {
        printf("Enter the data :");
        scanf("%d", &x);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;
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
            newnode->data = x;
            return;
        case 3:
            printf("Enter the data :");
            scanf("%d", &x);
            newnode = (struct node *)malloc(sizeof(struct node));
            current->next = newnode;
            newnode->data = x;
            newnode->next = NULL;
            current = newnode;
            return;

        default:
            break;
        }
    }
}