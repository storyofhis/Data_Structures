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

int main()
{
    map<int,int> map_int_int; //key : integer, value integer;
    map<int,string> map_int_string; //key : integer, value string;
    map<string,int> map_string_int; //key : string, value integer;

    for (int i = 1 ; i <= 5 ; i++)
    {
        map_int_int[i] = i * 5; // (key,value) = (1,5) , (2,10) , (3,15) , (4,20) , (5,25)
    }

    map_int_string[1] = "satu";
    map_int_string[2] = "dua";
    map_int_string[3] = "tiga"; // (key,value) = (1,"satu") , (2,"dua") , (3,"tiga")

    for (map<int,string>::iterator it = map_int_string.begin() ; it != map_int_string.end() ; ++it) // mengiterasi semua isi dari map_int_string
    {
        pair<int,string> cur = *it;
        map_string_int[cur.second] = cur.first; //(key,value) = ("satu",1) , ("dua",2) , ("tiga",3)
    }    

    cout << "ukuran map_int_string : " << map_int_string.size() << endl;
    map_int_string.clear();
    cout << "ukuran map_int_string setelah diclear : " << map_int_string.size() << endl;

    for (int i = 1 ; i <= 7 ; i++)
    {
        if (map_int_int.count(i))
            cout << "elemen dengan key " << i << " ada di dalam map" << endl;
        else
            cout << "elemen dengan key " << i << " tidak ada di dalam map" << endl; 
    }

    cout << "\n";

    // empty elements in random order
    map<int, int> g;

    // insert elements in random order 
    g.insert(pair<int, int>(1, 40));
    g.insert(pair<int, int>(2, 30));
    g.insert(pair<int, int>(3, 60));
    g.insert(pair<int, int>(4, 20));
    g.insert(pair<int, int>(5, 50));
    g.insert(pair<int, int>(6, 60));
    g.insert(pair<int, int>(7, 10));

    // printing map g
    map<int, int>::iterator itr;
    cout << "\n The map is\t:\n" << endl;
    cout << "\tKEY\tELEMENT : \n" << endl; 
    for (itr  = g.begin(); itr != g.end(); ++itr){
        cout << '\t' << itr->first << '\t' << itr->second << '\n';
    }
    cout << endl;
    
    // assigning the elements from g to key
    map<int, int> key (g.begin(), g.end());
    // print all elements to the map key
    cout << "\nThe map key sfter"<< " assign from g is : \n";
    cout << "\tKEY \tELEMENT\n";
    for (itr = key.begin(); itr != key.end(); ++itr){
        cout << '\t' << itr->first << '\t' << itr->second << '\n';
    }
    cout << endl;

    // remove all elements up to
    // element with key=3 in key
    cout << "\nkey after remove removal if"
            " elements less than key=3 : \n";
    cout << "\tKEY\tELEMENT\n";
    key.erase(key.begin(),key.find(3));
    for (itr = key.begin(); itr != key.end(); ++itr){
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    int num; 
    num = key.erase(4);
    cout << "\nkey.erase(4) : ";
    cout << num << " removed \n";
    cout << "\tKEY\tELEMENT";
    for (itr = key.begin(); itr != key.end(); ++itr){
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << endl;

    // lower bound and upper bound for map gquiz1 key = 5
    cout << "g.lower_bound(5) : "
         << "\tKEY = ";
    cout << g.lower_bound(5)->first << '\t';
    cout << "\tELEMENT = "
         << g.lower_bound(5)->second << endl;
    cout << "g.upper_bound(5) : "
         << "\tKEY = ";
    cout << g.upper_bound(5)->first << '\t';
    cout << "\tELEMENT = "
         << g.upper_bound(5)->second << endl;


    // map::insert({key, element});
    map<int, int> mp;
    // insert elements in random order
    mp.insert(pair<int, int>(2, 30));
    mp.insert(pair<int, int>(1, 40));
    mp.insert(pair<int, int>(3, 60));
    // does not inserts key 2 with element 20
    mp.insert(pair<int, int>(2, 20));
    mp.insert(pair<int, int>(5, 50));
    // prints the elements
    cout << "KEY\tELEMENT\n";
    for (auto itr = mp.begin(); itr != mp.end(); ++itr){
        cout << itr->first << '\t' << itr->second << '\n';
    }
    map<int, int> mp1;
    mp1.insert(mp.begin(), mp.end());
    cout << "Elements in mp1 are \n";
    cout << "KEY\tELEMENT\n";
    for (auto itr = mp1.begin(); itr != mp1.end(); ++itr){
        cout << itr->first << '\t' << itr->second << '\n';
    }

    // map::count() function
    if (mp.count(1)){
        cout << "The Key 1 is present\n";
    }else {
        cout << "The Key 1 is not present\n";
    }
    if (mp.count(2)){
        cout << "The Key 2 is present\n";
    }else {
        cout << "The Key 2 is not present\n";
    }
    if (mp.count(100))
        cout << "The key 100 is present\n";
    else
        cout << "The key 100 is not present\n";
    return 0;
}