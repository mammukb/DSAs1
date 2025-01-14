#include <stdio.h>
#define MAX 10

int front = 0, rear = 0, q[MAX];

// Check if the queue is full
int isfull() {
    return (rear + 1) % MAX == front;
}

// Check if the queue is empty
int isempty() {
    return front == rear;
}

// Insert an element into the queue
void insert() {
    int x;
    if (isfull()) {
        printf("Queue is full\n");
        return;
    }
    printf("Enter the element: ");
    scanf("%d", &x);
    q[rear] = x;
    rear = (rear + 1) % MAX;
}

// Display the queue
void display() {
    if (isempty()) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    printf("Queue elements: ");
    do {
        printf("%d ", q[i]);
        i = (i + 1) % MAX;
    } while (i != rear);
    printf("\n");
}

// Delete an element from the queue
void delete() {
    if (isempty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted element: %d\n", q[front]);
    front = (front + 1) % MAX;
}

int main() {
    int c;
    while (1) {
        printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c) {
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
                printf("Invalid choice. Please try again.\n");
        }
    }
}
