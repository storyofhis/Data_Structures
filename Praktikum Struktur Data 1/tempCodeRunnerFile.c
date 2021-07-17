#include <stdio.h>
void func(long long int arr[], long long int n, long long int k)
{
    long long int j, i;
    long long int max;
    long long int size = (n - k) + 1; 
    for(i = 0; i < size; i++)
    {
        max= arr[i];
        for(j = 1; j < k; j++)
        {
            if(arr[i + j] > max)
            {
                max = arr[i + j];
            }
        }
        printf("%lld ",max);
    }
}
 
int main(int argc, char const *argv[]){
    long long int n;
    scanf("%lld", &n);
    long long int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    long long int k;
    scanf("%lld", &k);
    func(arr, n, k);
    puts("");
    return 0;
}
