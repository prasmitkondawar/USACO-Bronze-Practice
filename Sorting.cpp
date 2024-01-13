#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define ll long long 
using namespace std;

// Selection Sort
// The outer loop goes for n steps  i form 0 to n-1
// In the ith step the ith minimum element is brought to ith position 
void Selection_Sort()
{
    int n;cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int swaps=0;
    for(int i=0;i<n;i++)
    {
        int mni=i;
        for(int j=i+1;j<n;j++)
        {
            if(v[j]<v[mni]) mni=j;
        }
        if(i!=mni)
        {
            swaps++;
            swap(v[i],v[mni]);
        }
    }

    for(int i=0;i<n;i++) cout<<v[i]<<' ';

    //  if all the number in the input are distinct then it given minimum number of swaps to sort the arrat
    cout<<swaps<<"\n";
}
// Insertion Sort
// The outer loop goes for n steps  i form 0 to n-1
// In the ith step the prefix upto i gets sorted , i+1 to n-1 index are not even touched
void Insertion_Sort()
{
    int n;cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(j>0 && v[j]<v[j-1]) 
        {
            swap(v[j],v[j-1]);
            j--;
        }
    }
    for(int i=0;i<n;i++) cout<<v[i]<<' ';
}

// Bubble Sort
// The outer loop goes for n steps  i form 0 to n-1
// we swap consecutive elements which do not satisfy a[i] <= a[i+1] , we can break out if we don't find any such i
void Bubble_sort()
{
    int n;cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++)
    {
        bool is_sorted = false;
        for(int j=1;j<n;j++)
        {
            if(v[j]<v[j-1])
            {
                is_sorted = false;
                swap(v[j],v[j-1]);
            }
        }
        if(is_sorted) break;
    }
}

void sort_lib()
{
    // Nlog2N ALgo's , Merge Sorts
    int n;cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    // sort all in asceding order
    sort(v.begin(),v.end());
    // sort only from ith to jth elements
    int i,j;
    sort(v.begin()+i,v.begin()+j+1);
    // sort all in descending order
    sort(v.rbegin(),v.rend());

    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    // sorts the array in ascending order
    sort(a,a+n);
}
bool cmp(int a,int b)
{
    int sum_of_digits_a=0;
    while(a > 0)
    {
        int d=a%10;
        sum_of_digits_a += d;
        a/=10;
    }
    int sum_of_digits_b=0;
    while(b > 0)
    {
        int d=b%10;
        sum_of_digits_b += d;
        b/=10;
    }
    return sum_of_digits_a < sum_of_digits_b;
}
bool Cmp(pair <int,int> a, pair <int,int> b)
{
    if(a.first == b.first) return a.second > b.second;
    else                   return a.first  < b.first;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;cin>>n;
   vector <pair <int,int>> v(n);
   for(int i=0;i<n;i++)
   {
     cin>>v[i].first>>v[i].second;
   }
   sort(v.begin(),v.end(),Cmp);
   for(int i=0;i<n;i++) cout<<v[i].first<<' '<<v[i].second<<"\n";
}

// Implement Merge Sort and also count the number inversion in the vector 
