#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
    vector<vector<int>> v;
    vector<int> vc;    
        
        if(numRows==1)
        {
            vc.push_back(1);
            v.push_back(vc);
        }
        else if(numRows==2)
        {
            vc.push_back(1);
            v.push_back(vc);
            vc.clear();
            vc.push_back(1);
            vc.push_back(1);
            v.push_back(vc);
        }
    
        else if(numRows>=3)
        {
            vc.push_back(1);
            v.push_back(vc);
            vc.clear();
            vc.push_back(1);
            vc.push_back(1);
            v.push_back(vc);
            
            vector<int> temp;
            vector<int> temp1;
            for(int i=3;i<=numRows;i++)
            {
                temp=v[v.size()-1];
                temp1.push_back(1);
                for(int j=0;j<temp.size()-1;j++)
                {
                    temp1.push_back(temp[j]+temp[j+1]);
                }
                temp1.push_back(1);
                v.push_back(temp1);  
                temp.clear();
                temp1.clear();
            
            }
          
             
        }
    
    
    return v;
    }
};
