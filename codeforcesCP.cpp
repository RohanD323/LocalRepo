#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vpi vector<pair<int,int>>
#define vpl vector<pair<ll, ll>>
#define yes cout<<"YES\n";
#define no cout<<"NO\n";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {   
        ll n, h, k;
        cin>>n>>h>>k;

        vl a(n);
        ll sum = 0;
        vl pre_sum(n + 1, 0);
        vl pre_min(n + 1, 0);

        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
            pre_sum[i + 1] = pre_sum[i] + a[i];
            sum += a[i];
        }   

        pre_min[0] = pre_min[1] = a[0];

        for(int i = 1; i < n; i++)
        {
            pre_min[i + 1] = min(pre_min[i], a[i]);
        }

        ll ans;
        ll cpy = h;

        if(h % sum == 0)
        {
            ans = n * (cpy/sum) + k * (cpy/sum - 1);
        }   
        else
        {
                h = h % sum;

                for(int i = 1; i < n + 1; i++)
                {
                    if(pre_sum[i] >= h)
                    {
                        ans = i;
                        break;
                    }
                }

                ll max_ele = *max_element(a.begin() + ans - 1, a.end());
                if(max_ele >= h)
                {
                    ans = 1 +  n * (cpy/sum) + k * (cpy/sum);
                }
                else
                {
                    bool any = false;
                    for(int i = 0; i < ans - 1; i++)
                    {
                        if(pre_sum[i + 1] - pre_min[i + 1] + max_ele >= h)
                        {
                            any = true;
                            ans = (i + 1) + n * (cpy/sum ) + k * (cpy/sum);
                            break;
                        }
                    }

                    if(!any) ans = ans + n * (cpy/sum ) + k * (cpy/sum);
                    
                }
        }
        cout<<ans<<"\n";
    }
   return 0;
}