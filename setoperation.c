#include <stdio.h>
#include <stdlib.h>

struct bitString
{
    int data;
    struct bitString *next;
} *head1 = NULL, *head2 = NULL, *newnode, *current;
int check(int x, struct bitString *head);
void Union(int a[], int b[]);
void intersection(int a[], int b[]);
void diff(int a[],int b[]);
int main()
{
    int a[10] = {0};
    int b[10] = {0};
    int n1, n2, x;
    int u[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Universal set \n U=:{1,2,3,4,5,6,7,8,9,10}\n");
    while (1)
    {
        printf("Enter the size of set 1:");
        scanf("%d", &n1);
        if (n1 > 10)
        {
            printf("enter a valid size\n");
        }
        else
        {
            break;
        }
    }
    printf("Enter your Elemnets from universal set : \n");
    for (int i = 1; i <= n1; i++)
    {
        printf("Enter %d th element:", i);
        scanf("%d", &x);
        if (x >= 1 && x <= 10)
        {
            if (check(x, head1))
            {
                newnode = (struct bitString *)malloc(sizeof(struct bitString));
                newnode->data = x;
                newnode->next = NULL;
                if (head1 == NULL)
                {
                    head1 = newnode;
                    current = newnode;
                }
                else
                {
                    current->next = newnode;
                    current = newnode;
                }
            }
            else
            {
                printf("Element already in the set\n");
                i = i - 1;
            }
        }
        else
        {
            printf("choose your elements from U \n");
            i = i - 1;
        }
    }
    struct bitString *temp;
    for (temp = head1; temp != NULL; temp = temp->next)
    {
        printf("%d\t", temp->data);
    }
    for (int i = 0; i < 10; i++)
    {
        for (temp = head1; temp != NULL; temp = temp->next)
        {
            if (u[i] == temp->data)
                a[i] = 1;
        }
    }
    printf("\nBit String=");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", a[i]);
    }

    while (1)
    {
        printf("\nEnter the size of set 2:");
        scanf("%d", &n2);
        if (n2 > 10)
        {
            printf("enter a valid size\n");
        }
        else
        {
            break;
        }
    }

    printf("Enter your Elemnets from universal set : \n");
    for (int i = 1; i <= n2; i++)
    {
        printf("Enter %d th element:", i);
        scanf("%d", &x);
        if (x >= 1 && x <= 10)
        {
            if (check(x, head2))
            {
                newnode = (struct bitString *)malloc(sizeof(struct bitString));
                newnode->data = x;
                newnode->next = NULL;
                if (head2 == NULL)
                {
                    head2 = newnode;
                    current = newnode;
                }
                else
                {
                    current->next = newnode;
                    current = newnode;
                }
            }
            else
            {
                printf("Element already in the set\n");
                i = i - 1;
            }
        }
        else
        {
            printf("choose your elements from U \n");
            i = i - 1;
        }
    }
    for (temp = head2; temp != NULL; temp = temp->next)
    {
        printf("%d\t", temp->data);
    }
    for (int i = 0; i < 10; i++)
    {
        for (temp = head2; temp != NULL; temp = temp->next)
        {
            if (u[i] == temp->data)
                b[i] = 1;
        }
    }
    printf("\nBit String=");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", b[i]);
    }

    Union(a, b);
    intersection(a,b);
    printf("\nA-B:\n");
    diff(a,b);
    printf("\nB-A:\n");
    diff(b,a);
    
}

int check(int x, struct bitString *head)
{
    struct bitString *temp;
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        for (temp = head; temp != NULL; temp = temp->next)
        {
            if (x == temp->data)
            {
                return 0;
            }
        }
        return 1;
    }
}

void Union(int a[], int b[])
{
    int c[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        if (a[i] == 1 && b[i] == 1)
        {
            c[i] = 1;
        }
        else
            c[i] = a[i] + b[i];
    }
    printf("\nUnion of two sets : \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", c[i]);
    }
}

void intersection(int a[], int b[])
{
    int c[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        if (a[i] == 1 && b[i] == 1)
        {
            c[i] = 1;
        }
        else{
            c[i]=0;
        }
    }
    printf("\nintersection of two sets are:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", c[i]);
    }
}
void diff(int a[],int b[]){
    int c[10]={0};
    for(int i=0;i<10;i++)
    {
        if(a[i]==1&&b[i]==0){
            c[i]=1;
        }
        else{
            c[i]=0;
        }
    }
    printf("Difference is:");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", c[i]);
    }
}