#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007;
#define ll long long int

//----------------Recursion-----------------
int solve(string s,int i,int j)
{
    if(i>j)
        return 0;
    if(i==j)
        return 1;
    //if the start and end of string matches -->considered as a subsequence
    if(s[i]==s[j])
        return 1 + solve(s,i+1,j) + solve(s,i,j-1);
    else
    /*
    if not same then search for both i+1,j and i,j-1 and remove the common
    portion of i+1,j-1 once
    */
        return solve(s,i+1,j) + solve(s,i,j-1) - solve(s,i+1,j-1);
}
//----------dp -> tabulation ----------------
int solveDP(string s)
{
  int n=s.size(),cnt=0;
  int dp[n][n];
  memset(dp,0,sizeof(dp));
  for(int i=n-1;i>=0;i--)
  {
      for(int j=i;j<n;j++)
      {
          if(i==j)
          dp[i][j]=1;
          else
          {
              if(s[i]==s[j])
              {
                  dp[i][j]= 1 + dp[i+1][j] + dp[i][j-1];
              }
              else
              dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
          }
      }
  }
  return dp[0][n-1];

}

int main()
 {
    int t;cin>>t;
    while(t--)
    {
        string s;cin>>s;
        cout<<solve(s,0,s.size()-1)<<endl;
    }
	return 0;
}
