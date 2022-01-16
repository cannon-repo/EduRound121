#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
using namespace std;
int main()
{
    SPEED
    int t;cin>>t;
    while(t--)
    {
        string s;cin>>s;
        sort(s.begin(),s.end());
        cout<<s<<endl;
    }
    return 0;
}