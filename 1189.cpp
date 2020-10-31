class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> m;
        m['b']=0;
        m['a']=0;
        m['l']=0;
        m['o']=0;
        m['n']=0;
        for(int i=0;i<text.length();i++)
        {
            char c=text[i];
            if(m.find(c)!=m.end())
            {
                m[c]++;
            }
        }
        int ans=INT_MAX;
        for(auto it=m.begin();it!=m.end();it++)
        {
            int freq;
            if(it->first=='o' or it->first=='l')
            {
                freq=it->second;
                freq=freq/2;
                ans=min(ans,freq);
            }
            else
            {
                freq=it->second;
                ans=min(ans,freq);
            }
        }
        return ans;
    }
};
