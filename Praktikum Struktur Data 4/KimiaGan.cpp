#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
typedef long long int ll;
typedef unsigned long long llu;
typedef long double ld;
#define max 1500000
using namespace std;

int main(int argc, char const *argv[])
{
    unsigned long long t;
    scanf("%llu", &t);
    unsigned K[max];
    for (llu i=1; i<t; i++){
        K[i]=K[i-1]+(2*i*i);
    }
 
    for (llu i=1; i<=t; i++){
        unsigned long long N;
        scanf("%llu", &N);
        //binarysearch
        unsigned long long first=0, result=0, last = t, middle;
        while (first<=last){
            middle = (first+last)/2;
            if (K[middle] >= N){
                result = middle;
                last = middle-1;
            }
            else{
                first = middle+1;
            }
        }
        printf("%llu\n", result);
    }
    return 0;
}
