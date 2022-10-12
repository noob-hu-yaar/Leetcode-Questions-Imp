#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007;
#define ll long long int
#define pq priority_queue <ll,vector<ll>,greater<ll>>
#define pqpii priority_queue <pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>
#define pie 3.1415926536
#define pb push_back
#define N 1000000007
#define M 998244353
#define ff first
#define ss second
#define pi pair<int,int>
#define pii pair< int, pair<int,int> >
#define all(v) (v).begin(),(v).end()
#define mem(a,b) memset(a,b,sizeof(a))

int num(string s)
{
    ll sum=0;
    for(int i=0;i<s.size();i++)
        sum+=sum*10+(s[i]-'0');
    return sum;
}

void solve(string s,vector <string> &res,vector <string> ans,  int n)
{
    if(ans.size()!=3 && ans.size()>s.size())return;
    if(ans.size()==3)
    {
        if(s.size()!=0)
        {
            string a;
            for(int i=0;i<ans.size();i++){
            if(stoll(ans[i])>255 || ans[i][0]=='0')return;
            a+=ans[i]+".";
            }
            //cout<<a<<" "<<s<<endl;
            if(stoll(s)>255 || s[0]=='0')return;
            a+=s;
            res.push_back(a);
        }
        return;
    }

    for(int i=0;i<n;i++)
    {
        ans.push_back(s.substr(0,i+1));
        solve(s.substr(i+1),res,ans,s.substr(i+1).size());
        ans.pop_back();
    }

}

int main()
{
     fast;
     int t;cin>>t;
     while(t--)
     {
        string s;cin>>s;
        vector <string> res;
        vector <string> res1;
        solve(s,res,res1,s.size());
        for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
     }
}

