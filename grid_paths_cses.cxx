#include <bits/stdc++.h>

using namespace std;
#define fr(i,a,b) for(int i=(a);i<(b);i++) 
#define in(a) cin>>a
#define sort(a,n) sort(a, a+n)
#define ar array
#define ll long long
#define dd double
#define fastio ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define pb(tmp) push_back(tmp)
#define cond(a) if(a)
#define inp(a) cin>>a
#define out(ar,n,m)         fr(i,0,n){fr(j,0,m){ cout<<dp[i][j]<<" ";}cout<<"\n";}cout<<"\n";

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
double fac(double n)
{
    if(n==0||n==1)
        return 1.0;
    return fac(n-1)*n;
}
double nCr(int n,int c)
{
    return fac(n)/(fac(c)*fac(n-c));
}

bool nVow(char c)
{
    if(c=='a' || c=='i' || c=='e' || c=='o' || c=='u')
        return true;
    return false;
}
int call(int i,int j,vector<string> inp,int n,int **dp)
{
    if(dp[i][j]!=-1 && i>=0 && j>=0)
        return dp[i][j];
    if(i < 0 || j <0 || inp[i][j]=='*') 
        {return 0;}
    if(i==0&&j==0)
        {dp[0][0]=1;return 1;}
    if((i==0 || j==0)) 
        {
            dp[i][j] = i==0?call(i,j-1,inp,n,dp)!=0:call(i-1,j,inp,n,dp)!=0;
            return dp[i][j];
        }
        
    dp[i][j] = call(i-1,j,inp,n,dp) + call(i,j-1,inp,n,dp);
    return dp[i][j];
}


void solve() {
    int n;
    cin>>n;
    vector<string> inp;
    for(int i=0;i<n;i++)
    {
        string t;
        cin>>t;
        inp.push_back(t);
    }
    int **dp = new int*[n];
    for(int i=0;i<n;i++)
    {
        dp[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            dp[i][j] = 0;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(inp[i][j]=='*' )
                dp[i][j] = 0; 
            else if(i==0 &&j==0)
                dp[i][j]=1;
            else if(i==0 || j==0)
            {
                dp[i][j] = i==0?dp[i][j-1]!=0:dp[i-1][j]!=0;
            }
            else
            {
                int op1 = dp[i-1][j];
                int op2 = dp[i][j-1];
                dp[i][j] = (op1+op2)%MOD;
            }
        }
    }
    //memset(dp,-1,sizeof(dp));
    cout<<dp[n-1][n-1]<<"\n";//call(n-1,n-1,inp,n,dp)<<"\n";
    }

    //return ;
/*
int call(int i,int j,vector<string> inp,int n,int **dp)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i < 0 || j <0 || inp[i][j]=='*') 
        {dp[i][j]=0;return 0;}
    if(i==0&&j==0)
        {dp[0][0]=1;return 1;}
    if((i==0 || j==0))
        {
            dp[i][j] = i==0?dp[i][j-1]!=0:dp[i-1][j]!=0;//call(i,j-1,inp,n,dp)!=0:call(i-1,j,inp,n,dp)!=0;
            return dp[i][j];
        }
        
    dp[i][j] = call(i-1,j,inp,n,dp) + call(i,j-1,inp,n,dp);
    return dp[i][j];
}

void solve() {
    int n;
    cin>>n;
    vector<string> inp;
    for(int i=0;i<n;i++)
    {
        string t;
        cin>>t;
        inp.push_back(t);
    }
    int **dp = new int*[n];
    for(int i=0;i<n;i++)
    {
        dp[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            dp[i][j] = -1;
        }
    }
    //memset(dp,-1,sizeof(dp));
    cout<<call(n-1,n-1,inp,n,dp)<<"\n";
    }
    */
    //return ;



int main() {
    fastio;
    int tc=1;
    //cout<<"helloworld";
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}