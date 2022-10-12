#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007;
#define ll long long int
#define pq priority_queue <ll,vector<ll>,greater<ll>>
#define pqpii priority_queue <pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>

bool isValid(string s)
{
    stack <char> stk;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='('){
                stk.push(s[i]);
        }
        else if(s[i]==')'){
            if(stk.size()==0)stk.push(s[i]);
            else if(stk.top()=='(')stk.pop();
            else if(stk.top()==')')stk.push(s[i]);
        }
    }
    if(stk.size()==0)return 1;
    return 0;
}

void solve(string s,set <string> &ans,int invalid)
{
    if(isValid(s)){
        ans.insert(s);
    }
    if(invalid==0)
    {
        if(isValid(s))
        ans.insert(s);
        return;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]==')'){
        string l = s.substr(0,i);
        string r = s.substr(i+1);
        if(l.size()==0)
        solve(r,ans,invalid-1);
        else if(r.size()==0)
        solve(l,ans,invalid-1);
        else
        solve(l+r,ans,invalid-1);
        }
    }
}

int main(){
    int t;cin>>t;
    while(t--)
    {
        string s;cin>>s;
        stack <char> stk;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                stk.push(s[i]);
            }
            else if(s[i]==')'){
                if(stk.size()==0)stk.push(s[i]);
                else if(stk.top()=='(')stk.pop();
                else if(stk.top()==')')stk.push(s[i]);
            }
        }
        int invalid = stk.size();
        cout<<invalid<<endl;
        if(invalid == 0)
            cout<<s<<endl;
        else if(invalid==s.size())
            cout<<""<<endl;
        else{
            set <string> ans;
            solve(s,ans,invalid);
            for(auto it: ans)
                cout<<it<<" ";
            cout<<endl;
            ans.clear();
        }
    }
}
