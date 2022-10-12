#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007;
#define ll long long int
#define pq priority_queue <ll,vector<ll>,greater<ll>>
#define pqpii priority_queue <pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>

void solve(vector <int> arr,int i,int nes,vector <int> sum,
           int Sum,int k,bool &pos)
{
    if(i==arr.size())
    {
        if(nes==k)
        {
            int cnt=0;
            for(int i=0;i<k;i++)
            {
                if(sum[i]!=Sum)
                    break;
                else
                    cnt++;
            }
            if(cnt==k)
            {
                pos=1;
            }
        }
        return ;
    }

    for(int j=0;j<k;j++)
    {
       if(sum[j]==0) //empty set
       {
           sum[j]+=arr[i];
           solve(arr,i+1,nes+1,sum,Sum,k,pos);
           sum[j]-=arr[i];
           return;
       }
       else //non-empty set
       {
           sum[j]+=arr[i];
           solve(arr,i+1,nes,sum,Sum,k,pos);
           sum[j]-=arr[i];
       }
    }
}


int main()
{
    int t;cin>>t;
    while(t--)
    {
        ll n,k,Sum=0;cin>>n>>k;
        vector <int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            Sum+=arr[i];
        }
        if(Sum%k!=0 || k>n)
        {
            cout<<0<<endl;
        }
        else
        {
            vector <int> sum(k);
            for(int i=0;i<k;i++)sum[i]=0;
            bool pos=0;
            solve(arr,0,0,sum,Sum/k,k,pos);
            if(pos==1)
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
    }
}
