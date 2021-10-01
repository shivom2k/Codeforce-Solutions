#include<bits/stdc++.h>
using namespace std;
typedef long long int ln;
void fun()
{
   int n;
   cin>>n;
   int a[n];
   int b[n];
   for(int i=0;i<n;i++)
   {
   	cin>>a[i];
   }
   for(int i=0;i<n;i++)
   {
   	cin>>b[i];
   }

  int min_index=100000000;
  int min_value=100000000;
  for(int i=0;i<n;i++)
  {
  	int c=(a[0]+b[i])%n;
  	if(c<min_value)
  	{
  		min_value=c;
  		min_index=i;
	}
    else if(c==min_value)
    {
    	
	}
    
  }
  int temp[n];
  int m=0;
  for(int i=min_index;i<n;i++)
  {
  	temp[m]=b[i];
  	m++;
  }
for(int i=0;i<min_index;i++)
{
	temp[m]=b[i];
	m++;
}

int lex[n];

for(int i=0;i<n;i++)
{
	lex[i]=(a[i]+temp[i])%n;
}
for(int i=0;i<n;i++)
{
	cout<<lex[i]<<" ";
}
cout<<endl;
return;
}
int main()
{
	int t=0;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		fun();
	}
return 0;
}
