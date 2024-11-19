#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL, *temp, *newnode ,*tail=NULL;

void push();
void pop();
void peek();
void display();


int main()
{
    while(1){
    
    int i, x;
    printf("\n 1.PUSH \n 2.POP  \n 3.DISPLAY \n 4.EXIT \n");
    scanf("%d", &x);

    switch (x)
    {
    case 1:
        push();
        break;
    case 2:
         pop();
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

void push()
{

    int n;
    printf("Enter the element to insert :");
    scanf("%d", &n);
    newnode = (struct node *)malloc(sizeof(struct node));
    if (head == NULL && tail==NULL)
    {
        head = newnode;
        tail= newnode;
        newnode->data = n;
        newnode->next = NULL;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
        newnode->data = n;
        newnode->next=NULL;
    }
}
void pop()
{
    if(head==NULL){
        printf("underflow condition");
    }
    else if(head->next==NULL){
        temp=head;
        head=tail=NULL;
        free(temp);
        printf("queue is now empty");
    }
   else{

    head=head->next;}
}

void display()
{
    temp = head;
    if(head==NULL){
        printf("underflow condition");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        printf(" --> ");
        temp = temp->next;
    }
    
}

