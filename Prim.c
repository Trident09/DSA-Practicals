/* Prim's Algorithm
    Create a priority queue and insert all the vertices of the graph, with the key of the vertex being set to infinity except for the starting vertex which has a key of 0.
    Create an empty minimum spanning tree and initialize it with the starting vertex.
    While the priority queue is not empty:
      a. Extract the vertex with the smallest key from the priority queue.
      b. For each neighboring vertex of the extracted vertex, update the key of the neighbor if the edge connecting the extracted vertex to the neighbor has a smaller weight than the current key of the neighbor.
      c. Add the extracted vertex to the minimum spanning tree.
    Return the minimum spanning tree. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES 10000

// structure for graph
struct Graph {
    int V;
    int** adj;
};

// create a graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (int**) malloc(V * sizeof(int*));
    int i;
    for (i = 0; i < V; i++) {
        graph->adj[i] = (int*) malloc(V * sizeof(int));
    }
    return graph;
}

// add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    graph->adj[src][dest] = weight;
    graph->adj[dest][src] = weight;
}

// find the vertex with the minimum key value
int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;
    int v;
    for (v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// print the minimum spanning tree
void printMST(int parent[], int V, int** graph) {
    printf("Edge \tWeight\n");
    int i;
    for (i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

// implement Prim's algorithm
void primMST(struct Graph* graph) {
    int V = graph->V;
    int key[V];
    int parent[V];
    bool mstSet[V];
    int i;
    for (i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    int v;
    for (v = 0; v < V - 1; v++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;
        int j;
        for (j = 0; j < V; j++) {
            if (graph->adj[u][j] && mstSet[j] == false && graph->adj[u][j] < key[j]) {
                parent[j] = u;
                key[j] = graph->adj[u][j];
            }
        }
    }
    printMST(parent, V, graph->adj);
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);
    primMST(graph);
    return 0;
}
