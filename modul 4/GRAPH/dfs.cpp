#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <array>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
// This program shows off a basic BFS implementation in C++
// By: Nick from CoffeeBeforeArch
using std::cout;
using std::endl;
using std::list;
using std::vector; 

// using namespace std;

// class Graph{
//     private:
//         // Number of vertices
//         int V;
//         // Pointer to adjacency list
//         list<int> *adj;
//         // DFS recursive helper functions
//         void DFS_helper(int s, bool *visited);

//     public:
//         // Constructor prototype
//         Graph(int v);

//         // Method to add an edge
//         void addEdge(int v, int w);

//         // Method for BFS traversal give a source "s"
//         void DFS(int s);
// };

// // Constructer with number of vertices
// Graph::Graph(int v){
//     // Set number of vertices
//     this->V = v;

//     // Create new adjacency list
//     adj = new list<int>[v];
// }

// // Implementation of method to add edges
// void Graph::addEdge(int v, int w){
//     adj[v].push_back(w);
// }

// void Graph::DFS_helper(int s, bool *visited){
//     // Mark the current node as visited
//     cout << "Visiting node " << s << endl;
//     visited[s] = true;

//     // Go through the adjacency list
//     for(auto i = adj[s].begin(); i != adj[s].end(); i++){
//         // If not visited, travel through that vertex
//         if(!visited[*i]){
//             cout << "Going to vertex " << *i << " from vertex " << s << endl;
//             DFS_helper(*i, visited);
//         }
//     }
// }

// // Perform BFS given a starting vertex
// void Graph::DFS(int s){
//     // Start with all vertices as not visited
//     bool *visited = new bool[V];
//     for(int i = 0; i < V; i++){
//         visited[i] = false;
//     }

//     // Beginning of recursive call
//     DFS_helper(s, visited);
// }

// int main(){
//     // Create a new graph
//     Graph g(6);

//     // Create some edges to the vertices
//     // Connections for vertex 0
//     g.addEdge(0, 1);
//     g.addEdge(0, 2);

//     // Connections for vertex 1
//     g.addEdge(1, 0);
//     g.addEdge(1, 3);
//     g.addEdge(1, 4);

//     // Connections for vertex 2
//     g.addEdge(2, 0);
//     g.addEdge(2, 4);

//     // Connections for vertex 3
//     g.addEdge(3, 1);
//     g.addEdge(3, 4);
//     g.addEdge(3, 5);

//     // Connections for vertex 4
//     g.addEdge(4, 1);
//     g.addEdge(4, 2);
//     g.addEdge(4, 3);
//     g.addEdge(4, 5);

//     // Connections for vertex 5
//     g.addEdge(5, 3);
//     g.addEdge(5, 4);

//     // Perform DFS and print result
//     g.DFS(0);
    
//     return 0;
// }



// Cara 2 (Depth First Search)
// template<typename T>
// class Graph{

//     map<T, list<T> > l;
//     public: 
//         void addEdge(int x, int y){
//             l[x].push_back(y);
//             l[y].push_back(x);
//         }
//         void dfs_helper(T src, map<T, bool> &visited){
//             // Recursive function that will traverse the graph
//             cout << src << " ";
//             visited[src] = true;
//             // go to any nbr of that node that is not visited
//             for (T nbr:l[src]){
//                 if (!visited[nbr]){
//                     dfs_helper(nbr, visited);
//                 }
//             }

//         }
//         void dfs(T src){
//             map<T, bool> visited;
//             // Mark all the nodes as visited in the beginning
//             for (auto p:l){
//                 T node = p.first;
//                 visited[node] = false;
//             }
//             // call the helper function
//             dfs_helper(src, visited);

//         }

// };

// int main(int argc, char const *argv[])
// {
//     Graph<int> g;
//     g.addEdge(0, 1);
//     g.addEdge(1, 2);
//     g.addEdge(2, 3);
//     g.addEdge(3, 4);
//     g.addEdge(4, 5);
//     g.addEdge(3, 0);

//     g.dfs(0);
    
//     return 0;
// }



// DFS algorithm in C
// struct node {
//   int vertex;
//   struct node* next;
// };

// struct node* createNode(int v);

// struct Graph {
//   int numVertices;
//   int* visited;

//   // We need int** to store a two dimensional array.
//   // Similary, we need struct node** to store an array of Linked lists
//   struct node** adjLists;
// };

// // DFS algo
// void DFS(struct Graph* graph, int vertex) {
//   struct node* adjList = graph->adjLists[vertex];
//   struct node* temp = adjList;

//   graph->visited[vertex] = 1;
//   printf("Visited %d \n", vertex);

//   while (temp != NULL) {
//     int connectedVertex = temp->vertex;

//     if (graph->visited[connectedVertex] == 0) {
//       DFS(graph, connectedVertex);
//     }
//     temp = temp->next;
//   }
// }

// // Create a node
// struct node* createNode(int v) {
//   struct node* newNode = malloc(sizeof(struct node));
//   newNode->vertex = v;
//   newNode->next = NULL;
//   return newNode;
// }

// // Create graph
// struct Graph* createGraph(int vertices) {
//   struct Graph* graph = malloc(sizeof(struct Graph));
//   graph->numVertices = vertices;

//   graph->adjLists = malloc(vertices * sizeof(struct node*));

//   graph->visited = malloc(vertices * sizeof(int));

//   int i;
//   for (i = 0; i < vertices; i++) {
//     graph->adjLists[i] = NULL;
//     graph->visited[i] = 0;
//   }
//   return graph;
// }

// // Add edge
// void addEdge(struct Graph* graph, int src, int dest) {
//   // Add edge from src to dest
//   struct node* newNode = createNode(dest);
//   newNode->next = graph->adjLists[src];
//   graph->adjLists[src] = newNode;

//   // Add edge from dest to src
//   newNode = createNode(src);
//   newNode->next = graph->adjLists[dest];
//   graph->adjLists[dest] = newNode;
// }

// // Print the graph
// void printGraph(struct Graph* graph) {
//   int v;
//   for (v = 0; v < graph->numVertices; v++) {
//     struct node* temp = graph->adjLists[v];
//     printf("\n Adjacency list of vertex %d\n ", v);
//     while (temp) {
//       printf("%d -> ", temp->vertex);
//       temp = temp->next;
//     }
//     printf("\n");
//   }
// }

// int main() {
//   struct Graph* graph = createGraph(4);
//   addEdge(graph, 0, 1);
//   addEdge(graph, 0, 2);
//   addEdge(graph, 1, 2);
//   addEdge(graph, 2, 3);

//   printGraph(graph);

//   DFS(graph, 2);

//   return 0;
// }