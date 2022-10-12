

#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define sp(x) fixed<<setprecision(x)
#define p_q priority_queue
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{

    fast_io;
    
    ll n,cnt = 0;
    cin>>n;
    
    vector<ll> a(n);
    for(ll &i : a)
        cin>>i;

    sort(a.begin(), a.end());

    for(ll i=0;i<n-2;i++)
    {
        for(ll j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(a[i]!=a[j] && a[j]!=a[k] && (a[j]+a[i] > a[k]) )
                    cnt++;
            }
        }
    }

    cout<<cnt<<endl;

return 0;
}
