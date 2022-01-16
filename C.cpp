#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
using namespace std;
struct dsa{
    ll mnReqd = 0;
    bool carry;
};
int main()
{
    SPEED
    int t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        vector<ll> arrT(n), arrH(n);
        for(int i=0;i<n;i++)
            cin>>arrT[i];
        for(int i=0;i<n;i++)
            cin>>arrH[i];
        vector<dsa> nums(n);
        nums[n-1].carry = false;
        nums[n-1].mnReqd = arrH[n-1];
        for(int i=n-2;i>=0;i--)
        {
            ll td = arrT[i+1] - arrT[i];
            if(td >= nums[i+1].mnReqd)
            {   
                nums[i].mnReqd = arrH[i];
                nums[i].carry = false;
            }
            else if(td < nums[i+1].mnReqd)
            {
                nums[i].mnReqd = max(arrH[i],nums[i+1].mnReqd-td);
                nums[i].carry = true;
            }
        }
        ll ans = (nums[0].mnReqd*(nums[0].mnReqd+1))/2;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1].carry)
            {
                ll td = arrT[i] - arrT[i-1];
                ll dL = nums[i-1].mnReqd+td;
                ll dS = nums[i-1].mnReqd;
                ll damage = ((dL*(dL+1))/2) - ((dS*(dS+1))/2);
                ans += damage;
                nums[i].mnReqd = max(nums[i].mnReqd,dS+td);
            }
            else if(!nums[i-1].carry)
            {
                ll damage = nums[i].mnReqd;
                ans += (damage*(damage+1))/2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}