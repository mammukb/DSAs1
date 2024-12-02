#include <stdio.h>
#include<stdlib.h>

struct bst
{
    int data;
    struct bst *leftchild;
    struct bst *rightchild;
} *root = NULL,*temp,*newnode;

int main()
{
    int n;
    int c=1;
    while (c)
    {
        printf("Enter the data : ");
        scanf("%d", &n);
        newnode = (struct node *)malloc(sizeof(struct node *));
        newnode->data = n;
        if(root == NULL){
            newnode->leftchild =NULL;
            newnode->rightchild = NULL;
        }
        else {
            

        }
        printf("Do you want to continue 1/0 ? ");
        scanf("%d",&c);
    }
}