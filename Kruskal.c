/* Kruskal's Algorithm
    Sort the edges of the graph by weight in non-decreasing order
    Initialize an empty minimum spanning tree
    Initialize the Union-Find data structure, with each vertex in the graph as a separate component.
    For each edge in the sorted list:
      a. If the edge connects two different connected components, add it to the minimum spanning tree, and union the two components
      b. If the edge connects two vertices that are already in the same component, ignore it
    Return the minimum spanning tree */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 10000

// edge structure
struct Edge {
    int src, dest, weight;
};

// structure for graph
struct Graph {
    int V, E;
    struct Edge* edge;
};

// create a graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc(E * sizeof(struct Edge));
    return graph;
}

// find set of an element i
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// union of two sets
void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    if (xset != yset)
        parent[xset] = yset;
}

// compare two edges according to their weights
int cmp(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*) a;
    struct Edge* b1 = (struct Edge*) b;
    return a1->weight > b1->weight;
}

// Kruskal's algorithm
void Kruskal(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), cmp);
    int *parent = (int*) malloc(V * sizeof(int));
    memset(parent, -1, sizeof(parent));
    while (e < V - 1) {
        struct Edge next_edge = graph->edge[i++];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            Union(parent, x, y);
        }
    }
    // printing the minimum spanning tree
    printf("Minimum Spanning Tree:\n");
    for (i = 0; i < e; ++i) {
        printf("%d - %d : %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main() {
    int V = 4;
    int E = 5;
    struct Graph* graph = createGraph(V, E);
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;
    Kruskal(graph);
    return 0;
}
