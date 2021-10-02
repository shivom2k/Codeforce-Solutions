#include<bits/stdc++.h>
using namespace std;
typedef long long int ln;  
void fun()
{
	int arr[3];
	for(int i=0;i<3;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+3);
	cout<<arr[2]+arr[1]<<endl;
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
