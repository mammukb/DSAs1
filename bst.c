

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
} *temp, *parent, *ptr;

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        return createnode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void inordertraversal(struct node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);
        printf("%d \t", root->data);
        inordertraversal(root->right);
    }
}
void preodertraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d \t", root->data);
        preodertraversal(root->left);
        preodertraversal(root->right);
    }
}
void postodertraversal(struct node *root)
{
    if (root != NULL)
    {
        postodertraversal(root->left);
        postodertraversal(root->right);
        printf("%d \t", root->data);
    }
}
struct node *succ(struct node *root)
{
    temp = root->right;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
// struct node* delete(struct node *root, int data)
// {

//     temp = root;
//     parent = NULL;
//     int flag = 0, Case;
//     while (temp != NULL && flag == 0)
//     {
//         if (data < temp->data)
//         {
//             parent = temp;
//             temp = temp->left;
//         }
//         if (data > temp->data)
//         {
//             parent = temp;
//             temp = temp->right;
//         }
//         if (temp->data == data)
//         {
//             flag = 1;
//         }
//     }
//     if (flag == 0)
//     {
//         printf("Element doesnot exits");
//         return root;
//     }
//     if (temp->left == NULL && temp->right == NULL)
//         Case = 1;
//     else if (temp->left != NULL && temp->right != NULL)
//         Case = 2;
//     else
//         Case = 3;

//     if (Case == 1)
//     {
//         if (parent->left == temp)
//         {
//             parent->left = NULL;
//             free(temp);
//         }
//         else
//         {
//             parent->right = NULL;
//             free(temp);
//         }
//             return;

//     }
//     if (Case == 2)
//     {
//         ptr = succ(temp);
//         temp->data = ptr->data;
//         delete (ptr, ptr->data);
//         return;
//     }
//     if (Case == 3)
//     {
//         if (parent->left == temp)
//         {
//             if (temp->left == NULL)
//             {
//                 parent->left = temp->right;

//             }
//             else
//             {
//                 parent->right = temp->left;
//             }
//         }
//         else if (parent->right == temp)
//         {
//             if (temp->left == NULL)
//             {
//                 parent->right = temp->right;
//             }
//             else
//             {
//                 parent->right = temp->left;
//             }
//         }
//         return;
//     }
// }
struct node *delete(struct node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (data < root->data)
    {
        root->left = delete (root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete (root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL || root == NULL)
        {
            if (root->left == NULL)
            {
                temp = root->right;
                free(root);
                return temp;
            }
            else
            {
                temp = root->left;
                free(root);
                return temp;
            }
        }
        else
        {
            temp = succ(root);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
    }

    return root;
}

void search(struct node *root, int key)
{
    if (root == NULL)
    {
        printf("Element  not Found !!");
        return;
    }

    if (root->data == key)
    {
        printf("Element Found !!");
    }
    if (key > root->data)
        search(root->right, key);
    if (key < root->data)
        search(root->left, key);
}

int empty(struct node *root)
{
    if (root == NULL)
    {
        printf("Treee is Empty!!");
        return 0;
    }
    else
        return 1;
}

int main()
{
    struct node *root = NULL;
    int data;

    int choice, value, s, f;
    printf("Enter your option :");
    do
    {
        printf("\n 1-Insert \n 2-Display \n 3-Search \n 4-delete \n 5-Exit");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter your value :");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Value %d inserted into bst :", value);
            break;
        case 2:
            printf("Inorder traversal :");
            inordertraversal(root);
            break;
        case 3:
            if (empty(root))
            {
                printf("Enter the element to search ?");
                scanf("%d", &s);
                search(root, s);
            }
            break;
        case 4:
          if (empty(root))
            {
            printf("Enter the Value to delete :");
            scanf("%d", &data);
            root = delete (root, data);
            }
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Entry !!");
        }
    } while (choice != 4);
}
