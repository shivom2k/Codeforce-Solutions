#include <iostream>
using namespace std;
int NKnapSack(int wt[],int val[],int n,int W)
{
    int dp[W+1]={0};
    for(int i=0;i<=W;i++)
    {
        for(int j=0;j<n;j++)
        { 
            if(wt[j]<=i)
            {
                dp[i]=max(dp[i],dp[i-wt[j]]+val[j]);
            }
        }
    }
    return dp[W];
}
int main() {
    int n,W;
    cin>>n>>W;
    int wt[n];
    int val[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    cout<<(NKnapSack(wt,val,n,W))<<endl;
}

