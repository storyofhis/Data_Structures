// Src : https://www.geeksforgeeks.org/program-to-count-number-of-connected-components-in-an-undirected-graph/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <iterator>
#include <list>
#include <queue>
#include <array>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <tuple>
#include <iostream>
#include <stack>
typedef long long int ll;
typedef long double ld;
using namespace std;

class Graph {
    int V;
    list<int>* adj;
    void DFSUtil(int v, bool visited[]);
 
    public:
        Graph(int V);
        void addEdge(int v, int w);
        void NumberOfconnectedComponents();
};
void Graph::NumberOfconnectedComponents()
{
    bool* visited = new bool[V];
    int count = 0;
    for (int v = 0; v < V; v++)
        visited[v] = false;
    for (int v = 0; v < V; v++) {
        if (!visited[v]) {
            DFSUtil(v, visited);
            count += 1;
        }
    }
    cout <<  count - 1 << endl;
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
int main(int argc, char const *argv[]){
    // p = vertex
    int p, t;
    cin >> p >> t;
    int a, b;
    Graph g(p);
    for (int i = 0; i < t; i++){
        cin >> a >> b;
        g.addEdge(a-1, b-1);
    }
    g.NumberOfconnectedComponents();
    return 0;
}












// #define N 100000
  
// // To keep correct and reverse direction
// vector<int> gr1[N], gr2[N];
  
// bool vis1[N], vis2[N];

// class Graph{
//     int V;
//     list<int> *adj;
//     void DFSUtil (int v, bool visited[]);

//     public:
//         Graph(int V);
//         void addEdge(int v, int w);
//         int NumberOfConnect();
// };


// // Function to add edges
// void Add_edge(int u, int v)
// {
//     gr1[u].push_back(v);
//     gr2[v].push_back(u);
// }
  
// // DFS function
// void dfs1(int x)
// {
//     vis1[x] = true;
  
//     for (auto i : gr1[x])
//         if (!vis1[i])
//             dfs1(i);
// }
  
// // DFS function
// void dfs2(int x)
// {
//     vis2[x] = true;
  
//     for (auto i : gr2[x])
//         if (!vis2[i])
//             dfs2(i);
// }
  
// bool Is_Connected(int n)
// {
//     memset(vis1, false, sizeof vis1);
//     dfs1(1);
//     memset(vis2, false, sizeof vis2);
//     dfs2(1);
  
//     for (int i = 1; i <= n; i++) {
//         if (!vis1[i] and !vis2[i])
//             return false;
//     }
//     return true;
// }

  
// // Driver code
// int main(int argc, char const *argv[])
// {
//     int n = 4;
//     int p, t, a, b;
//     int i, j;
//     scanf("%d %d", &p, &t);
//     for (i = 0; i < t; i++){
//         scanf("%d  %d", &a, &b);
//         Add_edge(a, b);
//     }  
//     // Function call
//     if (!Is_Connected(t)){
//         Graph g(t);
        
//     }else
//         return 0;
  
//     return 0;
// }













// bool isConnected(){
    
// }

// int main(int argc, char const *argv[])
// {
//     int p, t, a, b;
//     int matrix[1001][1001];
//     bool find, nullAll;
//     int src, dest, i, j;
//     // input vertex (p) and edge (t);
//     scanf("%d %d", &p, &t);
//     for (i = 0; i < p; i++){
//         for (int j = 0; j < p; j++){
//             matrix[i][j] = 0;
//         }
//     }
//     // addEdge
//     for (i = 1; i<= t; i++){
//         scanf("%d %d", &a, &b);
//         matrix[a][b] = 1;
//         matrix[b][a] = 1;
//     }
//     i = 1;
//     nullAll = false;
//     while(i<=p && nullAll==false){
//         j = 1;
//         find = false;
//         while (j <= p && find == false){
//             if (matrix[i][j] == 1){
//                 find = true;
//             }
//             else{
//                 j++;
//             }
//         }
//         if (find == false){
//             nullAll = true;
//         }else {
//             i++;
//         }
//     }
//     if (nullAll == true){
//         printf("not connection\n");
//     }else {
//         printf("connection\n");
//     }
//     return 0;
// }



// #define NODE 5
// using namespace std;
// // int graph[NODE][NODE] = {{0, 1, 0, 0, 0},
// //    {0, 0, 1, 0, 0},
// //    {0, 0, 0, 1, 1},
// //    {1, 0, 0, 0, 0},
// //    {0, 1, 0, 0, 0}
// // };
// int matrix[1001][1001];

// void traverse(int u, bool visited[]){
//    visited[u] = true; //mark v as visited
//    for(int v = 0; v<NODE; v++){
//       if(matrix[u][v]){
//          if(!visited[v])
//          traverse(v, visited);
//       }
//    }
// }
// bool isConnected(int p){
//     bool *vis = new bool[p];
//     //for all vertex u as start point, check whether all nodes are visible or not
//     for(int u; u < p; u++){
//         for(int i = 0; i<p; i++)
//         vis[i] = false; //initialize as no node is visited
//         traverse(u, vis);
//         for(int i = 0; i<p; i++){
//             if(!vis[i]) //if there is a node, not visited by traversal, graph is not connected
//             return false;
//         }
//     }
//     return true;
// }
// int main(int argc, char const *argv[]){
//     // p = vertex
//     // t = edge
//     int p, t, a, b;
//     bool find, nullAll;
//     int src, dest, i, j;
//     scanf("%d %d", &p, &t);
//     for (i = 0; i < p; i++){
//         for (j = 0; j < p; j++){
//             matrix[i][j] = 0;
//         }
//     }
//     // addEdge
//     for (i = 0; i < t; i++){
//         scanf("%d %d", &a, &b);
//         matrix[i][j] = 1;
//         matrix[j][i] = 1;
//     }
//     i = 1;
//     nullAll = false;
//     while(i <= p && nullAll == false){
//         j = 1;
//         find = false;
//         while (j <= p && find == false){
//             if (matrix[i][j] == 1){
//                 find = true;
//             }else {
//                 j++;
//             }
//         }
//         if (find == false){
//             nullAll = true;
//         }else {
//             i++;
//         }
//     }
//     if(isConnected(p))
//         cout << "The Graph is connected.";
//     else
//         cout << "The Graph is not connected.";
// }


