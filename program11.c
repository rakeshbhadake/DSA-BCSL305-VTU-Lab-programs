/****11. Develop a Program in C for the following operations on Graph(G) of Cities
 a. Create a Graph of N cities using Adjacency Matrix.
 b. Print all the nodes reachable from a given starting node in a digraph using
 DFS/BFS method****/


#include <stdio.h>
#include <stdlib.h>

int a[50][50], n, bvisited[50], dvisited[50]; // Adjacency matrix and visited arrays for BFS and DFS
int q[20], front = -1, rear = -1; // Queue for BFS
int s[20], top = -1; // Stack for DFS

// Breadth-First Search (BFS) function
void bfs(int v) {
    int i, cur;
    bvisited[v] = 1; // Mark the starting node as visited
    q[++rear] = v; // Enqueue the starting node
    printf("%d ", v);
    while (front != rear) { 
        cur = q[++front]; // Dequeue a node
        for (i = 1; i <= n; i++) {
            if (a[cur][i] == 1 && bvisited[i] == 0) { // If the node is connected and not visited
                q[++rear] = i; // Enqueue the node
                bvisited[i] = 1; // Mark the node as visited
                printf("%d ", i);
            }
        }
    }
}

// Depth-First Search (DFS) function
void dfs(int v) {
    int i;
    dvisited[v] = 1; // Mark the starting node as visited
    s[++top] = v; // Push the node onto the stack
    printf("%d ", v);
    for (i = 1; i <= n; i++) {
        if (a[v][i] == 1 && dvisited[i] == 0) { // If the node is connected and not visited
            dfs(i); // Recur for the connected node
        }
    }
}

// Main function
int main() {
    int ch, start, i, j;
    printf("\nEnter the number of vertices in the graph: ");
    scanf("%d", &n); // Input the number of vertices
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]); // Input the adjacency matrix
        }
    }
    for (i = 1; i <= n; i++) {
        bvisited[i] = 0; // Initialize BFS visited array
        dvisited[i] = 0; // Initialize DFS visited array
    }
    printf("\nEnter the starting vertex: ");
    scanf("%d", &start); // Input the starting vertex
    while (1) {
        printf("\nMENU");
        printf("\n==>1. BFS: Print all nodes reachable from a given starting node");
        printf("\n==>2. DFS: Print all nodes reachable from a given starting node");
        printf("\n==>3: Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch); // Input the choice
        switch (ch) {
            case 1:
                printf("\nNodes reachable from starting vertex %d are: ", start);
                bfs(start); // Call BFS function
                break;
            case 2:
                printf("\nNodes reachable from starting vertex %d are: ", start);
                dfs(start); // Call DFS function
                break;
            case 3:
                exit(0); // Exit the program
            default:
                printf("\nPlease enter a valid choice.");
        }
    }
}
