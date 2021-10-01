

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

    string s;
    cin>>s;

    int cnt = 0;
    for(int i=0;i<3;i++)
    {
        if(s[i] == 'R')
            cnt++;
    }

    if(cnt == 0)
    cout<<"0";

    else if(cnt == 1 || cnt == 3)
    cout<<cnt;

    else
    {
        if(s[1] == 'R')
        cout<<"2";
        else
        cout<<"1";
    }

return 0;
}
