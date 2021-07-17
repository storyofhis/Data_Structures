// #include <iostream>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <vector>
// #include <array>
// #include <cmath>
// #include <queue>
// #include <list>
// #include <string>
// #include <stack>
// #include <utility>
// #define pi 3.14159265
// #define pb push_back
// #define mod 1000000007
// #define mp make_pair
// #define INF 0x3f3f3f3f
// #define ff first
// #define ss second
// #define rep(i,a,b) for(ll i=a;i<b;i++)
// #define pq priority_queue
// typedef long long int ll;
// typedef unsigned long long int ull;
// typedef unsigned int ui;
// typedef std::vector<ll> vl;
// typedef std::vector<vl> vvl;
// typedef std::vector<bool> vb;
// typedef std::pair<ll, ll> pl;
// typedef std::list<ll> l;
// typedef std::map <ll, ll> ml;
// typedef std::list<ll>::iterator it;
// typedef std::list< pl > lpl;
// typedef std::stack<ll> st;
// typedef std::set<pl> spl;
// typedef l *adj;
// #define fr(it,a,b) for (it = adj[].begin(); it != adj[].end(); ++it)
// #define N 1000
// using namespace std;
// // source https://www.youtube.com/watch?v=yw0pttG9QjE
// ull MinCost (ull i, ull j, vector <vector <ull > > mat){
//     ull n = mat.size();
//     ull m = mat[0].size();

//     if (i == n - 1 and j == (m - 1)) return mat[i][j];
//     if (i >= n || j >= m) return N;
//     ull right = mat[i][j] + MinCost(i, j+1, mat);
//     ull left = mat[i][j] + MinCost(i+1, j, mat);
//     return min(right, left);
// }

// // source https://www.youtube.com/watch?v=t1shZ8_s6jc
// ull minCost (vector <vector <ull> > &grid){
//     ull rows = grid.size();
//     if (rows == 0)
//         return 0;
//     ull cols = grid[0].size();
//     vector < vector <ull> > dp(rows, vector <ull> (cols, 0));
//     ull i, j;
//     dp[0][0] = grid[0][0];
//     for (i = 1; i < cols; i++)
//         dp[0][i] = grid[0][i-1] + grid[0][i];
//     for (i = 1; i < rows; i++)
//         dp[i][0] = dp[i-1][0] + grid[i][0];
//     for (i=1; i < rows; i++){
//         for( j = 1; j < cols; j++)
//             dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
//     }
//     return dp[rows-1][cols-1];
// }

// // source https://github.com/ajahuang/UVa/blob/master/UVa%20929%20-%20Number%20Maze.cpp
// int arrx[] = {-1, 0, 1, 0};
// int arry[] = {0, 1, 0, -1};  
// class Edge {
//     public :     
//         ll i, j, cost;
//         // for std::priority_queue.
//         bool compare (const Edge &e) const
//         {    
//             return this->cost > e.cost;
//         }
// };

// int main(int argc, char const *argv[])
// {
//     ull q;
//     cin >> q;
//     for (int i = 0; i < q; i++){
//         ull n,m;
//         cin >> n >> m;

//         vector<vector <ull> > grid (n, vector <ull> (m,0));

//         for (ull i = 0; i < n; i++)
//             for (ull j = 0; j < m; j++)
//                 cin >> grid[i][j];
            
//         priority_queue <Edge, vector <Edge>, greater<Edge> > pq;
//         vector <vector <ull> > cost (n, vector <ull> (m, -1));

//         Edge e;
//         e.i = 0;
//         e.j = 0;
//         e.cost = grid[0][0];
//         pq.push(e);
//         cost[0][0] = e.cost;
//         while (!pq.empty()){
//             Edge v = pq.top();
//             pq.pop();
//             for (int i = 0; i < 4; i++){
//                 ull r = v.i + arrx[i];
//                 ull c = v.j + arry[i];
//                 if (r < 0 || r >= n || c < 0 || c >= m) 
//                     continue;
//                 if (cost[r][c] == -1 || cost[v.i][v.j] + grid[r][c] < cost[r][c]){
//                     cost[r][c] = cost[v.i][v.j] + grid[r][c];
//                     e.i = r;
//                     e.j = c;
//                     e.cost = cost[r][c];
//                     pq.push(e);
//                 }
//             }
//         }
//         cout << cost[n - 1][m - 1] << endl;
//     }
//     return 0;
// }


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Edge
{
    public:
        int r, c;
        int cost;
        // For std::priority_queue.
        bool operator>(const Edge &e) const
        {
            return this->cost > e.cost;
        }
};

int main()
{    
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int N, M;
        cin >> N >> M;
        int arrx[] = {-1, 0, 1, 0};
        int arry[] = {0, 1, 0, -1};
    

        vector<vector<int> > grid(N, vector<int>(M));

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                cin >> grid[i][j];

        priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
        vector<vector<int> > cost(N, vector<int>(M, -1));

        // Dijkstra's algorithm using min-heap.
        Edge e;
        e.r = 0;
        e.c = 0;
        e.cost = grid[0][0];
        pq.push(e);
        cost[0][0] = e.cost;
        while (!pq.empty())
        {
            Edge v = pq.top();
            pq.pop(); 
            for (int i = 0; i < 4; ++i)
            {
                int r = v.r + arrx[i];
                int c = v.c + arry[i];
                if (r < 0 || r >= N || c < 0 || c >= M)
                    continue;
                if (cost[r][c] == -1 || cost[v.r][v.c] + grid[r][c] < cost[r][c])
                {
                    cost[r][c] = cost[v.r][v.c] + grid[r][c];
                    e.r = r;
                    e.c = c;
                    e.cost = cost[r][c];
                    pq.push(e);
                }
            }
        }
        cout << cost[N - 1][M - 1] << endl;
    }
    return 0;
}
