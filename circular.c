#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head, *current, *newnode, *temp = NULL,*tail=NULL;

void insertion();
void print_link();
void delete_link();


int main()
{
    int n, x, k;
    // head = NULL;
    // // printf("Enter your element to insert:");
    // // scanf("%d",&newnode->data);
    // // struct node *head=(struct node*)(malloc(sizeof(newnode)));
    // printf("How many elements :");
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    // {

    // printf("%d",head->data);

    // int c = 1;
    // while (c)
    //{{}


    
    while (1)
    {
        printf("\n 1.Insertion \n 2.Display\n 3.Delete\n 4.exit\n");
        scanf("%d", &k);
        switch (k)
        {
        case 1:
            insertion();
            break;
        case 2:
            print_link();
            break;
        case 3:
            delete_link();
            break;
        case 4:
            return 0;  
          
        default:
            break;
        }
    }
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
        newnode->next = newnode;
        tail = newnode;
        head = newnode;
        current = newnode;
        return;
    }

    while (1)
    {
        int c;
        printf("\n1.insertion at beginning \n2.inerstion at any position \n3.insertion at end\n");
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
            tail->next = head;
            printf("head =%d tail=%d" , head->data, tail->data);
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
            printf(" head =%d tail=%d" , head->data, tail->data);

            return;
        case 3:
            printf("Enter the data :");
            scanf("%d", &x);
            newnode = (struct node *)malloc(sizeof(struct node));
            tail->next = newnode;
            newnode->data = x;
            newnode->next = head;
            tail = newnode;
            printf("head =%d tail=%d" , head->data, tail->data);

            return;

        default:
            break;
        }
    }

    // {
    //     current->next = newnode;
    //     newnode->data = x;
    //     newnode->next = NULL;
    //     current = newnode;
    // }
}

void delete_link()
{
    while (1)
    {
        int c, x, i;
        printf("\n1.deletion at beginning \n2.deletion at any position \n3.deletion at end \n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            head = head->next;
            tail->next = head;
            printf("head =%d tail=%d" , head->data, tail->data);
            return;
        case 2:
            printf("enter your position:");
            scanf("%d", &x);
            temp = head;
            for (i = 2; i < x; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            printf("head =%d tail=%d" , head->data, tail->data);
            return;
        case 3:

            temp = head;
            while (temp->next->next != head)
            {
                temp = temp->next;
            }
            temp->next = head;
            tail= temp;
            printf("head =%d tail=%d" , head->data, tail->data);
            return;

            
        }
    }
}

void print_link()
{
    temp = head;
    do
    {
        printf("%d", temp->data);
        printf(" --> ");
        temp = temp->next;
    }while (temp != head);
    printf("head");
}
