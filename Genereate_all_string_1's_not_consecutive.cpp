#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007;
#define ll long long int
#define pq priority_queue <ll,vector<ll>,greater<ll>>
#define pqpii priority_queue <pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>


//Print All the possibilities of 1's not consecutive
void solve(vector <string> &bS, int k, string S){
if(k==0){bS.push_back(S);return;}
else {
    if(S[S.size()-1]=='0'){
        solve(bS,k-1,S+'0');
        solve(bS,k-1,S+'1');
    }else{
        solve(bS,k-1,S+'0');
    }
}
}

int main()
{
     fast;
     int t;cin>>t;
     while(t--){
            int k;cin>>k;
            vector <string> binString;
            solve(binString,k-1,"0");
            solve(binString,k-1,"1");
            for(int i=0;i<binString.size();i++)
                cout<<binString[i]<<" ";
            cout<<endl;
            binString.clear();
     }
}

