/* The algorithm for depth-first search (DFS) is as follows:
    Create a stack and add the starting vertex to it.
    Create a set or array to keep track of the visited vertices.
    While the stack is not empty:
      a. Pop the top vertex from the stack.
      b. If the vertex has not been visited, mark it as visited and add it to the set or array.
      c. Push all of the vertex's unvisited neighbors onto the stack. */

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// graph
struct Graph {
    int V;
    struct AdjList* array;
};

// create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// create a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
    int i;
    for (i = 0; i < V; i++)
        graph->array[i].head = NULL;
    return graph;
}

// add an edge to a directed graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// depth-first search
void dfs(struct Graph* graph, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);
    struct AdjListNode* temp = graph->array[v].head;
    while (temp) {
        int u = temp->dest;
        if (!visited[u]) {
            dfs(graph, u, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    int visited[V];
    int i;
    for (i = 0; i < V; i++) {
        visited[i] = 0;
    }
    dfs(graph, 0, visited);
    return 0;
}