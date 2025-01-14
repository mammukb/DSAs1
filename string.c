#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *next;
};
struct node *head = NULL, *new, *current, *temp;

void check();
void insertion()
{
    char st[10];
    int n, i;
    printf("Enter the name :");
    // gets(st);
    scanf("%s", &st);
    n = strlen(st);
    for (i = 0; i < n; i++)
    {
        new = (struct node *)malloc(sizeof(struct node));
        new->data = st[i];
        new->next = NULL;
        if (head == NULL)
        {
            head = new;
            current = new;
        }
        else
        {
            current->next = new;
            current = new;
        }
    }
    for (temp = head; temp != NULL; temp = temp->next)
    {
        printf("%c \t", temp->data);
    }
    check();
}

void check()
{
    int f = 0;
    char v= "AEIOUaeiou";
    printf("Vowels in the string are :");
    for (temp = head; temp != NULL; temp = temp->next)
    {
        if (temp->data == 'A' || temp->data == 'E' || temp->data == 'I' || temp->data == 'O' || temp->data == 'U' || temp->data == 'a' || temp->data == 'e' || temp->data == 'i' || temp->data == 'o' || temp->data == 'u')
        {
            printf("%c", temp->data);
            f = 1;
        }
    }
    if (f == 0)
    {
        printf("There is no vowels in your string");
    }
}

int main()
{
    insertion();
}