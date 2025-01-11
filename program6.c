/**** 6. Develop a menu driven Program in C for the following operations on Circular QUEUE
 of Characters (Array Implementation of Queue with maximum size MAX).
 a. Insert an Element on to Circular QUEUE
 b. Delete an Element from Circular QUEUE
 c. Demonstrate Overflow and Underflow situations on Circular QUEUE
 d. Display the status of Circular QUEUE
 e. Exit
 Support the program with appropriate functions for each of the above operations****/


#include <stdio.h>
#include <stdlib.h>

#define N 5
char queue[N];
int front = -1, rear = -1;

void enque(char x) {
    if ((rear + 1) % N == front) {
        printf("Queue is overflow\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void deque() {
    if (front == -1 && rear == -1) {
        printf("\nQueue is empty\n");
    } else if (front == rear) {
        printf("Dequeued element is: %c\n", queue[front]);
        front = rear = -1;
    } else {
        printf("Dequeued element is: %c\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display() {
    int i;
    if (front == -1 && rear == -1) {
        printf("\nQueue is empty\n");
    } else {
        printf("Queue elements are:\n");
        i = front;
        while (i != rear) {
            printf("%c\t", queue[i]);
            i = (i + 1) % N;
        }
        printf("%c\t", queue[rear]);
        printf("\nFront position: %d", front);
        printf("\nRear position: %d\n", rear);
    }
}

int main() {
    char item;
    int choice;
    while (1) {
        printf("\nQueue operations\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("Enter the character to insert:\n");
                scanf(" %c", &item);
                enque(item);
                break;
            case '2':
                deque();
                break;
            case '3':
                display();
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
