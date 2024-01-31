#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Function to perform Depth-First Search
void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertex, bool visited[MAX_VERTICES], int numVertices) {
    printf("%d ", vertex);  // Print the current vertex

    visited[vertex] = true;  // Mark the current vertex as visited

    // Traverse all adjacent vertices
    for (int i = 0; i < numVertices; ++i) {
        // Check if there is an edge between the current vertex and vertex i
        // and if vertex i has not been visited yet
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(graph, i, visited, numVertices);  // Recursive call for unvisited adjacent vertices
        }
    }
}

int main() {
    int numVertices;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int graph[MAX_VERTICES][MAX_VERTICES];

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Array to keep track of visited vertices
    bool visited[MAX_VERTICES];
    for (int i = 0; i < numVertices; ++i) {
        visited[i] = false;
    }

    printf("DFS Traversal: ");

    // Start DFS from the first vertex (vertex 0)
    dfs(graph, 0, visited, numVertices);

    return 0;
}
