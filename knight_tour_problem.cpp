#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007;
#define ll long long int
#define pq priority_queue <ll,vector<ll>,greater<ll>>
#define pqpii priority_queue <pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>
#define pie 3.1415926536
#define MAX 100
#define pb push_back
#define N 1000000007
#define M 998244353
#define ff first
#define ss second
#define pi pair<int,int>
#define pii pair< int, pair<int,int> >
#define all(v) (v).begin(),(v).end()
#define mem(a,b) memset(a,b,sizeof(a))

bool isSafe(int chess[MAX][MAX],int row,int col,int n)
{
    if(row>=n || row<0 || col>=n || col<0 || chess[row][col]!=0)
        return 0;
    return 1;
}


void solve(int chess[MAX][MAX], int row, int col, int n , int cnt ,int &p)
{
    if(row>=n || row<0 || col>=n || col<0 || chess[row][col]!=0)
        return;

    if(n*n==cnt && isSafe(chess,row,col,n))
    {
        chess[row][col]=cnt;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                cout<<chess[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        //chess[row][col]=0; for finding all possible solutions
        p++;
        return ;
    }
    else
    {
        chess[row][col]=cnt;
        if(isSafe(chess,row-2,col+1,n))
        {
            solve(chess,row-2,col+1,n,cnt+1,p);
        }
        if(isSafe(chess,row-1,col+2,n))
        {
            solve(chess,row-1,col+2,n,cnt+1,p);
        }
        if(isSafe(chess,row+1,col+2,n))
        {
            solve(chess,row+1,col+2,n,cnt+1,p);
        }
        if(isSafe(chess,row+2,col+1,n))
        {
            solve(chess,row+2,col+1,n,cnt+1,p);
        }
        if(isSafe(chess,row+2,col-1,n))
        {
            solve(chess,row+2,col-1,n,cnt+1,p);
        }
        if(isSafe(chess,row+1,col-2,n))
        {
            solve(chess,row+1,col-2,n,cnt+1,p);
        }
        if(isSafe(chess,row-1,col-2,n))
        {
            solve(chess,row-1,col-2,n,cnt+1,p);
        }
        if(isSafe(chess,row-2,col-1,n))
        {
            solve(chess,row-2,col-1,n,cnt+1,p);
        }
        chess[row][col]=0;
    }
}


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int srow,scol;cin>>srow>>scol;
        int chess[MAX][MAX];
        mem(chess,0);
        //chess[srow][scol]=1;
        int p=0;
        solve(chess,srow,scol,n,1,p);
        if(p)
        {
            cout<<"Possible"<<endl;
        }
        else cout<<"Not Possible"<<endl;
    }
}
