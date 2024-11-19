#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL, *temp, *newnode;

void push();
void pop();
void peek();
void display();


int main()
{
    while(1){
    
    int i, x;
    printf("\n 1.PUSH \n 2.POP \n 3.PEEK \n 4.DISPLAY \n 5.EXIT \n");
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
        peek();
        break;
    case 4:
        display();
        break;
    case 5:
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
    if (head == NULL)
    {
        head = newnode;
        newnode->data = n;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = head;
        head = newnode;
        newnode->data = n;
    }
}
void pop()
{
    if(head==NULL){
        printf("underflow condition");
    }
    else if(head->next==NULL){
        temp=head;
        head=NULL;
        free(temp);
        printf("stack is now empty");
    }
   else{

    head=head->next;}
}

void display()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        printf(" --> ");
        temp = temp->next;
    }
    printf("null");
}

void peek() {
    printf("The top element is : %d",head->data);
}