#include <stdio.h>
#include <stdlib.h>
int check(int x);
int create(int n);

struct bitString
{
    int data;
    struct bitString *next;
} *head1 = NULL,*head2=NULL, *newnode, *current,*temp;

int main()
{
    int a[10] = {0};
    int n1,n2, x;
    int u[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Universal set \nU=:{1,2,3,4,5,6,7,8,9,10}\n");
    while(1){
    printf("Enter the size of set 1:");
    scanf("%d", &n1);
    printf("Enter the size of set 2:");
    scanf("%d", &n2);
    if(n1>10 && n2>10)
    {
        printf("enter a valid size\n");
    } 
    else{
        break;
    }
    }
    create(n1,head1);
    create(n2,head2);
    printf("The first set is:");
    print(head1);
    printf("The second set is:");
    print(head2);

   
   
    // for (int i =0 ; i<10 ;i++) {
    // for(temp=head;temp!=NULL;temp=temp->next){
    //     if (u[i] == temp->data) 
    //        a[i] = 1;
    // }
        
    // }
    // printf("\nBit String=");
    // for(int i=0;i<10;i++){
    //     printf("%d",a[i]);
    // }
}
int check(int x){
 if (head==NULL)
 {
    return 1;
 }
 else{
     for(temp=head;temp!=NULL;temp=temp->next){
        if(x==temp->data){
            return 0;
        }
     }
     return 1;
 }
}

int create(int n,struct bitString *head){
     printf("Enter your Elemnets from universal set : \n");
     for (int i = 1; i <= n; i++)
    {
        printf("Enter %d th element:", i);
        scanf("%d",&x);
        if(x>=1 && x<=10){
            if(check(x)){
                newnode = (struct bitString* )malloc(sizeof(struct bitString));
                newnode->data =x;
                newnode->next = NULL;
                if(head == NULL) {
                    head = newnode;
                    current = newnode;
                }
                else {
                    current->next = newnode;
                    current = newnode;
                }
            }
            else{
                printf("Element already in the set\n");
                i=i-1;
            }
       
        }
        else{
            printf("choose your elements from U \n");
            i=i-1;
        }
    }
}

void print(struct bitString *head){
 for(temp=head;temp!=NULL;temp=temp->next){
        printf("%d\t",temp->data);
    }
}