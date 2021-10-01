#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class activity_sel
{
	public:
		string activity;	
		int start;
		int finish;
};

bool comparison(activity_sel as1, activity_sel as2)
{
	return (as1.finish<as2.finish);  // Take care of sign
}


int main()
{
	cout<<"ENter number of activities "<<endl;
	int n;
	cin>>n;
		
	activity_sel as[n];
	activity_sel sol[n];
	
	cout<<"activity   start   finish"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>as[i].activity>>as[i].start>>as[i].finish;
	}
	
	//Step 1: Sorting on the basis of 'finish time' in the ascending order
	sort(as, as+n, comparison);
	
	int j=0;// To keep separate header for solution.
	
	// To enter the values if the activities in the solution object
	for(int i=1;i<n;i++)
	{
		if(j==0)
		{
			sol[j] = as[0];
			j++;
		}
		
		if(as[j-1].finish <= as[i].start || as[j-1].start>=as[i].finish)
		{
			sol[j] = as[i];
			j++; 
		}
	}
	
	cout<<"Printing the series of activities"<<endl;
	
	for(int i=0;i<j;i++)
	{
		cout<<sol[i].activity<<" "<<sol[i].start<<" "<<sol[i].finish<<endl;
	}
	
}

/*
6
a1 5 9
a2 1 2
a3 3 4
a4 0 6
a5 5 7
a6 8 9
*/
