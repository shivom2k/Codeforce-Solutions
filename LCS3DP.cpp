#include<iostream>
using namespace std;
int lcs3(string a,string b,string c,int i,int j,int k)
{
    int n=a.length();
    int m=b.length();
    int l=c.length();
    // if(i==n or b==m or k==l)
    // {
    //     return 0;
    // }

    int dp[n+1][m+1][l+1]={0};
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=l;k++)
            {
                if(i==0 or j==0 or k==0)
                dp[i][j][k]=0;
                else if(a[i]==b[j]==c[k])
                {
                    dp[i][j][k]=1+dp[i-1][j-1][k-1];
                }
                else
                {
                    dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                }
            }
        }
    }
    return dp[n][m][l];
}
int main()
{
    // int dp[11][12][13]={0};
    string a,b,c;
    cin>>a>>b>>c;
    cout<<lcs3(a,b,c,0,0,0);
}
