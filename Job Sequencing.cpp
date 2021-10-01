#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class job_sequencing
{
	public:
		string jobs;	
		int deadline;
		int profit;
};


bool comparison(job_sequencing js1, job_sequencing js2)
{
	return (js1.profit>js2.profit);
}

int maximum(job_sequencing js[], int n)
{
	int maxim = 0;
	
	for(int i=0;i<n;i++)
	{
		if(js[i].deadline > maxim)
		{
			maxim = js[i].deadline;
		}
	}
	
	return maxim;
}

int main()
{
	cout<<"Enter the number of jobs"<<endl;
	int n;
	cin>>n;
	
	job_sequencing js[n];
	
	cout<<"jobs     deadline    profit "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>js[i].jobs>>js[i].deadline>>js[i].profit;
	}
	
	//sort(js.profit, js.profit+n, greater<int>());   But js.profit is not an array, and we have to enter the array here
	
	
	//Step 1: Sorting on the basis of profit in the descending order
	sort(js, js+n, comparison);
	
	
	cout<<"\nActivities after sorting "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<js[i].jobs<<" "<<js[i].deadline<<" "<<js[i].profit<<endl;
	}
	
	int maximum_deadline = maximum(js, n);
	
	job_sequencing sol[maximum_deadline];
	
	for(int i=0;i<maximum_deadline;i++)
	{
		sol[i].jobs = "";
	}
	
	
	for(int i=0;i<n;i++)
	{
		int index = js[i].deadline;
		
		for(int j=index-1;j>=0;j--)
		{
			if(sol[j].jobs == "")
			{
				sol[j].jobs = js[i].jobs;
				sol[j].deadline = js[i].deadline;
				sol[j].profit = js[i].profit;
				break;
			}
		}	
		
	}
	
	cout<<"\nJob Sequence"<<endl;
	for(int i=0;i<maximum_deadline;i++)
	{
		cout<<sol[i].jobs<<" ";
	}
	
	cout<<"\n";
	int profit = 0;
	for(int i=0;i<maximum_deadline;i++)
	{
		profit += sol[i].profit;
	}
	
	cout<<"Profit is "<<profit<<endl;
	
	return 0;
	
}

/*
4
J1 2 6
J2 1 8
J3 1 5
J4 2 10

6
J1 5 200
J2 3 180
J3 3 190
J4 2 300
J5 4 120
J6 2 100

*/

