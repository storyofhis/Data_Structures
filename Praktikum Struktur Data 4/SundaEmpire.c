#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef long long int ll;
typedef long double ld;
struct node{
    int vertex;
    struct node *next;
};
struct node *createNode(int v);
struct Graph {
    int numVertices;
    int* visited;

    // We need int** to store a two dimensional array.
    // Similary, we need struct node** to store an array of Linked Lists.
    struct node** adjLists; // * a pointer and * a tag for an array;
};
void dfs(struct Graph* graph, int vertex){
    struct node *adjList = graph->adjLists[vertex];
    struct node *temp = adjList;

    graph->visited[vertex] = 1;
    printf("%d \n", vertex);

    while(temp != NULL){
        if(graph->visited[temp->vertex] == 0){
            dfs(graph, temp->vertex);
        }
        temp = temp->next;
    }
}
// Create Node;
struct node* createNode(int v){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
// Create Graph;
struct Graph *createGraph(int vertices){
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));

    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
    int v;
    for (v = 0; v < graph->numVertices; v++) {
        struct node* temp = graph->adjLists[v];
        printf("\nAdjacency list of vertex %d\n ", v);
        while (temp) {
        printf("%d -> ", temp->vertex);
        temp = temp->next;
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int p, t, a, b;
    scanf("%d", &p);
    scanf("%d", &t);
    struct Graph* graph = createGraph(t);
    for (int i = 0; i < t; i++){
        scanf ("%d %d", &a, &b);
        addEdge(graph, a, b);
    }
    printGraph(graph);

    dfs(graph, 2);
    return 0;
}
