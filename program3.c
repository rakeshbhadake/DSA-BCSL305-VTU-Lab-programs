#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int a[MAX];
int top = -1;
char n;

// Function to push an item onto the stack
void push(int item) {
    if (top == (MAX - 1)) {
        printf("STACK OVERFLOW\n");
        return;
    }
    top = top + 1;
    a[top] = item;
}

// Function to pop an item from the stack
int pop() {
    if (top == -1) {
        printf("STACK UNDERFLOW\n");
        return  n;
    }
    int item = a[top];
    top = top - 1;
    return item;
}

// Function to display the stack elements
void display() {
    if (top == -1) {
        printf("STACK IS EMPTY\n");
        return;
    }
    printf("STACK ELEMENTS ARE:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Function to check if the stack elements form a palindrome
void cpalindrome() {
    int flag = 1;
    printf("STACK ELEMENTS ARE:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d ", a[i]);
    }
    printf("\nREVERSE STACK ELEMENTS ARE:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d ", a[i]);
    }
    for (int i = 0; i <= top / 2; i++) {
        if (a[i] != a[top - i]) {
            flag = 0;
            break;
        }
    }
    if (flag == 1) {
        printf("\nIt is a Palindrome\n");
    } else {
        printf("\nIt is not a Palindrome\n");
    }
}

// Main function to drive the menu
int main() {
    int choice, item;
    while (1) {
        printf("\nMENU\n");
        printf("1: Push\t2: Pop\t3: Display\t4: Check Palindrome\t5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if (item != n) {
                    printf("Item popped: %d\n", item);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                cpalindrome();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
