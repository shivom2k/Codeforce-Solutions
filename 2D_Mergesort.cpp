
#include<bits/stdc++.h>
// #include<stdint.h>
// #define N 105
using namespace std;
// void printArray(vector<int> arr, int size)
// {
// for (int i=0; i<size ; i++)
// 	cout << arr[i] << " ";
// }
int n,m;

 // } Driver Code Ends
//User function Template for C++
// using namespace __gnu_pbds;
//using namepace __gnu_cxx;
// #define ff              first
// #define ss              second
// #define int             long long
// #define pb              push_back
// #define mp              make_pair
// #define pii             pair<int,int>
// #define vi              vector<int>
// #define vpii            vector<pii>
// #define mii             map<int,int>
// #define pq              priority_queue
// #define pqb             priority_queue<int>
// #define pqs             priority_queue<int,vi,greater<int>>
#define fo(i,a,b)     for(int i=a;i<b;i++)           
// #define setbits(x)      _buildin_popcountll(x)
// #define zrobits(x)      _buildin_ctzll(x)
// #define mod             1000000007
// #define inf             1e18
// #define ps(x,y)         fixed<<setprecision(y)<<x
// #define mk(arr,n,type)  type *arr=new type[n];
// #define w(x)            int x ; cin>>x;while(x--)
// #define FIO             ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
// mt19937                 rng(chrono:: steady_clock::now().time_since_epoch().count());
#define ce 				cout<<"\n";

void printgrid(int **grid )
{
      fo(i,0,n)
    {
        fo(j,0,m) cout<<grid[i][j]<<" ";
        ce
    }
    
}


void func(int **grid,int lr1,int hr1,int lc1,int hc1)
{  
    // cout<<" lr1 "<<lr1<<" hr1 "<<hr1<<" lc1 "<<lc1<<" hc1 "<<hc1<<endl; 
if(lr1>hr1 || lc1>hc1 || lr1==-1 || hr1==n || lc1==-1 || hc1==m) return ;
    
    // printgrid(grid);
    // ce
    if(lr1==hr1 && lc1==hc1) return ;
    if(lr1==hr1)
       {   
            
            sort(grid[lr1]+lc1,grid[lr1]+hc1-lc1+1);
        return ;
       }
    if(lc1==hc1)
    { 
        // cout<<"sort if lc1==hc1"<<endl;
        int temp[hr1-lr1+1];
        int i=0;
        for(int b=lr1;b<=hr1;b++)
        {
            temp[i++]=grid[b][lc1];
        }
        sort(temp,temp+i);
        for(int j=0;j<i;j++)
          grid[lr1+j][lc1]=temp[j];
        return ;
    }
    int m1=lr1+(hr1-lr1)/2;
    int m2=lc1+(hc1-lc1)/2;
    func(grid, lr1  ,m1   ,lc1   ,m2);
    func(grid, m1+1 ,hr1  ,lc1   ,m2);
    func(grid, lr1  ,m1   ,m2+1  ,hc1);
    func(grid, m1+1 ,hr1  ,m2+1  ,hc1);
    for(int a=lr1;a<=hr1;a++)
    {
        // int temp[]
        // cout<<" sort if lr1 < hr1 where lr1 = "<<lr1<<" hr1 ="<<hr1<<" lc1 = "<<lc1<<" hc1 = "<<hc1<<" a= "<<a;
        //  sort(grid[a],grid[a]+1hc1-lc1); yaha thi gadbad
        sort(grid[a]+lc1,grid[a]+1+hc1);
    }
    for(int a=lc1;a<=hc1;a++)
    {
        int temp[hr1-lr1+1];
        int i=0;
        for(int b=lr1;b<=hr1;b++)
        {
            temp[i++]=grid[b][a];
        }
        sort(temp,temp+i);
        for(int j=0;j<i;j++)
          grid[lr1+j][a]=temp[j];
    }
    // cout<<" at end of func "<<" lr1 "<<lr1<<" hr1 "<<hr1<<" lc1 "<<lc1<<" hc1 "<<hc1<<endl;
    //  printgrid(grid);
    // ce

}

int main()
{
	// FIO;
	
    cin>>n>>m;
    int **grid;
    grid= new int *[n];
    for(int i=0;i<n;i++)
         {  grid[i]=new int[m];
             for(int j=0;j<m;j++)
             {
                cin>>grid[i][j];
            }
         }
    func(grid,0,n-1,0,m-1);
    cout<<grid[0][0];
    fo(i,0,n)
    {   
        fo(j,0,m)  
        {if(i==0 && j==0) continue; 
        cout<<" "<<grid[i][j];}
        // cout<<endl;
    }
    // cout<<grid[n-1][m-1];
    // cout<<" now printing grid again "<<endl;
    // printgrid(grid);
    
	return 0;
}
//
/*
4 5
9 8 1 5 20 
6 0 2 3 18
25 23 21 19 18
8 7 3 6 1

*/
/* 
2 3
9 8 1
6 0 2
*/

/* 
5 5
9 8 1 5 20 
6 0 2 3 18
25 23 21 19 18
8 7 3 6 1
20 17 15 14 13
*/