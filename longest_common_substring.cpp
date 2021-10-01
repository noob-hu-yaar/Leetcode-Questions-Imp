#include<bits/stdc++.h>
using namespace std;

int LCS(string s1,string s2,int n,int m, int ans , int &maxi)
{
    if(n==0 || m==0)
        return ans;

    if(s1[n-1]==s2[m-1])
    {
     ans = LCS(s1,s2,n-1,m-1,ans+1,maxi);
    }
    return max(ans,max(LCS(s1,s2,n-1,m,0,maxi),LCS(s1,s2,n,m-1,0,maxi)));

}

int main()
{
    string s1,s2;cin>>s1>>s2;
    int ans=0 , maxi=INT_MIN;
    LCS(s1,s2,s1.size(),s2.size(),ans,maxi);
    cout<<ans<<endl;
}
