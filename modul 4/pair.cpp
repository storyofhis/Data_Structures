#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <array>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <utility>
#include <tuple>
using namespace std;

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
  
int main(int argc, char const *argv[])
{
    // declaring vector of pairs
    vector< pair <int, int> > vect;
  
    // Initialising 1st and 2nd element of pairs
    // with array values
    int arr[] = {10, 20, 5, 40 };
    int arr1[] = {30, 60, 20, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
  
    // Entering values in vector of pairs
    for (int i=0; i<n; i++)
        vect.push_back( make_pair(arr[i],arr1[i]) );
  
    // Printing the original vector(before sort())
    cout << "The vector before sort operation is:\n" ;
    for (int i=0; i<n; i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vect[i].first << " "
             << vect[i].second << endl;
  
    }
  
    // Using sort() function to sort by 2nd element
    // of pair
    sort(vect.begin(), vect.end(), sortbysec);
  
    // Printing the sorted vector(after using sort())
    cout << "The vector after sort operation is:\n" ;
    for (int i=0; i<n; i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vect[i].first << " "
             << vect[i].second << endl;
    }


    // SWAP 

    pair<char, int> pair1 = make_pair( 'A', 1);
    pair<char, int> pair2 = make_pair( 'B', 2);
    pair<int, int> p = make_pair(1,2);

    cout << "Before swapping:\n " ;
    cout << "Contents of pair1 = " 
         << pair1.first << " " << pair1.second ;
    cout << "Contents of pair2 = " 
         << pair2.first << " " << pair2.second ;
    pair1.swap(pair2);
  
    cout << "\nAfter swapping:\n ";
    cout << "Contents of pair1 = " 
         << pair1.first << " " << pair1.second ;
    cout << "Contents of pair2 = " 
         << pair2.first << " " << pair2.second ;
    cout << endl;

    return 0;
}