// TOPIC : std::array

// syntax : std::array<TypeData, size> array;

// NOTICE : 
// 1. std::array is a container that encapsulates fixed size arrays.
// class array {
//     DataType arr[];
//     ...
//     ...
// };
// 2. arraySize is needed at compile time.
// 3. Assign by Value is actually by value.
// 4. Access Element: 
//      a. at()
//      b. []
//      c. front()
//      d. back()
//      e. data() // gives access to the underlying array


// Operations on array :
// 1. at() :- This function is used to access the elements of array.
// 2. get() :- This function is also used to access the elements of array. This function is not the member of array class but overloaded function from class tuple.
// 3. operator[] :- This is similar to C-style arrays. This method is also used to access array elements.
// 4. front() :- This returns the first element of array.
// 5. back() :- This returns the last element of array.
// 6. size() :- It returns the number of elements in array. This is a property that C-style arrays lack.
// 7. max_size() :- It returns the maximum number of elements array can hold i.e, the size with which array is declared. The size() and max_size() return the same value
// 8. swap() :- The swap() swaps all elements of one array with other.
// 9. empty() :- This function returns true when the array size is zero else returns false.
// 10. fill() :- This function is used to fill the entire array with a particular value.

// src= https://www.geeksforgeeks.org/array-class-c/
#include <iostream>
#include <array>
#include <algorithm>
#include <set>
using namespace std;
int main(int argc, char const *argv[])
{
    // Initialization
    array<int, 4> angka = {1,2,3,4};
    array<int, 4> genap = {2,4,6,8};
    array<int, 4> ganjil = {1,3,5,7};
    array<int, 4> kosong;

    cout << "Isi array \"angka\"\t\t\t:";
    for (int i = 0; i < 4; i++)
        cout << ' ' << angka[i];
    cout << '\n';

    cout << "Elemen ke-2 (operator[])\t\t: " << angka[1] << endl;
    cout << "Elemen ke-2 (at())\t\t\t: " << angka.at(1) << endl;
    cout << "Elemen pertama\t\t\t\t: " << angka.front() << endl;
    cout << "Elemen terakhir\t\t\t\t: " << angka.back() << endl;
    // was return the pointer of that array
    cout << "gives access to the underlying array\t: " << *(angka.data()) << endl;

    angka.front() = 100;
    angka.at(2) = 200;
    angka.back() = 400;

    cout << "Isi array \"angka\" sekarang\t\t:";
    for (auto i = angka.begin(); i != angka.end(); ++i){
        cout << ' ' << *i;
    }cout << '\n';


    return 0;
}
