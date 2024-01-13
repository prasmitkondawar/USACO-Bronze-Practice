#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define ll long long 
using namespace std;

void SetUse()
{
    int n;cin>>n;
    set <int> s;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        s.insert(x);
    }
    int x;
    // s.begin() address of first (smallest) element in the set
    // *s.begin() will give value of first element 
    // x=s.size();
    // cout<<x<<"\n";
    // for(auto it=s.begin();it!=s.end();++it)
    // {
    //     cout<< *it <<' '<< &(*it) <<"\n";
    // }
    // // When we iterate through set we see elements are in sorted order but the address is in random order
    // // When we iterate through vector we see the address is consecutive
    // // s.find(x) tells us whether the element x is present in the set or not 
    // if(s.find(x)!=s.end())
    // {
    //   cout<<x<<' '<<"is present";
    // }
    // // s.lower_bound(x) -> address of first element y such that y>=x
    // // s.upper_bound(x) -> address of first element y such that y>x
    
    // int m;cin>>m;
    // while(m--)
    // {
    //     int x;cin>>x;
    //     auto it = s.lower_bound(x);
    //     if(it!=s.end())
    //     {
    //       cout<<"Smallest element in the set >=x is: "<<*it<<"\n";    
    //     }
    //     else cout<<x<<" is larger than all set elements"<<"\n";
    //     it = s.upper_bound(x);
    //     if(it!=s.end())
    //     {
    //       cout<<"Smallest element in the set >x is: "<<*it<<"\n";    
    //     }
    //     else cout<<x<<" is larger than all set elements"<<"\n";
    // }
    // finding address of largest element less than x
    cin>>x;
    if(x <= (*s.begin()))
    {
        cout<<"There is no element smaller than "<<x<<"\n";
    }
    else
    {
        auto it = s.lower_bound(x);
        it--;
        cout<<*it<<"\n";
    }
    // to delete an element y from the set 
    // s.delete(y);
    // s.delete(address of y);
}
void Sample_Problem()
{
    // You will be given q queries which can be of 3 types
    // 1 x  insert x into the set
    // 2 x  delete x from set
    // 3    print the smallest element

    int q;cin>>q;
    set <int> s;
    while(q--)
    {
        int type;cin>>type;
        int x;
        if(type == 1)
        {
            cin>>x;
            s.insert(x);
        }
        else if(type == 2)
        {
            cin>>x;
            if(s.find(x)!=s.end()) s.erase(x);
            else                   cout<<x<<' '<<"is not present in the array\n";
        }
        else
        {
            if(!s.empty())
            {
                cout<<*s.begin()<<"\n";
            }
            else cout<<"Set is empty\n";
        }
    }
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout << (1<<32)-1 << "\n" << INT_MAX;
   // Sample_Problem();
}


