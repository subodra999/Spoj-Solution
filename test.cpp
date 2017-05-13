#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int l,n,q,type,x;
    cin >> n >> q;
    string s,st;
    char str;
    cin >> s;
    l = s.length();
    for(int t=0; t<q ; t++)
    {
        cin >> type >> x;
        if(type == 1)
        {
            cin >> str;
            s[x-1] = str;
        }
        else if(type == 2)
        {
            vector<int> ar(26,0);
            char ans;
            for(int i=0;i<l;i++)
            {
                ar[s[i]-'a']++;
            }
            int sum=0;
            for(int i=0;i<26;i++)
            {
                sum+=ar[i];
                if(sum>=x)
                {
                    ans = 'a'+i;
                    break;
                }
            }
            cout  << ans << endl;
        }
    }
    
    return 0;
}
