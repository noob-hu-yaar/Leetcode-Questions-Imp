#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007;
#define ll long long int
#define pq priority_queue <ll,vector<ll>,greater<ll>>
#define pqpii priority_queue <pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>
#define MAX 100


bool isSafe(int maz[MAX][MAX],int x,int y,int n,int m){
if(x<0 || y<0 || x>=n || y>=m || maz[x][y]==-1 || maz[x][y]==0)
return 0;
return 1;
}


void solve(int maz[MAX][MAX],int cnt,int n,int m,
           int srow,int scol,int drow,int dcol,int &maxi)
{
    if(!isSafe(maz,srow,scol,n,m))return ;

    if(srow==drow && scol==dcol)
    {
        maxi=max(maxi,cnt);
        return;
    }
    else{
        maz[srow][scol]=-1;
        if(isSafe(maz,srow-1,scol,n,m)) //upward
        {
            solve(maz,cnt+1,n,m,srow-1,scol,drow,dcol,maxi);
        }
        if(isSafe(maz,srow+1,scol,n,m))//downward
        {
            solve(maz,cnt+1,n,m,srow+1,scol,drow,dcol,maxi);
        }
        if(isSafe(maz,srow,scol+1,n,m))//right
        {
            solve(maz,cnt+1,n,m,srow,scol+1,drow,dcol,maxi);
        }
        if(isSafe(maz,srow,scol-1,n,m))//left
        {
            solve(maz,cnt+1,n,m,srow,scol-1,drow,dcol,maxi);
        }
        maz[srow][scol]=1;
    }
}


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        int mat[MAX][MAX];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>mat[i][j];
        }
        int sx,sy;cin>>sx>>sy;
        int dx,dy;cin>>dx>>dy;
        int maxi=INT_MIN;
        solve(mat,0,n,m,sx,sy,dx,dy,maxi);
        cout<<maxi<<endl;
    }
}
