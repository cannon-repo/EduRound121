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
        ll n = s.length();
        ll pos = 0;
        vector<ll> single, couple;
        for(ll i=1;i<n;i++)
        {
            ll sum = (s[i]-'0') + (s[i-1]-'0');
            if(sum < 0)
                single.push_back(sum);
            else if(sum >= 10)
                couple.push_back(sum);
        }
        if(couple.size() > 0)
        {
            for(ll i=n-1;i>0;i--)
            {
                ll sum = (s[i]-'0') + (s[i-1]-'0');
                string ss = to_string(sum);
                if(sum >= 10)
                {
                    s[i-1] = ss[0], s[i] = ss[1];
                    break;
                }
            }
        }
        else if(couple.size() == 0)
        {
            string ans;
            ll sum = (s[0]-'0') + (s[1]-'0');
            string ss = to_string(sum);
            ans += ss;
            for(int i=2;i<n;i++)
                ans += s[i];
            s = ans;
        }
        cout<<s<<endl;
    }
    return 0;
}