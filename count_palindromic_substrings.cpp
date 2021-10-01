#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007;
#define ll long long int

//----------------Recursion-----------------

bool isPalindrome(string s,int i,int j)
{
    while(i<j)
    {
        if(s[i]==s[j])
            i++,j--;
        else return 0;
    }
    return 1;
}

int solve(string s,int i,int j)
{
    if(i>j || i==j)
        return 0;
    if(i+1==j)
    {
        if(s[i]==s[j])return 1;
        return 0;
    }
    /*add 1 for the current substring and subtract the common
     substring s(i+1,j-1) after finding for i+1,j and i,j-1
     */
    if(isPalindrome(s,i,j))
        return 1 + solve(s,i+1,j) + solve(s,i,j-1) - solve(s,i+1,j-1);
    else
    /*
    if not palindrome then search for both i+1,j and i,j-1 and remove the common
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
          dp[i][j]=0;
          else if(i+1==j)
          {
              if(s[i]==s[j])
                dp[i][j]=1;
              else dp[i][j]=0;
          }
          else
          {
              if(isPalindrome(s,i,j))
              {
                  dp[i][j]= 1 + dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
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
        cout<<solveDP(s)<<endl;
    }
	return 0;
}
