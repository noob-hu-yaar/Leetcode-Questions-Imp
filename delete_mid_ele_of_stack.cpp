#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007;
#define ll long long int
#define pq priority_queue <ll,vector<ll>,greater<ll>>
#define pqpii priority_queue <pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>

void mid(stack <ll> &stk , ll ct){
if(ct==1){
    stk.pop();
    return ;
}
ll val = stk.top();
stk.pop();
mid(stk,ct-1);
stk.push(val);
}


int main(){
ll t;cin>>t;
while(t--){
    ll n;cin>>n;
    stack <ll> stk;
    for(ll i=0;i<n;i++){
        ll x;cin>>x;
        stk.push(x);
    }
    ll cnt = n/2 + 1;
    mid(stk,cnt);
    while(stk.size()!=0){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<endl;
}
}
