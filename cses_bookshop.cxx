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

//int call(vector<int> cost,vector<int>pages,int n,int thr_cost)
int call(vector<int> cost,vector<int>pages,int n,int thr_cost,int **dp)
{


    //LOGIC FOR BOOK STORE cses   [Memoisation]
    if(dp[n][thr_cost]!=-1 )
        return dp[n][thr_cost];
    //cout<<dp[n][thr_cost]<<"\n";
    if(thr_cost<0)
        return INT_MIN;
    
    else if(n==0||thr_cost==0)
        return 0;
    
    else if(thr_cost>=cost[n-1])
    {
        //cout<<n<<" "<<thr_cost<<" \n";
 
        //cout<<cost[n-1]<<" "<<pages[n-1]<<"  index = "<<n-1<<"\n";
        dp[n][thr_cost] = max(pages[n-1]+call(cost,pages,n-1,thr_cost-cost[n-1],dp),call(cost,pages,n-1,thr_cost,dp));  
        return dp[n][thr_cost];
    }
    else
    {
        dp[n][thr_cost] = call(cost,pages,n-1,thr_cost,dp);
        return dp[n][thr_cost];
    }
    
    
    //LOGIC FOR GRID PATH cses  [Top Down]
    // if(dp[i][j]!=-1)
    //     return dp[i][j];
    // if(i < 0 || j <0 || inp[i][j]=='*') 
    //     {return 0;}
    // if(i==0&&j==0)
    //     {dp[0][0]=1;return 1;}
    // if((i==0 || j==0)) 
    //     {
    //         dp[i][j] = i==0?call(i,j-1,inp,n,dp)!=0:call(i-1,j,inp,n,dp)!=0;            
    //         return dp[i][j];
    //     }
        
    // dp[i][j] = call(i-1,j,inp,n,dp) + call(i,j-1,inp,n,dp);
    // return dp[i][j];
}

void solve() {

    int n,thr_cost;
    cin>>n>>thr_cost;
    vector<int> pages,cost;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        cost.push_back(t);
    }
    
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        pages.push_back(t);
    }


    int **dp = new int*[n+1];
    for(int i=0;i<=n;i++)
    {
       dp[i] = new int[thr_cost+1];
       for(int j=0;j<thr_cost+1;j++)
          dp[i][j] = -1;
    }
    //cout<<call(cost,pages,n,thr_cost,dp)<<"\n";

// Top Down Logic for GRID-PATH cses    
    for(int i=0;i<=n;i++)
    {
        for(int j = 0;j<=thr_cost;j++)
        {
            if(j==0||i==0)
                dp[i][j] = 0;
            else if(cost[i-1]<=j)
            {
                dp[i][j] = max(pages[i-1]+dp[i-1][j-cost[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
            //cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<dp[n][thr_cost]<<"\n";



// Top Down Logic for GRID-PATH cses
/*
    int n,thr_cost;
    cin>>n>>thr_cost;
    vector<int> pages,cost;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        cost.push_back(t);
    }
    
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        pages.push_back(t);
    }
    cout<<call(cost,pages,n,thr_cost)<<"\n";
    int **dp = new int*[n];
    for(int i=0;i<n;i++)
    {
        dp[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            dp[i][j] = 0;
        }
    }
    */
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         if(inp[i][j]=='*' )
    //             dp[i][j] = 0; 
    //         else if(i==0 &&j==0)
    //             dp[i][j]=1;
    //         else if(i==0 || j==0)
    //         {
    //             dp[i][j] = i==0?dp[i][j-1]!=0:dp[i-1][j]!=0;
    //         }
    //         else
    //         {
    //             int op1 = dp[i-1][j];
    //             int op2 = dp[i][j-1];
    //             dp[i][j] = op1+op2;
    //         }
    //     }
    // }
    //memset(dp,-1,sizeof(dp));
    //cout<<dp[n-1][n-1]<<"\n";//call(n-1,n-1,inp,n,dp)<<"\n";
    }
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