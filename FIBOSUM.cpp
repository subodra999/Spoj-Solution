
// Fast fibonacci

#include <bits/stdc++.h>

using namespace std;

unordered_map <long long int,long long int> mp;
long long int mod = 1000000007;

long long int f(long long int n)
{
    if(mp.find(n) != mp.end())
    {
        return mp[n];
    }
    if(n%2==0)
    {
        mp[n] = ((f(n/2))*((mod+((2*f(n/2+1))%mod-f(n/2)))%mod))%mod;
    }
    else
    {
        mp[n] = ((f((n-1)/2)*f((n-1)/2))%mod + (f((n+1)/2)*f((n+1)/2))%mod)%mod;
    }
    return mp[n];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); 
    int t;
    cin>>t;
    mp[0] = 0;
    mp[1] = 1;
    mp[2] = 1;
    long long int n,m,ans;
    while(t--)
    {
        cin>>n>>m;
        ans = 0;
        ans = (ans + f(m+2)%mod)%mod;
        ans = (ans + mod - f(n+1)%mod)%mod;
        cout<<ans<<endl;
    }
    return 0;
}