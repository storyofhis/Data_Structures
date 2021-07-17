#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <cmath>
#include <list>
#include <string>
#include <stack>
#include <utility>
#define pi 3.14159265
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define fill(a, b) memset(a, b, sizeof(a))
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long int ull;
typedef std::vector<ll> vl;
typedef std::vector<vl> vvl;
typedef std::vector<bool> vb;
typedef std::pair<ll, ll> pl;
typedef std::list<ll> l;
typedef std::map <ll, ll> ml;
typedef std::list<ll>::iterator it;
typedef std::list< pl > lpl;
typedef std::stack<ll> st;
typedef std::set<pl> spl;
typedef l *adj;
#define fr(it,a,b) for (it = adj[].begin(); it != adj[].end(); ++it)
using namespace std;

#define INT_MIN -2147483648

int sumHist(int* arr, int* start, int* finish, int N)
{
    int sum = 0, maxSum = INT_MIN, i;
    *finish = -1;
    int local_start = 0;
    for (i=0; i<N; ++i){
        sum += arr[i];
        if (sum < 0){
            sum = 0;
            local_start = i + 1;
        }
        else if (sum > maxSum){
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }
 
    if (*finish != -1)
        return maxSum;
 
    maxSum = arr[0];
    *start = *finish = 0;
 
    for (i=1; i<N; i++){
        if (arr[i] > maxSum){
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}
void findMaxSum(int N, int **matrix)
{
    int max = INT_MIN,
        left, right, top, bottom,
        temp[N], sum, start, finish;
    for (int i = 0; i < N; ++i){
        memset(temp, 0, sizeof(temp));
        for (int j = i; j < N; ++j){
            for (int k = 0; k < N; ++k)
                temp[k] += matrix[k][j];
            sum = sumHist(temp, &start, &finish, N);
            if (sum > max){
                max = sum;
                left = i;
                right = j;
                top = start;
                bottom = finish;
            }
        }
    }
    cout <<  max << endl;
}
 


int main(int argc, char const *argv[]){
    int N, **matrix;
    cin >> N;
    
    for (int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> matrix[i][j];
        }
    }
    findMaxSum(N, matrix);
    return 0;
}











// int func (int arr[], int n){
//     int current = arr[0], max = arr[0];
//     for (int i = 1; i <= n; ++i){
//         if (current < 0)
//             current = arr[i];
//         if (current > max)
//             max = current;
//         else 
//             current += arr[i];
        
//     }
//     return max;    
// }
// int main(int argc, char const *argv[]){
//     int N;
//     cin >> N;
//     int Matrix[N][N], temp[N], left, right;
//     for (int i=0; i<N; i++)
//         for(int j=0; j<N; j++)
//             cin >> Matrix[i][j];

//     int max = INT_MIN;
//     int result ;

//     for (left = 0; left < N; left++){
//         memset(temp, 0, sizeof(temp)); 
//         for (right = left; right < N; right++){
//             for (int i = 0; i < N; i++){
//                 temp[i] += Matrix[i][right];
//             }
//             result = func(temp, N);
//             if (result > max){
//                 max = result;
//             }
//         }
//     }

//     cout << max << endl;
//     return 0;
// }



// int potention(int a[],int n){
//     int current =a[0], max =a[0];
//     for(int i=1; i < n; i++){
//         if(current  < 0){
//             current =a[i];
//         }
//         else{
//             current += a[i];
//         }
//         if(current > max){
//             max = current;
//         }
//     }
//     return max;
// }

// int main(int argc, char const *argv[])
// {
//     int N;
//     cin >> N;
//     int x [N][N];
//     for(int i=0;i<N;i++)
//         for(int j=0;j< N;j++)
//             cin >> x [i][j];

//     int max = INT_MIN;
//     int left, right, sum, temp[N];


//     for(left=0;left< N;left++){
//         memset(temp,0,sizeof(temp));
//         for(right=left;right< N;right++){
//             for(int i=0;i< N;i++)
//                 temp[i] += x[i][right];

//             sum = potention(temp,N);
//             if(sum > max){
//                 max = sum;
//             }
//         }
//     }

//     cout << max << endl;

//     return 0;
// }