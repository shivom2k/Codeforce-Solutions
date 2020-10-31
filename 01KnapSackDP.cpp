//Knapsack 0/1
//wt and val array
#include<bits/stdc++.h>
using namespace std;
int knapsack(int wt[],int val[],int w,int n,int dp[][1002])
{
	//Base Case
	if(n==0 or w==0)
	return 0;
	
	//Recursion Case
	if(dp[n][w]!=-1)
	return dp[n][w];
	if(wt[n-1]<=w)
	{
		return dp[n][w]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1,dp),knapsack(wt,val,w,n-1,dp));
	}
	else
	{
		return dp[n][w]=knapsack(wt,val,w,n-1,dp);
	}
}
int main()
{
	int n,s;
	cin>>n>>s;
	int a[n],b[n];
	int dp[n+2][1002];
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	cout<<knapsack(a,b,s,n,dp);
}
